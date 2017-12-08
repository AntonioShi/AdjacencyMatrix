//
// Created by antonio on 17-12-8.
//

#ifndef ADJACENCYMATRIX_ADJMGRAPHTRAVERSE_H
#define ADJACENCYMATRIX_ADJMGRAPHTRAVERSE_H

#include <malloc.h>
#include "AdjMGraphCreate.h"
#include "AdjMGraph.h"

//连通图G以v为初始顶点、访问操作为Visit（）的深度优先遍历
void DepthFSearch(AdjMGraph G, int v, int visited[],
                  void Visit(DataType item)){
    //
    int w ;
    Visit(G.Vertices.list[v]) ;//访问顶点v
    visited[v] = 1 ;//标记变量
    w = GetFirstVex(G, v) ;//取第一个临接顶点

    while (w != -1){
        if(! visited[w]){
            DepthFSearch(G, w, visited, Visit);//递归
        }
        w = GetNextVex(G, v, w) ;//取下一个临接顶点
    }
}

//非连通图的深度优先遍历
void DepthFistSearch(AdjMGraph G, void Visit(DataType item)){
    int i ;
    int *visited = (int *)malloc(sizeof(int) * G.Vertices.size) ;

    for (i = 0; i < G.Vertices.size; ++i) {
        visited[i] = 0 ;//访问标记初始为0
    }
    for (i = 0; i < G.Vertices.size; ++i) {
        if (! visited[i]){
            DepthFSearch(G, i, visited, Visit) ;//以每个顶点为初始顶点进行调用
        }
    }
    free(visited) ;//
}

//连通图的广度优先遍历
#include "SeqCQueue.h"//顺序循环队列
//稍后自会创建循环队列的demo
void BroadFSearch(AdjMGraph G, int v, int visited[],
                  void Visit(DataType item)){
    //
    int u, w ;
    SeqCQueue cqueue ;
    Visit(G.Vertices.list[v]) ;//访问v
    visited[v] = 1 ;//标记
    QueueInitate(&cqueue) ;//初始化
    QueueAppend(&cqueue, v) ;//添加

    while (QueueNotEmpty(cqueue)){//若非空
        QueueDelete(&cqueue, &u) ;//出队列
        w = GetFirstVex(G, u) ;//取u的第一个临接顶点w

        while (w != -1){//若w存在
            if (! visited[w]){//且没有被访问过

                Visit(G.Vertices.list[w]) ;//访问
                visited[w] = 1 ;//标记
                QueueAppend(&cqueue, w) ;//添加w入队
            }
            w = GetNextVex(G, u, w) ;//取下一个临接顶点
        }
    }

}

//非连通图的广度优先遍历
void BroadFirstSearch(AdjMGraph G, void Visit(DataType item)){
    //
    int i ;
    int *visited = (int *)malloc(sizeof(int) * G.Vertices.size) ;

    for (i = 0; i < G.Vertices.size; ++i) {
        visited[i] = 0 ;
    }
    for (i = 0; i < G.Vertices.size; ++i) {
        if (! visited[i])
            BroadFSearch(G, i, visited, Visit) ;
    }
    free(visited) ;
}

#endif //ADJACENCYMATRIX_ADJMGRAPHTRAVERSE_H
