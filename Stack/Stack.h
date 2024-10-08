#ifndef READING_H
#define READING_H

#include <TXLib.h>

//#define DEBUG
#define NO_ITEMS 0
#define FILENAME 
typedef double StackElem_t;


#ifdef DEBUG                                                    
    #define ON_DEBUG(...) __VA_ARGS__
#else
    #define ON_DEBUG(...)
#endif                                                                   

#ifdef DEBUG
    #define STACK_CTOR(ad_stack, capacity, filename) \
            StackCtor(ad_stack, capacity, filename, #stack, __FILE__, __LINE__)
#endif
    #define STACK_CTOR(ad_stack, capacity, filename) \
            StackCtor(ad_stack, capacity, filename)

#define STACK_ASSERT(ad_stack, filename) \
        StackAssertFunc(ad_stack, filename/*, __FILE__, __LINE__*/)


const StackElem_t POIZON_VALUE_FOR_DATA = (StackElem_t)0xDEDEBEDBAD;            //что опроисходит с 16ричным числом ?
const int POIZON_VALUE_FOR_SIZE = (int)0xBADCAFE;
const int POISON_VALUE_FOR_CAPACITY = (int)0xFEEDDEDBAD;


struct Stack_t
{
    // canary_t

    StackElem_t* data;
    int size;
    int capacity;
    int status;
    ON_DEBUG(const char* name;)
    ON_DEBUG(const char* file;)
    ON_DEBUG(int line;)

    // canary_t
};


void StackCtor(struct Stack_t *ad_stack, int capacity, const char* filename ON_DEBUG(, const char* name, const char* file, int line));
void StackRealloc(struct Stack_t *ad_stack, const char* filename);
void FillPoisonValue(struct Stack_t *ad_stack);
void StackPush(struct Stack_t *ad_stack, StackElem_t elem, const char* filename);
void StackPop(struct Stack_t *ad_stack, StackElem_t* x, const char* filename);
void StackDestructor(struct Stack_t *ad_stack);
void PrintStack(struct Stack_t *ad_stack);

#endif