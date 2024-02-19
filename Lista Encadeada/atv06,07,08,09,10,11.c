#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int info;
	struct lista *prox;
} Lista;

Lista *criar_lista()
{
	return NULL;
}

// recebe a lista que receberá o novo elemento
// retorna a nova lista com inserção no início
Lista *insere_inicio(Lista *l, int i)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
} // retorna a nova lista (ponteiro para o novo elemento)

// 2 - IMPRIMINDO A LISTA
//======================
void imprimir_lista(Lista *l)
{
	Lista *p;
	// p vai varrendo cada nó da lista até NULL (tail)
	for (p = l; p != NULL; p = p->prox)
	{
		printf("%d \n", p->info);
	}
}

// 3 - VERIFICAR SE A LISTA ESTÁ VAZIA
//===================================
int vazia(Lista *l)
{
	if (l == NULL)
		return 1;
	return 0;
}

// 4 - BUSCAR UM ELEMENTO NA LISTA
//=================================
Lista *buscar(Lista *l, int valor)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == valor)
		{
			return p;
		} // se o elemento for encontrado
	}
	return NULL;
} // se o elemento não existe na lista

// 5 - REMOVER UM ELEMENTO DA LISTA
//=================================
Lista *remover(Lista *l, int valor)
{
	Lista *ant = NULL; // ponteiro para o elemento anterior
	Lista *p = l;	   // ponteiro para percorrer a lista

	while (p != NULL && p->info != valor)
	{
		ant = p;
		p = p->prox;
	}

	if (p == NULL)
	{
		printf("Valor não encontrado...\n");
		return l;
	}

	if (ant == NULL)
		l = p->prox; // remove do início da lista
	else
		ant->prox = p->prox; // remove do meio da lista

	free(p);
	return l;
}

// 6 - LIBERAR A LISTA DA MEMÓRIA
//=================================
void liberar(Lista *l)
{
	struct lista *p = l;

	while (p != NULL)
	{
		Lista *t = p->prox; // guarda o próximo elemento da lista
		free(p);			// libera o elemento atual da memória
		p = t;
	}
} // atualiza a lista (com a remoção do elemento)

int maior(Lista *l, int *posicao, int *valor)
{
	if (l == NULL)
	{
		return 0;
	}

	Lista *p = l;
	int maior = p->info;
	int posicaoMaior = 0;
	int posicaoAtual = 0;

	while (p != NULL)
	{
		if (p->info > maior)
		{
			maior = p->info;
			posicaoMaior = posicaoAtual;
		}
		p = p->prox;
		posicaoAtual++;
	}

	*posicao = posicaoMaior;
	*valor = maior;

	return 1;
}

Lista *pares(Lista *l)
{
	Lista *p = l;
	Lista *novaLista = criar_lista();

	while (p != NULL)
	{
		if (p->info % 2 == 0)
		{
			novaLista = insere_inicio(novaLista, p->info);
		}
		p = p->prox;
	}

	return novaLista;
}

Lista *inverter(Lista *l)
{
	Lista *p = l;
	Lista *novaLista = criar_lista();

	while (p != NULL)
	{
		novaLista = insere_inicio(novaLista, p->info);
		p = p->prox;
	}

	return novaLista;
}

int remover_kesimo(Lista *l, int k)
{
	Lista *ant = NULL; // ponteiro para o elemento anterior
	Lista *p = l;	   // ponteiro para percorrer a lista

	int posicaoAtual = 0;

	while (p != NULL && posicaoAtual != k)
	{
		ant = p;
		p = p->prox;
		posicaoAtual++;
	}

	if (p == NULL)
	{
		printf("Valor não encontrado...\n");
		return 0;
	}

	if (ant == NULL)
		l = p->prox; // remove do início da lista
	else
		ant->prox = p->prox; // remove do meio da lista

	free(p);
	return 1;
}

int contar_recursivo(Lista *l)
{
	if (l == NULL)
	{
		return 0;
	}

	return 1 + contar_recursivo(l->prox);
}

int main(void)
{

	Lista *lista;
	lista = criar_lista();

	int opcao = 0;

	do
	{
		printf("\n");
		printf("1 - Inserir no inicio\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir a lista\n");
		printf("4 - Buscar um valor\n");
		printf("5 - Encerrar\n");
		printf("------------------------\n");
		printf("7 - Buscar o maior valor\n");
		printf("8 - Lista com pares\n");
		printf("9 - Lista invertida\n");
		printf("10 - Remover o k-esimo\n");
		printf("11 - Contar elementos\n");
		printf("------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			printf("Digite o valor a ser inserido: ");
			int valor;
			scanf("%d", &valor);
			lista = insere_inicio(lista, valor);
			break;
		case 2:
			printf("Digite o valor a ser removido: ");
			int valorRemover;
			scanf("%d", &valorRemover);
			lista = remover(lista, valorRemover);
			break;
		case 3:
			printf("\nLista: \n");
			imprimir_lista(lista);
			break;
		case 4:
			printf("Digite o valor a ser buscado: ");
			int valorBuscar;
			scanf("%d", &valorBuscar);
			Lista *resultado = buscar(lista, valorBuscar);
			if (resultado == NULL)
			{
				printf("Valor nao encontrado...\n");
			}
			else
			{
				printf("Valor encontrado: %d\n", resultado->info);
			}
			break;
		case 5:
			liberar(lista);
			break;
		case 7:
			printf("Lista: \n");
			int pos, val;
			if (maior(lista, &pos, &val))
			{
				printf("Maior valor: %d\n", val);
				printf("Posicao: %d\n", pos);
			}
			else
				printf("Lista vazia\n");
			break;
		case 8:
			printf("Lista: \n");
			Lista *paresLista = pares(lista);
			printf("Lista com os numeros pares: \n");
			imprimir_lista(paresLista);
			break;
		case 9:
			printf("Lista: \n");
			Lista *inverterLista = inverter(lista);
			printf("Lista invertida: \n");
			imprimir_lista(inverterLista);
			break;
		case 10:
			printf("Digite a posicao do elemento a ser removido: ");
			int posicao;
			scanf("%d", &posicao);
			if (remover_kesimo(lista, posicao))
				printf("Elemento removido com sucesso\n");
			else
				printf("Erro ao remover o elemento\n");
			break;
		case 11:
			printf("Numero de elementos: %d\n", contar_recursivo(lista));
			break;
		default:
			printf("Opção invalida\n");
			break;
		}
	} while (opcao != 5);

	return 1;

}