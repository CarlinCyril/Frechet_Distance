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
#include <stdint.h>

uint32_t distance(Coordonates p1, Coordonates p2);

int frechet_recursive(uint32_t i, uint32_t j, int **matrix, Coordonates *p, Coordonates *q);

int frechetDistance(int **distanceMatrix, Coordonates *p, Coordonates *q, int lengthP, int lengthQ);

void frechet_rec(int *matrix, uint32_t i1, uint32_t i2, uint32_t j1, uint32_t j2, Coordonates *p, Coordonates *q, int lengthP, int lengthQ);

void frechet_optim(int *matrix, uint32_t i1, uint32_t i2, uint32_t j1, uint32_t j2, Coordonates *p, Coordonates *q, int lengthP, int lengthQ);

int frechet(char *filename);

void parcours_optimal(int **matrix, int distanceFrechet, int i, int j, int *parcours, int k);


#endif /* frechet_h */
