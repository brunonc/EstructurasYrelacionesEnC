#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct{
    int idUsuario;
    char nombre[50];
}eUsuario;

void crearListadoDeTresUsuarios(eUsuario[]);
int buscarUsuarioPorId(eUsuario[], int, int);

#endif // USUARIO_H_INCLUDED
