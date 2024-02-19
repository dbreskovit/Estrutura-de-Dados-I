#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista
{
    int valor;
    struct Lista *prox;
} Lista;

Lista *criaLista()
{
    return NULL;
}

Lista *insereLista(Lista *l, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = l;
    return novo;
}

void imprimeLista(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d ", p->valor);
    }
    printf("\n");
}

int verificaPrimo(int n)
{
    int i, cont = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        return 1;
    }
    return 0;
}

int verificaRepeticao(Lista *l, int valor)
{
    Lista *p;
    int cont = 0;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->valor == valor)
        {
            cont++;
        }
    }
    return cont;
}

int main()
{

    srand(time(NULL));

    Lista *l = criaLista();
    int i, n, valor, cont = 0, maior = 0, soma = 0, aux = 0;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        valor = rand() % 99 + 2;
        l = insereLista(l, valor);
    }
    imprimeLista(l);
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (verificaPrimo(p->valor) == 1 && verificaPrimo(p->prox->valor) == 1 && verificaPrimo(p->prox->prox->valor) == 1)
        {
            cont = verificaRepeticao(l, p->valor) + verificaRepeticao(l, p->prox->valor) + verificaRepeticao(l, p->prox->prox->valor);
            if (cont > maior)
            {
                maior = cont;
                soma = p->valor + p->prox->valor + p->prox->prox->valor;
            }
        }
    }
    printf("Soma: %d\n", soma);
    return 1;
}