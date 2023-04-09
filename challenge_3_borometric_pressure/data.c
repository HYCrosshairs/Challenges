#include <stdlib.h>
#include <stdio.h>

#include "data.h"

bool_t checkYear(uint16_t year)
{
    return (year_min <= year && year_max >= year) ? true : false;
}

char* SET_Date(date_t date)
{
    char* str = malloc(DATE_FORMAT_LENGHT * sizeof(char));
    sprintf(str, "%02d_%02d_%02d", date.year, date.month, date.day);
    return str;
}