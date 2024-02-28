#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NOME_UC 40
#define MAX_NOME_ALUNO 50

typedef struct
{
   char NOME[MAX_NOME_UC];
   int NOTA;
}UC;

typedef struct
{
    int NMEC;
    char NOME[MAX_NOME_ALUNO];
    UC V_UCs[5];
}ALUNO;

int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

ALUNO *CriarCarregarVectorAlunos(int N)
{
    ALUNO *V = (ALUNO *)malloc(N * sizeof(ALUNO));
    if (!V) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < N; i++)
    {
        V[i].NMEC = Aleatorio(1000, 9999);
        sprintf(V[i].NOME, "Zezito:---- %d", i);
        for (int k = 0; k < 5; k++)
        {
            V[i].V_UCs[k].NOTA = Aleatorio(0, 20);
            sprintf(V[i].V_UCs[k].NOME, "UC-%d", k);
        }
    }
    return V;
}

void Listar_Ecran(ALUNO *V, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("ALUNO NMEC = %d NOME = %s\n", (V + i)->NMEC, (V + i)->NOME);
        for (int k = 0; k < 5; k++)
        {
            printf("\t UC %s NOTA = %d\n", V[i].V_UCs[k].NOME, V[i].V_UCs[k].NOTA);
        }
    }
}

void Gravar_Ficheiro(char *nficheiro, ALUNO *V, int N)
{
    FILE *F = fopen(nficheiro, "w");
    if (!F) {
        printf("File opening failed\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        fprintf(F, "ALUNO NMEC = %d NOME = %s\n", V[i].NMEC, V[i].NOME);
        for (int k = 0; k < 5; k++)
        {
            fprintf(F, "\t UC %s NOTA = %d\n", V[i].V_UCs[k].NOME, V[i].V_UCs[k].NOTA);
        }
    }
    fclose(F);
}

int QuantosPassam(ALUNO *V, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int totNotas = 0;

        for (int k = 0; k < 5; k++){
            totNotas += V[i].V_UCs[k].NOTA;
        }

       float medNotas = (totNotas * 1.0) / 5;
        if(medNotas >= 10)
        {
            count++;
        }
    }
    return count;
}

float mediaUcInferior(ALUNO *V, int nReg, int lim){
    float totNotAlunos = 0;
    int count = 0;
    for(int i = 0; i < nReg; i++){
        int UCs = 5; float sumUCS = 0;
        for (int j = 0; j < UCs; j++)
           sumUCS += V[i].V_UCs[j].NOTA;
        
        if (sumUCS / 5 < lim)
        {
         totNotAlunos += sumUCS;   
         count++;
        }
    }
    return count == 0 ? 0 : totNotAlunos / count;
}

void listaNotas(ALUNO *lista, int n, int val, char *nomeFich){
    FILE *F = fopen(nomeFich, "w");
    if (!F){
        printf("Erro ao abrir ficheiro\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(F, "Nome do aluno: %s\n",(lista + i)->NOME);
            if ((lista + i)->V_UCs[j].NOTA >= val)
            {
                fprintf(F, "UC: %s, Nota: %d\n", (lista + i)->V_UCs[j].NOME, (lista + i)->V_UCs[j].NOTA);
            }
            else if ((lista + i)->V_UCs[j].NOTA < val)
            {
               fprintf(F, "UC: %s, Nota: --\n", (lista + i)->V_UCs[j].NOME );
            }

        }

        fprintf(F, "-------------------------------\n");
    }
    
    

}



int main()
{
    srand(time(NULL) );

    int N = Aleatorio(2, 5);
    ALUNO *ListAlun = CriarCarregarVectorAlunos(N);
    if (!ListAlun) return 1;

    Listar_Ecran(ListAlun, N);
    int QP = QuantosPassam(ListAlun, N);
    printf("Passam = %d\n", QP);
    float t = mediaUcInferior(ListAlun, N, 8);
    printf("Medios inferiores %.2f", t);
    listaNotas(ListAlun, N, 10, "notas.txt");
    free (ListAlun);
    return 0;
}