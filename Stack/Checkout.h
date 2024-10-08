#include <TXLib.h>
#include "Stack.h"

#define STACK_DUMP(ad_stack, filename)  \
        StackDump(ad_stack, filename, __FILE__, __LINE__)

enum StackError {
    STACK_NO_ERROR = 0,
    STACK_NULL = 1,
    STACK_DATA_NULL = 2,
    STACK_SIZE_LESS_THAN_ZERO = 3,
    STACK_SIZE_MORE_THAN_CAPACITY = 4,
};


void StackAssertFunc(struct Stack_t *ad_stack, const char* filename/*, const char* file, int line*/);
int StackError(struct Stack_t *ad_stack);
void StackDump(struct Stack_t *ad_stack, const char* filename, const char* file, int line);