#ifndef AUTOFUN_H
#define AUTOFUN_H

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

#endif // AUTO_FUN_H_INCLUDED
