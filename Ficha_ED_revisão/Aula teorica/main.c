#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tipos_Dados.h"

extern int Aleatorio(int min, int max);
extern void f1();
int main()
{
    printf("Hello world!\n");
   // f1();
    srand(time(NULL));
    int N = Aleatorio(3, 7);
    printf("N = %d\n", N);

    system("video_camara.mp4");
    //while (1)
    //{
        ARMAZEM *Lidl = CriarArmazem(N);

        //LerDadosArmazem(Lidl);
        ListarProdutos(Lidl);
        AumentarPrecos(Lidl, 0.5);
        ListarProdutos(Lidl);
        //PesquisarProduto(Lidl);

        DestruirArmazem(Lidl);
    //}
    return 0;
}
