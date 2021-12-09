#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airline.h"
#include "Plane.h"
#include "StringFunc.h" //TODO: 07/12/2021


int initAirline(Airline *airline) {
    char name[MAXSIZE];
    printf("Please enter the name of airline: \n");
//    //gets(name);
////    myGets(name,MAXSIZE);
//    do {
//        if ((*name) == '\0') printf("You have entered an empty name. Please reenter the name.\n");
//        myGets(name,MAXSIZE);
//    } while ( (*name) == '\0'); //TODO: while our string will not an emptyStrung
    airline->name = strdup(getStringFromUser(name));
//    if (! (airline->name))
//    {
//        printf("\nERROR! Out of memory! Did NOT succeed put name to the airline\n");
//        return -1;
//    }
//    printf("\nSUCCESS - the name of airline - | %s |  was put successfully\n", airline->name);
    checkIfSpaceGiven(airline->name);
    airline->flightArr = NULL;
    airline->countOfFlights = 0;
    return 0;
}

void printAirline(const Airline *airline) {
    int i;
    printf("Name of Airline: %s\n", airline->name);
    printf("The count of Flights: %d\n", airline->countOfFlights);
    printf("List of all Flight:\n");
    for (i = 0; i < airline->countOfFlights; i++) {
        printf("Flight number %d:\n ", i);
        printFlight(airline->flightArr[i]);
    }
}

int addFlight(Flight *flight, Airline *airline) {



    airline->flightArr = (Flight **) realloc(airline->flightArr,
                                                 sizeof(Flight *) * (airline->countOfFlights + 1));
        if(checkMemory(airline->flightArr) == -1)return -1;
        airline->flightArr[airline->countOfFlights] = (Flight *) malloc(sizeof(Flight) * 1);
        if (checkMemoryforArrFlight(airline->flightArr[airline->countOfFlights]) == -1)return -1;
        airline->flightArr[airline->countOfFlights] = flight;

        airline->countOfFlights++;
        return 1;

}

void doPrintFlightsWithPlaneCode(const Airline *airline) {
    int counter = 0;
    if (airline->countOfFlights == 0) {
        printf("We dont have flights in our airline \n ");
    } else {
        int i;
        char code[5];
        printf("Please enter a code of plane:\n");
        gets(code);
        printf("The flights with code %s\n", code);
        for (i = 0; i < airline->countOfFlights; i++) {
            if (isPlaneCodeInFlight(airline->flightArr[i], code) ==
                1)
                printFlight(airline->flightArr[i]);
            counter++;
        }
        if (counter == 0) {
            printf("We dont have flight with code %s: \n", code);
        }
    }
}

void doPrintFlightsWithPlaneType(const Airline *airline) {
    int counter = 0;
    if (airline->countOfFlights == 0) {
        printf("We dont have flights in our airline \n ");
    } else {
        int i;
        type typePlane = getType();
        printf("The flights with type %s\n", typeTitle[typePlane]);
        for (i = 0; i < airline->countOfFlights; i++) {
            if (isPlaneTypeInFlight(airline->flightArr[i], typePlane))
                printFlight(airline->flightArr[i]);
            counter++;
        }
        if (counter == 0) {
            printf("We dont have flight with type %s: \n", typeTitle[typePlane]);
        }
    }

}

void doCountFlightsFromName(const Airline *airline) {
    if (airline->countOfFlights == 0) {
        printf("We dont have flights in our airline \n ");
    } else {
        int i;
        int counter = 0;
        char name[MAXSIZE];
        printf("Please enter a name of Airport");
        gets(name);
        for (i = 0; i < airline->countOfFlights; i++) {
            if (strcmp(name, airline->flightArr[i]->departureNameAirport) == 0)
                counter++;
        }

        printf("The count of Flights from Airport: %d\n", counter);
    }
}

void freeAirline(Airline *airline) {
    int i;
    free(airline->name);
    for (i = 0; i < airline->countOfFlights; i++) {
        freeFlight(airline->flightArr[i]);
        free(airline->flightArr[i]);
    }
    free(airline->flightArr);
}


int checkMemory(Flight **pFlight) {
    if (!pFlight) {
        printf("ERROR! Out of memory!\n");
        return -1;
    }
    return 1;
}

int checkMemoryforArrFlight(Flight *flight) {
    if (!flight) {
        printf("ERROR! Out of memory!\n");
        return -1;
    }
    return 1;
}

