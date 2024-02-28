#ifndef EST_DADOSFICHA1_H_INCLUDED
#define EST_DADOSFICHA1_H_INCLUDED


// ---------------------------------------------------------------------
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

extern int Aleatorio(int min, int max);

// ---------------------------------------------------------------------
// definir macros
#define MAX_NOME_WEB 50
#define MAX_UT_PASS 20
#define MAX_EMAIL 30
#define SUCESSO 1
#define INSUCESSO -1
#define DEBUG 1


// criar estruturas para guardar os dados
typedef struct
{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct
{
    char nome[MAX_NOME_WEB];
    char utilizador[MAX_UT_PASS];
    char password[MAX_UT_PASS];
    float joia;
    DATA data_registo;
    char email[MAX_EMAIL];
    char pagina_web_pessoal[MAX_NOME_WEB];
    int telemovel;
    int numero_acessos;
    DATA data_ultimo_acesso;
}USER, REGISTO_UTILIZADORES;

typedef struct
{
    USER *Dados;
    int N_USER;
}EDADOS;


// ---------------------------------------------------------------------
//protótipos das funcoes implementadas

void GerarFicheiro_So_Para_Testes(char *nficheiro, int N); // gerar aleatoriamente N registos de USERS e gravar no ficheiro “Utilizadores.dat”
/* **********************************************************
// ALUNOS: implementar!!
// alterar ff para devolver int com indicação de sucesso/insucesso ao ler os dados
// int LerFicheiro(EDADOS *ed, char *nficheiro);
 // **********************************************************
*/
void LerFicheiro(EDADOS *ed, char *nficheiro); // lê os dados do ficheiro
EDADOS * DuplicarDados(EDADOS *ed); // duplica os dados
void OrdenarDados(EDADOS *ed); // Deve implementar um método de ordenação
void ListarUtilizadores(EDADOS *ed); // Deve Listar todos os utilizadores
int ContarPessoasAcessosAno(EDADOS *ed, int ano); // Contar o número de pessoas que fizeram o último acesso ao site num dado ano
void PessoaMaisAcessos(EDADOS *ed); // Determinar a pessoa que fez mais acessos
float TotalJoias(EDADOS *ed); // Determinar a soma de todas as “joias”
int MesMaisRegistos(EDADOS *ed); // Determinar qual o mês em que houve mais registos
void PesquisarCod(EDADOS *ed, char *UserName); // Pesquisar pelo código
void PesquisarNome(EDADOS *ed, char *Name); // Pesquisar pelo nome

void LibertarMemoria(EDADOS *ed); // Deve libertar toda a memória alocada






#endif // EST_DADOSFICHA1_H_INCLUDED
