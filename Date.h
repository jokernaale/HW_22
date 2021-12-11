

#ifndef HW_22_DATE_H
#define HW_22_DATE_H
#define MAXLENGHT 255
#define MAX_YR  9999
#define MIN_YR  2022
typedef struct {

    int day;
    int month;
    int year;

} t_date;

void initDate(t_date *date1);

void printDate(const t_date *date1);

int isValidDate(t_date *validDate);

int checkLength(char *date);

int checkIndexDollar(char *date);

void separateToInteger(char *date, char *day, char *month, char *year, t_date *date1);


#endif //HW_22_DATE_H
