/**
 * @file main.c
 * @author AyElAldo
 * @brief Programa que realiza ordenamiento por duracion (en milisegundos) de acuerdo a un CSV de datos reales de canciones en Spotify.
 * El usuario escoge el genero a ordenar. Se usa BubbleSort para el ordenamiento.
 * @version 0.1
 * @date 2020-12-11
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
void imprimirCancion(struct Cancion cancion);
// Algoritmos de Ordenamiento
void bubbleSort(struct Cancion lista[], int n);
// void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);


struct Cancion canciones_pop[1055];
struct Cancion canciones_rap[1080];
struct Cancion canciones_rock[1005];
struct Cancion canciones_latin[964];
struct Cancion canciones_ryb[866];

/**
 * @brief Cuerpo del programa.
 * 
 * @return int Retorna 0 si ha finalizado correctamente.
 */
int main(){
    despliegaMenu();
    return 0;
}

/**
 * @brief Despliega el menu y procesa las opciones a elegir del usuario para el ordenamiento de las listas
 * 
 */
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
                leeArchivo("src/pop.csv",1055, "pop");
                bubbleSort(canciones_pop, 1055);
                
                for(i = 0; i < 1055; i++){
                    // printf("%s: %ld\n", canciones_pop[i].nombreCancion, canciones_pop[i].duracion);
                    imprimirCancion(canciones_pop[i]);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 2:
                printf("\n-------------------------------------------------\n");
                leeArchivo("src/rap.csv",1080, "rap");
                bubbleSort(canciones_rap, 1080);
                for(i = 0; i < 1080; i++){
                    // printf("%s: %ld\n", canciones_rap[i].nombreCancion, canciones_rap[i].duracion);
                    imprimirCancion(canciones_rap[i]);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 3:
                printf("\n-------------------------------------------------\n");
                leeArchivo("src/rock.csv",1005, "rock");
                bubbleSort(canciones_rock, 1005);
                for(i = 0; i < 1005; i++){
                    // printf("%s: %ld\n", canciones_rock[i].nombreCancion, canciones_rock[i].duracion);
                    imprimirCancion(canciones_rock[i]);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 4:
                printf("\n-------------------------------------------------\n");
                leeArchivo("src/latin.csv",964, "latin");
                bubbleSort(canciones_latin, 964);
                for(i = 0; i < 964; i++){
                    // printf("%s: %ld\n", canciones_latin[i].nombreCancion, canciones_latin[i].duracion);
                    imprimirCancion(canciones_latin[i]);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            case 5:
                printf("\n-------------------------------------------------\n");
                leeArchivo("src/r&b.csv",964, "r&b");
                bubbleSort(canciones_ryb, 866);
                for(i = 0; i < 866; i++){
                    // printf("%s: %ld\n", canciones_ryb[i].nombreCancion, canciones_ryb[i].duracion);
                    imprimirCancion(canciones_ryb[i]);
                }
                system("PAUSE");
                printf("-------------------------------------------------\n");
                break;
            default:
                break;
        }

    }while(opcionGenero != 0);
}

/**
 * @brief Intercambia la posicion de canciones haciendo uso de punteros
 * 
 * @param c1 Primera cancion
 * @param c2 Segunda cancion
 */
void intercambiarCanciones(struct Cancion *c1, struct Cancion *c2){
    struct Cancion auxiliar = *c1;
    *c1 = *c2;
    *c2 = auxiliar;

}

/**
 * @brief Realiza ordenamiento burbuja y calcula el tiempo total en la implementacion del algoritmo a la lista deseada.
 * 
 * @param lista Lista de canciones
 * @param n Numero de elementos en la lista a ordenar
 */
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
            }
        }
    }

    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    // Imprime el tiempo transcurrido
    printf("Tiempo BubbleSort en ordenar: %f segundos\n", tiempo_transcurrido);
}

/**
 * @brief Abre el archivo a analizar de acuerdo al genero escogido. Extrae por tokens cada dato de la cancion de cada linea y la almacena en un arreglo
 * 
 * @param nombre_archivo Nombre del archivo a extraer los datos de las canciones
 * @param renglones Numero de renglones del archivo. A su vez contiene el numero de canciones
 * @param genero Genero escogido a analizar
 */
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
            if(!strcmp(genero, "rap")){
                canciones_rap[cancion.id-1] = cancion;

            }
            if(!strcmp(genero, "rock")){
                canciones_rock[cancion.id-1] = cancion;

            }
            if(!strcmp(genero, "latin")){
                canciones_latin[cancion.id-1] = cancion;

            }
            if(!strcmp(genero, "r&b")){
                canciones_ryb[cancion.id-1] = cancion;

            }

            printf("Cancion %d insertada.\n", cancion.id);
        }else{
            if(bandera = 1) break;
        }

        
    }
    printf("Extraccion completa.\n");
    system("PAUSE");
}

/**
 * @brief Formato para imprimir la estructura cancion en consola
 * 
 * @param cancion Cancion a imprimir
 */
void imprimirCancion(struct Cancion cancion){
    // printf("\nID: %d\n", cancion.id);  // Usando "%ld" para imprimir un long int
    printf("Nombre de la Cancion: %s\n", cancion.nombreCancion);
    printf("Nombre artista: %s\n", cancion.nombreArtista);
    printf("Nombre del album: %s\n", cancion.nombreAlbum);
    printf("Genero: %s\n", cancion.genero);
    printf("Duracion: %ld ms\n\n", cancion.duracion);
}