#include "Checker.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void doCheck(char *string, char *temp) {


    strcpy(string, trimWhiteSpace(string));
    checkString(string);
    formatString(string, temp, countWords(string));


}

void connectWords(char *country, char *city, char *street, char *number) {
    strcat(country, "@");
    strcat(country, city);
    strcat(country, "@");
    strcat(country, street);
    strcat(country, "@");
    strcat(country, number);
}

void checkString(char *string) {

    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            string[i] = '#';
        }
        i++;
    }


}

char *trimWhiteSpace(char *Str) {
    char *p = Str;
    char *p2 = Str;
    while (*p != '\0') {
        if (*p == ' ')
            p++;
        else if (*p != ' ') {
            *p2 = *p;
            p2++;
            p++;
            if (*p == ' ') {
                *p2 = *p;
                p2++;
                p++;
            }
        }
    }
    *(p2) = '\0';
    return Str;
}


void capitalLater(char *string) {
    while (*string == ' ')
        string++;
    if (islower(*string)) {
        *string = toupper(*string);
    }
}

//---------------------------------------------------------------------------------------------
void lowUp(char *string) {
    int i;
    for (i = 0; i < strlen(string) - 1; i += 2) {
        string[i] = toupper(string[i]);
        string[i + 1] = tolower(string[i + 1]);
    }
}

int checkEvenLetters(char *string) {
    if (strlen(string) % 2 == 0) {
        return 1;
    }
    return 0;
}

int countWords(char *string) {
    int count = 0;
    while (*string != '\0') {
        if (*string == '#')
            count++;
        string++;

    }
    count++;
    return count;
}


void formatString(char *string, char *temp, int count) {
    char *delimit = "#";
    char *word;
    if (count > 1) {
        word = strtok(string, delimit);
        if (checkEvenLetters(word) == 1) {
            lowUp(word);
        }
        temp = strcpy(temp, word);
        temp = strcat(temp, "#");


        while (word) {

            word = strtok(NULL, delimit);
            if (word != NULL) {
                if (checkEvenLetters(word) == 1) {
                    lowUp(word);
                }
                temp = strcat(temp, word);
                temp = strcat(temp, "#");


            }

        }

        temp[strlen(temp) - 1] = '\0';
        string = strcpy(string, temp);


    } else if (countWords(string) == 1) {
        capitalLater(string);
    }


}





