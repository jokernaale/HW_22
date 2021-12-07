#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AirportManager.h"

void initAirportManager(AirportManager *airportManager) {
    airportManager->airportArr=NULL;
    airportManager->countOfAirport = 0;
}

void printAirportManager(const AirportManager *airportManager) {

    int i;
    printf("AirportManager:\n");
    for (i = 0; i < airportManager->countOfAirport; i++) {
        printf("Airport number %d: \n", i);
        printAirport(&airportManager->airportArr[i]);
    }
    printf("Count of Airports: %d\n", airportManager->countOfAirport);

}

int addAirport(AirportManager *airportManager, Airport *airport) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; ++i) {
        if (isSameAirport(airport, &airportManager->airportArr[i]) == 1) {
            printf("We have already the same Airport in our system\n");
            return 1;
        }
    }
    airportManager->airportArr = (Airport *) realloc(airportManager->airportArr,
                                                     (airportManager->countOfAirport + 1) * sizeof(Airport));
    if (!airportManager->airportArr) {
        printf("ERROR! Out of memory!\n");
        return -1;
    }
    airportManager->airportArr[airportManager->countOfAirport] = *airport;
    airportManager->countOfAirport++;
    return 0;
}

Airport *findAirportByName(char *name, AirportManager *airportManager) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; i++) {
        if (isAirportName(name, &airportManager->airportArr[i]) == 0) {
            return &airportManager->airportArr[i];
        }


    }
    return NULL;
}

void freeAirportManager(AirportManager *airportManager) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; i++) {
        freeAirport(&airportManager->airportArr[i]);
        free(&airportManager->airportArr[i]);
    }


}



