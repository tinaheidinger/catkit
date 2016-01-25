//
//  TabBarController.swift
//  CatkitApp
//
//  Created by Marcel Hansemann on 24/01/16.
//  Copyright © 2016 Moto5. All rights reserved.
//

import Foundation
import UIKit

class TabBarController : UITabBarController {
    @IBOutlet var webView: UIWebView!
    @IBAction func showVideoStream(sender: AnyObject) {
        self.view.addSubview(webView)
        webView.frame = CGRectMake(0, 0, 200, 300)
    }
    override func viewDidLoad() {
       // showVideoStream(" ")
    }
}