#include <stdio.h>
#include <math.h>

#define CURRENCY_VARIATIONS 6

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char: "char", \
    default: "unknown")

typedef struct Dinero {
    const int cedulas[CURRENCY_VARIATIONS];
    const float moedas[CURRENCY_VARIATIONS];
} Dindin;

/*
typedef enum {
  CASH = 1,
  COIN = 2
} CashCoin;
*/


int main() {
    
    // Inicializando a struct
    Dindin d = {
        .cedulas = {100, 50, 20, 10, 5, 2},
        .moedas = {1.0, 0.50, 0.25, 0.10, 0.05, 0.01}
    };

    float pgmto = 0.0;

    scanf("%f",&pgmto);
    
    int cash = (int) pgmto;
    float coin = pgmto - cash + 0.001;

    puts("NOTAS:");
    int sumNota = 0;
    for(int i = 0 ; i < CURRENCY_VARIATIONS; i++)
    {
        int cedula = d.cedulas[i];
        int troco = cash/cedula;
        float mask = (float) cedula;
        printf("%d nota(s) de R$ %.2f\n",troco,mask);
        sumNota += troco * cedula;
        cash -= troco * cedula;
    }
    
    int unidade = (int) (pgmto - sumNota);

    puts("MOEDAS:");
    printf("%d moeda(s) de R$ %.2f\n",unidade,d.moedas[0]);
    for(int i = 1 ; i < CURRENCY_VARIATIONS; i++)
    {
        float moeda = d.moedas[i];
        float troco = coin - moeda;
        int qtd = 0;
        
        while(coin > moeda)
        {
            coin -= moeda;
            qtd++;
        }
        
        printf("%d moeda(s) de R$ %.2f\n",qtd,d.moedas[i]);
    }
    

    return 0;
}
