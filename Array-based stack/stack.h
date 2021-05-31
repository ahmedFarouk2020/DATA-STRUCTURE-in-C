#ifndef STACK_H_
#define STACK_H_

/* MAX NUM OF ELEMENT IN STACK IS 100 */
#define MAXSTACK 100

/* REMEBER TO CHANGE THE FN diplay ACCORDING TO THIS */
#define StackEntry int

typedef struct
{
    int top; /* POINTS TO THE LOCATION IN WHICH WE PUT THE DATA (ACCESS THEN INCREAMENT) */
    StackEntry entry[MAXSTACK];
}Stack;

void creatStack(Stack* ptr_s);

// return type is int to test whether a value is pushed or not
int push(StackEntry value , Stack* ptr_s); 

void push_v(StackEntry value , Stack* ptr_s);

int StackFull(Stack* ptr_s);

int StackEmpty(Stack* ptr_s);

void pop(StackEntry* pe , Stack* ptr_s);

void stackTop(StackEntry* pe , Stack* ptr_s); //check if the stack empty


int stackSize(Stack* ptr_s);


void clearStack(Stack* ptr_s);


void traverse(Stack *ps , void (*pf)(StackEntry));

#endif
