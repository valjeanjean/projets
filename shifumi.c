#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

#define pierre 1   // if p1shifumi > p2shifumi && p1shifumi > pierre printf("%s à gagné", p1shifumi); ?
#define feuille 2
#define ciseaux 3

char player1_username[255], player2_username[255], p1ShiFuMi[255], p2ShiFuMi[255];

void ask_usernameP1(){

    printf("Veuillez saisir le pseudonyme du premier joueur.\n");
}

void ask_usernameP2(){

    printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
}

void username_displayP1(){

    printf("Vous avez choisi le pseudo %s.\n", player1_username);
}

void username_displayP2(){

    printf("Vous avez choisi le pseudo %s.\n", player2_username);
}

void choice_displayP1(){

    printf("%s, saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n", player1_username);
}

void choice_displayP2(){

    printf("%s, saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n", player2_username);
}

int score = 0; // Bonne réponse = score + 1;

int main(){

    
    int shifumi_comp_p1, shifumi_comp_p2;

    // Mettre les sections d'affichages dans des fonctions

    ask_usernameP1();
    fgets(player1_username,sizeof(player1_username), stdin); // Où mettre strlen, comment ça marche?
    player1_username[strcspn(player1_username, "\n")] = 0;
    username_displayP1();

    ask_usernameP2();
    fgets(player2_username,sizeof(player2_username), stdin);
    player2_username[strcspn(player2_username, "\n")] = 0;
    username_displayP2();

    choice_displayP1();
    fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);
    //strlen

    choice_displayP2();
    fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);
    //strlen

    shifumi_comp_p1 = atoi(p1ShiFuMi);
    shifumi_comp_p2 = atoi(p2ShiFuMi);

    //Mettre les if dans boucle while
    while(1){   //While(1) car != 0 veut dire vrai pour que la boucle s'effectue toujours

        if(shifumi_comp_p1 == pierre){

            printf("%s, vous avez choisi pierre.\n", player1_username); //Rajouter des breaks ? + préférer switch à else if?
            break;
        
        //system(clear); (pour éviter que le joueur d'après vois ce que le joueur précédent à choisi, à mettre après fgets?)

        }else if(shifumi_comp_p1 == feuille){

            printf("%s, vous avez choisi feuille.\n", player1_username);
            break;
        

        }else if(shifumi_comp_p1 == ciseaux){

            printf("%s, vous avez choisi ciseaux.\n", player1_username);
            break;
            

        }else{
            //redemander pour joueur 1 ou joueur 2
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n ");
            fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);
            break;
        }continue;

        if(shifumi_comp_p2 == pierre){

            printf("%s, vous avez choisi pierre.\n", player2_username);
            break;
        

        }else if(shifumi_comp_p2 == feuille){

            printf("%s, vous avez choisi feuille.\n", player2_username);
            break;
            

        }else if(shifumi_comp_p2 == ciseaux){

            printf("%s, vous avez choisi ciseaux.\n", player2_username);
            break;
        

        }else{

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n ");
            fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);
            break;
        }

    }

    return 0;
}


