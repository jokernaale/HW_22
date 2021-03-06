#ifndef AIRLINE_H
#define AIRLINE_H

#include "Flight.h"
#include "AirportManager.h"


typedef struct {
    char *name;
    int countOfFlights;
    Flight **flightArr;


} Airline;

int initAirline(Airline *airline);

void printAirline(const Airline *airline);

int addFlight(Flight *flight, Airline *airline, AirportManager *airportManager);

void doPrintFlightsWithPlaneCode(const Airline *airline);

void doPrintFlightsWithPlaneType(const Airline *airline);

void doCountFlightsFromName(const Airline *airline);

void freeAirline(Airline *airline);

int checkMemory(Flight **pFlight);

int checkMemoryforArrFlight(Flight *flight);

int checkCountOfAirports(AirportManager *airportManager);


#endif
