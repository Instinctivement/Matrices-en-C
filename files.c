#include <stdio.h>
#include <stdlib.h>

#include "files.h"


/*
    fopen(<fichier>, <mode_ouverture>) : r  (lecture seule, doit exister)
                                         w  (écriture seule)
                                         a  (ajout fin fichier)
                                         r+ (lecture/écriture, doit exister) 
                                         w+ (lecture/écriture, supprime contenu) 
                                         a+ (ajout lecture/écriture, fin de fichier)

*/

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        return NULL;
    }

    /*
        Trouver la taille du fichier
        fseek(file, 0, SEEK_END) : déplace le curseur de lecture dans le fichier à la fin du fichier.
        ftell(file) : renvoie la position actuelle du curseur de lecture dans le fichier. 
                      Dans ce cas, la position est la fin du fichier, 
                      donc la valeur renvoyée est la taille totale du fichier en octets.
        fseek(file, 0, SEEK_SET) : déplace le curseur de lecture dans le fichier au début du fichier.
    
    */
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /*
        Allouer de la mémoire pour contenir le contenu du fichier
        size : est la taille totale du fichier en octets, telle que déterminée précédemment en utilisant ftell.
        (size + 1) * sizeof(char) : est la taille totale de la mémoire que nous voulons allouer, 
                                    en prenant en compte un octet supplémentaire pour le caractère nul ('\0').
    */
    char* content = (char*) malloc((size + 1) * sizeof(char));
    if (!content) {
        printf("Erreur lors de l'allocation de mémoire pour contenir le contenu du fichier %s\n", filename);
        fclose(file);
        return NULL;
    }

    /*
        Lire le contenu du fichier
        Le premier argument   : de la fonction fread est un pointeur vers la zone mémoire où les données lues seront stockées. 
                                Dans ce cas, content est le pointeur qui pointe vers le tableau de caractères dans lequel nous stockerons le contenu du fichier.
        Le deuxième argument  : est la taille de chaque élément lu. Dans ce cas, nous lisons des caractères, 
                                donc la taille de chaque élément est sizeof(char), qui est généralement égale à 1.
        Le troisième argument : est le nombre d'éléments à lire. Dans ce cas, nous lisons size éléments, où size est la taille totale du fichier en octets.
        Le quatrième argument : est un pointeur vers le fichier à partir duquel lire. Dans ce cas, file est le pointeur qui pointe vers le fichier que nous voulons lire.
        Enfin, la valeur renvoyée par fread est stockée dans bytes_read, qui correspond au nombre total d'éléments lus avec succès à partir du fichier.
    */
    long bytes_read = fread(content, sizeof(char), size, file);
    if (bytes_read != size) {
        printf("Erreur lors de la lecture du contenu du fichier %s\n", filename);
        fclose(file);
        free(content);
        return NULL;
    }
    content[size] = '\0';

    fclose(file);
    return content;
}

int write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        return 1;
    }

    fputs(content, file);
    fclose(file);
    return 0;
}

int copy_file(const char* source_filename, const char* destination_filename) {
    char* content = read_file(source_filename);
    if (!content) {
        printf("Impossible de lire le contenu du fichier %s\n", source_filename);
        return 1;
    }

    int result = write_file(destination_filename, content);
    free(content);
    if (result) {
        printf("Erreur lors de l'écriture du contenu dans le fichier %s\n", destination_filename);
        return 1;
    }

    return 0;
}


void file_test(){
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
