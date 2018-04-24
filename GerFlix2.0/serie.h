#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED

typedef struct {
    int idSerie;
    char nombre[50];
    char genero[50];
} eSerie;

void crearListadoSeries(eSerie[],int);
int buscarSeriePorId(eSerie[], int, int);
void mostrarSeries(eSerie[], int);
void mostrarSerie(eSerie serie);

#endif // SERIE_H_INCLUDED
