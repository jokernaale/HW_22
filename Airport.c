#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Airport.h"

#include "Checker.h"

#include "StringFunc.h" //TODO: 09-12-2021


void initAirport(Airport *airport) {
//    int i;
    char name[SIZEMAX];
    char country[SIZEMAX];
    char city[SIZEMAX];
    char street[SIZEMAX];
    char number[SIZEMAX];
    char temp[SIZEMAX];

    printf("Please enter a name for Airport\n");
//    gets(name);
    airport->name = strdup(getStringFromUser(name)); //TODO: 09-12-2021
    printf("The airport name is - | %s |\n",airport->name);
    setAddress(country,city,street,number);



    doCheck(country,temp);
    doCheck(city,temp);
    doCheck(street,temp);
    doCheck(number,temp);

    connectWords(country, city, street, number);
    airport->address = strdup(country);

}
void setAddress(char* country,char* city,char* street, char* number)
{

    printf("\nPlease enter a country for Airport\n");
  //  gets(country);
    country = strdup(getStringFromUser(country)); //TODO: 09-12-2021
//    checkIfSpaceGiven(country); //TODO: 09-12-2021 do not forget to do free
    printf("The country is - |%s|\n",country);

    printf("\nPlease enter a city for Airport\n");
//    gets(city);
    city = strdup(getStringFromUser(city)); //TODO: 09-12-2021
//    checkIfSpaceGiven(city); //TODO: 09-12-2021 do not forget to do free
    printf("The city is - |%s|\n",city);

    printf("\nPlease enter a street for Airport\n");
//    gets(street);
    street = strdup(getStringFromUser(street)); //TODO: 09-12-2021
//    checkIfSpaceGiven(street); //TODO: 09-12-2021 do not forget to do free
    printf("The street is - |%s|\n",street);

    printf("\nPlease enter a number of house for Airport\n");
//    gets(number);
    number = strdup(getStringFromUser(number)); //TODO: 09-12-2021
//    checkIfSpaceGiven(number); //TODO: 09-12-2021 do not forget to do free
    printf("The number is - |%s|\n",number);



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
