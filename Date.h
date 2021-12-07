

#ifndef HW_22_DATE_H
#define HW_22_DATE_H
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

#endif //HW_22_DATE_H
