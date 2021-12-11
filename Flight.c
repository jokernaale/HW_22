#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Flight.h"

#include "StringFunc.h"


void initFlight(Flight *flight, AirportManager *airportManager) {
    char departureName[SIZE];
    char arrivalName[SIZE];
    rewind(stdin);

    do
    {

        printf("Please enter departure name of Airport : \n");
        strcpy(departureName, getStringFromUser(departureName));
        if(findAirportByName(departureName, airportManager) == NULL) printf("No airport with this name - try again.\n");
    } while (findAirportByName(departureName, airportManager) == NULL);
    do
    {
        printf("Please enter arrival name of Airport : \n");
        strcpy(arrivalName, getStringFromUser(arrivalName));
        if(findAirportByName(arrivalName, airportManager) == NULL) printf("No airport with this name - try again.\n");
        else if(checkName(departureName, arrivalName) == 1 ) printf("Same departure and arrival airport.\n");
    } while (findAirportByName(arrivalName, airportManager) == NULL || checkName(departureName, arrivalName) == 1);
    flight->departureNameAirport = myStrdup(departureName);
    flight->arrivalNameAirport = myStrdup(arrivalName);
    initPlane(&flight->plane);
    initDate(&flight->date);


}

void printFlight(const Flight *flight) {
    printf("Departure Name Of Airport: %s\n", flight->departureNameAirport);
    printf("Arrival Of Airport: %s\n", flight->arrivalNameAirport);
    printPlane(&flight->plane);
    printDate(&flight->date);
}

int isFlightFromSourceName(const Flight *depflight, char *departureName) {
    if (checkName(depflight->departureNameAirport, departureName) == 1)
        return 1;
    return 0;
}

int isFlightFromDestName(const Flight *arrivalflight, char *arrivalName) {
    if (checkName(arrivalflight->arrivalNameAirport, arrivalName) == 1)
        return 1;
    return 0;

}

int isPlaneCodeInFlight(const Flight *flight, char *code) {
    if (checkName(flight->plane.code, code) == 1)
        return 1;
    return 0;
}

int isPlaneTypeInFlight(const Flight *flight, type typePlane) {
    if (typePlane == flight->plane.type)
        return 1;
    return 0;
}

int checkName(const char *flightName1, const char *flightName2) {
    if (strcmp(flightName1, flightName2) == 0)
        return 1;
    return 0;
}


void freeFlight(Flight *flight) {
    free(flight->departureNameAirport);
    free(flight->arrivalNameAirport);
    freePlane(&flight->plane);
}
