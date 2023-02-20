#ifndef __MATRIX__
#define __MATRIX__

#include "array.h"
#include "files.h"

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

void extract_dimensions(char *content, t_matrice *mat);
void extract_coefficients(char *content, t_matrice *mat);
void read_matrix_from_file(char *filename, t_matrice *mat);
#endif

