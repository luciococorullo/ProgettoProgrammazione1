#include "dizfun.h"

//semplici funzioni che stampano il benvenuto, la frase modificata o meno ed il ringraziamento finale

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
