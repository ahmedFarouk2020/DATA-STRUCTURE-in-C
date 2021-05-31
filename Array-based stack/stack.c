/*                BASED-ARRAYS STACK                 */
/*****************************************************/
#include "stack.h"
#include <stdio.h>
void creatStack(Stack* ptr_s)
{
    ptr_s->top = 0;
}

int push(StackEntry value , Stack* ptr_s)
{
    if(ptr_s->top == MAXSTACK)
        return 0;
    else    
    {
        ptr_s->entry[ptr_s->top++] = value ;
        return 1;
    }    
}

void push_v(StackEntry value , Stack* ptr_s)
{
    ptr_s->entry[ptr_s->top++] = value ;
}

int StackFull(Stack* ptr_s)
{
    return((ptr_s->top == MAXSTACK));
}

int StackEmpty(Stack* ptr_s)
{
    return((ptr_s->top == 0));
}

void pop(StackEntry* pe , Stack* ptr_s)
{
    *pe = ptr_s->entry[-- ptr_s->top];
}

void stackTop(StackEntry* pe , Stack* ptr_s) //check if the stack empty
{
    *pe = ptr_s->entry[ptr_s-> top-1];
}

int stackSize(Stack* ptr_s)
{
    return ptr_s->top ;
}

void clearStack(Stack* ptr_s)
{
    ptr_s->top = 0;
}

void traverse(Stack *ps , void (*pf)(StackEntry))
{
    printf("[ ");
    for(int i = ps->top - 1 ; i >= 0 ; i--)
    {
        pf(ps -> entry[i]);
        printf(",");
    }
    printf(" ]\n");
}

/* the code below is just to know how to use the above functions */

/* THIS FN SHOUD BE IN USER LEVEL BECAUSE THE USER KNOW THE DATATYPE OF STACKENTRY */
void display(StackEntry data)
{
    printf("%d",data);
}

int main()
{
    Stack s;
    StackEntry e = 10;
    void (*pf)(StackEntry) = display;

    creatStack(&s);

    if(!StackFull(&s))
    {
        push(e , &s);
    }
    if(!StackEmpty(&s))
        pop(&e , &s);   
    
    push_v(45 , &s);
    traverse(&s , pf);
    return 0;
    
}