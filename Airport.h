#ifndef AIRPORT_H
#define AIRPORT_H


#define _CRT_SECURE_NO_WARNINGS
#define SIZEMAX 255

typedef struct {
    char *name;
    char *address;
} Airport;

void initAirport(Airport *airport);

void printAirport(const Airport *airport);

int isSameAirport(const Airport *airport1, const Airport *airport2);

int isAirportName(const char *name, const Airport *airport);

void setAddress(char* country,char* city,char* street, char* number);


void freeAirport(Airport* airport);




#endif