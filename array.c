#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int** create_2d_array(int rows, int columns) {
    int** array = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*) malloc(columns * sizeof(int));
    }
    return array;
}

void create_2d_array_void(int rows, int columns, int*** array) {
    *array = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        (*array)[i] = (int*) malloc(columns * sizeof(int));
    }
}

void fill_2d_array(int rows, int columns, int** array) {
    for (int i = 0; i < rows; i++) {
        printf("Entrez les coefficients de la ligne %d :\n", i);
        for (int j = 0; j < columns; j++) {
            printf("Vleur de la cellule (%d,%d) : ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

void show_2d_array(int rows, int columns, int** array) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void free_2d_array(int rows, int** array) {
     for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}