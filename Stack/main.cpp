#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

#include "Stack.h"
#include "Checkout.h"

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Erroneous number elements %d", argc);
    }

    //FILE* dump_file = fopen(argv[1], "wb");
    
    struct Stack_t stack = {};
    STACK_CTOR(&stack, 2, argv[1]);                   
    
    PrintStack(&stack);
    
    for (int i = 0; i < 5; i++)
    {
        StackPush(&stack, StackElem_t(i));
        PrintStack(&stack);
    }

    for (int i = 0; i < 5; i++)
    {
        STACK_ASSERT(&stack);   //здесь не нужно, но почему записывает в файлы лишь единожды?
        StackElem_t x = 0;
        StackPop(&stack, &x);
        PrintStack(&stack);
    }

    StackDestructor(&stack);

    //fclose(dump_file);

    return 0;
}


void PrintStack(struct Stack_t *ad_stack)
{
    assert(ad_stack != NULL);
    for (int i  = 0; i < ad_stack->size; i++)
    {
        printf("%u ", ad_stack->data[i]);
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
