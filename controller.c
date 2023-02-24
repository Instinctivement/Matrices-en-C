#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "controller.h"
#include "matrix.h"
#include "files.h"


void app(char f1[], char f2[], char f3[])
{
    t_matrice m1;
    t_matrice m2;
    char first_filename[20]; // nom du fichier contenant la matrice
    char second_filename[20]; // nom du fichier contenant la matrice

    strcpy(first_filename, f1);
    strcpy(second_filename, f2);

    // Lecture des matrices à partir du fichier
    read_matrix_from_file(first_filename, &m1);
    read_matrix_from_file(second_filename, &m2);

    // Affichage de la matrice
    printf("1 - Matrice lue à partir du fichier %s :\n", first_filename);
    show_matrix(&m1);
    printf("2 - Matrice lue à partir du fichier %s :\n", second_filename);
    show_matrix(&m2);

    printf("********************************************************\n");
    t_matrice product = product_matrix_array(m1, m2);

    if (product.rows == -1) {
        printf("Impossible de calculer le produit : dimensions incompatibles.\n");
    } else {
        printf("Produit de matrices:\n");
        for (int i = 0; i < product.rows; i++) {
            for (int j = 0; j < product.cols; j++) {
                printf("%d ", product.data[i][j]);
            }
            printf("\n");
        }
    }

    /*const char* new_content = "Nouveau contenu pour le fichier test.txt\n";
    int result = write_file(filename, new_content);
    if (!result) {
        printf("Contenu du fichier %s modifié avec succès\n", filename);
    }*/

    // Libération de la mémoire allouée pour la matrice
    free_matrix(&m1);
    free_matrix(&m2);
    free_matrix(&product);
}

void error_arg()
{
    printf("\n\tLe nombre d'argument passé en paramètre est erroné.\n\tUtiliser le flag --help pour consulter l’aide.\n\n");
}

void help(char **argv)
{
    char* arg_help = "--help";
     
        printf("\n- argv[1]: %s\n", argv[1]);
        if (strcmp(argv[1], arg_help) == 0)
        {
            printf("\n ./app --help\n");
            printf("\t Utilisation: a.out [option] fichier1 fichier2 \n");
            printf("\t Options :\n");
            printf("\t\t --help\n");
            printf("\t\t Afficher ces informations\n");
            printf("\t\t -o <s>\n");
            printf("\t\t Produit matriciel dans le fichier de sortie <s>, par defaut <out.txt>\n");
        }else
        {
            printf("\n Le nombre d'argument passé en paramètre est 1.\n Mais il ne convient pas au drapeau '--help'\n\tUtiliser le flag --help pour consulter l’aide.\n\n \n");
        }
}

void with_out_file(int count, char **argv)
{
    int counter;
    int is_there = 0;
    int is_posit = 0;
    char* arg_out = "-o";
    for(counter=0;counter<count;counter++)
    {
        if (strcmp(argv[counter], arg_out) == 0)
        {
            is_there = 1;
            is_posit = counter;
        }
    }

    if (is_there == 1)
    {
        switch (is_posit)
        {
        case 1:
            app(argv[3], argv[4], argv[2]);
            break;
        case 3:
            app(argv[1], argv[2], argv[4]);
            break;
        
        default:
            help(argv);
            break;
        }
    }else
    {
        help(argv);
    }
    
}

void without_out_file(char **argv)
{
    char filename[40];
    char destination_filename[40];
    strcpy(filename, argv[1]);
    strcpy(destination_filename, argv[2]);
    char* content = read_file(filename);
    if (content) {
        printf("Contenu du fichier %s : %s\n", filename, content);
        free(content);
    }

    const char* new_content = "Nouveau contenu pour le fichier test.txt\n";
    int result = write_file(filename, new_content);
    if (!result) {
        printf("Contenu du fichier %s modifié avec succès\n", filename);
    }

    result = copy_file(filename, destination_filename);
    if (!result) {
        printf("Copie du contenu de %s vers %s réussie\n", filename, destination_filename);
    }
}