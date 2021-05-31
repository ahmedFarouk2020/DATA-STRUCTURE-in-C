/*               LL BASED STACK                     */
/*******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "LL_stack.h"

void createStack(Stack* ps)
{
    ps->top = NULL;
}

/* SPECIAL CASES IS SPECIFIED (PUSH FRONT) */
int push(stacktype value , Stack* ps)
{
    node* pn = (node*) malloc(sizeof(node));
    pn ->data =value;
    pn ->next = ps ->top;
    ps ->top = pn;
}

/* PE IS A POINTER TO NODE THAT WILL BE POPED (POP FRONT) */
void pop(stacktype* pe , Stack* ps)
{
    node* pn = ps ->top; 
    *pe = ps ->top ->data;
    ps ->top = ps ->top ->next;
    free(pn);
}

int stackEmpty(Stack* ps)
{
    return(ps ->top == NULL);
}

void clearStack(Stack* ps)
{
    node* pn = ps->top;
    while(pn)
    {
        pn = pn->next;
        free( ps->top);
        ps->top = pn ;
    }
}

void traverseStack(Stack* ps , void (*pf)(stacktype) )
{
    node* pn = ps->top;
    printf("[ ");
    while(pn)
    {
        pf(pn->data);
        pn = pn->next;
        printf(", ");
    }
    printf(" ]\n");
}

int stackSize(Stack* ps)
{
    node* pn = ps->top;
    int x=0;
    for(x=0 ; pn ; pn=pn->next)
        x++;
    return x;
}
/* we can optimize stackSize by adding a member (size) into the struct stack the the fn will be O(1) */
/* THIS FN SHOUD BE IN USER LEVEL BECAUSE THE USER KNOW THE DATATYPE OF STACKENTRY */
void display(stacktype data)
{
    printf("%d",data);
}

void main()
{
    Stack s;
    stacktype data;
    void (*pf)(stacktype) = display;
    createStack(&s);
    push(50,&s);
    push(50,&s);
    push(50,&s);
    push(50,&s);
    traverseStack(&s , pf);
    printf("ssdfdf");
}