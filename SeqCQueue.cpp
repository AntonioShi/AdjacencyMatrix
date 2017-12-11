//
// Created by antonio on 17-12-11.
//

#include "SeqCQueue.h"

void QueueInitiate(SeqCQueue *Q){
    Q->front = 00 ;//tou
    Q->rear = 0 ;//wei
    Q->count = 0 ;//
}

int QueueNotEmpty(SeqCQueue Q){
    if(Q.count)
        return 1 ;
    return 0 ;
}

int QueueAppend(SeqCQueue *Q, DataType x){
    if(Q->count > 0 && Q->rear == Q->front){
        printf("队列已满， 无法插入元素\n") ;
        return 0 ;
    }
    Q->queue[Q->rear] = x ;
    Q->rear = (Q->rear + 1) % MaxQueueSize ;//对尾指示器+1,计算出循环下标
    Q->count ++ ;
    return 1 ;
}

int QueueDelete(SeqCQueue *Q, DataType *x){
    if (!Q->count){
        printf("队列已空\n") ;
        return 0 ;
    }
    *x = Q->queue[Q->front] ;
    Q->front = (Q->front + 1) % MaxQueueSize ;
    Q->count-- ;
    return 1 ;
}

int QueueGet(SeqCQueue Q, DataType *x){
    if (!Q.count){
        printf("队列已空\n") ;
        return 0 ;
    }
    *x = Q.queue[Q.front] ;
    return 1 ;
}