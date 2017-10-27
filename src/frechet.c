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

#define S 256

int lengthP = 0;
int lengthQ = 0;

uint distance(Coordonates p1, Coordonates p2)
{
    return((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Version naïve de l'algorithme
// frechetDistance appelle frechet_recursive et initialise la matrice
void frechetDistance(int *distanceMatrix, Coordonates *p, Coordonates *q)
{
    for (int i = 0; i < (lengthP-1) * lengthQ + lengthQ; i++) {
        distanceMatrix[i] = -1;
    }
    
    frechet_recursive(lengthP - 1, lengthQ - 1, distanceMatrix, p, q);
}

// Version naïve de l'algorithme
// frechet_recursive applique la relation de Bellman
int frechet_recursive(uint i, uint j, int *matrix, Coordonates *p, Coordonates *q)
{
    if (matrix[i*(lengthQ) +j] > -1) {
        return matrix[i*(lengthQ) +j];
    }
    if(i==0 && j==0)
        matrix[0] = distance(p[0], q[0]);
    else if (i==0 && j>0)
        matrix[j] = (maximum(distance(p[0], q[j]), frechet_recursive(0, j-1, matrix, p, q), -1));
    else if (i>0 && j==0)
        matrix[i*(lengthQ)] = (maximum(distance(p[i], q[0]), frechet_recursive(i-1, 0, matrix, p, q), -1));
    else
        matrix[i*(lengthQ) +j] = (maximum(distance(p[i], q[j]), minimum( frechet_recursive(i, j-1, matrix, p, q), frechet_recursive(i-1, j-1, matrix, p, q),frechet_recursive(i-1, j, matrix, p, q), -1), -1));
    
    return matrix[i*(lengthQ) +j];

}

// Version optimisée de l'algorithme
// frechet_rec découpe la matrice en blocs plus petit qui doivent pouvoir être contenus dans le cache (de manière récursive)
void frechet_rec(int *matrix, uint i1, uint i2, uint j1, uint j2, Coordonates *p, Coordonates *q)
{
    if((i2 - i1)*(j2 - j1) < 128)
    {
        frechet_optim(matrix, i1, i2, j1, j2, p, q);
    }
    else
    {
        uint middle_i = (i2 + i1)/2;
        uint midle_j = (j2 + j1)/2;
        frechet_rec(matrix, i1, middle_i, j1, midle_j, p, q);
        frechet_rec(matrix, i1, middle_i, midle_j, j2, p, q);
        frechet_rec(matrix, middle_i, i2, j1, midle_j, p, q);
        frechet_rec(matrix, middle_i, i2, midle_j, j2, p, q);
    }
}

// Version optimisée de l'algorithme
// frechet_optim applique la relation de Bellman
void frechet_optim(int *matrix, uint i1, uint i2, uint j1, uint j2, Coordonates *p, Coordonates *q)
{
    for (uint i = i1; i < i2; i++) {
        for (uint j = j1; j <j2; j++) {
            if (i == 0 && j == 0)
                matrix[0] = distance(p[0], q[0]);
            else if (i == 0 && j > 0)
                matrix[j] = maximum(distance(p[0], q[j]), matrix[j-1], -1);
            else if (i > 0 && j == 0)
                matrix[i * lengthQ] = maximum(distance(p[i], q[0]), matrix[(i-1)*lengthQ], -1);
            else
                matrix[i * lengthQ + j] = maximum(distance(p[i], q[j]), minimum(matrix[i*lengthQ + j-1], matrix[(i-1)*lengthQ + j] , matrix[(i-1)*lengthQ + j-1], -1), -1);
        }
    }
}

//Calcul du parcours optimal
int parcours_optimal(int *matrix, int distanceFrechet, int i, int j, int *parcours, int k)
{
    parcours[k] = j;
    parcours[k-1] = i;
    
    if(i == 0 && j > 0)
    {
        k = parcours_optimal(matrix, distanceFrechet, i, j-1, parcours, k-2);
    }
    else if (i > 0 && j == 0)
    {
        k = parcours_optimal(matrix, distanceFrechet, i-1, j, parcours, k-2);
    }
    else if (i > 0 && j > 0)
    {
        if (matrix[(i-1)*lengthQ + j-1] <= matrix[i * lengthQ + j])
           k =  parcours_optimal(matrix, distanceFrechet, i-1, j-1, parcours, k-2);
        else if (matrix[i*lengthQ + j-1] <= matrix[i * lengthQ + j])
            k = parcours_optimal(matrix, distanceFrechet, i, j-1, parcours, k-2);
        else
            k = parcours_optimal(matrix, distanceFrechet, i-1, j, parcours, k-2);
    }
    return k;
}

// frechet est la fonction finale qui appelle l'une des version de l'agorithme
// Elle renvoie le résultat final sous forme d'un int
int frechet(char *filename)
{
    Coordonates **p1 = malloc(sizeof(Coordonates *));
    Coordonates **q1 = malloc(sizeof(Coordonates *));
    int *n = malloc(sizeof(int));
    int *m = malloc(sizeof(int));
    
    
    parse(filename, p1, q1, n, m);
    
    lengthP = *n;
    lengthQ = *m;
    
    int *distanceMatrix = (int *)malloc((*n) * (*m) * sizeof(int));
    
    int *parcours = malloc((*n + *m) * 2 * sizeof(int));
    int k = 0;
    for (int i = 0; i < *n + *m; i++) {
        parcours[i] = -1;
    }

//    frechetDistance(distanceMatrix, *p1, *q1);
    
    frechet_rec(distanceMatrix, 0, *n, 0, *m, *p1, *q1);
    
    free(p1);
    free(q1);
    
    int x = distanceMatrix[(*n-1)*(*m)+(*m-1)];
    
    printf("%d\n", x);
    
    int y = parcours_optimal(distanceMatrix, x, *n-1, *m-1, parcours, 2*(*n + *m) - 1) - 2;
    
    free(distanceMatrix);
    
    int lengthParcours = (2*(*n + *m) - 1 - y)/2;
    
    printf("%d\n", lengthParcours);
    while (k < 2*(*n + *m)) {
        if(parcours[k] >= 0)
        printf("%d %d ", parcours[k]+1, parcours[k+1]+1);
        k+=2;
    }
    printf("\n");
    
    free(n);
    free(m);
    
    return x;
    
//    return distanceMatrix[(*n-1)*(*m)+(*m-1)];
}

