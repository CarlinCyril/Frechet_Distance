//
//  parse.c
//  AOD
//
//  Created by Cyril Carlin on 20/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#include "parse.h"
#include <stdio.h>
#include<stdlib.h>

 void parse(char *filename, Coordonates *P, Coordonates *Q, int *n, int *m){
  FILE* fichier = NULL;


  fichier = fopen(filename, "r");
  if (fichier == NULL) {
    perror("Error in opening file");
  }

  int i = 0;

  int j = 0;

  int i1 = 0;

  int x1 = 0;

  char caractereActuel = fgetc(fichier);

  int chiffre = 0;

  int nombre = 0;

  int indicateur = 0;

  //On calcule la valeur de n

  while (caractereActuel != ' '){

    chiffre = atoi(&caractereActuel);
    *n = (*n)*10 + chiffre;
    caractereActuel = fgetc(fichier);

  }

  //On calcule la valeur de m

  while (caractereActuel != '\n') {
    chiffre = atoi(&caractereActuel);
    *m = (*m)*10 + chiffre;
    caractereActuel = fgetc(fichier);

  }

  caractereActuel = fgetc(fichier);

  Coordonates* parcoursP = malloc(sizeof(Coordonates)*(*n));

  Coordonates* parcoursQ = malloc(sizeof(Coordonates)*(*m));

  //On stocke dans un tableau parcoursP l'ensemble des points de P

  while (i < 2*(*n) + 1) {
    if (caractereActuel == ' ' || caractereActuel == '\n') {

      caractereActuel = fgetc(fichier);


      if (i % 2  == 1) {

        if (indicateur == 1){
          x1 = (-1)*nombre;
        } else {
          x1 = nombre;
        }
        indicateur = 0;
      } else {

        if (indicateur == 1) {
          nombre = (-1)*nombre;
          indicateur = 0;
        }
        j = i / 2;
        P->x = x1;
        P->y = nombre;
        parcoursP[j - 1] = *P;

      }


      nombre = 0;

    }

    while (caractereActuel != ' ' && caractereActuel != '\n') {
      if (caractereActuel == '-'){
        caractereActuel = fgetc(fichier);
        indicateur = 1;


      } else {

        chiffre = atoi(&caractereActuel);
        nombre = nombre*10 + chiffre;
        caractereActuel = fgetc(fichier);

      }

    }


    i += 1;

  }
  caractereActuel = fgetc(fichier);
  caractereActuel = fseek(fichier, -4, SEEK_CUR);

  x1 = 0;
  nombre = 0;

  //On stocke dans un tableau parcoursQ l'ensemble des points de Q


  while (i1 < 2*(*m) + 1) {
    if (caractereActuel == ' ' || caractereActuel == '\n') {

      caractereActuel = fgetc(fichier);


      if (i1 % 2  == 1) {
        if (indicateur == 1){
          x1 = (-1)*nombre;
        } else {
          x1 = nombre;
        }
        indicateur = 0;
      } else {
        if (indicateur == 1) {
          nombre = (-1)*nombre;
          indicateur = 0;
        }
        j = i1 / 2;
        Q->x = x1;
        Q->y = nombre;
        parcoursQ[j - 1] = *Q;

      }
    }

    if (caractereActuel == EOF) {
      break;
    }

      nombre = 0;

    while (caractereActuel != ' ' && caractereActuel != '\n') {

      if (caractereActuel == '-'){
        caractereActuel = fgetc(fichier);

        indicateur = 1;

      } else {

        chiffre = atoi(&caractereActuel);
        nombre = nombre*10 + chiffre;
        caractereActuel = fgetc(fichier);

      }

    }
    i1 += 1;
  }
  //printf("%i", i1);


printf("%i, %i", parcoursP[0].x, parcoursP[0].y);
printf("\n");
printf("%i, %i", parcoursP[1].x, parcoursP[1].y);
printf("\n");
printf("%i, %i", parcoursP[2].x, parcoursP[2].y);
printf("\n");
printf("%i, %i", parcoursP[10].x, parcoursP[10].y);
printf("\n");
printf("%i, %i", parcoursP[254].x, parcoursP[254].y);
printf("\n");
printf("%i, %i", parcoursQ[0].x, parcoursQ[0].y);
printf("\n");
printf("%i, %i", parcoursQ[1].x, parcoursQ[1].y);
printf("\n");
printf("%i, %i", parcoursQ[2].x, parcoursQ[2].y);
printf("\n");
printf("%i, %i", parcoursQ[311].x, parcoursQ[311].y);
printf("\n");


fclose(fichier);
}

int main(int argc, const char * argv[]) {
  int n = 0;
  int m = 0;
  Coordonates P;
  P.x = 0;
  P.y = 0;
  Coordonates Q;
  Q.x = 0;
  Q.y = 0;
  parse("/home/mehdi/Téléchargements/Frechet_Distance-master/Benchmark/benchmark2", &P, &Q, &n, &m);
    return 0;
}
