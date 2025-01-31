#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

#define NB_QUESTIONS 6
#define choix_duo_cash 3

/*Tableau regroupant les questions qui seront posées à l'utilisateur*/
char* questions[NB_QUESTIONS] = {
    "Quelle est la couleur du cheval blanc d'Henri IV?\n",
    "Date de la prise de la Bastille ?\n",
    "Quel est le plus grand océan du monde ?\n",
    "Qui a écrit Les Misérables ?\n",
    "Quelle est la capitale de l'Australie ?\n",
    "Quelle est l'année de l'assassinat de Kennedy?\n", 
};

/*Tableau regroupant les propositions qui seront faite à l'utilisateur s'il choisit "CARRE"*/
char* choix_reponses_carre[NB_QUESTIONS] = {
    "1. Bleu\t2. Rouge\n3. Blanc\t4. Vert\n", 
    "1. 2025\t2. 1789\n3. 1993\t4. 1718\n",
    "1. Océan Indien\t2. Océan Austral\n3. Océan Atlantique\t4. Océan Pacifique\n",
    "1. Victor Hugo\t2. Jean de La Fontaine\n3. Émile Zola\t4. Charles Baudelaire\n",
    "1. Sydney\t2. Melbourne\n3. Canberra\t4. Brisbane\n",
    "1. 1959\t2. 1972\n3. 1955\t 4. 1963\n", 
};

/*Tableau où l'utilisateur choisis son type de réponses*/
char* DUO_CARRE_CASH[choix_duo_cash] = {

    "DUO\n",
    "CARRE\n",
    "CASH\n",
//RAJOUTER "\n" pour qu'en appuyant sur la touche entrée, ça valide CARRE;
};

/* Tableau avec les 2 propositions dans l'ordre qui seront faites si l'utilisateur choisis "DUO"*/
char* choix_reponses_duo[NB_QUESTIONS] = {
    "1. Blanc\t 2. Rouge\n",
    "1. 2025\t 2. 1789\n",
    "1. Océan Indien\t 2. Océan Pacifique\n", 
    "1. Victor Hugo\t 2. Jean de La Fontaine\n",
    "1. Sydney\t 2. Canberra\n",
    "1. 1963\t 2. 1972\n", 

    // Obligé d'adapter les réponses de choix_reponses_duo[i], car si imaginons reponses[4] > 2, il faudrait afficher dans le désordre
    // 1. réponseA / 3. réponseB par ex
};

/*Tableau regroupant les réponses dans le cas où l'utilisateur choisis "CASH"*/
char* choix_reponses_cash[NB_QUESTIONS] = {
    "BLANC\n",
    "1789\n",
    "OCEAN PACIFIQUE\n",
    "VICTOR HUGO\n",
    "CANBERRA\n",
    "1969\n"

};
 
/*Tableau (ints) regroupant les bonnes réponses dans l'ordre de chaque question pour les duo :*/
int reponses_duo[NB_QUESTIONS] = {1, 2, 2, 1, 2, 1}; 

/*Tableau (ints) regroupant les bonnes réponses dans l'ordre de chaque question pour les CARRE :*/
int reponses_carre[NB_QUESTIONS] = {3, 2, 4, 1, 3, 4};

// On rappelle à l'utilisateur certaines règles pour éviter tout problèmes lors de l'enregistrement de ses réponses
/*Rappel règles DUO*/
void if_regles_duo(){

    printf("\nEntrez 1 pour la réponse 1, 2 pour la réponse 2 :\n\n");
}
/*Rappel règles CARRE*/
void if_regles_carre(){

    printf("\nEntrez 1, 2, 3 ou 4 en fonction de la réponse correspondante\n\n");
}

/*Règles générales*/
void rappel_regles(){

    printf("Bienvenue dans Tout le monde veut prendre sa place !\n");
    printf("Lorsqu'une question vous sera posée, vous aurez le choix entre DUO, CARRE ou CASH.\n\n");
    printf("DUO : Vous avez 2 choix de réponses à votre question, si vous répondez bon, +2 points.\n");
    printf("CARRE : Vous avez 4 choix de réponses à votre question, si vous répondez bon, +4 points.\n");
    printf("CASH : Vous devrez écrire votre réponse en majuscules, si vous répondez bon, +6 points.\n");
    printf("Lorsque vous choisissez un carré ou un duo, tapez le chiffre de la réponse que vous pensez être la bonne.\n"); // Approfondir règles

}

/*Fonction pour prévenir du début du jeu*/
void start_display(){

    printf("###################################################\n");
    printf("####### Tout le monde veut prendre sa place #######\n");
    printf("###################################################\n\n");

}

/*Fonction qui affiche la fin du jeu*/
void end_display(){


    printf("###################################\n");
    printf("#######     JEU TERMINÉ     #######\n");
    printf("###################################\n\n");
}

/*Fonction qui prévient l'utilisateur qu'une question va lui être posée*/
void question_display(){

    printf("\nVous pouvez quitter le jeu en saisissant N\n");
    printf("\nVoici votre question :\n\n");
}

/*Affichage qui prévient l'utilisateur qu'il a choisi "carré", 4 propositions vont lui être faite.*/
void carre_display(){

    printf("Vous avez choisi carré. Voici les 4 propositions :\n");
}

/*Affichage qui prévient l'utilisateur qu'il a choisi "duo", 2 propositions lui seront faite*/
void duo_display(){

    printf("Vous avez choisi duo. Voici vos 2 propositions :\n");
}

/*Affichage qui prévient l'utilisateur qu'il a choisi "cash", il devra taper la réponse dans le terminal*/
void cash_display(){

    printf("Vous avez choisi cash. Saisissez votre réponse en faisant attention aux fautes.\n");
}

int score = 0;
char user_choice[255];
char user_input[255];
int user_answer;
int cmp_cash;

int main(){

    int i = 0;
    int is_duo = 0, is_carre = 0, is_cash = 0, enter_carre_comparaison = 0, leave_game = 0;

    start_display();
    rappel_regles();

    for(i = 0; i < NB_QUESTIONS; i++){ 

        question_display();
        printf("%s\n", questions[i]);
        printf("Vous avez 3 choix : DUO, CARRE ou CASH. Que choisissez vous ?\n\n");
        fgets(user_choice,sizeof(user_choice), stdin); 

        is_duo = strcmp(user_choice,"DUO\n");
        is_carre = strcmp(user_choice,"CARRE\n");
        is_cash = strcmp(user_choice,"CASH\n");
        enter_carre_comparaison = strcmp(user_choice, "\n");
        leave_game = strcmp(user_choice, "N\n");
    
        // Si l'utilisateur choisi DUO :
        if(is_duo == 0){

            printf("\nVous avez choisi DUO, voici vos deux propositions :\n\n");
            if_regles_duo();
            printf("%s\n", choix_reponses_duo[i]); 
            fgets(user_input,sizeof(user_input), stdin); // Utilisation de fgets pour récupérer une chaine de caractère malgré que ce soit un int

            user_answer = atoi(user_input); // Utilisation d'atoi pour convertir chaine de caractère en int

            printf("Suspens...\n\n");
                
                //Si l'utilisateur rentre la bonne réponse, alors :
            if(user_answer == reponses_duo[i]){

                printf("Bonne réponse ! Vous gagnez 2 points !\n\n");
                score = score + 2;
                printf("Votre score est de %d points\n\n", score);
                
            // Sinon :
            }else{

                printf("Mauvaise réponse !\n");
                printf("Votre score est de %d points\n\n", score);
            }
            
            // Si l'utilisateur choisis CARRE
        }else if(is_carre == 0 || enter_carre_comparaison == 0 ){ // || fonction_\n == 0, alors .... (L'utilisateur peut donc taper CARRE ou juste appuyer sur la touche entrée pour sélectionner CARRE)

            printf("\nVous avez choisi CARRE, voici vos 4 propositions :\n\n");
            if_regles_carre();
            printf("%s\n", choix_reponses_carre[i]);
            fgets(user_input,sizeof(user_input), stdin);

            user_answer = atoi(user_input);

            if(user_answer == reponses_carre[i]){

                printf("Bien joué ! Vous gagnez 4 points !\n\n");
                score = score + 4;
                printf("Votre score est de %d points\n\n", score);
                
            }else{

                printf("Mauvaise réponse !\n");
                printf("Votre score est de %d points\n\n", score);
            }
                
        }else if(is_cash == 0){ 

            printf("\nVous avez choisi CASH, veuillez entrer la réponse.\n\n");
            fgets(user_input,sizeof(user_input), stdin);
            printf("%s\n", user_input);
            cmp_cash = strcmp(user_input, choix_reponses_cash[i]);
            
            printf("%d\n\n", cmp_cash);
            printf("%s\n\n", choix_reponses_cash[0]);

            if(cmp_cash == 0){

                printf("C'est excellent ! Bonne réponse !\n\n");
                score = score + 6;
                printf("Votre score est de %d points\n\n", score);
            }


        }else if(leave_game == 0){
            printf("Vous avez choisi de quitter le jeu, au revoir.\n");
            break;

        }else{

            printf("\nCela n'a pas marché. Faites votre choix : DUO, CARRE ou CASH ?\n");
            fgets(user_choice,sizeof(user_choice), stdin);
            score + 0;
        }

    }

    end_display();
    printf("Votre score final est de %d points !\n\n", score);

    return 0;
}
