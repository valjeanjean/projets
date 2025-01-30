#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input[10];  // Un tableau pour stocker la chaîne de caractères
    int input_value;

    printf("Entrez un nombre : ");
    fgets(user_input, sizeof(user_input), stdin);  // Lecture de la ligne complète

    // Conversion de la chaîne en entier
    input_value = atoi(user_input);

    printf("Vous avez entré l'entier : %d\n", input_value);
    return 0;
}
