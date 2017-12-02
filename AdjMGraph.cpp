//
// Created by antonio on 17-11-29.
//

#include <cstdlib>
#include <cstdio>
#include "AdjMGraph.h"


void ListInitiate(SeqList *L){
    L->size = 0 ;
}


int ListInsert(SeqList *L, int i, DataType x){
    if (i >= MaxSize || i < 0){
        printf("插入失敗,參數有誤\n") ;
    }
    else{
        for (int j = L->size; j > i; j--) {
            L->list[j] = L->list[j - 1] ;
        }

        L->list[i] = x ;
        L->size ++ ;

    }
    return 1 ;
}



void Initiate(AdjMGraph *G, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                G->edge[i][j] = 0 ;
            else
                G->edge[i][j] = MaxWeight ;//MaxWeight视为无穷大
        }
    }
    G->numOfEdges = 0 ;//边的条数0
    //Node**初始化顺序表
    ListInitiate(&G->Vertices) ;
}

void InsertVertex(AdjMGraph *G, DataType vertex){
    //在图中增加一个顶点
    ListInsert(&G->Vertices, G->Vertices.size, vertex);
}

void InsertEdge(AdjMGraph *G, int v1, int v2, int weight){
    //在图中增加一条有向边，对于增加一条无向边可通过增加两条有向边完成
    if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }
    G->edge[v1][v2] = weight;
    G->numOfEdges++;
}

void DeleteEdge(AdjMGraph *G, int v1, int v2){
    //在图中取消一条有向边
    if(v1 < 0 || v1 > G->Vertices.size || v2 < 0
       ||  v2 > G->Vertices.size || v1 == v2) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }

    if(G->edge[v1][v2] == MaxWeight || v1 == v2) {
        printf("该边不存在!\n"); 	exit(0);
    }

    G->edge[v1][v2] = MaxWeight;
    G->numOfEdges--;
}

int GetFirstVex(AdjMGraph G, int v){
    //在图G中寻找序号为v的顶点的第一个邻接顶点
    //如果这样的顶点存在，则返回该邻接顶点的序号，否则返回-1
    int col;

    if(v < 0 || v > G.Vertices.size) {
        printf("参数v1越界出错!\n");
        exit(1);
    }

    for(col = 0; col <= G.Vertices.size; col++)
        if(G.edge[v][col] > 0 &&G.edge[v][col] < MaxWeight)
            return col;
    return -1;
}


int GetNextVex(AdjMGraph G, int v1, int v2){
    //在图中寻找V1顶点的邻接顶点V2的下一个邻接顶点
    //如果这样的邻接顶点存在，则返回该邻接顶点的序号，否则返回-1
    int col;
    if(v1 < 0 || v1 > G.Vertices.size || v2 < 0 || v2 > G.Vertices.size) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }

    for(col = v2+1; col <= G.Vertices.size; col++)
        if(G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight)
            return col;
    return -1;
}
