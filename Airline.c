#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airline.h"
#include "Plane.h"
#include "StringFunc.h"


int initAirline(Airline *airline) {
    char name[MAXSIZE];
    printf("Please enter the name of airline: \n");

    airline->name = myStrdup(getStringFromUser(name));

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

int addFlight(Flight *flight, Airline *airline, AirportManager *airportManager) {
    if (checkCountOfAirports(airportManager) == 0) {
        printf("There are not enough airport to set a flight\n"
               "Error adding flight");
        return 0;
    }

    airline->flightArr = (Flight **) realloc(airline->flightArr,
                                             sizeof(Flight *) * (airline->countOfFlights + 1));
    if (checkMemory(airline->flightArr) == -1)return -1;
    airline->flightArr[airline->countOfFlights] = (Flight *) malloc(sizeof(Flight) * 1);
    if (checkMemoryforArrFlight(airline->flightArr[airline->countOfFlights]) == -1)return -1;
    airline->flightArr[airline->countOfFlights] = flight;
    airline->countOfFlights++;
    return 1;

}

void doPrintFlightsWithPlaneCode(const Airline *airline) {
    int counter = 0;
    char code[MAXLENGHT];
    if (airline->countOfFlights == 0) {
        printf("We dont have flights in our airline \n ");
    } else {
        int i;

        printf("Please enter a code of plane:\n");
        rewind(stdin);
        strcpy(code, getStringFromUser(code));
        printf("The flights with code %s\n", code);
        for (i = 0; i < airline->countOfFlights; i++) {
            if (isPlaneCodeInFlight(airline->flightArr[i], code) ==
                1) {
                printFlight(airline->flightArr[i]);
                counter++;
            }
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
            if (isPlaneTypeInFlight(airline->flightArr[i], typePlane)== 1) {
                printFlight(airline->flightArr[i]);
                counter++;
            }

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
        rewind(stdin);
        strcpy(name, getStringFromUser(name));
        for (i = 0; i < airline->countOfFlights; i++) {
            if (isFlightFromDestName(airline->flightArr[i], name) == 1)
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

int checkCountOfAirports(AirportManager *airportManager) {
    if (airportManager->countOfAirport > 1)
        return 1;
    return 0;
}



