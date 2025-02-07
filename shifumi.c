#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <unistd.h>

#define pierre 1   // if p1ShiFuMi > p2shifumi && p1ShiFuMi > pierre printf("%s à gagné", p1shifumi); ?
#define feuille 2
#define ciseaux 3

// Quand des chiffres sont invariables, qu'ils resteront toujours pareil dans mon code, les mettre en constantes #define

char player1_username[255], player2_username[255], p1ShiFuMi[255], p2ShiFuMi[255];

void ask_username_displayP1(){
    printf("Veuillez saisir le pseudonyme du premier joueur.\n");
    fgets(player1_username,sizeof(player1_username), stdin);
    player1_username[strcspn(player1_username, "\n")] = 0; // Méthode pour enlever le \n avec strcspn
    return; // Facultatif mais bonne habitude à prendre de toujours mettre un return à une fonction
}

void ask_username_displayP2(){

    printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
    fgets(player2_username,sizeof(player2_username), stdin);
    player2_username[strlen(player2_username)-1] = 0; // Méthode pour enlever le \n avec strlen
    return;

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
    
    /* Exemples de Massi

    memset(player1_username,0,sizeof(player1_username));
    scanf("%s",player1_username);
    scanf("%s",memset(player1_username,0,sizeof(player1_username)));*
 
    char *line;
    while(        (   line    =  fgets(line,sizeof(player1_username), save)     )          !=          NULL          ){
        printf("%s",line);
    }*/
    
    // Déclarations de variables pour le calcul atoi
    int shifumi_comp_p1, shifumi_comp_p2;

    // Mettre les sections d'affichages dans des fonctions
    // Je peux mettre fgets dans la fonction ask_usernameP1 puisqu'il est censé être demandé à chaque fois pour ce type d'affichage(fait);

    ask_username_displayP1(); 
    //player1_username[strcspn(player1_username, "\n")] = 0; 
    username_displayP1();

    ask_username_displayP2();
    //player2_username[strlen(player2_username)-1] = 0; 
    //player2_username[strcspn(player2_username, "\n")] = 0;
    username_displayP2();

    choice_displayP1();
    fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);

    shifumi_comp_p1 = atoi(p1ShiFuMi);

    while(1){

        if(shifumi_comp_p1 == pierre){

            printf("%s, vous avez choisi Pierre.\n", player1_username); //Rajouter des breaks ? + préférer switch à else if (faire attention, switch case n'accepte que les variables constantes)
            sleep(2);
            system("clear");
            
        }else if(shifumi_comp_p1 == feuille){ 

            printf("%s, vous avez choisi Feuille.\n", player1_username);
            sleep(2);
            system("clear");
            break;
        

        }else if(shifumi_comp_p1 == ciseaux){

            printf("%s, vous avez choisi Ciseaux.\n", player1_username); // Encapsuler ça dans une fonction!
            sleep(2);
            system("clear");
            break;
            

        }else{
            //redemander pour joueur 1 ou joueur 2
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n ");
            fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);
        }


        choice_displayP2();
        fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);
        shifumi_comp_p2 = atoi(p2ShiFuMi);

        if(shifumi_comp_p2 == pierre){ // Utiliser également switch ici!

            printf("%s, vous avez choisi Pierre.\n", player2_username);
            sleep(2);
            system("clear");
            break;
            

        }else if(shifumi_comp_p2 == feuille){

            printf("%s, vous avez choisi Feuille.\n", player2_username);
            sleep(2);
            system("clear");
            break;
            

        }else if(shifumi_comp_p2 == ciseaux){

            printf("%s, vous avez choisi Ciseaux.\n", player2_username);
            sleep(2);
            system("clear");
            break;
        

        }else{

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(p2ShiFuMi, sizeof(p2ShiFuMi), stdin);
        }
    
    }

    /**
     * Utiliser strcmp + atoi, si p1shifumi == pierre && p2shifumi == pierre printf("égalité.\n"); ou tout simplement if p1shifumi == p2shifumi, print égalité.
     *                         si p1shifumi == pierre && p2shifumi == feuille printf("La feuille enveloppe la pierre, %s gagne.\n", player2username);
     *                         si p1shifumi == pierre && p2shifumi == ciseaux printf("La pierre casse les ciseaux, %s gagne.\n", player1username); UTILISER ||
     * 
     *                         si p1shifumi == ciseaux && p2shifumi == pierre printf("La f, %s gagne.\n", player2username);
     *                         si p1shifumi == ciseaux && p2shifumi == feuille printf("Légalité\n");
     *                         si p1shifumi == ciseaux && p2shifumi == ciseaux printf("La feuille enveloppe la pierre, %s gagne.\n", player2username);
     * 
     */

   /* if(){ 

    }*/

    return 0;
}


