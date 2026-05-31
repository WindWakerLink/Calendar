#include <stdio.h>
#include <time.h>
#include "calendar.h"


 int is_leap(int year){  //Aqui comprobamos si el año actual es o no bisiesto
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static const char *months_name[12] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};

static const char *wdays[7] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};

/*Los dos arrays de abajo no tiene perdida porque son los meses y los
acronimos de los días de la semana*/

int days_in_month(int month, int year){ //Aqui calculamos los dias que tiene el mes
    if (month == 2){
        return is_leap(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    return 31;
}

/* h = (q + ⌊(13(m+1))/5] + K + ⌊K/4⌋ + ⌊J/4⌋ + 5J) % 7
FORMULA DE ZELLER PARA SACAR EL DÍA DE LA SEMANA CORRESPONDIENTE*/

int get_weekday(int day, int month, int year) { //Aqui obtenemos el primer dia de la primera semana del mes

    if (month < 3){ // Esta comparativa se hace porque al usar el Epoch time
        month += 12;
        year -= 1;
    }

    int q = day, m = month, K = year % 100, J = year / 100;
    int h = (q + ((13*(m+1))/5) + K + (K/4) + (J/4) + 5*J ) % 7;
    return (h + 7) % 7;
}

void print_header(int month, int year){ //aqui imprimimos algo como "December 2067" y eso y lo centramos
                                        //con espacios
    printf("   ");
    printf("   ");
    printf("%s %d\n", months_name[month - 1], year);
}

void print_weekdays(){ //Y aquí lo mismo de antes pero con los acronimos de los días de la semana
    int i;
    for (i = 0; wdays[i] != NULL; i++){
        printf("%s ", wdays[i]);
    }
}

void print_calendar(int day, int month_days){ //En esta funcion imprimimos los numeros del calendario
    printf("\n");
    int i, k = 0; 

    for (int j = 1; j < day; j++){ //En este bucle se imprimen los espacios antes de que inicie el día 1
        printf("   ");
        k++;
    }
    
    for (i = 1; i <= month_days; i++){ //Y en este bucle se imprime día por día
        k++;
        k == 1 || k == 7 ? printf("\033[31m%2d \033[0m", i) : printf("%2d ",i);
        if (k == 7){
            printf("\n");
            k = 0;
        }
    }
}


