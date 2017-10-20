//
//  frechet.c
//  AOD
//
//  Created by Cyril Carlin on 20/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#include "frechet.h"
#include "math.h"
#include <math.h>
#include <stdlib.h>

uint distance(Coordonates p1, Coordonates p2)
{
    return((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int frechetDistance(Coordonates *p, Coordonates *q, int lengthP, int lengthQ)
{
    int **distanceMatrix = malloc(lengthP * sizeof(int *));
    
    for (int i = 0; i < lengthP; i++) {
        distanceMatrix[i] = malloc(lengthQ * sizeof(int));
        for (int j = 0; j < lengthQ; j++) {
            distanceMatrix[i][j] = -1;
        }
    }
    
    return frechet_recursive(lengthP - 1, lengthQ - 1, distanceMatrix, p, q);
}

int frechet_recursive(uint i, uint j, int **matrix, Coordonates *p, Coordonates *q)
{
    
    if (matrix[i][j] > -1)
        return matrix[i][j];
    else if(i==0 && j==0)
        matrix[i][j] = distance(p[0], q[0]);
    else if (i==0 && j>0)
        matrix[i][j] = (maximum(distance(p[0], q[j]), frechet_recursive(0, j-1, matrix, p, q), -1));
    else if (i>0 && j==0)
        matrix[i][j] = (maximum(distance(p[i], q[0]), frechet_recursive(i-1, 0, matrix, p, q), -1));
    else
        matrix[i][j] = (maximum(distance(p[i], q[j]), minimum(frechet_recursive(i-1, j-1, matrix, p, q), frechet_recursive(i, j-1, matrix, p, q), frechet_recursive(i-1, j, matrix, p, q), -1), -1));
    
    return matrix[i][j];

}

