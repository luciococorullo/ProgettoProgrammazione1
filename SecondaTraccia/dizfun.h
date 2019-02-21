#ifndef DIZFUN_H
#define DIZFUN_H

#include <stdio.h>
#include <string.h>

void benvenuto();
void displayfrase(char *frase);
void grazie();

#define  MAXW 20        //definisco il numero massimo di caratteri che puo contenere una parola
#define  CON  5         //definisco il numero massimo di contrari che puo avere ogni parola
#define  MAXF 100       //definisco il numero massimo di caratteri che puo contenere una frase
#define  SPAZIO " " 

typedef struct parola{  //creo la struct parola che contiene il termine ed i rispettivi contrari
    char termine[MAXW];
    char contrario[CON][MAXW];
}structparola;

static structparola paroledizionario[]={    //inserisco le parole in paroledizionario che sara' un array di tipo structparola definito precedentemente
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
    {"ordinato",{"disordinato","diso"}},
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


#endif // DIZ_FUN_H
