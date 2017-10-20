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

uint frechet_recursive(uint i, uint j);

uint frechetDistance(Coordonates *p, Coordonates *q);

#endif /* frechet_h */
