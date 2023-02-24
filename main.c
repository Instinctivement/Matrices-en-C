#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "controller.h"

int main(int argc, char **argv) {
    
    switch (argc)
    {
        case 2:
            help(argv);
            break;
        case 3:
            without_out_file(argv);
            break;
        case 5:
            with_out_file(argc, argv);
            break;
        default:
            error_arg();
            break;
    }
    return 0;
}

