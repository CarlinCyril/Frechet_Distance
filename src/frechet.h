//
//  frechet.h
//  AOD
//
//  Created by Cyril Carlin on 20/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#ifndef frechet_h
#define frechet_h

#include "parse.h"

uint distance(Coordonates p1, Coordonates p2);

int frechet_recursive(uint i, uint j, int **matrix, Coordonates *p, Coordonates *q);

int frechetDistance(Coordonates *p, Coordonates *q, int lengthP, int lengthQ);

#endif /* frechet_h */
