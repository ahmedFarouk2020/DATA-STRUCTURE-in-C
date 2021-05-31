/*               LL BASED STACK                     */
/*******************************************************/
#ifndef STACK_H_
#define STACK_H_

#define stacktype int

/* NODE CREATION */
typedef struct Node
{
    stacktype data; /* data */
    struct Node* next;
}node;

/* STACK */
typedef struct
{
    node *top;
}Stack;


/* FUNCTION DECLARATIONS */

void createStack(Stack* ps);

/* SPECIAL CASES IS SPECIFIED (PUSH FRONT) */
int push(stacktype value , Stack* ps);

/* PE IS A POINTER TO NODE THAT WILL BE POPED (POP FRONT) */
void pop(stacktype* pe , Stack* ps);

int stackEmpty(Stack* ps);

void clearStack(Stack* ps);

void traverseStack(Stack* ps , void (*pf)(stacktype) );

int stackSize(Stack* ps);

#endif