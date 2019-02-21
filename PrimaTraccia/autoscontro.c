#include "autofun.h"


 macchine automobili [] = {         //dichiaro un array di macchine denominato automobili nel quale inserisco tutti i dati relativi a ciascuna macchina
     {"Macchina 1",3,0,'W',20,10,30,40},    //il primo sará il nome, il secondo la sua x, il terzo e'la y, poi abbiamo il simbolo che la contraddistingue sulla griglia ed infine le quattro percentuali di movimento nelle quattro direzioni
     {"Macchina 2",0,3,'S',25,25,25,25},
     {"Macchina 3",3,7,'A',30,20,45,5},
     {"Macchina 4",7,3,'D',0,0,0,0},
 };

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
    printf("\n\n==========================================\n\n\n");


    stampagriglia(griglia);

    int scelta;
    printf("\nPronto per il prossimo turno?Premi 1\n"); //ho inserito un interazione con l'utente in modo che passi del tempo tra un turno e l'altro e la funzione srand possa generare un seed diverso da quello vecchio
    scanf("%d",&scelta);
    }

    grazie();                                           //stampa i ringraziamenti quando il gioco e'  finito
    return 0;
}


