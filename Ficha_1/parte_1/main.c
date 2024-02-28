#include "Est_DadosFicha1.h"

int main()
{
    srand(time(NULL)); // variar semente para gerar aleatorios

    printf("ED 2023/2024 Ficha de Trabalho n 1 (Revisao): ponteiros, memoria dinamica (...)\n");

    EDADOS *ed = (EDADOS *)malloc(1 * sizeof(EDADOS));

    if (ed == NULL)
    {
        printf("Erro ao alocar mem�ria\n");
        return INSUCESSO; // Termina o programa com codigo de erro
    }

    char *nficheiro = "Ficha1Utilizadores.dat";
    int Nutilizadores = 15;
    //    printf("N utilizadores:\n");
    //   scanf("%d", &Nutilizadores);
    GerarFicheiro_So_Para_Testes(nficheiro, Nutilizadores);

    // Ler ficheiro
    LerFicheiro(ed, nficheiro);
    /* **********************************************************
    // ALUNOS: implementar!!
    // alterar ff para devolver int com indica��o de sucesso/insucesso ao ler os dados

    flagSuc = LerFicheiro(ed, "ED_Utilizadores_rs.dat");
    if (flagSuc == 1)
        printf("Dados lidos com sucesso\n");
    else
        printf("Insucesso ao ler os dados\n");
     // **********************************************************
    */

    // Listar todos os utilizadores
    ListarUtilizadores(ed); // ALUNOS: alterar a ff para mostrar apenas M utilizadores inv�s de todos!!!

    // Duplicar dados
    EDADOS *ConjUtiliz_novo = (EDADOS *)malloc(1 * sizeof(EDADOS));
    ConjUtiliz_novo = DuplicarDados(ed);

    // Ordenar dados
    OrdenarDados(ed);

    // Contar o n�mero de pessoas que fizeram o �ltimo acesso ao site num dado ano
    int ContPessAcAno = ContarPessoasAcessosAno(ed, 2022);

    // Determinar a pessoa que fez mais acessos
    PessoaMaisAcessos(ed);

    // Determinar a soma de todas as �joias�
    float valorTotalJoias = TotalJoias(ed);

    // Determinar qual o m�s em que houve mais registos
    int mesMaisReg = MesMaisRegistos(ed);

    // Pesquisar pelo c�digo
    PesquisarCod(ed, "QQcoisa");

    // Pesquisar pelo nome
    PesquisarNome(ed, "Qualquer nome");

    // Libertar toda a mem�ria alocada
    LibertarMemoria(ed);
    LibertarMemoria(ConjUtiliz_novo);

    return 0;
}
