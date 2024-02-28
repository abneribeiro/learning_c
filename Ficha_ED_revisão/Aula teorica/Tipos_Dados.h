#ifndef TIPOS_DADOS_H_INCLUDED
#define TIPOS_DADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME_PRODUTO 50
#define MAX_NOME_ARMAZEM 20

typedef struct
{
    int CODIGO;
    char NOME[MAX_NOME_PRODUTO];
    float PRECO;
}PRODUTO;

typedef struct
{
    char NOME[MAX_NOME_ARMAZEM];
    PRODUTO *VP;
    int N;
}ARMAZEM;

ARMAZEM *CriarArmazem(int N);
void LerDadosArmazem(ARMAZEM *A);
void ListarProdutos(ARMAZEM *A);
void PesquisarProduto(ARMAZEM *A);
void DestruirArmazem(ARMAZEM *A);
void GravarArmazemFicheiro(ARMAZEM *A, char *ficheiro);
void PassarNomesProdutosMaiusculas(ARMAZEM *A);
void AumentarPrecos(ARMAZEM *A, float perc);

#endif // TIPOS_DADOS_H_INCLUDED
