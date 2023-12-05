/**
 * Programa de ordenamiento de canciones de acuerdo al genero escogido
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Cancion.h" // Incorpora la estructura creada

#define MAX_COLUMNAS 6 // Numero maximo de columans a manejar en el CSV

/* Prototipo de funciones */
void despliegaMenu();

// Algoritmos de Ordenamiento
void bubbleSort(int lista[], int n);
void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);

int main(){
    
    // /* Abrir archivo */
    // char nombreArchivo[] = "spotify.csv"; // Almacena el nombre del archivo que contiene los datos
    // // Se abre el CSV para solo lectura
    // FILE *archivo = fopen("spotify.csv", "r");
    // // Verifica que el archivo de abrio correctamente
    // if(archivo == NULL){
    //     perror("No se pudo abrir el archivo.");
    //     exit(EXIT_FAILURE);
    // }

    // char linea[1000];
    // while (fgets(linea, sizeof(linea), archivo) != NULL) {
    //     // Procesar la línea (aquí puedes dividir la línea en columnas)
    //     char *token = strtok(linea, ",");

    //     while (token != NULL) {
    //         printf("%s ", token);
    //         token = strtok(NULL, ",");
    //     }
    // }

    despliegaMenu();
    int lista[] = {5,4,6,7,5,2,2,4,5,76,8,32,52,2,5242,3,25,325,32,536,34,62,335,235,32};
    selectionSort(lista, 11);

    return 0;
}

/* Despliega el menu */
void despliegaMenu(){

    int opcionGenero;
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
                printf("\n-------------------------------------------------\n");
                system("PAUSE");
                printf("-------------------------------------------------\n");
        
            default:
                break;
        }

    }while(opcionGenero != 0);
}

void bubbleSort(int lista[], int n) {
    clock_t inicio, fin;
    double tiempo_transcurrido;
    inicio = clock();

    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Comparar elementos adyacentes y realizar el intercambio si es necesario
            if (lista[j] > lista[j + 1]) {
                lista[j] = lista[j] + lista[j + 1];
                lista[j + 1] = lista[j] - lista[j + 1];
                lista[j] = lista[j] - lista[j + 1];
            }
        }
    }

    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    // Imprime el tiempo transcurrido
    printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);
}

void insertionSort(int lista[], int n) {
    clock_t inicio, fin;
    double tiempo_transcurrido;
    inicio = clock();

    int i, llave, j;

    for (i = 1; i < n; i++) {
        llave = lista[i];
        j = i - 1;

        // Desplazar elementos mayores que llave hacia adelante
        while (j >= 0 && lista[j] > llave) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }

        // Colocar llave en su posición correcta
        lista[j + 1] = llave;
    }


    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    // Imprime el tiempo transcurrido
    printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);
}

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