#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

//system(clear); (pour éviter que le joueur d'après vois ce que le joueur précédent à choisi, à mettre après fgets?)
#define pierre 1
#define feuille 2
#define ciseaux 3

void ask_username(){

    printf("Veuillez saisir votre pseudonyme :\n");
}

int score = 0; // Bonne réponse = score + 1;

int main(){

    char player1_username[255], player2_username[255], p1ShiFuMi[255], p2ShiFuMi[255];
    int shifumi_comp_p1, shifumi_comp_p2;

    // Mettre les sections d'affichages dans des fonctions

    printf("Veuillez saisir le pseudonyme du premier joueur.\n");
    fgets(player1_username,sizeof(player1_username), stdin);
    printf("Vous avez choisi le pseudo %s\n", player1_username);

    printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
    fgets(player2_username,sizeof(player2_username), stdin);
    printf("Vous avez choisi le pseudo %s\n", player2_username);

    printf("%s, saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n", player1_username);
    fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);

    printf("%s, saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n", player2_username);
    fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);

    shifumi_comp_p1 = atoi(p1ShiFuMi);
    shifumi_comp_p2 = atoi(p2ShiFuMi);

    //Mettre les if dans boucle while
    while(1){   //While(1) car != 0 veut dire vrai pour que la boucle s'effectue toujours

        if(shifumi_comp_p1 == 1){

            printf("Vous avez choisi pierre.\n"); //Rajouter des breaks ?

        }else if(shifumi_comp_p1 == 2){

            printf("Vous avez choisi feuille.\n");

        }else if(shifumi_comp_p1 == 3){

            printf("Vous avez choisi ciseaux.\n");

        }else{
            //redemander pour joueur 1 ou joueur 2
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n ");
            fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);
        }

        if(shifumi_comp_p2 == 1){

            printf("Vous avez choisi pierre.\n");

        }else if(shifumi_comp_p2 == 2){

            printf("Vous avez choisi feuille.\n");

        }else if(shifumi_comp_p2 == 3){

            printf("Vous avez choisi ciseaux.\n");

        }else{

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n ");
            fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);
        }
    }

return 0;
}
