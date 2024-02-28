#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

/** \brief Funcao que devolve um numero aleatorio in [min, max]
 *
 * \param min int: Valor minimo do intervalo
 * \param max int: Valor maximo do intervalo
 * \return int : Retorna um aleatorio in [min, max]
 * \author Aluno & Docentes
 * \date   20/02/2024
 * \version V-1.0
 */
int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

ALUNO *CriarCarregarVectorAlunos(int N)
{
    printf("Entrei em <%s>\n", __FUNCTION__);
    ALUNO *V = (ALUNO *)malloc(N * sizeof(ALUNO));
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
    printf("Sai de <%s>\n", __FUNCTION__);
    return V;
}
void Listar_Ecran(ALUNO *V, int N)
{
    printf("Entrei em <%s>\n", __FUNCTION__);
    for (int i = 0; i < N; i++)
    {
        printf("ALUNO NMEC = %d NOME = %s\n", V[i].NMEC, V[i].NOME);
        for (int k = 0; k < 5; k++)
        {
            printf("\t UC %s NOTA = %d\n", V[i].V_UCs[k].NOME, V[i].V_UCs[k].NOTA);;
        }
    }
    printf("Sai de <%s>\n", __FUNCTION__);
}
/** \brief Gravar para ficheiro
 *
 * \param nficheiro char* : Nome do ficheiro
 * \param V ALUNO*
 * \param N int
 * \return void : Não retorna nada
 *
 */
void Gravar_Ficheiro(char *nficheiro, ALUNO *V, int N)
{
    printf("Entrei em <%s>\n", __FUNCTION__);
    FILE *F = fopen(nficheiro, "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(F, "ALUNO NMEC = %d NOME = %s\n", V[i].NMEC, V[i].NOME);
        for (int k = 0; k < 5; k++)
        {
            fprintf(F, "\t UC %s NOTA = %d\n", V[i].V_UCs[k].NOME, V[i].V_UCs[k].NOTA);;
        }
    }
    fclose(F);
    printf("Sai de <%s>\n", __FUNCTION__);
}
int QuantosPassam(ALUNO *V, int N)
{
    printf("Entrei em <%s>\n", __FUNCTION__);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int totNotas = 0;

        for (int k = 0; k < 5; k++){
            
            totNotas += V[i].V_UCs[k].NOTA;
        }

       float medNotas = ceil((totNotas * 1.0) / 5);
       printf("Media = %.2f\n", medNotas);
        if(medNotas >= 10)
        {
            count++;
        }

        
    }
    return count;
    

    printf("Sai de <%s>\n", __FUNCTION__);
    return -1;
}


void mediaUcInferior(ALUNO *V, int nReg, int lim){
    float totNotAlunos; float totMediaALunos;
    for(int i = 0; i < nReg; i++){
        int UCs = 5; float sumUCS;
        for (int j = 0; i < UCs; j++)
           sumUCS += V->V_UCs->NOTA;
        
        if (sumUCS / 5 < lim)
        {
         totNotAlunos += sumUCS;   
        }
    }
    totMediaALunos = totNotAlunos / nReg;
    printf("O numero de medio de UCs inferiores a %d, é %f",nReg, totMediaALunos );
}

int main()
{
    printf("Ficha0-Ex3-TP1!\n");
    srand(time(NULL) );

    ALUNO *VA = NULL;
        int N;
        //printf("Quantos Queres ? ");
        //scanf("%d", &N);
        N = Aleatorio(2, 5);
        VA = CriarCarregarVectorAlunos(N);
       
        Listar_Ecran(VA, N);
        Gravar_Ficheiro("Sofia.txt", VA, N);
        int QP;
        QP = QuantosPassam(VA, N);
        printf("Passam = %d\n", QP);
        mediaUcInferior(VA, N, 8);
    free (VA);
    return 0;
}



    