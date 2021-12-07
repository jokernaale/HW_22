#include "Checker.h"
#include <ctype.h>
#include <string.h>

void doCheck(char* string)
{

    strcpy(string, trimWhiteSpace(string));
    checkString(string);
    capitalLater(string);

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
    while(*p!='\0')
    {
        if(*p==' ')
            p++;
        else if(*p!=' ')
        {
            *p2 = *p;
            p2++;
            p++;
            if(*p==' ')
            {
                *p2=*p;
                p2++;
                p++;
            }
        }
    }
    *(p2-1)='\0';
    return Str;
}

void capitalLater(char *string) {
    while (*string == ' ')
        string++;
    if (islower(*string)) {
        *string = toupper(*string);
    }
}

int countOfWords(char *string)
{
    char* delimit = "#";
    int numOfWords = 0;
    char* word;
    word = strtok(string, delimit);
    while (word)
    {
        numOfWords++;
        word = strtok(NULL, delimit);
    }

    return numOfWords;

}


