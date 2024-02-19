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

void printStack(struct Stack *stk)
{
  struct ListNode *temp;
  temp = stk->top;
  printf("\nStack: ");
  while (temp)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void insertAtBottom(struct Stack *stk, int data)
{
  int temp;
  if (isEmpty(stk))
  {
    push(stk, data);
    return;
  }
  temp = pop(stk);
  insertAtBottom(stk, data);
  push(stk, temp);
}

void sortASC(struct Stack *stk)
{
  struct Stack *stk2;
  stk2 = createStack();
  int temp;
  while (!isEmpty(stk))
  {
    temp = pop(stk);
    while (!isEmpty(stk2) && peek(stk2) > temp)
    {
      push(stk, pop(stk2));
    }
    push(stk2, temp);
  }
  while (!isEmpty(stk2))
  {
    push(stk, pop(stk2));
  }
}

void main(void)
{

  struct Stack *pilha;
  pilha = createStack();

  push(pilha, 12);
  push(pilha, 23);
  push(pilha, 63);
  push(pilha, 10);
  push(pilha, 55);

  printf("Pilha Original:");
  printStack(pilha);
  printf("\n");

  sortASC(pilha);
  printf("Pilha Ordenada:");
  printStack(pilha);
}