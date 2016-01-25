//
//  PreferencesViewController.swift
//  CatkitApp
//
//  Created by Marcel Hansemann on 25/01/16.
//  Copyright © 2016 Moto5. All rights reserved.
//

import Foundation
import UIKit
class PreferencesViewController : UITableViewController {
    
    @IBOutlet weak var serverAddressTextfield: UITextField!
    @IBAction func sendRequest(sender: AnyObject) {
        let comm = Communications(yunUrl: serverAddressTextfield.text!, yunPort: 8081)
        comm.sendRequestToYun("arduino/feed", onComplete:
            { (NSData data, NSURLResponse urlResponse, NSError error) -> Void in
                var alertView = UIAlertView(title: "Connection successful", message: ("Server response: " + String(data: data!, encoding: NSUTF8StringEncoding)!), delegate: nil, cancelButtonTitle: "Done")
                alertView.show()
        });
        
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}