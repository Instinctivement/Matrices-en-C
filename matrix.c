#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Fonction pour extraire les dimensions de la matrice
void extract_dimensions(char *content, t_matrice *mat) {
    sscanf(content, "%d %d\n", &mat->rows, &mat->columns);
}

// Fonction pour extraire les coefficients de la matrice
void extract_coefficients(char *content, t_matrice *mat) {
    char *line;
    line = strtok(content, "\n"); // Ignorer la première ligne qui contient les dimensions

    for (int i = 0; i < mat->rows; i++) {
        line = strtok(NULL, "\n"); // Lire une nouvelle ligne
        for (int j = 0; j < mat->columns; j++) {
            sscanf(line, "%d", &mat->matr[i][j]); // Extraire un coefficient de la ligne
            line += 2; // Avancer à la prochaine valeur en sautant l'espace
        }
    }
}

// Fonction qui lit un fichier contenant les coefficients d'une matrice
// et les stocke dans une matrice allouée dynamiquement
void read_matrix_from_file(char *filename, t_matrice *mat) {
    char *content = read_file(filename);
    
    if (content) {
        extract_dimensions(content, mat);
        printf("Rows : %d, Cols : %d \n", mat->rows, mat->columns);
        mat->matr = create_2d_array(mat->rows, mat->columns);
        extract_coefficients(content, mat);
        free(content);
    }
}
