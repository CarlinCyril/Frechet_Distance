//
//  parse.c
//  AOD
//
//  Created by Cyril Carlin on 23/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

void parse(char *filename, Coordonates **P, Coordonates **Q, int *n, int *m)
{
    FILE *fichier = NULL;
    int check = 0;
    
    fichier = fopen(filename, "r");
    if (fichier == NULL) {
        perror("Error opening file");
    }
    
    fscanf(fichier, "%d %d\n", n, m);
    if (n == NULL || m == NULL) {
        perror("Format not recognized");
    }
    
    *P = malloc(*n * sizeof(Coordonates));
    *Q = malloc(*m * sizeof(Coordonates));
    P = &(*P);
    Q = &(*Q);
     
    for (int i = 0; i < *n-1; i++) {
        //P[i] = malloc(sizeof(Coordonates));
        check = fscanf(fichier, "%d %d ", &((*P)[i].x), &((*P)[i]).y);
        if (check < 2) {
            perror("Format not recognized");
        }
    }
    //P[*n-1] = malloc(sizeof(Coordonates));
    check = fscanf(fichier, "%d %d\n", &((*P)[*n-1].x), &((*P)[*n-1].y));
    if (check < 2) {
        perror("Format not recognized");
    }
    
    for (int j = 0; j < *m-1; j++) {
        //Q[j] = malloc(sizeof(Coordonates));
        check = fscanf(fichier, "%d %d ", &((*Q)[j].x), &((*Q)[j].y));
        if (check < 2) {
            printf("j : %d", j);
            perror("Format not recognized");
        }
    }
    //Q[*m-1] = malloc(sizeof(Coordonates));
    check = fscanf(fichier, "%d %d\n", &((*Q)[*m-1].x), &((*Q)[*m-1].y));
    if (check < 2) {
        perror("Format not recognized");
    }
    
//    *P = P_res;
//    *Q = Q_res;
}
