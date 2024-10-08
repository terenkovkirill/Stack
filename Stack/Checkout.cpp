#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include "Checkout.h"


void StackAssertFunc(struct Stack_t *ad_stack, const char* filename /*, const char* file, int line*/)         //фигово написано
{
    StackErr_t err = StackError(ad_stack);
    if (err != STACK_NULL) {
        ad_stack->status = err;
    }

    if (err != STACK_NO_ERROR)
    {
        STACK_DUMP(ad_stack, filename);          
        assert(0);
    }
}


StackErr_t StackError(struct Stack_t *ad_stack)  
{
    if (!ad_stack)
    {
        return STACK_NULL;
    }
    
    if (!ad_stack->data)
    {
        return STACK_DATA_NULL;
    }

    if (ad_stack->size < 0)
    {
        return STACK_SIZE_LESS_THAN_ZERO;
    }

    if (ad_stack->size > ad_stack->capacity)
    {
        return STACK_SIZE_MORE_THAN_CAPACITY;
    }

    return STACK_NO_ERROR;
}


StackErr_t StackDump(struct Stack_t *ad_stack, const char* filename, const char* file, int line)         //фигово написано
{
     FILE* fileptr = fopen(filename, "wb");

    fprintf(fileptr, "called from %s : %d \n", file, line);
    fprintf(fileptr, "address stack = %p \n", ad_stack);

    if (ad_stack == NULL) {
        fclose(fileptr);
        return STACK_NULL;
    }

    fprintf(fileptr, "error: %d\n", ad_stack->status);
    fprintf(fileptr, "address data = %p \n", ad_stack->data);
    fprintf(fileptr, "stack size = %d \n", ad_stack->size);
    fprintf(fileptr, "stack capacity = %d \n", ad_stack->capacity);
    fprintf(fileptr, "\n \n");

    fclose(fileptr);

    return STACK_NO_ERROR;
}





