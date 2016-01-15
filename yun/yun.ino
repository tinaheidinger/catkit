#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

YunServer server; // instantiate yun server that will listen for clients

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for debugging
  pinMode(13,OUTPUT); // turn on LED while bridge begins
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH); // bridge is ready, turn off LED

  server.listenOnLocalhost(); // server listens to connections from localhost on port 5555
  server.begin(); // start server

}

void loop() {
  // put your main code here, to run repeatedly:
  YunClient client = server.accept(); // connect client

  if (client) {
    process(client); // process requests
    client.stop(); // disconnect client
  }

  delay(50); 

}

/**
 * Parses REST commands by functionality,
 * passes information to respective functions
 */
void process(YunClient client) {
  String command = client.readStringUntil('/');

  if (command == "digital") {
    digitalCommand(client);
  }
  if (command == "analog") {
    analogCommand(client);
  }
  if (command == "mode") {
    modeCommand(client);
  }
}

/**
 * Deals with digital commands
 */
void digitalCommand(YunClient client) {
  int pin;
  int value;
  pin = client.parseInt(); // parse request for pin

  if (client.read() == '/') { // URL will have value 1 or 0
    value = client.parseInt();
    digitalWrite(pin, value);
  } 
  else {
    value = digitalRead(pin);
  }
  Bridge.put("D" + pin, String(value)); // send key and value to bridge
}

/**
 * Deals with analog commands
 */
void analogCommand(YunClient client) {
  int pin;
  int value;

  pin = client.parseInt();

  if (client.read() == '/') {
    value = client.parseInt();
    analogWrite(pin, value);
    Bridge.put("D" + pin, String(value)); // send key and value to bridge
  } else {
    value = analogRead(pin);
    Bridge.put("A" + pin, String(value));  
  }
}

/**
 * Deals with mode commands
 */
void modeCommand(YunClient client) {
  int pin;
  pin = client.parseInt();

  if (client.read() != '/') {
    client.println(F("error")); // invalid URL
    return;
  }

  String mode = client.readStringUntil('\r');

  if (mode == "input") {
    pinMode(pin, INPUT);
    return;
  }

  if (mode == "output") {
    pinMode(pin, OUTPUT);
    return;
  }

  client.print(F("error: invalid mode"));
}


  
