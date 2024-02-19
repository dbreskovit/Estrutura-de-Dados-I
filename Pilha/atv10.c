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
    //printf("\nStack: ");
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

void display(struct Stack *tower1, struct Stack *tower2, struct Stack *tower3)
{
    system("cls");
    printf("A:\n");
    printStack(tower1);
    printf("\nB:\n");
    printStack(tower2);
    printf("\nC:\n");
    printStack(tower3);
}

int main(void)
{

    struct Stack tower1, tower2, tower3;

    int n, origin, dest, move = 0;

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    if (!(n >= 3 && n <= 7))
    {
        printf("Numero invalido!\n");
        exit(1);
    }

    tower1 = *createStack();
    tower2 = *createStack();
    tower3 = *createStack();

    for (int i = n; i > 0; i--)
        push(&tower1, i);

    while (1)
    {
        display(&tower1, &tower2, &tower3);
        printf("\nDigite a Origem (1,2,3): ");
        scanf("%d", &origin);
        printf("Digite o Destino (1,2,3): ");
        scanf("%d", &dest);

        if (origin == 1)
        {
            if (dest == 2)
            {
                if (peek(&tower1) < peek(&tower2) || isEmpty(&tower2))
                {
                    push(&tower2, pop(&tower1));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
            else if (dest == 3)
            {
                if (peek(&tower1) < peek(&tower3) || isEmpty(&tower3))
                {
                    push(&tower3, pop(&tower1));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
        }
        else if (origin == 2)
        {
            if (dest == 1)
            {
                if (peek(&tower2) < peek(&tower1) || isEmpty(&tower1))
                {
                    push(&tower1, pop(&tower2));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
            else if (dest == 3)
            {
                if (peek(&tower2) < peek(&tower3) || isEmpty(&tower3))
                {
                    push(&tower3, pop(&tower2));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
        }
        else if (origin == 3)
        {
            if (dest == 1)
            {
                if (peek(&tower3) < peek(&tower1) || isEmpty(&tower1))
                {
                    push(&tower1, pop(&tower3));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
            else if (dest == 2)
            {
                if (peek(&tower3) < peek(&tower2) || isEmpty(&tower2))
                {
                    push(&tower2, pop(&tower3));
                    move++;
                }
                else
                {
                    printf("Movimento invalido\n");
                    getch();
                }
            }
        }

        if (size(&tower3) == n || size(&tower2) == n)
        {
            display(&tower1, &tower2, &tower3);
            printf("\nVoce venceu em %d movimentos\n", move);
            break;
        }
    }

    return 1;
}