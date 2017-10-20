//
//  main.c
//  AOD
//
//  Created by Cyril Carlin on 19/10/2017.
//  Copyright © 2017 Cyril Carlin. All rights reserved.
//

#include <stdio.h>
#include "frechet.h"

int main(int argc, const char * argv[]) {
    Coordonates u1;
    u1.x = 1;
    u1.y = 2;
    
    Coordonates u2;
    u2.x = -3;
    u2.y = -1;
    Coordonates u3;
    u3.x = 5;
    u3.y = -3;
    Coordonates u4;
    u4.x = 2;
    u4.y = -1;
    Coordonates u5;
    u5.x = 4;
    u5.y = 1;
    Coordonates u6;
    u6.x = 1;
    u6.y = 4;
    Coordonates u7;
    u7.x = -2;
    u7.y = -3;
    
    Coordonates v1;
    v1.x = -2;
    v1.y = 3;
    Coordonates v2;
    v2.x = -2;
    v2.y = 1;
    Coordonates v3;
    v3.x = -1;
    v3.y = -1;
    Coordonates v4;
    v4.x = -1;
    v4.y = -3;
    Coordonates v5;
    v5.x = 4;
    v5.y = -2;
    Coordonates v6;
    v6.x = 3;
    v6.y = -1;
    Coordonates v7;
    v7.x = 3;
    v7.y = 1;
    Coordonates v8;
    v8.x = 0;
    v8.y = 0;
    
    Coordonates p[7] = {u1, u2, u3, u4, u5,u6, u7};
    Coordonates q[8] = {v1, v2, v3, v4, v5, v6, v7, v8};
    
    int x = frechetDistance(p, q, 7, 8);
    printf("Résultat : %d\n", x);
    return 0;
}
