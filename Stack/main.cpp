#include <TXLib.h>
#include <stdio.h>

//#define DEBUG
#define NO_ITEMS 0
typedef double StackElem_t; 

#ifdef DEBUG                                                    //почему макрос определяется именно в такой форме ?
    #define ON_DEBUG(...) __VA_ARGS__
#else
    #define ON_DEBUG(...)
#endif

#define STACK_CTOR(ad_stack, capacity) \                                         
        StackCtor(ad_stack, capacity, #ad_stack, __FILE__, __LINE__)                  
                                                                                

#define STACK_ASSERT(ad_stack) \                                                 
    StackAssertFunc(ad_stack, __FILE__, __LINE__)

struct Stack  // _t
{
    StackElem_t* data;
    int size;
    int capacity;
    ON_DEBUG(char* name;)
    ON_DEBUG(char* file;)
    ON_DEBUG(int line;)
};

void StackCtor(struct Stack *ad_stack, int capacity ON_DEBUG(, char* name, char* file, int line));
void StackAssertFunc(struct Stack *ad_stack, char* file, int line);
int StackError(struct Stack *ad_stack);
void StackDump(struct Stack *ad_stack, char* file, int line);
void StackPush(struct Stack *ad_stack, StackElem_t elem);
void StackPop(struct Stack *ad_stack, StackElem_t* x);
void StackFree(struct Stack *ad_stack);
void PrintStack(struct Stack *ad_stack);



int main()
{
    struct Stack stack = {};
    STACK_CTOR(&stack, 2);                   //правильно ли я передаю адрес stack в через макрос?

    PrintStack(&stack);

    for (int i = 0; i < 5; i++)
    {
        StackPush(&stack, i);
        PrintStack(&stack);
    }
    
    for (int i = 0; i < 5; i++)
    {
        StackElem_t x = 0;
        StackPop(&stack, &x);
        PrintStack(&stack);
    }

    StackFree(&stack);

    return 0;
}


void StackCtor(struct Stack *ad_stack, int capacity ON_DEBUG(, char* name, char* file, int line))
{
    ad_stack->size = 0;
    ad_stack->capacity = capacity;
    ad_stack->data = (StackElem_t *)calloc(capacity, sizeof(StackElem_t));
    ON_DEBUG(ad_stack->name = name;) 
    ON_DEBUG(ad_stack->file = file;)                                                 //нужны ли здесь макросы и знак ; после них ?
    ON_DEBUG(ad_stack->line = line;)

    STACK_ASSERT(ad_stack);                                             //где внутри функции дожен быть расположен этот assert ?
}


void StackPush(struct Stack *ad_stack, StackElem_t elem)
{
    STACK_ASSERT(ad_stack);

    if (ad_stack->size == ad_stack->capacity)
    {
        ad_stack->capacity  = 2 * ad_stack->capacity;
        ad_stack->data = (StackElem_t *)realloc(ad_stack->data, sizeof(StackElem_t) * ad_stack->capacity);
    }
    
    ad_stack->data[(ad_stack->size] = elem;
    ad_stack->size++;

    STACK_ASSERT(ad_stack);
}

void StackPop(struct Stack *ad_stack, StackElem_t* x)
{
    /*
    if ((*ad_stack).size == 0) 
    {
        return NO_ITEMS;
    }
    */
    *x = ad_stack->data[ad_stack->size];
    ad_stack->size--;

}


void StackFree(struct Stack *ad_stack)
{
    //assert(ad_stack != NULL);
    free(ad_stack->data);
    ad_stack->size = 0;
    ad_stack->capacity = 0;
}

void PrintStack(struct Stack *ad_stack)
{
    for (int i  = 0; i < ad_stack->size; i++)
    {
        printf("%g ", ad_stack->data[i]);
    }
    printf("\n");
}


int StackError(struct Stack *ad_stack)         //написанa точно неправильно, нужно подправить
{
    if (!(ad_stack && ad_stack->data))
    {
        return 0;
    }
    
    if (ad_stack->size < 0)
    {
        return 0;
    }

    return 1;
}

void StackAssertFunc(struct Stack *ad_stack, char* file, int line)         //тоже написана неправильно
{
    if (!StackError(ad_stack))
    {
        StackDump(ad_stack, __FILE__, __LINE__);            //указатели на какой файл и строку передаются при вызове этих макросов ?
        assert(0);
    }
}

void StackDump(struct Stack *ad_stack, char* file, int line)         //тоже написана неправильно
{
    printf("called from %c : %d \n", file, line);
    printf("address stack = %d \n", ad_stack);
    printf("address data = %d \n", ad_stack->data);
    printf("stack size = %d \n", ad_stack->size);
    printf("stack capacity = %d \n", ad_stack->capacity);
}