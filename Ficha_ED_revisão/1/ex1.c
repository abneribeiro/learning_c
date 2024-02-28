#include <stdio.h>

int Esparsa(int *Matriz, int M, int N, float percentagem)
{
    int count = 0;  
    int tam = M * N; 
    for(int i = 0; i < tam; i++)
    {
        if (*(Matriz + i) == 0)
        {
            count++;
        }
    }
   float perz = (count* 100.0f) / tam;

    if (perz / 100 > percentagem)
    {
        printf("%f\n", perz);
        return 1;
    }
    return 0;
}

int main()
{
    int M = 2, N = 3;
    int Matriz[2][3] = {{1, 2, 0}, {0, 0, 3}};
    float percentagem = 0.4f;
    int perz = Esparsa(&Matriz[0][0], M, N, percentagem);
    if ( perz == 1)
    {
        printf("A matriz é esparsa\n");
    }
    else if (perz == 0)
    {
        printf("A matriz não é esparsa\n");
    }
    
    return 0;
}