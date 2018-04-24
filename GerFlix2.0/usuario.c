#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

void crearListadoDeTresUsuarios(eUsuario MisUsuarios[])
{
    int i;
    for(i=0;i<3;i++)
    {
        MisUsuarios[i].idUsuario=i+100;

    }
     strcpy(MisUsuarios[0].nombre,"Maria pia");
     strcpy(MisUsuarios[1].nombre,"Jose luis");
     strcpy(MisUsuarios[2].nombre,"Dafne");
}

int buscarUsuarioPorId(eUsuario usuarios[], int id, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (usuarios[i].idUsuario == id) {
            return i;
        }
    }
    return -1;
}
