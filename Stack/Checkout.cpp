#include <TXLib.h>
#include <stdio.h>
#include <assert.h>


void StackAssertFunc(struct Stack_t *ad_stack, const char* filename /*, const char* file, int line*/)         //фигово написано
{
    ad_stack->status = StackError(ad_stack);
    if (ad_stack->status != STACK_NO_ERROR)
    {
        STACK_DUMP(ad_stack, filename);           
        assert(0);
    }
}


int StackError(struct Stack_t *ad_stack)  
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


void StackDump(struct Stack_t *ad_stack, const char* filename, const char* file, int line)         //фигово написано
{
    FILE* fileptr = fopen(filename, "wb");
    
    fprintf(fileptr, "error: %d", ad_stack->status);
    fprintf(fileptr, "error: %d", ad_stack->status);
    fprintf(fileptr, "called from %s : %d \n", file, line);
    fprintf(fileptr, "address stack = %p \n", ad_stack);
    fprintf(fileptr, "address data = %p \n", ad_stack->data);
    fprintf(fileptr, "stack size = %d \n", ad_stack->size);
    fprintf(fileptr, "stack capacity = %d \n", ad_stack->capacity);
    fprintf(fileptr, "\n \n");

    fclose(fileptr);
}





