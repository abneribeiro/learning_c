
#include <string.h>
#include "Tipos_Dados.h"

extern int Factorial(int N);
extern int LerInteiro(char *txt);

ARMAZEM *CriarArmazem(int N)
{
   // printf("Um dia vou implementar <%s>\n", __FUNCTION__);
    // int k = Factorial(4);
    // printf("K = %d\n", k);
  //  int tam = sizeof(ARMAZEM);
  //  printf("Tam = %d\n", tam);
    ARMAZEM *X = (ARMAZEM *)malloc(1 * sizeof(ARMAZEM));
    X->VP = (PRODUTO *)malloc(N * sizeof(PRODUTO));
    X->N = N;
    strcpy(X->NOME, "Lidl. Lda");
    for (int i = 0; i < N; i++)
    {
        X->VP[i].CODIGO = 1000 + i;
        X->VP[i].PRECO = Aleatorio(1, 15);
        sprintf(X->VP[i].NOME, "Produto--> %d", i);
    }
    return X;
}
void DestruirArmazem(ARMAZEM *A)
{
    //printf("Um dia (e hoje) vou implementar <%s>\n", __FUNCTION__);
    free(A->VP);
    free(A);
}
void LerDadosArmazem(ARMAZEM *A)
{
    printf("Um dia vou implementar <%s>\n", __FUNCTION__);

}
void ListarProdutos(ARMAZEM *A)
{
   // printf("Um dia vou implementar <%s>\n", __FUNCTION__);
   printf("NOME: [%s]\n", A->NOME);
   printf("\t NProdutos: %d\n", A->N);
   for (int i = 0; i < A->N; i++)
   {
       printf("\t Produto: %d [%s] %f\n", A->VP[i].CODIGO,
              A->VP[i].NOME, A->VP[i].PRECO);
   }
}
void PesquisarProduto(ARMAZEM *A)
{
    printf("Um dia vou implementar <%s>\n", __FUNCTION__);
    int NPesq = LerInteiro("Qual o Codigo Produto Pesquisar ?");

    printf("PESQ = %d\n", NPesq);
}

void GravarArmazemFicheiro(ARMAZEM *A, char *ficheiro)
{
    printf("Um dia vou implementar <%s>\n", __FUNCTION__);

}

void PassarNomesProdutosMaiusculas(ARMAZEM *A)
{
    printf("Um dia vou implementar <%s>\n", __FUNCTION__);

}
void AumentarPrecos(ARMAZEM *A, float perc)
{
    for (int i = 0; i < A->N; i++)
        A->VP[i].PRECO = A->VP[i].PRECO + perc * A->VP[i].PRECO;
}
