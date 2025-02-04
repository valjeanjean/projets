#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

int main(){

    char user_input[255];
    //size_t essai;

    printf("Veuillez saisir une chaîne de caractères :\n");
    //user_input[strlen(user_input) - 1] = 0;
    fgets(user_input, sizeof(user_input),stdin);
    user_input[strcspn(user_input, "\n")] = 0;


    //essai = strlen(user_input) - 1;

    printf("%s est votre pseudo\n", user_input);

    return 0;
 }