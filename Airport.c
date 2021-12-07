#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Airport.h"

#include "Checker.h"


void initAirport(Airport *airport) {
    int i;
    char name[SIZEMAX];
    char country[SIZEMAX];
    char city[SIZEMAX];
    char street[SIZEMAX];
    char number[SIZEMAX];

    printf("Please enter a name for Airport\n");
    gets(name);
    airport->name = strdup(name);
    setAddress(country,city,street,number);
    airport->address = strdup(country);

}
void setAddress(char* country,char* city,char* street, char* number)
{

    printf("Please enter a country for Airport\n");
    gets(country);
    printf("Please enter a city for Airport\n");
    gets(city);
    printf("Please enter a street for Airport\n");
    gets(street);
    printf("Please enter a number of house for Airport\n");
    gets(number);
    doCheck(country);
    doCheck(city);
    doCheck(street);
    doCheck(number);
    connectWords(country, city, street, number);

}




int isSameAirport(const Airport *airport1, const Airport *airport2) {
    if (isAirportName(airport1->name, airport2) == 1)
        return 1;
    return 0;
}


int isAirportName(const char *name, const Airport *airport) {
    if (strcmp(name, airport->name) == 0)
        return 1;
    return 0;
}



void printAirport(const Airport *airport) {
    printf("Name of Airport : %s \n", airport->name);
    printf("Address of Airport : %s \n ", airport->address);
}

void freeAirport(Airport *airport) {
    free(airport->name);
    free(airport->address);
}
