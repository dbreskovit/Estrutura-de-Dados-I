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
