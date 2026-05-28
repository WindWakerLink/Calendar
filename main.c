#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "calendar.h"

/* Este va a ser el archivo principal en el qeu vamos a implementar toda la logica del resto de 
archivos y eso*/

int main(){

    time_t fecha_actual = time(NULL); //Primero obtenemos la fecha en bruto graicas a time(NULL);
    struct tm *t = localtime(&fecha_actual); /* Luego guardamos la fecha de forma más legible en un puntero a
    struct tm (porque localtime devuelve un puntero) */ 

    Date today = {
        t->tm_mday,
        t->tm_mon + 1,
        t->tm_year + 1900
    };

    /*Luego copiamos los datos correspondientes del dia mes y año obtenidos con el puntero *t al struct
    (Date) today para saber la fecha de ese día y poner el encabezado del mes y esas cosas*/

    int DIM = days_in_month(today.month, today.year); // DIM = Days In Month
    int weekday = get_weekday(today.day, today.month, today.year);
    print_header(today.month, today.year);
    print_weekdays();
    print_calendar(weekday, DIM);
    printf("\n");
    return 0;
}
