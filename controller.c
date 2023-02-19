#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "matrix.h"
#include "files.h"


void app()
{   
    /* 
    t_matrice m1 = {0, 0, NULL};

    // Creation de la matrice
    create_matrix(&m1);
    // Remplissage de la matrice
    fill_matrix(&m1);
    // Affichage de la matrice
    show_matrix(&m1);
    
    // Libérez la mémoire allouée pour de la matrice
    free_matrix(&m1);*/

    const char* filename = "test.txt";
    const char* destination_filename = "test_copy.txt";
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