#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

void create_matrix(t_matrice *mat)
{
    printf("Entrer le nombre de ligne :\t");
    scanf("%d", &mat->rows);
    printf("Entrer le nombre de colenne :\t"); 
    scanf("%d", &mat->cols);

    mat->data = create_2d_array(mat->rows, mat->cols);
}

void fill_matrix(t_matrice *mat)
{
    fill_2d_array(mat->rows, mat->cols, mat->data);
}

void show_matrix(t_matrice *mat)
{
    show_2d_array(mat->rows, mat->cols, mat->data);
}

void free_matrix(t_matrice *mat)
{
    free_2d_array(mat->rows, mat->data);
}

t_matrice product_matrix_array(t_matrice mat1, t_matrice mat2) {
    t_matrice result;
    if (mat1.cols != mat2.rows) {
        result.rows = -1;
        result.cols = -1;
        result.data = NULL;
        return result;
    }
    result.rows = mat1.rows;
    result.cols = mat2.cols;
    result.data = (int **) malloc(result.rows * sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (int *) malloc(result.cols * sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1.cols; k++) {
                sum += mat1.data[i][k] * mat2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Fonction pour extraire les dimensions de la matrice
void extract_dimensions(char *content, t_matrice *mat) {
    sscanf(content, "%d %d\n", &mat->rows, &mat->cols);
}

// Fonction pour extraire les coefficients de la matrice
void extract_coefficients(char *content, t_matrice *mat) {
    char *line;
    line = strtok(content, "\n"); // Ignorer la première ligne qui contient les dimensions

    for (int i = 0; i < mat->rows; i++) {
        line = strtok(NULL, "\n"); // Lire une nouvelle ligne
        for (int j = 0; j < mat->cols; j++) {
            sscanf(line, "%d", &mat->data[i][j]); // Extraire un coefficient de la ligne
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
        printf("Rows : %d, Cols : %d \n", mat->rows, mat->cols);
        mat->data = create_2d_array(mat->rows, mat->cols);
        extract_coefficients(content, mat);
        free(content);
    }
}


void matrix_test(){
    t_matrice m1 = {0, 0, NULL};

    // Creation de la matrice
    create_matrix(&m1);
    // Remplissage de la matrice
    fill_matrix(&m1);
    // Affichage de la matrice
    show_matrix(&m1);
    
    // Libérez la mémoire allouée pour de la matrice
    free_matrix(&m1);
}