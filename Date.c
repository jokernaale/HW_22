#include <stdio.h>
#include "Date.h"

void initDate(t_date *date1) {

    int status = 0;

    printf(" Enter date in format (day$$month$$year): \n");
    scanf("%d$$%d$$%d",&date1->day,&date1->month,&date1->year);

    status = isValidDate(date1);
    while(status !=1)
    {
        printf(" Please enter a valid date in format (day$$month$$year) !\n");
        scanf("%d$$%d$$%d",&date1->day,&date1->month,&date1->year);
        status = isValidDate(date1);
    }

        printf(" Date is valid!\n");

}

void printDate(const t_date *date1) {
    printf("%d/%d/%d \n", date1->day, date1->month, date1->year);
}

int isValidDate(t_date *validDate)
{

    if (validDate->year > MAX_YR ||
        validDate->year < MIN_YR)
        return 0;
    if (validDate->month < 1 || validDate->month > 12)
        return 0;
    if (validDate->day < 1 || validDate->day > 31)
        return 0;

    if (validDate->month == 2)
    {

        return (validDate->day <= 28);
    }

    if (validDate->month == 4 || validDate->month == 6 ||
        validDate->month == 9 || validDate->month == 11)
        return (validDate->day <= 30);
    return 1;
}