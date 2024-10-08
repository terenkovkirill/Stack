#include <TXLib.h>
#include <assert.h>
#include "Stack.h"
#include "Checkout.h"                   


void StackCtor(struct Stack_t *ad_stack, int capacity, const char* filename ON_DEBUG(, const char* name, const char* file, int line))
{
    assert(ad_stack != NULL);       //убираю assert 
    ad_stack->size = 0;
    ad_stack->capacity = capacity;
    
    // ad_stack->data = (StackElem_t *)calloc(capacity * sizeof(StackElem_t) + 2 * sizeof(canary_t), sizeof(char))

    // ad_stack->data = (StackElem_t *)((char*)ad_stack->data + sizeof(canary_t));

    ad_stack->data = (StackElem_t *)calloc(capacity, sizeof(StackElem_t));

    ad_stack->status = STACK_NO_ERROR;

    ON_DEBUG(ad_stack->name = name;) 
    ON_DEBUG(ad_stack->file = file;)                                             
    ON_DEBUG(ad_stack->line = line;)
    STACK_ASSERT(ad_stack, filename);                                             
}


void StackPush(struct Stack_t *ad_stack, StackElem_t elem, const char* filename)
{
    STACK_ASSERT(ad_stack, filename);

    if (ad_stack->size == ad_stack->capacity)
    {
        StackRealloc(ad_stack, filename);
    }
    
    ad_stack->data[ad_stack->size] = elem;
    ad_stack->size++;

    STACK_ASSERT(ad_stack, filename);           
}


void StackPop(struct Stack_t *ad_stack, StackElem_t* x, const char* filename)
{
    STACK_ASSERT(ad_stack, filename);
    
    *x = ad_stack->data[ad_stack->size];
    ad_stack->size--;
    
    STACK_ASSERT(ad_stack, filename);
}


void StackRealloc(struct Stack_t *ad_stack, const char* filename)
{
    STACK_ASSERT(ad_stack, filename);

    ad_stack->capacity  = 2 * ad_stack->capacity;
    ad_stack->data = (StackElem_t *)realloc(ad_stack->data, sizeof(StackElem_t) * ad_stack->capacity);
    FillPoisonValue(ad_stack);

    STACK_ASSERT(ad_stack, filename);             
}

void FillPoisonValue(struct Stack_t *ad_stack)
{
    for (int i = ad_stack->size; i < ad_stack->capacity; i++) {
        ad_stack->data[i] = POIZON_VALUE_FOR_DATA;
    }
}


void StackDestructor(struct Stack_t *ad_stack)
{
    assert(ad_stack != NULL);
    free(ad_stack->data);
    ad_stack->size = POIZON_VALUE_FOR_SIZE;
    ad_stack->capacity = POISON_VALUE_FOR_CAPACITY;
}

