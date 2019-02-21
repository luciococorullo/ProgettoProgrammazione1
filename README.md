# ProgettoProgrammazione1
sviluppo software della traccia dell'esame di programmazione 1

PROGETTO D’ESAME DI LABORATORIO
1. Auto scontro.
Si supponga di avere quattro macchine al centro dei quattro lati opposti di una griglia
(vedi figura). Le macchine possono muoversi in una della quattro posizioni vicine.
La griglia è formata da mura esterne ed è di 8x8 caselle.
Si supponga che ogni macchina si muova seguendo le seguenti regole:
o La macchina 1 può andare a destra con probabilità 20% a sinistra con
probabilità del 10%, in avanti con probabilità del 30 % e indietro con
probabilità del 40%.
o La macchina 2 osserva i movimenti della macchina 1 e con una probabilità
del 30% sceglie la stessa direzione.
o La macchina 3 può andare a destra con probabilità 30% a sinistra con
probabilità del 20%, in avanti con probabilità del 5 % e indietro con
probabilità del 45%.
o La macchina 4 osserva le direzioni delle altre auto e si sposta nella direzione
di minima distanza (usare un algoritmo ricorsivo per calcolare la minima
distanza).
La simulazione finisce quando si verifica uno scontro tra almeno due macchine.
L’algoritmo usa la function rand() in stdlib per generare numeri casuali: si
ricorda che, per esempio, se numero_casuale è un int, la chiamata
numero_casuale=rand()%11; genera un numero casuale intero (distribuzione
uniforme) nell’insieme (0,1,2,3,4,5,6,7,8,9,10). Usare sempre la srand() per rendere
automatica la scelta iniziale del seed della sequenza di numeri casuali. Effettuare almeno
5 simulazioni. 




2. Dizionario dei contrari
Si vuole simulare la gestione di un dizionario dei contrari. Il dizionario è indicizzato
tramite le lettere dell’alfabeto ed ogni parola contiene i suoi contrari (massimo 5).
Permettere all’utente di:
• Inserisce una frase dove ogni parola è separata da uno spazio
Il programma riconosce ogni singola parola e chiede all’utente se vuole cercare nel
dizionario il suo contrario. Se la risposta è affermative il programma sostituisce la
parola.
Provvedere all’implementazione dell’algoritmo che data una frase ritorna una nuova
frase con i contrari al posto delle parole decise dall’utente. Effettuare almeno 3 test.
