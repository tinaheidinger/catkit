#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

YunServer server; // instantiate yun server that will listen for clients

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for debugging
  pinMode(13,OUTPUT); // turn on LED while bridge begins
  digitalWrite(13, HIGH);
  Bridge.begin();
  digitalWrite(13, LOW); // bridge is ready, turn off LED

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
  String command = client.readStringUntil('\r');

  if (command == "feed") {
    feedCommand(client);
  }
  if (command == "fill") {
    fillCommand(client);
  }
  if (command == "play") {
    playCommand(client);
  }
  if (command == "status") {
    statusCommand(client);
  }
}

void feedCommand(YunClient client) {
  client.println("Status: 200");
  client.println("Content-type: application/json");
  client.println();
  // return ok status
  client.print("{\"fed\":\"ok\"}");
}

void fillCommand(YunClient client) {
  client.println("Status: 200");
  client.println("Content-type: application/json");
  client.println();
  // return ok status
  client.print("{\"filled\":\"ok\"}");
}

void playCommand(YunClient client) {
  client.println("Status: 200");
  client.println("Content-type: application/json");
  client.println();
  // return ok status
  client.print("{\"played\":\"ok\"}");
}

void statusCommand(YunClient client) {
  client.println("Status: 200");
  client.println("Content-type: application/json");
  client.println();
  // return ok status
  client.print("{\"status\":\"ok\"}");
}


  
