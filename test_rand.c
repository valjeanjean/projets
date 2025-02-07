#include <stdio.h>
#include <unistd.h> // Pour la fonction sleep()

#define browse_table 4

int main() {
    

    /* OU alors faire un char*nom_tableau
    pour qu'en sorte que nom_tableau[0] = "pIlE";
                         nom_tableau[1] = "PiLe"; etc...
                         et donc user_input[i] == nom_tableau[0][i]?
                         car on compare la ligne 0, et chaque caractère dans chaque colonne 

    */



   /**
    * 
        Parce que sinon jpeux faire char* nom_tableau[] = 
        "PiLe",
        "pIlE",
        "PILE";

        Et le comparer à user_input mais si jfais if( user_input[i] == nom_tableau[0]) ça va pas marcher non?
        ou alors ptet if( user_input[i] == nom_tableau[0][i])
    * 
    * 
    */
    char user_input[255];
    //char comparaison[] = "pIlE";
    char * comparaison[browse_table] = {
            "pile\n",
            "PiLe\n",
            "PILE\n",
            "pIlE\n"

    };
    int i = 0, is_match = 0;

    printf("userinput\n");
    fgets(user_input, sizeof(user_input), stdin);
        //printf("%s\n", comparaison[0]);
        //printf("%s\n", user_input);
        //printf("%s\n", user_input[i]);

    /*while(i < 4){

        printf("tableau : %d\n",comparaison[0][i]);
        printf("user_input : %d\n", user_input[i]);
        i++;
    }*/
   
    for(i = 0; i < browse_table; i++){

        if((int)user_input[i] == (int)comparaison[0][i]){// || user_input[i] == comparaison[1][i] || user_input[i] == comparaison[2][i] || user_input[i] == comparaison[3][i]){

            is_match = 1;
            //printf("user_input = %s\t valeur = %s\n", user_input[i], comparaison[0][i]);
        }
    }

    /* Si if(is_match = 1) ça veut dire que les caractères correspondent à la réponse, donc on print que c'est bon
    
        Mais si if(is_match = 0) ça veut dire qu'au moins un caractère ne correspond pas, dans le if d'en haut is_match passe à 0 et un if(0) correspond à un false,
        on passe donc directement au else             */
    if(is_match){

        printf("Les caractères correspondent!\n");

    }else{

        printf("NOn!\n");
    }
    


    return 0;
}