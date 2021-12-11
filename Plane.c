#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Plane.h"
#include "StringFunc.h"


const char *typeTitle[eNofTypes] = {"PASSENGER", "FREIGHT", "ARMY"};

void initPlane(Plane *plane) {
    char code[255];
    do {
        printf("Please enter a code for plane : ");
        strcpy(code, getStringFromUser(code));
    } while (strlen(code) != 4 || checkerCode(code) == 0);
    plane->code = myStrdup(code);
    plane->type = getType();
}

type getType() {
    int t;
    int i;
    printf("Enter person type\n");
    do {
        for (i = 0; i < eNofTypes; i++)
            printf("Enter %d for %s\n", i, typeTitle[i]);
        scanf("%d", &t);

    } while (t < 0 || t >= eNofTypes);
    return (type) t;
}

void printPlane(const Plane *plane) {
    printf("Plane code is: %s\n", plane->code);
    printf("Plane type is: %s\n", typeTitle[plane->type]);
}

void freePlane(Plane *plane) {
    free(plane->code);
}

int checkerCode(const char *codes) {
    int i;
    for (i = 0; i < strlen(codes); i++) {
        if (codes[i] < 'A' || codes[i] > 'Z')
            return 0;
    }
    return 1;
}


