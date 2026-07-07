#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "calendar.h"

int main(int argc, char **argv){
    
    time_t current_date = time(NULL); //Primero obtenemos la fecha en segundos del Epoch time gracias a time(NULL);

    //El Epoch time es el tiempo que ha pasado desde el 1 de enero de 1970 

    struct tm *t = localtime(&current_date); /* Luego guardamos la fecha de forma más legible en un puntero a
    struct tm (porque localtime devuelve un puntero) */ 

    Date today = {
        t->tm_mday,
        t->tm_mon + 1,
        t->tm_year + 1900
    };

    /*Después copiamos los datos correspondientes del dia mes y año obtenidos con el puntero *t al struct
    (Date) today para saber la fecha de ese día y poner el encabezado del mes y esas cosas*/

    static const char *mn[12] = {"january", "february", "march", "april", "may", "june", "july", // mn -> months name
                        "august", "september", "october", "november", "december"}; 

  
    for (int i = 0; mn[i] != NULL && argc >= 2; i++) if (strcmp(argv[1], mn[i]) == 0) today.month = i + 1;

    if (argc >= 3 && argv[2] != NULL){
        int i = atoi(argv[2]);
        if (i != 0 && i >= 1000  && i <= 9999) today.year = i; 
    }


    int DIM = days_in_month(today.month, today.year); // DIM -> Days In Month
    int weekday = get_weekday(1, today.month, today.year);
    
    print_header(today.month, today.year); 
    print_weekdays();
    print_calendar(weekday, DIM, today.day);
    puts(""); 
}
