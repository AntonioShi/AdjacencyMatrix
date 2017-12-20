#include <iostream>
typedef int DataType ;
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "AdjMGraphTraverse.h"

using namespace std ;

void Visit(DataType it){
    printf("%c ", it) ;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMGraph g1;
    DataType a[] = {'A','B','C','D','E','F', 'G', 'H'};
    RowColWeight rcw[] = {{0,1,10}, {0,4,20}, {1,3,30}, {2,1,40},
                          {3,2,50}, {1,4,30}, {2,3,40}, {3,4,50}};
    int n = 8, e = 8;
    int i, j;
    CreatGraph(&g1, a, n, rcw, e);
    //DeleteEdge(&g1, 0, 4);//删除一条边
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

    printf("深度优先遍历\n") ;
//    int visit[] = {0, 0, 0, 0, 0, 0, 0, 0};
    DepthFirstSearch(g1, Visit) ;
    printf("\n") ;
    BroadFirstSearch(g1,Visit) ;
    return 0;
}

