/***********************************************************************************/
/* Author : FAROUK                                                                */
/* Date   : 21 SEP 2020                                                           */
/* Version: V02                                                                   */
/**********************************************************************************/
#include <stdio.h>
#include "queue.h"

int QFull(Queue* pq)
{
    return(pq->size == MAX_SIZE);
}

int QEmpty(Queue* pq)
{
    return(pq->size == 0);
}

void QCreat(Queue* pq)
{
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}

void push_v(QueueType value , Queue* pq)
{
    if(! QFull(pq) )
    {    
        pq->Qdata[++pq->rear] = value;
        pq->size++;
    }
}


void pop(QueueType* pvalue , Queue* pq)
{
    *pvalue = pq->Qdata[pq->front++];
    pq->size --;
}

void QTop(QueueType* pvalue , Queue* pq)
{
    *pvalue = pq->Qdata[pq->front];
}

int Qsize(Queue* pq)
{
    return pq->size;
}

void clearQ(Queue* pq)
{
    pq->size =  0;
    pq->front = 0;
    pq->rear = -1;
}

void traverseQ(Queue *pq , void (*pf)(QueueType))
{
    printf("[ ");
    for(int i=0; i<pq->size; i++){

       pf(pq->Qdata[pq->front + i]);
       printf(", ");
    }
    printf(" ]\n");
}

/* THIS FN SHOUD BE IN USER LEVEL BECAUSE THE USER KNOW THE DATATYPE OF STACKENTRY */
void display(QueueType data)
{
    printf("%d",data);
}

int main()
{
    Queue q;
    QueueType e = 10;
    void (*pf)(QueueType) = display;

    QCreat(&q);

    push_v(45 , &q);
    push_v(45 , &q);
    push_v(45 , &q);
    traverseQ(&q , pf);
    return 0;
}