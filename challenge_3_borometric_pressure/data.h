#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define DATE_FORMAT_LENGHT 9
#define MAX_LINE_LENGHT 100

typedef enum {
    false = 0,
    true = 1
} bool_t;

typedef enum Year
{
    year_min = 1970,
    year_max = 2999
} year_t;

typedef struct date
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

typedef struct xtime
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} xtime_t;

typedef struct timestamp
{
    date_t date;
    xtime_t time;
} timestamp_t;

typedef struct wind
{
    float direction;
    float gust;
    float speed;
} wind_t;

typedef struct data
{
    timestamp_t timestamp_t;
    float air_temp;
    float barometric_press;
    float dew_point;
    float relative_hum;
    wind_t wind;
} data_t;

bool_t checkYear(uint16_t year);

char* SET_Date(date_t date);

#endif // DATA_H