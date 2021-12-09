#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AirportManager.h"

int checkValidityAnswer1or2(int *answer) //TODO:07-12-2021
{
    do
    {
        printf("Enter one of two choices.\n1-yes 2-no\n");
        scanf("%d", answer);
        if (*answer == 1 || *answer == 2)
        {
            rewind(stdin); //TODO: проверить или тут надо чистить буффер?
            return *answer;
        }
    } while (*answer != 1 || *answer != 2);
    rewind(stdin); //TODO: проверить или тут надо чистить буффер?
    return *answer;
}

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

void firstInitAirportManager(AirportManager* airportManager, Airport* airport) //TODO:07-12-2021
{
    airportManager->airportArr=NULL;
    airportManager->countOfAirport = 0;
    int choose;

    printf("Do you want to add an airport?\n");
    choose = checkValidityAnswer1or2(&choose);
    if(choose == 1)
    {
        initAirport(airport);
        addAirport(airportManager, airport);
    }
    else
    {
        printf("You choose not to add an airport.\n");
    }
}


void freeAirportManager(AirportManager *airportManager) {
    int i;
    for (i = 0; i < airportManager->countOfAirport; i++) {
        freeAirport(&airportManager->airportArr[i]);
        free(&airportManager->airportArr[i]);
    }


}



