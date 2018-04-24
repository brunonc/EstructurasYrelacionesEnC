#ifndef USUARIOSERIE_H_INCLUDED
#define USUARIOSERIE_H_INCLUDED
#include "serie.h"
#include "usuario.h"

typedef struct {
    int idUsuario;
    int idSerie;
} eUsuarioSerie;

typedef struct {
    int idSerie;
    int rating;
} eRating;

void crearListadoUsuariosYSeries(eUsuarioSerie[]);
void mostrarUsrsPorSerie(eUsuario[], eSerie[], eUsuarioSerie[], int, int, int);
void mostrarUsrSerie(eUsuario[], eUsuarioSerie[], eSerie[], int, int, int);
void mostrarSeriesPorUsr(eUsuario[], eSerie[], eUsuarioSerie[], int, int, int);
void calcularRatings(eSerie[], eRating[], eUsuarioSerie[], int, int);
void mostrarSeriesMenosVistas(eRating[], eSerie[], int);

#endif // USUARIOSERIE_H_INCLUDED
