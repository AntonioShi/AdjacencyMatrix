//
// Created by antonio on 17-11-29.
//

#ifndef ADJMGRAPH_ADJMGRAPH_H
#define ADJMGRAPH_ADJMGRAPH_H


#define MaxVertices 10
#define MaxWeight 10000

//#include "SeqList.h"


#define MaxSize 100
typedef int DataType ;

//静态指针：伪指针
typedef struct {
    DataType list[MaxSize] ;
    int size ;
}SeqList;


//邻接矩阵的存储方法
typedef struct {
    SeqList Vertices ;
    int edge[MaxVertices][MaxVertices] ;
    int numOfEdges ;
}AdjMGraph;

typedef struct {
    int row;			//行下标
    int col;				//列下标
    int weight;			//权值
} RowColWeight ;

void Initiate(AdjMGraph *G, int n) ;

void InsertVertex(AdjMGraph *G, DataType vertex) ;

void InsertEdge(AdjMGraph *G, int v1, int v2, int weight) ;

void CreatGraph(AdjMGraph *G, DataType V[], int n, RowColWeight E[],   int e) ;

void DeleteEdge(AdjMGraph *G, int v1, int v2) ;

//int GetFirstVex(AdjMGraph G, int v) ;
//
//int GetNextVex(AdjMGraph G, int v1, int v2) ;

void ListInitiate(SeqList *L) ;

int ListInsert(SeqList *L, int i, DataType x) ;


#endif //ADJMGRAPH_ADJMGRAPH_H
