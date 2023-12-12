#ifndef CANCION_H
#define CANCION_H
#include <stdio.h>

/**
 * @brief Estructura de una cancion. Se guardaran datos reales descargados de un CSV existente en el sitio kaggle.com/datasheets
 * 
 */
struct Cancion {
    int id;
    char nombreCancion[100];
    char nombreAlbum[100];
    char genero[50];
    char nombreArtista[50];
    long int duracion; // Almacena la duracion en milisegundos
};

#endif
