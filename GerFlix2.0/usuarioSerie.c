#include "usuarioSerie.h"

void crearListadoUsuariosYSeries(eUsuarioSerie misRelaciones[])
{
    int i;

    int u[9]={100,100,100,100,101,101,101,102,102};
    int s[9]={1,2,3,4,1,2,3,1,4};


    for(i=0;i<9;i++)
    {
       misRelaciones[i].idSerie=s[i];
       misRelaciones[i].idUsuario=u[i];
    }

}

void mostrarUsrsPorSerie(eUsuario usuarios[], eSerie series[], eUsuarioSerie relUsrSerie[], int tamu, int tamrel, int tams) {
    int i, j, iusuario;
    for (i = 0; i < tams; i++) {
        printf("%s:\n", series[i].nombre);
        for (j = 0; j < tamrel; j++) {
            if (relUsrSerie[j].idSerie == series[i].idSerie) {
                iusuario = buscarUsuarioPorId(usuarios, relUsrSerie[j].idUsuario, tamu);
                printf("\t- %s\n", usuarios[iusuario].nombre);
            }
        }
    }
}

void mostrarUsrSerie(eUsuario usuarios[], eUsuarioSerie usuarioSerie[], eSerie series[], int tamrel, int tamu, int tams) {
    int i, iusuario, iserie;
    for (i = 0; i < tamrel; i++) {
        iusuario = buscarUsuarioPorId(usuarios, usuarioSerie[i].idUsuario, tamu);
        iserie = buscarSeriePorId(series, usuarioSerie[i].idSerie, tams);
        printf("%s -- %s\n", usuarios[iusuario].nombre, series[iserie].nombre);
    }
}

void mostrarSeriesPorUsr(eUsuario usuarios[], eSerie series[], eUsuarioSerie relUsrSerie[], int tamu, int tamrel, int tams) {
    int i, j, iserie;
    for (i = 0; i < tamu; i++) {
        printf("%s:\n", usuarios[i].nombre);
        for (j = 0; j < tamrel; j++) {
            if (relUsrSerie[j].idUsuario == usuarios[i].idUsuario) {
                iserie = buscarSeriePorId(series, relUsrSerie[j].idSerie, tams);
                printf("\t- %s\n", series[iserie].nombre);
            }
        }
    }
}

void calcularRatings(eSerie series[], eRating raitings[], eUsuarioSerie relUsrSerie[], int tams, int tamrel) {
    int i, j, cont;
    for (i = 0; i < tams; i++) {
        cont = 0;
        raitings[i].idSerie = series[i].idSerie;
        for (j = 0; j < tamrel; j++) {
            if (series[i].idSerie == relUsrSerie[j].idSerie) {
                cont++;
            }
        }
        raitings[i].rating = cont;
    }
}

void mostrarSeriesMenosVistas(eRating ratings[], eSerie series[], int tams) {
    int i, menor, iserie;
    menor = ratings[0].rating;
    for (i = 1; i < tams; i++) {
        if (ratings[i].rating < menor) {
            menor = ratings[i].rating;
        }
    }
    for (i = 0; i < tams; i++) {
        if (ratings[i].rating == menor) {
            iserie = buscarSeriePorId(series, ratings[i].idSerie, tams);
            printf("%s\n", series[iserie].nombre);
        }
    }
}
