//
//  math.c
//  AOD
//
//  Created by Cyril Carlin on 20/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#include "math.h"
#include <stdarg.h>

uint maximum(uint u1, ...)
{
    va_list args;
    uint currentMax = u1;
    
    va_start(args, u1);
    int arg = va_arg(args, int);
    
    while (arg != -1) {
        if(currentMax < arg)
            currentMax = arg;
        arg = va_arg(args, int);
    }
    return currentMax;
}

uint minimum(uint u1, ...)
{
    va_list args;
    uint currentMin = u1;
    
    va_start(args, u1);
    int arg = va_arg(args, int);
    
    while (arg != -1) {
        if(currentMin > arg)
            currentMin = arg;
        arg = va_arg(args, int);
    }
    return currentMin;
}
