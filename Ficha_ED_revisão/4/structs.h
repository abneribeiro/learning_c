#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>

typedef struct dataNascimento
{
    int dia;
    int mes;
    int ano;
} dataNascimento;

typedef struct indiv
{
    int numeroCartaoCidadao;
    float altura;
    float massa;
    char genero; // 'M' para masculino, 'F' para feminino
    dataNascimento dataNascimento;

} Indiv;

int indSaudaveis(Indiv *ListIndiv, int nReg)
{
    int nSaudaveis = 0;
    for (int i = 0; i < nReg; i++)
    {
        float imc = (ListIndiv + i)->massa / ((ListIndiv + i)->altura * (ListIndiv + i)->altura);

        if (imc >= 18.5 || imc <= 24.9)
        {
            nSaudaveis++;
        }
    }

    return nSaudaveis;
}


float mediaCorporal(Indiv *ListIndiv, int nReg, int ano1, int ano2)
{
    float media = 0.0;
    for (int i = 0; i < nReg; i++)
    {
        if ((ListIndiv + i)->dataNascimento.ano >= ano1 && (ListIndiv + i)->dataNascimento.ano <= ano2)
        {
            media += (ListIndiv + i)->massa / ((ListIndiv + i)->altura * (ListIndiv + i)->altura);
        }
    }
    return media / nReg;
    
}

void removeIndiv(Indiv *vet_ind, int *n, int nCC){
    for(int i = 0; i < *n; i++){
        if((vet_ind + i)->numeroCartaoCidadao == nCC){
            for(int j = i; j < *n - 1; j++){
                *(vet_ind + j) = *(vet_ind + j + 1);
            }
            (*n)--;
            break;
        }
    }
}

void listaIndiv(Indiv *vet_ind, int n){
    for(int i = 0; i < n; i++){
        printf("Numero do cartao de cidadao: %d\n", (vet_ind + i)->numeroCartaoCidadao);
        printf("Altura: %.2f\n", (vet_ind + i)->altura);
        printf("Massa: %.2f\n", (vet_ind + i)->massa);
        printf("Genero: %c\n", (vet_ind + i)->genero);
        printf("Data de nascimento: %d/%d/%d\n", (vet_ind + i)->dataNascimento.dia, (vet_ind + i)->dataNascimento.mes, (vet_ind + i)->dataNascimento.ano);
    }
}

#endif