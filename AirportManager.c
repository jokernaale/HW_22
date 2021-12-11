#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AirportManager.h"

int checkValidityAnswer1or2(int *answer) {
    do {
        printf("Enter one of two choices.\n1-yes 2-no\n");
        scanf("%d", answer);
        if (*answer == 1 || *answer == 2) {
            rewind(stdin);
            return *answer;
        }
    } while (*answer != 1 || *answer != 2);
    rewind(stdin);
    return *answer;
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

    if (findAirportByName(airport->name, airportManager) != NULL)
        printf("We already have this airport in our system\n");
    airportManager->airportArr = (Airport *) realloc(airportManager->airportArr,
                                                     (airportManager->countOfAirport + 1) * sizeof(Airport));
    if (!airportManager->airportArr) {
        printf("ERROR! Out of memory!\n");
        return -1;
    }   //TODO: Вывести в метод если будет время
    airportManager->airportArr[airportManager->countOfAirport] = *airport;
    airportManager->countOfAirport++;
    return 0;
}

Airport *findAirportByName(char *name, AirportManager *airportManager) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; i++) {
        if (isAirportName(name, &airportManager->airportArr[i]) == 1) {
            return &airportManager->airportArr[i];
        }


    }
    return NULL;
}

void firstInitAirportManager(AirportManager *airportManager, Airport *airport) {
    airportManager->airportArr = NULL;
    airportManager->countOfAirport = 0;
    int choose;

    do {
        printf("Do you want to add an airport?\n");
        choose = checkValidityAnswer1or2(&choose);
        if (choose == 1) {
            initAirport(airport);
            addAirport(airportManager, airport);
        } else {
            printf("You choose not to add an airport.\n");
        }
    } while (choose == 1);

}


void freeAirportManager(AirportManager *airportManager) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; i++) {
        freeAirport(&airportManager->airportArr[i]);
        free(&airportManager->airportArr[i]);
    }


}



