/***********************************************************************************/
/* Author : FAROUK                                                                */
/* Date   : 21 SEP 2020                                                           */
/* Version: V01                                                                   */
/**********************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 10

#define QueueType int

// this is Queue
typedef struct
{
    int size;
    int front;
    int rear;
    QueueType Qdata[MAX_SIZE];
}Queue;

/* function declaration */

void QCreat(Queue* pq); // Initialization of queue members

int push(QueueType value , Queue* pq);// push value into Qdata 

void push_v(QueueType value , Queue* pq);// push value into Qdata (different technique)

int QFull(Queue* pq);

int QEmpty(Queue* pq);

void pop(QueueType* pvalue , Queue* pq);

void QTop(QueueType* pvalue , Queue* pq);

int Qsize(Queue* pq);

void clearQ(Queue* pq);

void traverseQ(Queue *pq , void (*pf)(QueueType));

#endif