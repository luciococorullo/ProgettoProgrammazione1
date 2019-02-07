#include <stdio.h>
#include <string.h>

void benvenuto();
void displayfrase(char *frase);
void grazie();

#define  MAXW 20
#define  CON  5
#define  MAXF 100
#define  SPAZIO " "

typedef struct parola{
    char termine[MAXW];
    char contrario[CON][MAXW];
}structparola;

static structparola paroledizionario[]={
    //lettera A
    {"alzare",{"abbassare","calare"}},
    {"aprire",{"chiudere","bloccare"}},
    {"allegro",{"triste","serio"}},
    //lettera B
    {"bello",{"orrendo","brutto"}},
    {"brutto",{"bello","carino"}},
    {"bullismo",{"educazione","rispetto"}},
    //lettera C
    {"complicato",{"facile","semplice"}},
    {"costoso",{"economico","leggero"}},
    //lettera D
    {"distante",{"vicino","prossimo"}},
    //lettera E
    {"esigente",{"superficiale","leggero"}},
    //lettera F
    {"faticoso",{"piacevole","spicciativo"}},
    {"felice",{"triste","malinconico"}},
    //lettera G
    {"grande",{"piccolo","irrilevante"}},
    {"gustoso",{"disgustoso","brutto"}},
    //lettera I
    {"irregolare",{"regolare","proporzionato"}},
    //lettera L
    {"leggero",{"pesante","faticoso"}},
    {"lecito",{"illecito","ingiusto"}},
    //lettera M
    {"morbido",{"duro","solido"}},
    {"magro",{"grasso","obeso"}},
    {"magra",{"grassa","obesa"}},
    //lettera N
    {"normale",{"strano","diverso"}},
    //lettera O
    {"orrendo",{"bello","piacevole"}},
    {"ordinato",{"disordinato",""}},
    //lettera P
    {"partire",{"tornare","venire"}},
    {"prezioso",{"comune","banale"}},
    {"pazzo",{"normale","sano"}},
    {"pesante",{"lieve","semplice"}},
    //lettera Q
    {"qualificato",{"incompetente","inesperto"}},
    //lettera R
    {"rapido",{"lento","calmo"}},
    //lettera S
    {"spegnere",{"accendere","avviare"}},
    //lettera T
    {"tardi",{"presto","anticipo"}},
    //lettera U
    {"uscita",{"ingresso","entrata"}},
    //lettera V
    {"veloce",{"lento","pigro"}},
    //lettera Z
    {"zuccherato",{"amaro","salato"}}
    };

int main(){

    char frase[MAXF];
    char *parola_frase;
    int risposta;
    int i=0,k,j;
    char *parole[100];
    char separatori[] = {' ','\0','\n'};
    int numero_parole = sizeof(paroledizionario)/sizeof(paroledizionario[0]);
    
    benvenuto();
    
    printf("Inserisci la frase: ");
    fgets(frase, 4096, stdin);
    parola_frase = strtok(frase, separatori);
    
    printf("============================================\n\n");

    while (parola_frase != NULL) {
        parole[i++] = strdup(parola_frase);
        parola_frase = strtok(NULL," \n");
    }
    
    
    strcpy(frase, "");
  
    
    for (k = 0; k < i; k++) {
        for (j = 0; j < numero_parole; j++) {

            if (strcmp(parole[k], paroledizionario[j].termine) == 0){

            printf("La parola %s e' presente nel dizionario,vuoi ricercare il contrario?\n",parole[k]);  
            restart: printf("Premi 1 per si e 0 per no ---->");
            scanf("%d",&risposta);
            printf("\n");

            switch(risposta){

                case 1:
                strcpy(parole[k], paroledizionario[j].contrario[0]);
                break;

                case 0:
                break;

                default:
                goto restart;
            }
            }
            
        }
        strcat(frase, parole[k]);
        strcat(frase, " ");
    }
    displayfrase(frase);
    grazie();

    return 0;
}


void benvenuto(){
    printf("\n\n============================================\n");
    printf("|| Benvenuto nel dizionario dei contrari  ||\n");
    printf("============================================\n\n\n");
}
void displayfrase(char *frase){
    printf("\nLa frase ora e':\n");
    printf("%s\n", frase);
    printf("===============================================\n\n");
}
void grazie(){
    printf("\n\n===========================================================\n");
    printf("|| Grazie per aver utilizzato il dizionario dei contrari!||\n");
    printf("===========================================================\n\n\n");
}
