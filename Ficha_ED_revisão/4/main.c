#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int main() {
    int nReg;
    printf("Diga o numero de registros que deseja inserir: ");
    scanf("%d", &nReg);

    Indiv *ListIndiv = (Indiv *)malloc(nReg * sizeof(Indiv));
    
    for (int i = 0; i < nReg; i++)
    {
        printf("Insira o numero do cartao de cidadao: ");
        scanf("%d", &(ListIndiv + i)->numeroCartaoCidadao);
        printf("Insira a altura: ");
        scanf("%f", &(ListIndiv + i)->altura);
        printf("Insira a massa: ");
        scanf("%f", &(ListIndiv + i)->massa);
        printf("Insira o genero (M/F): ");
        scanf(" %c", &(ListIndiv + i)->genero);
        printf("Insira a data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &(ListIndiv + i)->dataNascimento.dia, &(ListIndiv + i)->dataNascimento.mes, &(ListIndiv + i)->dataNascimento.ano);
    }

    printf("Numero de individuos saudaveis: %d\n", indSaudaveis(ListIndiv, nReg));
    printf("Media corporal: %.2f\n", mediaCorporal(ListIndiv, nReg, 1990, 2000));
    int nCC;
    printf("Insira o numero do cartao de cidadao que deseja remover: ");
    scanf("%d", &nCC);
    removeIndiv(ListIndiv, &nReg, nCC);
    printf("Numero de registros: %d\n", nReg);
    listarIndiv(ListIndiv, nReg);

    free(ListIndiv);
    return 0;
}
