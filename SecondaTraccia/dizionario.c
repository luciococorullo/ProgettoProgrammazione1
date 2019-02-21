#include "diz_fun.h"
int main(){

    char frase[MAXF];
    char *parola_frase;
    int risposta;
    int i=0,k,j;
    char *parole[100];
    char separatori[] = {' ','\0','\n'};                                        //dichiaro un array di separatori
    int numero_parole = sizeof(paroledizionario)/sizeof(paroledizionario[0]);   //questo corrisponde al numero delle parole presenti nel dizionario



    benvenuto();                                                                //utilizzo la function di benvenuto che printa la grafica iniziale

    printf("Inserisci la frase: ");
    fgets(frase, 4096, stdin);
    parola_frase = strtok(frase, separatori);                                   //spezzetto la frase dai separatori e metto la parola in "parola_frase"

    printf("============================================\n\n");

    while (parola_frase != NULL) {                                              //fino a quando ci sono parole nella frase
        parole[i++] = strdup(parola_frase);                                     //metto le parole della frase in un array di parole
        parola_frase = strtok(NULL," \n");
    }


    strcpy(frase, "");


    for (k = 0; k < i; k++) {
        for (j = 0; j < numero_parole; j++) {

            if (strcmp(parole[k], paroledizionario[j].termine) == 0){       //uso la function strcmp per confrontare la parola e il dizionario e vedere se la parola e' presente

            printf("La parola %s e' presente nel dizionario,vuoi ricercare il contrario?\n",parole[k]);
            printf("Premi 1 per si e 0 per no ---->");
            scanf("%d",&risposta);
            printf("\n");

            switch(risposta){

                case 1:
                strcpy(parole[k], paroledizionario[j].contrario[0]);        //se la parola e'presente e l'utente acconsente sostituisco la parola con il contrario presente nel dizionario
                break;

                case 0:                                                     //se l'utente non vuole non sostituisco la parola
                break;

                default:
                printf("Comando sconosciuto, la parola non verra' modificata\n");
            }
            }

        }
        strcat(frase, parole[k]);                                           //ricostruisco la frase precedentemente frammentata
        strcat(frase, " ");
    }
    displayfrase(frase);                                                     //funzione che printa la frase
    grazie();                                                                //funzione che printa il ringraziamento finale

    return 0;
}

