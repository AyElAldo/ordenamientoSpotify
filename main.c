/**
 * Programa de ordenamiento de canciones de acuerdo al genero escogido
 * 
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Cancion.h" // Incorpora la estructura creada

#define MAX_COLUMNAS 6 // Numero maximo de columans a manejar en el CSV

/* Prototipo de funciones */
void despliegaMenu();
void leeArchivo(char nombre_archivo[], int renglones, char genero[]);
void intercambiarCanciones(struct Cancion *c1, struct Cancion *c2);
// Algoritmos de Ordenamiento
void bubbleSort(struct Cancion lista[], int n);
// void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);


struct Cancion canciones_pop[1055];

int main(){
    int i;
    despliegaMenu();
    // for(i = 0; i < 1055; i++){
    //     printf("%d\n", canciones_pop[i].id);
    // }
    return 0;
}

/* Despliega el menu */
void despliegaMenu(){
    int i;

    int opcionGenero, opcionOrdenamiento;
    do{
        system("CLS"); // Limpia la pantalla (terminal)
        /*Formato*/
        printf("-------------------------------------------------\n");
        printf("|\t\tBIENVENIDO AL MENU\t\t|\n");
        printf("-------------------------------------------------\n");
        /* Opciones */
        // Se eligen esas 6 opciones porque son las opciones que contiene el CSV
        printf("1. POP\n");
        printf("2. RAP\n");
        printf("3. ROCK\n");
        printf("4. LATIN\n");
        printf("5. R&B\n");
        printf("6. EDM\n");
        printf("\n\n0. Salir del programa\n");
        printf("-------------------------------------------------\n");
        printf("Escoge el genero que te gustaria ordenar: ");
        scanf("%d", &opcionGenero); // Guarda el genero escogido

        switch (opcionGenero)
        {
            case 0:
                /* Finaliza el programa*/
                printf("\n-------------------------------------------------\n");
                printf("Saliendo del programa...\n");
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 1:
                // 1055 canciones
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();
                leeArchivo("pop.csv",1055, "pop");
                if(opcionOrdenamiento == 1){
                    bubbleSort(canciones_pop, 1055);
                }
                for(i = 0; i < 1055; i++){
                    printf("%s: %ld\n", canciones_pop[i].nombreCancion, canciones_pop[i].duracion);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 2:
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();

                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 3:
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();

                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 4:
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();

                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 5:
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();

                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 6:
                printf("\n-------------------------------------------------\n");
                opcionOrdenamiento = eligeOrdenamiento();

                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            default:
                break;
        }

    }while(opcionGenero != 0);
}

/**
 * @brief Da a escoger el tipo de ordenamiento a usar
 * 
 * @return int: La opcion elegida por el usuario
 */
int eligeOrdenamiento(){
    int opcionAlgoritmo;
    system("CLS");
    printf("\n-------------------------------------------------\n");
    printf("1. Burbuja\n");
    printf("2. Insercion\n");
    printf("3. Seleccion\n");

    printf("Elige el algoritmo de ordenamiento: ");
    scanf("%d", &opcionAlgoritmo);
    printf("-------------------------------------------------\n");
    return opcionAlgoritmo;
}

void intercambiarCanciones(struct Cancion *c1, struct Cancion *c2){
    struct Cancion auxiliar = *c1;
    *c1 = *c2;
    *c2 = auxiliar;

}

void bubbleSort(struct Cancion lista[], int n) {
    clock_t inicio, fin;
    double tiempo_transcurrido;
    inicio = clock();


    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Comparar elementos adyacentes y realizar el intercambio si es necesario
            if (lista[j].duracion > lista[j + 1].duracion) {
                intercambiarCanciones(&lista[j], &lista[j+1]);
                
                // lista[j] = lista[j] + lista[j + 1];
                // lista[j + 1] = lista[j] - lista[j + 1];
                // lista[j] = lista[j] - lista[j + 1];
            }
        }
    }

    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    // Imprime el tiempo transcurrido
    printf("Tiempo BubbleSort en ordenar: %f segundos\n", tiempo_transcurrido);
}

// void insertionSort(struct Cancion lista[], int n) {
//     clock_t inicio, fin;
//     double tiempo_transcurrido;
//     inicio = clock();

//     struct Cancion cancion_aux;

//     int i, llave, j;

//     for (i = 1; i < n; i++) {
//         llave = lista[i].duracion;
//         j = i - 1;

//         // Desplazar elementos mayores que llave hacia adelante
//         while (j >= 0 && lista[j].duracion > llave) {
//             lista[j + 1] = lista[j];
//             j = j - 1;
//         }

//         // Colocar llave en su posición correcta
//         lista[j + 1] = llave;
//     }


//     fin = clock();

//     // Calcula el tiempo transcurrido en segundos
//     tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

//     // Imprime el tiempo transcurrido
//     printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);
// }

void selectionSort(int lista[], int n) {
    clock_t inicio, fin;
    double tiempo_transcurrido;
    inicio = clock();

    int i, j, minIndex;


    for (i = 0; i < n - 1; i++) {
        // Encontrar el índice del elemento mínimo en el sublista no ordenado
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (lista[j] < lista[minIndex]) {
                minIndex = j;
            }
        }

        // Intercambiar el elemento mínimo encontrado con el primer elemento del sublistaeglo no ordenado
        if (minIndex != i) {
            // Utilizar XOR sin variable temporal para intercambiar elementos
            lista[i] = lista[i] ^ lista[minIndex];
            lista[minIndex] = lista[i] ^ lista[minIndex];
            lista[i] = lista[i] ^ lista[minIndex];
        }
    }

    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    // Imprime el tiempo transcurrido
    printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);
}

void leeArchivo(char nombre_archivo[], int renglones, char genero[]){
    FILE *archivo = fopen(nombre_archivo, "r");
    // Verifica que el archivo de abrio correctamente
    if(archivo == NULL){
        perror("No se pudo abrir el archivo.");
        exit(EXIT_FAILURE);
    }

    struct Cancion canciones[1055]; 

    char linea[1000];
    int id_cancion_aux = 0;
    printf("Extrayendo datos...\n");
    // Lee cada linea y lo almacena en "linea"
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Procesar la línea (aquí puedes dividir la línea en columnas)
        char *token = strtok(linea, ",");
        char auxiliar[10]; // Almacena el dato que se convertira a Integer
        int bandera = 0;
        

        int actual_id = ++id_cancion_aux;
        token = strtok(NULL, ",");
        char actual_nombreCancion[100];
        strcpy(actual_nombreCancion, token);
        token = strtok(NULL, ",");
        char actual_nombreAlbum[50];
        strcpy(actual_nombreAlbum, token);
        token = strtok(NULL, ",");
        char actual_genero[50];
        strcpy(actual_genero, token);
        token = strtok(NULL, ",");

        char actual_nombreArtista[50];
        strcpy(actual_nombreArtista, token);
        token = strtok(NULL, ",");

        strcpy(auxiliar, token);
        long int actual_duracion;
        actual_duracion = atoi(auxiliar);
        token = strtok(NULL, ",");

        struct Cancion cancion;
        printf("Actual genero: %s", actual_genero);
        if(!strcmp(genero, actual_genero)){
            bandera = 1;
            cancion.id = actual_id;
            strcpy(cancion.nombreCancion, actual_nombreCancion);
            strcpy(cancion.nombreArtista, actual_nombreArtista);
            strcpy(cancion.nombreAlbum, actual_nombreAlbum);
            strcpy(cancion.genero, actual_genero);
            cancion.duracion = actual_duracion;

            // Se inserta a la lista de canciones
            if(!strcmp(genero, "pop")){
                canciones_pop[cancion.id-1] = cancion;

            }

            printf("Cancion %d insertada.\n", cancion.id);
        }else{
            if(bandera = 1) break;
        }

        // printf("\nID: %d\n", cancion.id);  // Usando "%ld" para imprimir un long int
        // printf("Nombre de la Cancion: %s\n", cancion.nombreCancion);
        // printf("Nombre artista: %s\n", cancion.nombreArtista);
        // printf("Nombre del album: %s\n", cancion.nombreAlbum);
        // printf("Genero: %s\n", cancion.genero);
        // printf("Duracion: %ld ms\n", cancion.duracion);
        
    }
    printf("Extraccion completa.\n");
    system("PAUSE");
}