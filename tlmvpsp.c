#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Vérifier si les tableaux sont faits pour chaque strings que je veux stocker
// variable score

#define NB_QUESTIONS 6

 // modifier questions
 // duo = 2pts; carré = 4pts; cash = 6pts;

// Tableau regroupant les questions qui seront posées à l'utilisateur

char* questions[NB_QUESTIONS] = {
    "Quelle est la couleur du cheval blanc d'Henri IV?\n",
    "Date de la prise de la Bastille ?\n",
    "Quel est le plus grand océan du monde ?\n",
    "Qui a écrit Les Misérables ?\n",
    "Quelle est la capitale de l'Australie ?\n",
    "Quelle est l'année de l'assassinat de Kennedy?\n", 
};

// Cash = strcmp user_input, if user_input == réponse[i] == + 6pts

// Tableau regroupant les propositions qui seront faite à l'utilisateur s'il choisit "carré"

// TABLEAU RÉPONSES CARRÉ
char* choix_reponses_carre[NB_QUESTIONS] = {
    "1. Blanc\t 2. Rouge\n3. Bleu\t 4. Vert\n",
    "1. 2025\t 2. 1789\n3. 1993\t 4. 1718\n",
    "1. Océan Indien\t 2. Océan Pacifique\n3. Océan Atlantique\t 4. Océan Austral\n",
    "1. Victor Hugo\t 2. Jean de La Fontaine\n3. Émile Zola\t 4. Charles Baudelaire\n",
    "1. Sydney\t 2. Melbourne\n3. Canberra\t 4. Brisbane\n",
    "1. 1963\t 2. 1972\n3. 1955\t 4. 1959\n", 
};

// Tableau avec les 2 propositions dans l'ordre qui seront faites si l'utilisateur choisis "duo"

// TABLEAU RÉPONSES DUO
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

// Tableau (ints) regroupant les bonnes réponses dans l'ordre de chaque question

int reponses[NB_QUESTIONS] = {1, 2, 2, 1, 2, 1}; // modifier int bonne réponses

// On rappelle à l'utilisateur certaines règles pour éviter tout problèmes lors de l'enregistrement de ses réponses
// Faire une explication des règles plus détaillées ?

void rappel_regles(){

    printf("Lorsque vous choisissez un carré ou un duo, taper le chiffre de la réponse que vous pensez être la bonne\n");

}

// Fonction pour prévenir du début du jeu

void start_display(){

    printf("###################################################\n");
    printf("####### Tout le monde veut prendre sa place #######\n");
    printf("###################################################\n\n");

}

// Fonction qui permet d'afficher "JEU TERMINÉ" à la fin du jeu

void end_display(){


    printf("###################################\n");
    printf("#######     JEU TERMINÉ     #######\n");
    printf("###################################\n\n");
}

//Fonction qui prévient l'utilisateur qu'une question va lui être posée

void question_display(){

    printf("Voici votre question :\n\n");
}

// Affichage qui prévient l'utilisateur qu'il a choisi "carré", 4 propositions vont lui être faite
void carre_display(){

    printf("Vous avez choisi carré. Voici les 4 propositions :\n");
}

//Affichage qui prévient l'utilisateur qu'il a choisi "duo", 2 propositions lui seront faite

void duo_display(){

    printf("Vous avez choisi duo. Voici vos 2 propositions :\n");
}

// Affichage qui prévient l'utilisateur qu'il a choisi "cash", il devra taper la réponse dans le terminal

void cash_display(){

    printf("Vous avez choisi cash. Saisissez votre réponse en faisant attention aux fautes.\n");
}

int score = 0;

int main(){

    int i = 0, user_input;

    start_display();
    rappel_regles();
    question_display();

    for(i = 0; i < NB_QUESTIONS; i++){

        printf("%s\n", questions[i]);
        printf("Vous avez 3 choix : Duo, Carré ou Cash. Que choisissez vous ?\n\n");
        fgets(user_input,sizeof(user_input), stdin);
        scanf("voir : %s\n", user_input);
        // Pour récupérer un string, utiliser fgets. Pour récupérer un int, utiliser scanf pour l'instant
        // fgets -> strcmp pour vérifier s'il a tapé duo, carré ou cash
        // if user choisis duo, appeler fonction duo_display(), carré = carre_display, cash = cash_display pour qu'il printf %s choix[i] 
        // else if user choisi cash, appeler fonction cash_display;
        // (if) appeler fonction() en fonction de si l'utilisateur choisi carré, duo ou cash
        // fgets 
        // EXEMPLE fgets : fgets(user_input,sizeof(user_input),stdin);
        // Utiliser rand() pour les choix du carré et duo ?
        printf("Suspens...\n\n");

    }



    end_display();

    return 0;
}

/**
 * if, else if, else if, else
 * 
 */