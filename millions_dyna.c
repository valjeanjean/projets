#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NB_QUESTIONS 6
#define POURCENTAGE_MIN 50

// Création d'un tableau contenant les questions

char* questions[NB_QUESTIONS] = {
    "Quelle est la couleur du cheval blanc d'Henri IV?\n1.Blanc\n2.Rouge\n3.Noir\n",
    "Date de la prise de la Bastille ?\n1.1750\n2.1789\n3.1800\n",
    "Quel est le plus grand océan du monde ?\n1.Océan Atlantique\n2.Océan Indien\n3.Océan Pacifique\n",
    "Qui a écrit Les Misérables ?\n1.Victor Hugo\n2.Emile Zola\n3.Marcel Proust\n",
    "Quelle est la capitale de l'Australie ?\n1.Sydney\n2.Melbourne\n3.Canberra\n",
    "Laquelle de ces deux oeuvres est un tableau de De Vinci ?\n1.Le cri\n2.La Joconde\n", 
};

/*
    Déclaration de variables pour les calculs du:
    - score
    - pourcentage de victoire (nb_bonne_reponse)
    Création d'un tableau pour contenir les réponses.
*/
int nb_bonne_reponse = 0.0;
int reponses[NB_QUESTIONS] = {1, 2, 3, 1, 3, 2};
int score = 0;

int main(void){
                    
    int i, user_input;

    // Affichage de l'interface d'entête

    printf("###################################################\n");
    printf("######## Qui veux gagner des millions ?! ##########\n");
    printf("###################################################\n\n");
    printf("###################################################\n");
    printf("Score : %d\n", score);
    printf("###################################################\n\n");
    printf("\n Question 1 :\n\n"); 

    /**
     * EVENT LOOP
     *   Boucle for permettant de faire défiler les questions une par une.
     * 
     */
    for(i = 0; i < NB_QUESTIONS; i++){
    
        printf("%s\n", questions[i]);
        scanf("%d", &user_input);
        printf("Suspens....\n\n");

        // Boucle if qui permet de vérifier si l'utilisateur à saisi la bonne réponse, si oui exécuter les instructions ci-dessous.

        if(user_input == reponses[i]){
            
            score = score + 10;

            printf("Bien joué !\n\n");
            printf("*Le score augmente de 10*\n\n");
            printf("###################################################\n");
            printf("Score : %d\n", score);
            printf("###################################################\n\n");
            nb_bonne_reponse++;

        // Si l'utilisateur n'a pas saisi la bonne réponse, exécuter les instructions ci-dessous.

        }else{

            score = score + 0;
            printf("NON !\n\n");
            printf("*Le score n'augmente pas :(*\n\n");
            printf("###################################################\n");
            printf("Score : %d\n", score);
            printf("###################################################\n\n");
        }

    }

    // Déclaration d'une variable de type float car elle va contenir le pourcentage de victoire de l'utilisateur.
    float calcul_final = (float)nb_bonne_reponse / NB_QUESTIONS;
    calcul_final = calcul_final * 100;

    // Affichage de fin de partie
    printf("########## GAME OVER ##########\n");
    printf("Pourcentage de bonne(s) réponse(s) : %f%%\n\n", calcul_final);

    // Condition pour vérifier si l'utilisateur a eu assez de points (> 50% de bonnes réponses) pour remporter le jeu.
    if(calcul_final > POURCENTAGE_MIN){

        printf("Bien joué tu as gagné des millions !\n");

    // Si le joueur à 50% ou moins de bonnes réponses, afficher qu'il n'a pas remporté le jeu.

    }else{

        printf("Vous n'avez PAS gagné des millions !\n");
    }

    return 0;
}