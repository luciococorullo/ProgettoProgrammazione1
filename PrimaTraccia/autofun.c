#include "autofun.h"


void stampagriglia(char griglia[L_GRL][A_GRL]){

    int i;
    int j;

   for(i = 0; i <= 2 * A_GRL; i++){
        //ogni riga ha spazio vuoto e | e poi spazio vuoto, quindi avremo tre posizioni

        //printa l'asterisco alla sinistra della tabella
        if(i % 2 != 0)
            printf("~");

        for(j = 0; j <= 2 * L_GRL; j++){
            //printa *** nelle posizioni pari
            if(i%2==0)//se la posizione iesima / 2 da resto zero
            {
                if(j==0)//se j = 0 printa spazio
                    printf(" ");
                if(j%2==0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else//altrimenti mi trovo in posizione dispari e printa ***
                    printf("***");
            }
            //printa |  nelle posizioni dispari
            else{
                //se pari printa |
                if(j % 2== 0)
                    printf("|");
                else
                    printf(" %c ", griglia[i/2][j/2]);//altrimenti tre spazi
            }
        }

        //istruzione di fine riga quindi se dispari stampa
        if(i%2!=0)
            printf("~");

        printf("\n");
    }
}

boolean scontro(macchine *automobili){


    int i,j;
    boolean scontro = falso;
    //controllo se due auto occupano la stessa posizione
    for(i=0;i < TOT_AUTO+1;i++){
    for(j=0;j<TOT_AUTO+1;j++){
        if(i!=j && automobili[i].x == automobili[j].x && automobili[i].y == automobili[j].y){
            printf("\nLa macchina %c e la macchina %c si sono scontrate.\n",automobili[i].simbolo,automobili[j].simbolo);
            scontro=vero;
            return scontro;
        }
        }
    }
    return scontro;
}
int nrnd(){
    srand(time(NULL));  //funzione per cambiare il seed di generazione del numero pseudocasuale

    return 1+rand()%100;    //genero un numero casuale da 1 a 100
}
int gestione(int numerocasuale, int p_1, int p_2, int p_3){

    int prima=p_1;
    int seconda=p_1+p_2;
    int terza=p_1+p_2+p_3;

    if(numerocasuale<prima)
    return 1;               //se il numero casuale e' minore della prima percentuale ritorna 1

    else if(numerocasuale>= prima && numerocasuale<=seconda)
    return 2;              //se il numero casuale e' minore della prima e della seconda percentuale ritorna 2

    else if(numerocasuale>=seconda && numerocasuale<=terza)
    return 3;              //se il numero casuale e' minore della prima, della seconda e della terza percentuale ritorna 3

    else
    return 4;              //se e' maggiore della somma di tutte ritorna 4
}


void grazie(){
printf("\n\n========================================================\n");
printf("||        Grazie per aver giocato!                    ||\n");
printf("========================================================\n\n\n");
}

void reset(macchine *automobili){   //ripristina le percentuali di movimento della seconda auto
    automobili[1].avanti=25;
    automobili[1].destra=25;
    automobili[1].sinistra=25;
    automobili[1].indietro=25;
}

double distanza(macchine *automobili,int i){ //ritorna la distanza tra la macchina i e la quarta macchina
    return sqrt((pow(automobili[i].x - automobili[3].x, 2) + pow(automobili[i].y - automobili[3].y, 2)));
}
double distanzamin(double distanze[],int n){    //funzione ricorsiva che seleziona la distanza minima dall'array di distanze 

	double min;
    if(n==1)                                    //caso base
    return distanze[0];
    min=distanzamin(&distanze[1],n-=1);         //chiamata della funzione decrementando n
    if(min<distanze[0]){                        //se la distanza ottenuta dall'output della funzione ricorsiva e' minima la ritorna 
    return min;                                 
	}else{
	return distanze[0];
}
}

int macmin(double distanze[],double minima){ //funzione che ritorna l'indice della macchina alla minima distanza
int k;
int mac=0;

    for(k=0;k<3;k++){
    if(distanze[k]==minima){                   //se la distanza della macchina k e' la distanza minima ritorna k 
    mac=k;
    }
    }
return mac;
}

void benvenuto(){
    printf("\n\n============================================\n");
    printf("||     Benvenuto nell'autosconto          ||\n");
    printf("============================================\n\n\n");
    }

void svuota(char griglia[L_GRL][A_GRL]){    //funzione che stampa uno spazio in ogni casella della griglia svuotandola
    int i;
    int j;
    for(i=0;i<A_GRL;i++){
       for(j=0;j<L_GRL;j++)
       griglia[i][j]=' ';
    }
}

int gestionemacx(macchine *automobili,int macx){    //funzione che gestisce la direzione della quarta macchina


    if(automobili[macx].y==automobili[3].y){        //se le macchine sono sulla stessa y si muovera' sull'asse delle x
    if(automobili[macx].x>automobili[3].x){
    return 8;
    }
    else if(automobili[macx].x<automobili[3].x){
    return 7;
    }
    }

    else if(automobili[macx].x==automobili[3].x){   //se le macchine sono sulla stessa x si muovera'sulle y
    if(automobili[macx].y>automobili[3].y){
    return 5;
    }
    else if(automobili[macx].y<automobili[3].y){
    return 6;
    }
    }
    else if(automobili[macx].x>automobili[3].x){    //in generale la macchina 4 preferira' muoversi principalmente sulle x
    return 8;
    }
    else if(automobili[macx].x<automobili[3].x){
    return 7;
    }

    return 0;
}
