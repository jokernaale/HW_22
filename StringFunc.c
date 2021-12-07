#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "stringFunc.h"

char* myGets(char* buf, size_t size)
{
    int c;
    if(buf != NULL && size > 0)
    {
        if(fgets(buf,size,stdin))
        {
            buf[strcspn(buf,"\n")] = '\0';
            rewind(stdin); //TODO: проверить или тут надо чистить буффер?
            return buf;
        }
        *buf = '\0';
    }
    return NULL;
}