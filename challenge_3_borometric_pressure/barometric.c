#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "barometric.h"
#include "data.h"

float* GET_Barometric_Pressure(date_t begin, date_t end)
{
    char* start_date = SET_Date(begin);
    char* end_date = SET_Date(end);
    char line[MAX_LINE_LENGHT];
    char date[DATE_FORMAT_LENGHT];

    fprintf(stdout, "%s\n", start_date);

    FILE* fp = fopen("data.txt", "r"); // read only

    while (fgets(line, MAX_LINE_LENGHT, fp) != NULL)
    {
        sscanf(line, "%10s", date);

        if (strcmp(start_date, date) == 0)
        {
            fprintf(stdout, "%s\n", line);
        }
        
        break;
    }
    

    float* baromertric_press = NULL;

    free(start_date);
    free(end_date);
    return baromertric_press;
}