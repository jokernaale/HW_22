

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"
#include "Airport.h"
#include "Airline.h"
#include "Date.h"


int main() {


    int choose ;
    AirportManager airportManager;
    Airport airport;
    Airline airline;
//    initAirportManager(&airportManager);
//
//    printf("Do you want to add an airport?\n");
//    choose = checkValidityAnswer1or2(&choose);
//    //scanf("%d", &choose);
//    //getchar();
//    while (choose == 1) {
//        initAirport(&airport);
//        addAirport(&airportManager, &airport);
//        printf("If you want add Airport press 1\n");
//        scanf("%d", &choose);
//        getchar();
//    }

    firstInitAirportManager(&airportManager, &airport);


    initAirline(&airline);


    int chooser = 0;
    while (chooser != 8) {


        printf("Please choose one of the following option\n"
               "1. Add Flight to Airline\n"
               "2.Add Airport to AirportManager\n"
               "3.Print Info Of Airline\n"
               "4.Print Info of AirportManager\n"
               "5.Print count of Flights that departs from Airport\n"
               "6.Print all Flights that equals to code that you choose\n"
               "7.Print all Flights that equals to type that you choose\n"
               "8. - Quit\n");


        scanf("%d", &chooser);



        switch (chooser) {
            case 1:
                Flight flight;
                initFlight(&flight);
                addFlight(&flight, &airline);
                break;

            case 2:
                initAirport(&airport);
                addAirport(&airportManager, &airport);

                break;

            case 3:
                printAirline(&airline);
                break;

            case 4:
                printAirportManager(&airportManager);


                break;

            case 5:
                doCountFlightsFromName(&airline);

                break;

            case 6:
                doPrintFlightsWithPlaneCode(&airline);

                break;

            case 7:
                doPrintFlightsWithPlaneType(&airline);

                break;

            case 8:
                printf("Bye bye");
                freeAirportManager(&airportManager);
                freeAirline(&airline);
                break;


            default:
                printf("Error! your choose  is not correct\n");
        }


    }

    return 0;
}
