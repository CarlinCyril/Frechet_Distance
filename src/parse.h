//
//  parse.h
//  AOD
//
//  Created by Cyril Carlin on 20/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#ifndef parse_h
#define parse_h

#include <stdio.h>

typedef struct Coordonates
{
    int x;
    int y;
} Coordonates;

void parse(FILE *file, Coordonates *P, Coordonates *Q, int n, int m);

#endif /* parse_h */
