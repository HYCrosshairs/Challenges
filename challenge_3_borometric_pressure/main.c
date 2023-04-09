#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "barometric.h"
#include "data.h"


int main(int argc, char const *argv[])
{
    date_t date_start = {.year = 2012, .month = 1, .day = 1};
    date_t date_end = {.year = 2023, .month = 4, .day = 9};

    GET_Barometric_Pressure(date_start, date_end);

    fprintf(stdout, "%d\n", checkYear(2023));
    fprintf(stdout, "%d\n", checkYear(3023));
    return 0;
}
