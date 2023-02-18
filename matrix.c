#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void create_matrix(t_matrice *mat)
{
    printf("Entrer le nombre de ligne :\t");
    scanf("%d", &mat->rows);
    printf("Entrer le nombre de colenne :\t");
    scanf("%d", &mat->columns);

    mat->matr = create_2d_array(mat->rows, mat->columns);
}

void fill_matrix(t_matrice *mat)
{
    fill_2d_array(mat->rows, mat->columns, mat->matr);
}

void show_matrix(t_matrice *mat)
{
    show_2d_array(mat->rows, mat->columns, mat->matr);
}

void free_matrix(t_matrice *mat)
{
    free_2d_array(mat->rows, mat->matr);
}

#include "matrix.h"