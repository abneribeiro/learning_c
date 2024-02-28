
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/** \brief Fun��o que devolve um n�mero aleatorio entre [min, max]
 *
 * \param min int: Valor min do intervalo
 * \param max int: Valor max do intervalo
 * \return int : Valor aleatorio entre [min, max]
 * \author Alunos e Docentes de ED
 */
int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}


