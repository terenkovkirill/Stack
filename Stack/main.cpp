#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

#include "Stack.h"
#include "Checkout.h"

// typedef canary_t double



int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Erroneous number elements %d", argc);
    }
    
    struct Stack_t stack = {};
    STACK_CTOR(&stack, 2, argv[1]);                   
    
    PrintStack(&stack);
    
    for (int i = 0; i < 5; i++)
    {
        StackPush(&stack, i, argv[1]);
        PrintStack(&stack);
    }

    for (int i = 0; i < 5; i++)
    {
        StackElem_t x = 0;
        StackPop(&stack, &x, argv[1]);
        PrintStack(&stack);
    }

    StackDestructor(&stack);

    return 0;
}


void PrintStack(struct Stack_t *ad_stack)
{
    for (int i  = 0; i < ad_stack->size; i++)
    {
        printf("%g ", ad_stack->data[i]);
    }
    printf("\n");
}


//когда size = 0 указатель на структуру делаем NULL (при уменьшении размера)



// TODO:
// 1) StackRealloc() (расширение + FillPoizonValue(Stack* stk, size_t size_to fill))   +
// 2) Потом с Enum StackError разобраться                                              +
// 3) добавляешь канарейки
// 4) хеш функции


// вот тут про то, что мы говорили, но для Сани типо не говорили
