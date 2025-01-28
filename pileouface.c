#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pile 1
#define face 2

void separate_display(){

    printf("|-------------------------------|\n\n");
}

void lost(){

    printf("C'est PERDU, dommage...\n");
}

void dice_throw(){

    printf("La pièce est jetée\n");
}

void choice(){

    printf("Pile ou Face ?\n");
}

int main(){

    printf("######## Pile ou Face########\n\n");
    choice();
    //fgets
    
    return 0;
}