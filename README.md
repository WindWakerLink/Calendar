# PROYECTO DEL CALENDARIO EN C

## ESTRUCTURA PARA EL PROYECTO 

1. Organización de la estructura del proyecto:

- main.c: punto de partida del programa (inicializacion, coordinar llamadas entre modulos, gestion flujo principal)
- calendar.c logica del calendario (calcular dia del mes, detectar anos bisiestos, imprimir calendario, etc)
- calendar.h interfaz pública del módulo del calendario (funciones publicas, structs de fechas, etc)
- events.c logica del gestor de eventos y recordatorios (crear, eliminar y buscar eventos, asociar eventos a fechas)
- events.h interfaz publica del modulo de eventos (structs de eventos, etc)
- storage.c logica de persistencia de datos (guardar/cargar info, leer/escribir archivos)
- storage.h interfaz para el modulo de datos (declarar funciones y structs relacionados con guardado y carga de info, y 
lectura y escritura de archivos)

RECUERDA: archivo.c -> implementa comportamiento / archivo.h -> expone interfaz pública (funciones, structs, constantes)
main.c -> coordina módulos

2. El objetivo de este proyecto (o por lo menos en su version v1) es mostrar un calendario mensual en la terminal en el que más adelante se le sumará la posibilidad de navegar entre días, meses y años y añadir eventos

3. En el proyecto que voy a hacer, los meses del año tiene distinta duración, el mes puede empezar en un día distinto, hay semanas en las que 2 meses pueden coincidir (tipo, que el lunes y el martes sean el 30 y el 31 de Octubre y que del 1 al 5 sea de Noviembre)

4. Lo que voy a necesitar va a ser sí o sí:

- módulos: <stdio.h>, <time.h>, <string.h>, <stdlib.h>

- funciones (que no están incluidas en los módulas que voy a usar):
    - int get_weekday(int day, int month, int year)
    - int is_leap(int year)
    - void print_header(Date date)
    - int days_in_month(int month, int year)
    - void print_weekdays()
    - void print_days()
    - void print_calendar()

- structs: Date (int day, int month, int year)
- tipos: int, char, void, buffers, arrays, punteros...

5. El programa por lo general debería de consumir pocos recursos, pero como no estamos en un sistema embebido, nos podemos tomar la libertad de de consumir un poco de RAM, pero no tanta (además, creo que este calendario no va a usar mucha RAM)

6. print_calendar() necesita a get_weekday(), que necesita days_in_month(), por ejemplo (de momento no vamos a pensar en las dependencias más importantes, no en T0DAS)

7. La lógica del programa sería:

usuario inicia progrmaa -> se detecta el año, mes y día actual del sistema -> se extrae el día/mes/año ->
se calcula el primer día del mes -> se calcula cuantos días tiene el mes -> se imprime el ecabecado (mes y año en el centro)
-> debajo se imprimen las semanas (con sus días de las semanas y los números de los días correspondientes) -> se resalta
el día actual -> fin

8. Los casos especiales que podría haber en el programa sería:

- Febrero es el mes que no tiene 30 o 31 días, sino 28, y en años bisiestos tiene 29
- Un año puede llegar a ser bisiesto
- Como no le vamos a pedir input al usuario (por lo menos en esta versión del programa), no nos vamos a tener que preocupar por ningún inputç
- el ancho de la terminal es muy pequeño para mostrar la información
- la fecha del sistema no sea válida
- haya un locale distinto

9: Las ideas futuras que tengo pensadas para la siguiente o futuras versiones y ordenadas por prioridad, son:

    - IMPRESCINDIBLE: añadir la navegación entre días, meses y años. añadir eventos,

    - IMPORTANTE: guardar recordatorios, mejorar el diseño del calendario (meterlo en un recuadro con un título
    que diga "Manu's Calendar" separado por una ralla y debajo el calendario normal, marcar sábado y domingo
    con un color especial para distinguirlos de los días entre semana)

    - OPCIONAL: añadir debajo del calendario una barra que muestre el día de la semana
    actual junto con el el año, més y día actual, junto con la hora actual
    EJEMPLO: Sun 2026-05-24 [ 18:19:23 ] y debajo de esa barra un espacio para el futuro input del
    usuario junto con las teclas correspondientes para ese input (tipo ? Help, q Quit, r Reload...), añadir música
    de fondo (estaría muy guay)

Las fases 10 y 11 las tengo que hacer una vez termine de hacer el programa, así que de momento se quedan en blanco





