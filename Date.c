#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"
#include "StringFunc.h"

void initDate(t_date *date1) {
    char date[MAXLENGHT];
    char year[MAXLENGHT];
    char day[MAXLENGHT];
    char month[MAXLENGHT];
    int status = 1;


    do {
        rewind(stdin);
        printf(" Please enter a valid date in format (dd$$mm$$yyyy) !\n");
        strcpy(date, getStringFromUser(date));
        if (checkLength(date) != 1) status = 0;
        if (checkIndexDollar(date) != 1)status = 0;
        separateToInteger(date, day, month, year, date1);
        status = isValidDate(date1);
    } while (status != 1);


    printf(" Date is valid!\n");

}

void separateToInteger(char *date, char *day, char *month, char *year, t_date *date1) {
    memcpy(day, date, 2);
    date1->day = atoi(day);
    memcpy(month, date + 4, 2);
    date1->month = atoi(month);
    memcpy(year, date + 8, 4);
    date1->year = atoi(year);
}

void printDate(const t_date *date1) {
    printf("%d/%d/%d \n", date1->day, date1->month, date1->year);
}

int checkLength(char *date) {
    if (strlen(date) == 12)
        return 1;
    return 0;
}

int checkIndexDollar(char *date) {
    if (date[2] == '$' && date[3] == '$' && date[6] == '$' && date[7] == '$')
        return 1;
    return 0;
}


int isValidDate(t_date *validDate) {

    if (validDate->year > MAX_YR ||
        validDate->year < MIN_YR)
        return 0;
    if (validDate->month < 1 || validDate->month > 12)
        return 0;
    if (validDate->day < 1 || validDate->day > 31)
        return 0;

    if (validDate->month == 2) {

        return (validDate->day <= 28);
    }

    if (validDate->month == 4 || validDate->month == 6 ||
        validDate->month == 9 || validDate->month == 11)
        return (validDate->day <= 30);
    return 1;
}

