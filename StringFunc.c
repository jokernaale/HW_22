#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "StringFunc.h"

int checkIfSpaceGiven(char *workPointer) {
    if (!(workPointer)) {
        printf("\nERROR! Out of memory!\n");
        return -1;
    }
    printf("\nSUCCESS - memory was given\n");
    return 0;
}

char *myGets(char *buf, size_t size) {

    if (buf != NULL && size > 0) {
        if (fgets(buf, size, stdin)) {
            buf[strcspn(buf, "\n")] = '\0';
            rewind(stdin);
            return buf;
        }
        *buf = '\0';
    }
    return NULL;
}

char *getStringFromUser(char *workArray) {
    do {
        if ((*workArray) == '\0') printf("You have entered an empty data. Please reenter the data.\n");
        myGets(workArray, MAXSIZE);
    } while ((*workArray) == '\0');
    return workArray;
}
