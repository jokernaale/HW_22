#ifndef FLIGHT_H
#define FLIGHT_H

#include "Date.h"
#include "Plane.h"


#define SIZE 255
typedef struct {
    char *departureNameAirport;
    char *arrivalNameAirport;
    Plane plane;
    t_date date;

} Flight;

void initFlight(Flight *flight);

void printFlight(const Flight *flight);

int isFlightFromSourceName(const Flight *flight, char *departureName);

int isFlightFromDestName(const Flight *flight, char *arrivalName);

int isPlaneCodeInFlight(const Flight *flight, char *code);

int isPlaneTypeInFlight(const Flight *flight, type typePlane);

int checkName(const char *flightName1, const char *flightName2);

void freeFlight(Flight* flight);

#endif