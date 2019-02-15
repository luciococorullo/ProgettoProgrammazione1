#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define L_GRL       8                     // larghezza della griglia, modificabile
#define A_GRL       8                     // altezza della griglia, modificabile
#define TOT_AUTO    3                     // quantita' d'auto presenti nella griglia
#define MAXN        15                    // numero massimo di lettere del nome

typedef enum {destra=1,sinistra,avanti,indietro}direzione;
typedef enum {falso,vero} boolean;        //creazione del tipo boleano che gestisce la presenza di scontri

typedef struct Macchine {

    char nome[MAXN];
    int x;
    int y;
    char simbolo;
    int destra;
    int sinistra;
    int avanti;
    int indietro;

} macchine;

 macchine automobili [] = {
     {"Macchina 1",3,0,'W',20,10,30,40},
     {"Macchina 2",0,3,'S',25,25,25,25},
     {"Macchina 3",3,7,'A',30,20,45,5},
     {"Macchina 4",7,3,'D',0,0,0,0},
 };

void benvenuto();                         //funzione che stampa il messaggio di benvenuto
void svuota(char griglia[L_GRL][A_GRL]);  //funzione che printa spazi nella griglia
void stampagriglia(char [L_GRL][A_GRL]);  //funzione che stampa la griglia con le macchine
void reset(macchine *);                   //funzione che ripristina i valori della seconda macchina
boolean scontro(macchine *);              //funzione che gestisce la presenza di eventuali scontri
int nrnd();                               //funzione che genera il numero casuale sul quale si basa il movimento delle macchine
int gestione(int , int , int , int );     //funzione che gestisce l'assegnamento del numero casuale
double distanza(macchine *,int);          //funzione che calcola la distanza tra la macchina 4 e le altre macchine
double distanzamin(double[],int);         //funzione ricorsiva per il calcolo della distanza minima
int macmin(double [],double );            //funzione che ritorna quale macchina si trova alla distanza minima dalla macchina 4
int gestionemacx(macchine *,int );
void grazie();                            //funzione che stampa il ringraziamento




 int main() {
    int i,j;
    int n=3;
    char griglia[A_GRL][L_GRL];
    double distanze[n];
    double minima;


    svuota(griglia);
                                         //posiziono le macchine nella griglia
    griglia[3][0] = automobili[0].simbolo;
    griglia[0][3] = automobili[1].simbolo;
    griglia[3][7] = automobili[2].simbolo;
    griglia[7][3] = automobili[3].simbolo;


    printf("\n");                       //creo spazio dal bordo
    printf(" ");                        //creo spazio


    benvenuto();                        //printo il messaggio di benvenuto

    stampagriglia(griglia);             //stampo la griglia di partenza
    printf("\nQuesta e' la griglia di partenza\n==========================================\n\n\n");
    boolean scontri=falso;              //dichiaro una variabile scontri di tipo boolean e la inizializzo a falso

    while(!scontri){                    //ciclo che si ripete fino a quando non si verifica uno scontro

    for(i=0;i<TOT_AUTO;i++){            //ciclo for che gestisce le prime tre macchine

        int turno;
        turno += 1;                      

        int numerocasuale;
        numerocasuale=nrnd();           //utilizzo la funzione nrnd per generare un numero casuale intero

        reset(automobili);              //ripristino le percentuali di movimento della seconda macchina

        int direzionemacchine;          //dichiaro un intero che assumera' valori da 1 a 4 per gestire le 4 direzioni che puo prendere la macchina
        direzionemacchine=gestione(numerocasuale,automobili[i].destra,automobili[i].sinistra,automobili[i].avanti);
                                        //assegno questa variabile alla funzione di gestione 

        distanze[i]=distanza(automobili,i);
                                        //creo un array che contiene le distanze tra la macchina i e la quarta macchina
        switch (direzionemacchine){     //switch sull'output della funzione di gestione che gestisce le direzioni

        case avanti:
        if(automobili[i].x>0){          //verifico se e' possibile lo spostamento o se la macchina valicherebbe il muro
        if(i==0){
        automobili[1].avanti=30;        //se la prima auto prende questa direzione modifico la probabilita' della seconda macchina di prendere la stessa direzione al 30%
        }
            griglia[automobili[i].x][automobili[i].y] = ' ';
            automobili[i].x-=1;         //metto uno spazio nella vecchia posizione della macchina e incremento la sua x
            griglia[automobili[i].x][automobili[i].y] = automobili[i].simbolo;
                                        //printo il simbolo dell'auto nella nuova posizione
            printf("La macchina %c si e' spostata in avanti\n",automobili[i].simbolo);
            scontri = scontro(automobili);
        }else                           //verifico la presenza di eventuali scontri
        printf("La macchina %c e' rimasta ferma\n",automobili[i].simbolo);
        break;                          //se la macchina non puo spostarsi rimane ferma


        case indietro:
        if(automobili[i].x<A_GRL-1){
        if(i==0){
        automobili[1].indietro=30;
        }
            griglia[automobili[i].x][automobili[i].y] = ' ';
            automobili[i].x+=1;
            griglia[automobili[i].x][automobili[i].y] = automobili[i].simbolo;
            printf("La macchina %c si e' spostata indietro\n",automobili[i].simbolo);
            scontri = scontro(automobili);
        }else
        printf("La macchina %c e' rimasta ferma\n",automobili[i].simbolo);
        break;


        case destra:
        if(automobili[i].y<L_GRL-1){
        if(i==0){
        automobili[1].destra=30;
        }
            griglia[automobili[i].x][automobili[i].y] = ' ';
            automobili[i].y+=1;
            griglia[automobili[i].x][automobili[i].y] = automobili[i].simbolo;
            printf("La macchina %c si e' spostata a destra\n",automobili[i].simbolo);
            scontri = scontro(automobili);
        }else
        printf("La macchina %c e' rimasta ferma\n",automobili[i].simbolo);
        break;


        case sinistra:
        if(i==0){
        automobili[1].sinistra=30;
        }
        if(automobili[i].y>0){
            griglia[automobili[i].x][automobili[i].y] = ' ';
            automobili[i].y-=1;
            griglia[automobili[i].x][automobili[i].y] = automobili[i].simbolo;
            printf("La macchina %c si e' spostata a sinistra\n",automobili[i].simbolo);
            scontri = scontro(automobili);
        }else
        printf("La macchina %c e' rimasta ferma\n",automobili[i].simbolo);
        break;

        default:
        return 0;
        }


    }


    minima=distanzamin(distanze,n);      //utilizzo la funzione ricorsiva distanza min per calcolare quale e' la distanza minima con la macchina numero 4       

    int macx;                            //dichiaro una variabile macx che corrisponde all'auto alla distanza minima dalla quarta auto
    macx=macmin(distanze,minima);        //assegno la variabile macx all'output della funzione macmin che ritorna quale e' la macchina alla distanza minima

    int gest;
    gest=gestionemacx(automobili,macx);  //assegno la variabile gest all'output della funzione gestionemacx che gestisce la direzione della quarta macchina

    switch(gest){

    case 5:
    if(automobili[3].y<L_GRL-1){
    griglia[automobili[3].x][automobili[3].y] = ' ';
    automobili[3].y+=1;
    griglia[automobili[3].x][automobili[3].y] = automobili[3].simbolo;
    printf("La macchina %c si e' spostata a destra\n",automobili[3].simbolo);
    scontri = scontro(automobili);
    }else
    printf("La macchina %c e' rimasta ferma\n",automobili[3].simbolo);
    break;

    case 6:
    if(automobili[i].y>0){
    griglia[automobili[3].x][automobili[3].y] = ' ';
    automobili[3].y-=1;
    griglia[automobili[3].x][automobili[3].y] = automobili[3].simbolo;
    printf("La macchina %c si e' spostata a sinistra\n",automobili[3].simbolo);
    scontri = scontro(automobili);
    }else
    printf("La macchina %c e' rimasta ferma\n",automobili[3].simbolo);
    break;

    case 7:
    if(automobili[3].x>0){
    griglia[automobili[3].x][automobili[3].y] = ' ';
    automobili[3].x-=1;
    griglia[automobili[3].x][automobili[3].y] = automobili[3].simbolo;
    printf("La macchina %c si e' spostata in avanti\n",automobili[3].simbolo);
    scontri = scontro(automobili);
    }else
    printf("La macchina %c e' rimasta ferma\n",automobili[3].simbolo);
    break;


    case 8:
    if(automobili[3].x<A_GRL-1){
    griglia[automobili[3].x][automobili[3].y] = ' ';
    automobili[3].x+=1;
    griglia[automobili[3].x][automobili[3].y] = automobili[3].simbolo;
    printf("La macchina %c si e' spostata indietro\n",automobili[3].simbolo);
    scontri = scontro(automobili);
    }else
    printf("La macchina %c e' rimasta ferma\n",automobili[3].simbolo);
    break;


    default:
    break;
    }


    printf("\nla distanza minima e' %f con la macchina %d\n",minima,macx);
    printf("\n\n==========================================\n\n\n");


    stampagriglia(griglia);

    int scelta;
    printf("\nPronto per il prossimo turno?Premi 1\n");
    scanf("%d",&scelta);
    }

    grazie();
    return 0;
}


void stampagriglia(char griglia[L_GRL][A_GRL]){

    int i;
    int j;

   for(i = 0; i <= 2 * A_GRL; i++){ // per i che è uguale a 0 che va a 2 che moltiplica il numero di righe
        //ogni riga ha spazio vuoto e | e poi spazio vuoto, quindi avremo tre posizioni 0-1-2

        //printa l'asterisco alla sinistra della tabella
        if(i % 2 != 0) // se faccio l'elemento iesimo / 2 avrò reso zero per 0 e 2 ma non per 1 quindi quando non è vero sono centrato
            printf("~");

        for(j = 0; j <= 2 * L_GRL; j++){//per j che va da 0 a 2 che moltiplica nr. colonne(16), incrementa

            //printa --- nelle posizioni pari
            if(i%2==0)//se la posizione iesima / 2 da resto zero
            {
                if(j==0)//se j = 0 printa spazio
                    printf(" ");
                if(j%2==0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else//altrimenti mi trovo in posizione dispari e printa ---
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

        //istruzione di fine riga quindi se dispari stampa l'asterisco
        if(i%2!=0)
            printf("~");

        printf("\n");
    }
}

boolean scontro(macchine *automobili){


    int i,j;
    boolean scontro = falso;

    for(i=0;i < TOT_AUTO;i++){
    for(j=0;j<TOT_AUTO;j++){
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
    srand(time(NULL));

    return 1+rand()%100;
}
int gestione(int numerocasuale, int p_1, int p_2, int p_3){

    int prima=p_1;
    int seconda=p_1+p_2;
    int terza=p_1+p_2+p_3;

    if(numerocasuale<prima)
    return 1;

    else if(numerocasuale>= prima && numerocasuale<=seconda)
    return 2;

    else if(numerocasuale>=seconda && numerocasuale<=terza)
    return 3;

    else
    return 4;
}


void grazie(){
printf("\n\n========================================================\n");
printf("||        Grazie per aver giocato!                    ||\n");
printf("========================================================\n\n\n");
}

void reset(macchine *automobili){
    automobili[1].avanti=25;
    automobili[1].destra=25;
    automobili[1].sinistra=25;
    automobili[1].indietro=25;
}

double distanza(macchine *automobili,int i){
    return sqrt((pow(automobili[i].x - automobili[3].x, 2) + pow(automobili[i].y - automobili[3].y, 2)));
}
double distanzamin(double distanze[],int n){

	double min;
    if(n==1)
    return distanze[0];
    min=distanzamin(&distanze[1],n-=1);
    if(min<distanze[0]){
    return min;
	}else{
	return distanze[0];
}
}

int macmin(double distanze[],double minima){
int k;
int mac;

    for(k=0;k<3;k++){
    if(distanze[k]==minima){
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

void svuota(char griglia[L_GRL][A_GRL]){
    int i;
    int j;
    for(i=0;i<A_GRL;i++){
       for(j=0;j<L_GRL;j++)
       griglia[i][j]=' ';
    }
}

int gestionemacx(macchine *automobili,int macx){


    if(automobili[macx].y==automobili[3].y){
    if(automobili[macx].x>automobili[3].x){
    return 8;
    }
    else if(automobili[macx].x<automobili[3].x){
    return 7;
    }
    }

    else if(automobili[macx].x==automobili[3].x){
    if(automobili[macx].y>automobili[3].y){
    return 5;
    }
    else if(automobili[macx].y<automobili[3].y){
    return 6;
    }
    }
    else if(automobili[macx].x>automobili[3].x){
    return 8;
    }
    else if(automobili[macx].x<automobili[3].x){
    return 7;
    }
    else if(automobili[macx].y>automobili[3].y){
    return 5;
    }
    else if(automobili[macx].y<automobili[3].y){
    return 6;
    }
}
