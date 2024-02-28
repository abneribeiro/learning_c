#include "Est_DadosFicha1.h"

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief gerar aleatoriamente N registos de USERS e gravar no ficheiro �Utilizadores.dat�
 *
 * \param
 * \param
 * \return void ....
 *
 */

void GerarFicheiro_So_Para_Testes(char *nficheiro, int N)
{
    FILE *F = fopen(nficheiro, "wb");
    if (!F)
        return;

    for (int i = 0; i < N; i++)
    {

        USER ut;
        ut.numero_acessos = Aleatorio(10, 1000);
        sprintf(ut.nome, "NOME_utilizador-%d", i + 1);
        sprintf(ut.utilizador, "username-XXX%d", i + 1);
        ut.data_registo.ano = Aleatorio(2000, 2023);
        ut.data_registo.mes = Aleatorio(1, 12);
        ut.data_registo.dia = Aleatorio(1, 28);
        ut.data_ultimo_acesso.ano = Aleatorio(2000, 2023);
        ut.data_ultimo_acesso.mes = Aleatorio(1, 12);
        ut.data_ultimo_acesso.dia = Aleatorio(1, 28);
        ut.telemovel = 900000000 + Aleatorio(1, 100);
        ut.joia = (float)Aleatorio(100, 200) / 10;

        fwrite(&ut, sizeof(USER), 1, F);
    }
    fclose(F);

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sao de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

/* **********************************************************
// ALUNOS: implementar!!
// alterar ff para devolver int com indica��o de sucesso/insucesso ao ler os dados
// int LerFicheiro(EDADOS *ed, char *nficheiro)
 // **********************************************************
*/
void LerFicheiro(EDADOS *ed, char *nficheiro)
{
    if (!ed)
        return;
    if (!ed->Dados)
        return;

    FILE *F = fopen(nficheiro, "rb");
    if (!F)
    {
        printf("Erro ao abrir ficheiro");
        return; // INSUCESSO;  -- sse a ff retornar int! ver nota ALUNOS ALTERAR
    }

    int Tam_User = sizeof(USER);
    printf("Tam_User = %d\n", Tam_User);
    // Quantos elementos estar�o no ficheiro? ftell e fseek
    long posicao = ftell(F);
    printf("Posicionamento na abertura: \"%s\" na %ld posicao\n", nficheiro, posicao);
    fseek(F, 0, SEEK_END);
    posicao = ftell(F);
    printf("Posicionamento na fim: \"%s\" na %ld posicao\n", nficheiro, posicao);
    // num de utilizadores registados no ficheiro:
    int Nreg = posicao / Tam_User;
    printf("num de utilizadores registados no ficheiro = %d\n", Nreg);

    // Ir para o inicio do ficheiro
    fseek(F, 0, SEEK_SET); // OU rewind(F);

    ed->Dados = (USER *)malloc(Nreg * sizeof(USER));

    fread(ed->Dados, sizeof(USER), Nreg, F);
    ed->N_USER = Nreg;
    fclose(F);

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Listar todos os utilizadores
 *
 * \param
 * \param
 * \return
 *
 */

void MostrarUser(USER *Reg)
{
    printf("------------------------------------------------------\n");
    printf("USER:\t [%s]\n", Reg->nome);
    printf("USERNAME:\t [%s]\n", Reg->utilizador);
    printf("NumAcessos:\t %d\n", Reg->numero_acessos);
    printf("Joia paga:\t %.2f\n", Reg->joia);
    printf("telemovel:\t %d\n", Reg->telemovel);
    printf("\t DataRegisto: %d/%d/%d\n", Reg->data_registo.dia,
           Reg->data_registo.mes, Reg->data_registo.ano);

    printf("\t DataUltimoAcesso: %d/%d/%d\n", Reg->data_ultimo_acesso.dia,
           Reg->data_ultimo_acesso.mes, Reg->data_ultimo_acesso.ano);
    printf("------------------------------------------------------\n");
}

void ListarUtilizadores(EDADOS *ed)
{
    if (!ed)
        return;
    if (!ed->Dados)
        return;

    for (int i = 0; i < ed->N_USER; i++)
    {
        MostrarUser(&(ed->Dados[i]));
    }

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}
// ff auxiliar � funcao ListarUtilizadores

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief duplica dados
 *
 * \param
 * \param
 * \return
 *
 */

EDADOS *DuplicarDados(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    return NULL;
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief implementa um m�todo de ordena��o
 *
 * \param
 * \param
 * \return
 *
 */

void OrdenarDados(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Conta o n�mero de pessoas que fizeram o �ltimo acesso ao site num dado ano
 *
 * \param
 * \param
 * \return
 *
 */

void ContarPessoasAcessosAno(EDADOS *ed, int ano)
{

    if (!ed)
        return;
    if (!ed->Dados)
        return;

    int cont = 0;

    for (int i = 0; i < ed->N_USER; i++)

        if (ed->Dados[i].data_ultimo_acesso.ano == ano)
            cont++;

    printf("?\nNumero de pessoas que fizeram o ultimo acesso ao site no ano %d: %d\n", ano, cont);
    

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Determina a pessoa que fez mais acessos
 *
 * \param
 * \param
 * \return
 *
 */

void PessoaMaisAcessos(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Determina a soma de todas as �joias�
 *
 * \param
 * \param
 * \return
 *
 */

float TotalJoias(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    return 0;
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Determina qual o m�s em que houve mais registos
 *
 * \param
 * \param
 * \return
 *
 */

int MesMaisRegistos(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
    return 0;
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Pesquisar pelo c�digo
 *
 * \param
 * \param
 * \return
 *
 */

void PesquisarCod(EDADOS *ed, char *UserName)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief Pesquisa pelo nome
 *
 * \param
 * \param
 * \return
 *
 */

void PesquisarNome(EDADOS *ed, char *Name)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    printf("c�digo aqui!!!!\n");

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}

//____________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________
/** \brief liberta toda a mem�ria alocada
 *
 * \param
 * \param
 * \return
 *
 */

void LibertarMemoria(EDADOS *ed)
{
    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Entrei em <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);

    if (!ed)
        return;
    if (ed->Dados != NULL)
        free(ed->Dados);
    free(ed);
    ed = NULL;

    if (DEBUG)
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sa� de <%s> ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", __FUNCTION__);
}
