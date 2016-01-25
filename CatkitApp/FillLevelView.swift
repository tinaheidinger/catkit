//
//  FillLevelView.swift
//  CatkitApp
//
//  Created by Marcel Hansemann on 25/01/16.
//  Copyright © 2016 Moto5. All rights reserved.
//

import Foundation
import UIKit

class FillLevelView : UIView {
    var maxFillLevel : Double = 100
    var targetFillLevel : Double = 100
    var fillLevel : Double = 0
    
    override func drawRect(rect: CGRect) {
        let c : CGContextRef? = UIGraphicsGetCurrentContext()
        if c != nil {
            var fillHeight = (Double(self.frame.height) / maxFillLevel) * fillLevel;
            
            CGContextSetFillColorWithColor(c, UIColor.blueColor().CGColor)
            CGContextFillRect(c, CGRectMake(self.frame.origin.x, 0, self.frame.origin.y, CGFloat(fillHeight)))
        }
    }
}