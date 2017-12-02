#include <iostream>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

using namespace std ;


int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMGraph g1;
    DataType a[] = {'A','B','C','D','E'};
    RowColWeight rcw[] =
            {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
    int n = 5, e = 5;
    int i, j;
    CreatGraph(&g1, a, n, rcw, e);
    DeleteEdge(&g1, 0, 4);
//    DeleteVertex(&g1, 3);//删除顶点的函数
    printf("顶点集合为：");
    for(i = 0; i < g1.Vertices.size; i++)
        printf("%c   ", g1.Vertices.list[i]);
    printf("\n");
    printf("权值集合为：\n");

    for(i = 0; i < g1.Vertices.size; i++) {
        for(j = 0; j < g1.Vertices.size; j++)
            printf("%5d   ", g1.edge[i][j]);
        printf("\n");
    }

    return 0;
}

