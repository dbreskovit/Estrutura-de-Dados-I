#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pilha.c"

// Definindo a estrutura para um nó da lista
typedef struct no
{
    int valor;          // Valor armazenado no nó
    struct no *proximo; // Ponteiro para o próximo nó
} No;

// Definindo a estrutura para a fila
typedef struct
{
    No *inicio; // Ponteiro para o início da fila
    No *fim;    // Ponteiro para o fim da fila
} Fila;

// Função para criar uma nova fila
Fila *criarFila()
{
    // Aloca memória para a fila
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    novaFila->inicio = NULL; // Define o início da fila como NULL
    novaFila->fim = NULL;    // Define o fim da fila como NULL
    return novaFila;         // Retorna a fila criada
}

// Função para verificar se a fila está vazia
int estaVazia(Fila *fila)
{
    // Retorna 1 (verdadeiro) se o início da fila for NULL, caso contrário retorna 0 (falso)
    return (fila->inicio == NULL);
}

// Função para inserir um valor na fila
void inserirNaFila(Fila *fila, int valor)
{
    // Aloca memória para um novo nó
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;  // Define o valor do novo nó
    novoNo->proximo = NULL; // Define que o próximo nó é NULL

    // Se a fila estiver vazia, insere o nó no início
    if (estaVazia(fila))
    {
        fila->inicio = novoNo;
    }
    else
    {
        // Se não, insere no fim da fila
        fila->fim->proximo = novoNo;
    }
    // Atualiza o fim da fila para o novo nó
    fila->fim = novoNo;
}

// Função para remover um valor da fila
int removerDaFila(Fila *fila)
{
    // Verifica se a fila está vazia
    if (estaVazia(fila))
    {
        printf("Fila vazia. Não é possível remover.\n");
        return -1; // Retorna um valor indicativo de erro
    }

    // Armazena o nó a ser removido e seu valor
    No *noRemovido = fila->inicio;
    int valor = noRemovido->valor;

    // Atualiza o início da fila para o próximo nó
    fila->inicio = noRemovido->proximo;

    // Libera a memória do nó removido
    free(noRemovido);

    // Retorna o valor removido
    return valor;
}

// Função para imprimir a fila
void imprimirFila(Fila *fila)
{
    // Ponteiro para percorrer a fila
    No *atual = fila->inicio;

    // Verifica se a fila está vazia
    if (estaVazia(fila))
    {
        printf("Fila vazia.\n");
    }
    else
    {
        // Percorre a fila e imprime cada valor
        while (atual != NULL)
        {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

// Função para liberar a memória utilizada pela fila
void liberarFila(Fila *fila)
{
    // Ponteiro para percorrer e liberar cada nó da fila
    No *atual = fila->inicio;

    while (atual != NULL)
    {
        // Armazena o próximo nó
        No *proximo = atual->proximo;

        // Libera o nó atual
        free(atual);

        // Atualiza o ponteiro para o próximo nó
        atual = proximo;
    }

    // Libera a estrutura da fila
    free(fila);
    printf("Memória liberada.\n");
}

int contarImpares(Fila *fila)
{
    No *atual = fila->inicio;
    int n = 0;

    if (estaVazia(fila))
    {
        printf("Fila vazia.\n");
        return -1;
    }

    while (atual != NULL)
    {
        if (atual->valor % 2 != 0)
        {
            n++;
        }
        atual = atual->proximo;
    }

    return n;
}

void excluirNegativos(Fila *fila)
{
    No *atual = fila->inicio;
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->valor < 0)
        {
            No *temp = atual;
            if (anterior == NULL)
            {
                fila->inicio = atual->proximo;
                atual = fila->inicio;
            }
            else
            {
                anterior->proximo = atual->proximo;
                atual = anterior->proximo;
            }

            free(temp);
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

int main(void)
{
    // Cria uma nova fila
    Fila *minhaFila = criarFila();

    inserirNaFila(minhaFila, -1);
    inserirNaFila(minhaFila, 1);
    inserirNaFila(minhaFila, 2);
    inserirNaFila(minhaFila, 3);
    inserirNaFila(minhaFila, -5);
    inserirNaFila(minhaFila, 4);
    inserirNaFila(minhaFila, 5);
    inserirNaFila(minhaFila, -1);

    imprimirFila(minhaFila);
    excluirNegativos(minhaFila);
    imprimirFila(minhaFila);

    return 1;
}