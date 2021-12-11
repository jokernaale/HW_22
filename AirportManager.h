#ifndef AIRPORT_MANAGER_H
#define AIRPORT_MANAGER_H

#include "Airport.h"

typedef struct {
    Airport *airportArr;
    int countOfAirport;
} AirportManager;


int addAirport(AirportManager *airportManager, Airport *airport);

Airport *findAirportByName(char *name, AirportManager *airportManager);

void printAirportManager(const AirportManager *airportManager);

void freeAirportManager(AirportManager *airportManager);

int checkValidityAnswer1or2(int *answer);

void firstInitAirportManager(AirportManager *airportManager, Airport *airport);


#endif

