#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int indice, int indice2)
{
    int aux;

    aux = v[indice];
    v[indice] = v[indice2];
    v[indice2] = aux;
}

int particiona(int *v, int inicio, int fim)
{
    int pivo = v[inicio];
    int esq  = inicio;
    int dir = fim;

    while(esq < dir)
    {
        while(v[dir] > pivo)
        {
            dir--;
        }
        while(v[esq] <= pivo)
        {
            esq++;
        }

        if(esq<dir)
        {
            troca(v, esq, dir);
        }
    }

    v[inicio] = v[dir];
    v[dir] = pivo;

    return dir;

}

void quicksort(int *v, int inicio, int fim)
{
    int pivo;

    if(inicio<fim)
    {
        pivo = particiona(v, inicio, fim);
        quicksort(v, inicio, pivo-1);
        quicksort(v, pivo+1, fim);
    }

}

main(int argc, char **argv)
{
    int v[20] = {1,1,1,1,1,2,3,4,4,4,5};

    quicksort(v, 0, 19);

    int i;

    for(i = 0; i < 20; i++)
    {
        printf("%d ", v[i]);
    }
}


