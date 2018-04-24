#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "usuarioSerie.h"
#define TAMS 5
#define TAMU 3
#define TAMUS 9

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
    eRating ratings[TAMS];
        for (i = 0; i < TAMS; i++) {
        ratings[i].idSerie = 0;
        ratings[i].rating = 0;
    }
    eUsuarioSerie relUsuarioSerie[TAMUS];

    crearListadoDeTresUsuarios(usuarios);
    crearListadoSeries(series, TAMS);
    crearListadoUsuariosYSeries(relUsuarioSerie);

    do {
        printf("1. SERIES\n2. USUARIOS\n3. REPORTES\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            mostrarSeries(series, TAMS);
            break;
        case 3:
            do {
                printf("1. LISTAR SERIES POR USUARIO\n2. LISTAR USUARIOS POR SERIES\n3. LISTAR SERIES MENOS VISTAS\n9. SALIR\nElija una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
                case 1:
                    mostrarSeriesPorUsr(usuarios, series, relUsuarioSerie, TAMU, TAMUS, TAMS);
                    //mostrarUsrSerie(usuarios, relUsuarioSerie, series, TAMUS, TAMU, TAMS);
                    break;
                case 2:
                    mostrarUsrsPorSerie(usuarios, series, relUsuarioSerie, TAMU, TAMUS, TAMS);
                    break;
                case 3:
                    calcularRatings(series, ratings, relUsuarioSerie, TAMS, TAMUS);
                    mostrarSeriesMenosVistas(ratings, series, TAMS);
                }
            } while (opcion != 9);
        }
    } while (opcion != 9);
    return 0;
}








