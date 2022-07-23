
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

typedef struct Stack *Stack;
Stack createStack(unsigned capacity)
{
    Stack stack = (Stack)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int test_IsFull(Stack stack)
{
    return stack->top == stack->capacity - 1;
}

int test_IsEmpty(Stack stack)
{
    return stack->top == -1;
}
void test_Push(Stack stack, int item)
{
    if (test_IsFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack index :%d\n", item, stack->top);
}
int test_Pop(Stack stack)
{
    if (test_IsEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int test_peek(Stack stack)
{
    if (test_IsEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
int main()
{
    Stack stack = createStack(100);

    test_Push(stack, 14);
    test_Push(stack, 25);
    test_Push(stack, 38);
    test_Push(stack, 48);

    printf("%d popped from stack\n", test_Pop(stack));
    printf("Top item is %d\n", test_peek(stack));

    return 0;
}