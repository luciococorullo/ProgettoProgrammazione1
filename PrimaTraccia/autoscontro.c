#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define L_GRL       8 // larghezza della griglia, modificabile
#define A_GRL       8 // altezza della griglia, modificabile
#define TOT_AUTO    4 // quantita' d'auto presenti nella griglia
#define MAXN        15// numero massimo di lettere del nome

typedef enum {destra=1,sinistra,avanti,indietro}direzione;
typedef enum {falso,vero} boolean;

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
     {"Macchina 4",7,3,'D',25,25,25,25},
 };

void benvenuto();
void stampagriglia(char [L_GRL][A_GRL]);
void reset(macchine *);
boolean scontro(macchine *);
int nrnd();
int gestione(int , int , int , int );
double distanza(macchine *,int);
double distanzamin(double[],int);
void grazie();

 int main() {
    int i,j;
    int n=3;
    char griglia[A_GRL][L_GRL];
    double distanze[n];
    double minima;

    for(i=0;i<A_GRL;i++){
       for(j=0;j<L_GRL;j++)
       griglia[i][j]=' ';
    }

    griglia[3][0] = automobili[0].simbolo;
    griglia[0][3] = automobili[1].simbolo;
    griglia[3][7] = automobili[2].simbolo;
    griglia[7][3] = automobili[3].simbolo;

    printf("\n");//creo spazio dal bordo
    printf(" ");//creo spazio



    benvenuto();
    stampagriglia(griglia);
    boolean scontri=falso;

    while(!scontri){

    for(i=0;i<TOT_AUTO;i++){

        int turno;
        turno += 1;

        int numerocasuale;
        numerocasuale=nrnd();

        reset(automobili); //ripristino le percentuali di movimento della seconda macchina

        int direzionemacchine;
        direzionemacchine=gestione(numerocasuale,automobili[i].destra,automobili[i].sinistra,automobili[i].avanti);


        distanze[i]=distanza(automobili,i);

        switch (direzionemacchine){

        case avanti:
        if(automobili[i].x>0){
        if(i==0){
        automobili[1].avanti=30;
        }
            griglia[automobili[i].x][automobili[i].y] = ' ';
            automobili[i].x-=1;
            griglia[automobili[i].x][automobili[i].y] = automobili[i].simbolo;
            printf("La macchina %c si e' spostata in avanti\n",automobili[i].simbolo);
            scontri = scontro(automobili);
        }else
        printf("La macchina %c e' rimasta ferma\n",automobili[i].simbolo);
        break;


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
    printf("\n\n==========================================\n\n\n");

    minima=distanzamin(distanze,n);
    printf("\nla distanza minima e' %f\n",minima);
    
    stampagriglia(griglia);

    int scelta;
    printf("\nPronto per il prossimo turno?Premi 1\n");
    scanf("%d",&scelta);
    }

    grazie();
    return 0;
}

void benvenuto(){
        printf("\n\n============================================\n");
    printf("||     Benvenuto nell'autosconto          ||\n");
    printf("============================================\n\n\n");
}
void stampagriglia(char griglia[L_GRL][A_GRL]){

    int i;
    int j;

   for(i = 0; i <= 2 * A_GRL; i++){ // per i che è uguale a 0 che va a 2 che moltiplica il numero di righe
        //ogni riga ha spazio vuoto e | e poi spazio vuoto, quindi avremo tre posizioni 0-1-2

        //printa numero alla sinistra della tabella
        if(i % 2 != 0) // se faccio l'elemento iesimo / 2 avrò reso zero per 0 e 2 ma non per 1 quindi quando non è vero sono centrato
            printf("%d",(i/2)+1);//quindi stampo i/2 + 1 altrimenti salta di due posizioni a causa dell'interazione del ciclo

        for(j = 0; j <= 2 * L_GRL; j++){//per j che va da 0 a 2 che moltiplica nr. colonne(16), incrementa

            //printa --- nelle posizioni pari
            if(i%2==0)//se la posizione iesima / 2 da resto zero
            {
                if(j==0)//se j = 0 printa spazio
                    printf(" ");
                if(j%2==0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else//altrimenti mi trovo in posizione dispari e printa ---
                    printf("---");
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

        //istruzione di fine riga quindi se dispari stampa 1 o valori successivi
        if(i%2!=0)
            printf("%d",(i/2)+1);

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

    return rand()%100;
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
    min=distanzamin(&distanze[1],n-1);
    if(min<distanze[0]){
    return min;
	}else{
	return distanze[0];
}
}
