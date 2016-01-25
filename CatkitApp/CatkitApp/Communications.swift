//
//  Communications.swift
//  CatkitApp
//
//  Created by Marcel Hansemann on 21/01/16.
//  Copyright © 2016 Moto5. All rights reserved.
//

import Foundation
class Communications {
    init(yunUrl:String, yunPort:Int) {
        self.yunUrl = NSURL(string:("http://" + yunUrl + ":" + String(yunPort)))!;
    }
    public var yunUrl:NSURL;
    
    func sendRequestToYun(requestUrl: String, /*parameters: [String: AnyObject], */ onComplete: (NSData?, NSURLResponse?, NSError?) -> Void) -> NSURLSessionTask {
       // let parameterString = parameters.stringFromHttpParameters()
        var urlTrunk : String
        urlTrunk = String(self.yunUrl) + "/" + requestUrl
        
        let requestURL = NSURL(string: requestUrl, relativeToURL: self.yunUrl)
        let request = NSMutableURLRequest(URL:requestURL!)
        request.HTTPMethod = "GET"
        
        let session = NSURLSession.sharedSession()
        let task = session.dataTaskWithRequest(request, completionHandler: onComplete)
        task.resume()
        return task
    }
}
