#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "matrix.h"


void app()
{   
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