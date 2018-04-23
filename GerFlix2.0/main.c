#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"
#define TAMS 5

void mostrarSeries(eSerie[], int);
void mostrarSerie(eSerie serie);

/**
*
    1. los datos de la serie que ve cada usuario
    2. por cada serie todos los usuarios que la ven
    3. por cada serie cuantos usuarios la ven
*
*/
int main() {
    int i, opcion;
    eSerie series[TAMS];
    for (i = 0; i < TAMS; i++) {
        series[i].idSerie = 0;
    }

    crearListadoSeries(series, TAMS);

    do {
        printf("1. MOSTRAR SERIES\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            mostrarSeries(series, TAMS);
        }
    } while (opcion != 9);
    return 0;
}

void mostrarSeries(eSerie series[], int tam) {
    int i;
    for (i = 0; i < TAMS; i++) {
        mostrarSerie(series[i]);
    }
}

void mostrarSerie(eSerie serie) {
    printf("%s -- %s\n", serie.nombre, serie.genero);
}
