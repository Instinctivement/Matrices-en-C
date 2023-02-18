#ifndef __MATRIX__
#define __MATRIX__

#include "array.h"

typedef struct t_matrice
{
    int rows;
    int columns;
    int** matr;
}t_matrice;

void create_matrix(t_matrice *mat);
void create_matrix_void(int rows, int columns, int*** array);
void fill_matrix(t_matrice *mat);
void show_matrix(t_matrice *mat);
void free_matrix(t_matrice *mat);

#endif

