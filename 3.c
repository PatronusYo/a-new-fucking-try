#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}


void push(Stack *s, char c)
{
    if (!isFull(s)) {
        s->data[++s->top] = c;
    }
}


char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top--];
    }
    return '\0';
}

char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }
    return '\0';
}

int judge(char *inOrder, char *outOrder, char *operations)
{
    Stack s;
    initStack(&s);
    int inIndex = 0, outIndex = 0;
    int opIndex = 0;
    while (outIndex < strlen(outOrder)) {
        while (isEmpty(&s) || peek(&s) != outOrder[outIndex])
        {
            if (inIndex >= strlen(inOrder))
                {
                    return 0;
                }
            push(&s, inOrder[inIndex]);
            operations[opIndex++] = inOrder[inIndex];
            operations[opIndex++] = '_';
            operations[opIndex++] = 'i';
            operations[opIndex++] = 'n';
            inIndex++;
        }
        pop(&s);
        operations[opIndex++] = outOrder[outIndex];
        operations[opIndex++] = '_';
        operations[opIndex++] = 'o';
        operations[opIndex++] = 'u';
        operations[opIndex++] = 't';
        outIndex++;
    }
    operations[opIndex] = '\0';
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char inOrder[MAX_SIZE];
    char outOrder[MAX_SIZE];
    char operations[MAX_SIZE * 5];
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &inOrder[i]);
    }
    inOrder[n] = '\0';

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &outOrder[i]);
    }
    outOrder[n] = '\0';

    if (judge(inOrder, outOrder, operations))
        {
            printf("1\n%s\n", operations);
        }
    else
        {
            printf("0\n");
        }

    return 0;
}
