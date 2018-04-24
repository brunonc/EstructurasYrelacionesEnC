#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

void crearListadoSeries(eSerie series[],int cantidad) {
    int i;
    for(i=0;i<cantidad;i++)
    {
        series[i].idSerie=i+1;
        if(i%2==0)
        {
            strcpy(series[i].genero,"Terror");
        }else{
             strcpy(series[i].genero,"Humor");
        }
    }
     strcpy(series[0].nombre,"Los muertos vivos");
     strcpy(series[1].nombre,"Los vickingos");
     strcpy(series[2].nombre,"Los extraterrestres");
     strcpy(series[3].nombre,"Los Hacker");
     strcpy(series[4].nombre,"Los perdidos");
}

int buscarSeriePorId(eSerie series[], int id, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (series[i].idSerie == id) {
            return i;
        }
    }
    return -1;
}

void mostrarSeries(eSerie series[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        mostrarSerie(series[i]);
    }
}

void mostrarSerie(eSerie serie) {
    printf("%s -- %s\n", serie.nombre, serie.genero);
}
