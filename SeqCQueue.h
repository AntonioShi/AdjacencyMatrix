//
// Created by antonio on 17-12-11.
//

#ifndef ADJACENCYMATRIX_SEQCQUEUE_H
#define ADJACENCYMATRIX_SEQCQUEUE_H
#include <stdio.h>
typedef int DataType ;
#define MaxQueueSize 6

typedef struct {
    DataType queue[MaxQueueSize] ;
    int rear ;
    int front ;
    int count ;
}SeqCQueue;

void QueueInitiate(SeqCQueue *Q) ;

int QueueNotEmpty(SeqCQueue Q) ;

int QueueAppend(SeqCQueue *Q, DataType x) ;

int QueueDelete(SeqCQueue *Q, DataType *x) ;

int QueueGet(SeqCQueue Q, DataType *x) ;

#endif //ADJACENCYMATRIX_SEQCQUEUE_H
