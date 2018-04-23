#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"
#define TAMS 5
#define TAMU 3
#define TAMUS 9

void mostrarSeries(eSerie[], int);
void mostrarSerie(eSerie serie);
void mostrarUsrConSeries(eUsuario[], eUsuarioSerie[], eSerie[], int);
int buscarUsuarioPorId(eUsuario[], int, int);
int buscarSeriePorId(eSerie[], int, int);

/**
*
    1. los datos de la serie que ve cada usuario
    2. por cada serie todos los usuarios que la ven
    3. por cada serie cuantos usuarios la ven
*
*/
int main() {
    int i, opcion;
    eUsuario usuarios[TAMU];
    for (i = 0; i < TAMU; i++) {
        usuarios[i].idUsuario = 0;
    }
    eSerie series[TAMS];
    for (i = 0; i < TAMS; i++) {
        series[i].idSerie = 0;
    }
    eUsuarioSerie relUsuarioSerie[TAMUS];

    crearListadoDeTresUsuarios(usuarios);
    crearListadoSeries(series, TAMS);
    crearListadoUsuariosYSeries(relUsuarioSerie);

    do {
        printf("1. MOSTRAR SERIES\n2. MOSTRAR SERIES DE USUARIOS\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            mostrarSeries(series, TAMS);
            break;
        case 2:
            mostrarUsrConSeries(usuarios, relUsuarioSerie, series, TAMUS);
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

void mostrarUsrConSeries(eUsuario usuarios[], eUsuarioSerie usuarioSerie[], eSerie series[], int tamrel) {
    int i, iusuario, iserie;
    for (i = 0; i < tamrel; i++) {
        iusuario = buscarUsuarioPorId(usuarios, usuarioSerie[i].idUsuario, TAMU);
        iserie = buscarSeriePorId(series, usuarioSerie[i].idSerie, TAMS);
        printf("%s -- %s\n", usuarios[iusuario].nombre, series[iserie].nombre);
    }
}

int buscarUsuarioPorId(eUsuario usuarios[], int id, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (usuarios[i].idUsuario == id) {
            return i;
        }
    }
}

int buscarSeriePorId(eSerie series[], int id, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (series[i].idSerie == id) {
            return i;
        }
    }
}
