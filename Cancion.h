#ifndef CANCION_H
#define CANCION_H
#include <stdio.h>

// Definición de la estructura Cancion
struct Cancion {
    int id;
    char nombreCancion[100];
    char nombreAlbum[100];
    char genero[50];
    char nombreArtista[50];
    long int duracion; // Almacena la duracion en milisegundos
};

#endif
