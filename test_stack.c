
#include <stdio.h>

int top = -1;
int capacity = 3;
int test_Top(int stack[])
{
    return stack[top];
}

int test_Size()
{
    return top + 1;
}

int test_IsFull()
{
    return (top == capacity - 1);
}

int test_IsEmpty()
{
    return top == -1;
}

void test_Push_int(int stack[], int value)
{
    if (test_IsFull(capacity) == 1)
        printf("\nStack is full. Overflow condition!");
    else
    {
        ++top;
        stack[top] = value;
    }
}
void test_Push_char(char stack[], char character)
{
    if (test_IsFull(capacity) == 1)
        printf("\nStack is full. Overflow condition!");
    else
    {
        ++top;
        stack[top] = character;
    }
}
void test_Pop()
{
    if (test_IsEmpty() == 1)
        printf("\nStack is empty. Underflow condition!");
    else
        --top;
}
int test_Pull_int(char stack[])
{
    if (test_IsEmpty() == 1)
        printf("\nStack is empty. Underflow condition!");
    else
    {
        --top;
        return stack[top + 1];
    }
}
int main()
{
    // test int

    int top = -1;
    int stack[capacity];

    test_Push_int(stack, 5);
    printf("\n size %d", test_Size());
    test_Push_int(stack, 10);
    test_Push_int(stack, 24);
    printf("\n size %d", test_Size());
    test_Push_int(stack, 12);
    printf("\n top %d", test_Top(stack));

    for (int i = 0; i < 3; i++)
        test_Pop();
    printf("\n size %d", test_Size());
    test_Pop();

    // test str
    /*
    char str [] = "()()(())()";
    char stack [capacity] ;
    for(int i = 0 ; i < 10 ; i++ )
    {
        if (str [ i ] == '(')
        {
            test_Push_char(stack, str[i]);
        }
        if(str[ i ] == ')' )
        {
            test_Pop();
        }
    }

    if(top == -1)
        printf("String is balanced!\n");
    else
        printf("String is unbalanced!\n");
    */
}