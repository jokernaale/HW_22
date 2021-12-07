#ifndef AIRPORT_MANAGER_H
#define AIROPRT_MANAGER_H

#include "Airport.h"

typedef struct {
    Airport *airportArr;
    int countOfAirport;
} AirportManager;

void initAirportManager(AirportManager *airportManager);

int addAirport(AirportManager *airportManager, Airport *airport);

Airport *findAirportByName(char *name, AirportManager *airportManager);

void printAirportManager(const AirportManager *airportManager);

void freeAirportManager(AirportManager* airportManager);


#endif

