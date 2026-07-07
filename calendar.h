#ifndef CALENDAR_H
#define CALENDAR_H

/*En este header vamos a declarar los struct, funiones y constantes que va a usar calendar.c*/

typedef struct{
    int day;
    int month;
    int year;
} Date; /*Aqui tenemos un struct que hace alusión a una fecha cualquiera*/

void print_calendar(int day, int month_days, int current_day);
void print_weekdays();
void print_header(int month, int year);
int is_leap(int year);
int days_in_month(int month, int year);
int get_weekday(int day, int month, int year);

/*Y aqui tenemos funciones que va a usar calendar.c para saber si un año en bisiesto o calcular los dias
que hay en el mes actual y mas*/

#endif
