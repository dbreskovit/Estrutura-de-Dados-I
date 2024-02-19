
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
  int data;
  struct ListNode *next;
};

struct Stack
{
  struct ListNode *top;
  int size;
};

struct Stack *createStack()
{
  struct Stack *stk;
  stk = malloc(sizeof(struct Stack));
  stk->top = NULL;
  return stk;
}

void push(struct Stack *stk, int data)
{
  struct ListNode *temp;
  temp = malloc(sizeof(struct ListNode));
  if (!temp)
  {
    printf("\nStack overflow");
    return;
  }
  temp->data = data;
  temp->next = stk->top;
  stk->top = temp;
  stk->size++;
}

int isEmpty(struct Stack *stk)
{
  return stk->top == NULL;
}

int size(struct Stack *stk)
{
  return stk->size;
}

int pop(struct Stack *stk)
{
  int data;
  struct ListNode *temp;
  if (isEmpty(stk))
    return INT_MIN;
  temp = stk->top;
  stk->top = stk->top->next;
  data = temp->data;
  free(temp);
  stk->size--;
  return data;
}

int peek(struct Stack *stk)
{
  if (isEmpty(stk))
    return INT_MIN;
  return stk->top->data;
}

int search(struct Stack *stk, int data)
{
  int pos = 0;
  struct ListNode *temp;
  temp = stk->top;
  while (temp)
  {
    if (temp->data == data)
      return pos;
    temp = temp->next;
    pos++;
  }
  return -1;
}

void deleteStack(struct Stack *stk)
{
  struct ListNode *temp, *p;
  p = stk->top;
  while (p)
  {
    temp = p->next;
    free(p);
    p = temp;
  }
  free(stk);
}

void menu()
{
  printf("1 - Inicializar pilha\n");
  printf("2 - Push\n");
  printf("3 - Pop\n");
  printf("4 - Top\n");
  printf("5 - Size\n");
  printf("6 - isEmpty\n");
  printf("7 - Clear\n");
  printf("8 - Imprimir pilha\n");
  printf("9 - Buscar elemento na pilha\n");
  printf("0 - Sair\n");

  printf("Digite a opcao desejada: ");
}

void main(void)
{
  system("clear");
  struct Stack *stk;

  int op, data, res;

  do
  {
    menu();
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      stk = createStack();
      printf("Pilha inicializada com sucesso!\n");
      break;
    case 2:
      printf("Digite o elemento a ser inserido: ");
      scanf("%d", &data);
      push(stk, data);
      printf("Elemento inserido com sucesso!\n");
      break;
    case 3:
      res = pop(stk);
      if (res == INT_MIN)
        printf("Pilha vazia!\n");
      else
        printf("Elemento removido: %d\n", res);
      break;
    case 4:
      res = peek(stk);
      if (res == INT_MIN)
        printf("Pilha vazia!\n");
      else
        printf("Elemento do topo: %d\n", res);
      break;
    case 5:
      res = size(stk);
      printf("Tamanho da pilha: %d\n", res);
      break;
    case 6:
      res = isEmpty(stk);
      if (res)
        printf("Pilha vazia!\n");
      else
        printf("Pilha nao vazia!\n");
      break;
    case 7:
      deleteStack(stk);
      printf("Pilha apagada com sucesso!\n");
      break;
    case 8:
      printf("Pilha: ");
      while (!isEmpty(stk))
        printf("%d ", pop(stk));

      printf("\n");
      break;
    case 9:
      printf("Digite o elemento a ser buscado: ");
      scanf("%d", &data);
      res = search(stk, data);
      if (res == -1)
        printf("Elemento nao encontrado!\n");
      else
        printf("Elemento encontrado na posicao %d\n", res);
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (op != 0);
}