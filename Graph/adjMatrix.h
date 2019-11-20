//
// Created by LYL on 2019/11/19.
//

#ifndef DATAANDSTRUCT_ADJMATRIX_H
#define DATAANDSTRUCT_ADJMATRIX_H

#include "graph.h"
#include <iostream>
using namespace std;
template<class VertexType, class EdgeType>
class adjMatrix : public graph<VertexType, EdgeType> {
private:
    void dfs(int start) const {

    }
//从start顶点出发深度优先遍历图
public:
    EdgeType noEdge;//无边标志
    EdgeType **edges;//邻接矩阵
    VertexType *vertexs;//顶点向量
    adjMatrix(int size, EdgeType noEdgeFlag) {
        this->verNum = size;
        this->edgeNum = 0;
        this->noEdge = noEdgeFlag;
        vertexs = new VertexType[this->verNum];
        for (int i = 0; i < this->verNum; ++i) {
            edges[i] = new EdgeType[this->verNum];
            for (int j = 0; j < this->verNum; ++j) {
                edges[i][j] = noEdge;
            }
        }
        this->visited = new bool[this->verNum];
//        this->TE = this->mstEdge[this->verNum-1];//最小生成树的边集
    }

    ~adjMatrix() {
        delete [] vertexs;
        for (int i = 0; i < this->verNum; ++i) {
            delete [] edges[i];
        }
        delete edges;
        delete this->visited;
        delete this->TE;
    }

    void createGraph(const VertexType V[], const EdgeType E[]);

    void printGraph() const override;

    bool searchEdge(int from, int to) const override;

    void dfsTraverse() const override;

    void bfsTraverse() const override;

    bool topSort() const override;

    void prim(EdgeType noEdge) const override;

    void kruskal() const override;

    void printMst() const override;

    bool insertEdge(int from, int to, EdgeType w) override;

    bool removeEdge(int from, int to) override;

    void createGraph(VertexType vertex[], int vlen, EdgeType **edge, int elen ) {
        int i, p1, p2;
        //初始化顶点和边数
        this->verNum = vlen;
        this->edgeNum = elen;
        //初始化顶点
        for (int i = 0; i < this->verNum; ++i) {
            this->vertexs[i] = vertex[i];
        }
        //初始化边
        for (int i = 0; i < this->verNum; ++i) {
            for (int j = 0; j < this->verNum; ++j) {
                edges[i][j] = edge[i][j];
            }
        }
    }
};

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::createGraph(const VertexType *V, const EdgeType *E) {
    //V为顶点数组，E为经过降维的邻接矩阵
    int i, j;
    for (i = 0; i < this->verNum; ++i) {
        vertexs[i] = V[i];
    }
    for (i = 0; i < this->verNum; ++i) {
        for (j = 0; j < this->verNum; ++j) {
            if(E[i * this->verNum + j] > 0){
                insertEdge(i, j, E[i * this->verNum + j]);
//                insertEdge(i, j, 0);
            }
        }
    }
    cout<<"create successful"<<endl;
}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::dfsTraverse() const {

}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::bfsTraverse() const {

}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::topSort() const {
    return false;
}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::prim(EdgeType noEdge) const {

}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::kruskal() const {

}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printMst() const {

}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::searchEdge(int from, int to) const {
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum -1)
        return false;
    if (edges[from][to] == noEdge)
        return false;
    else
        return true;
}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w) {
    if (from < 0 || from > this->verNum -1 || to < 0 || to > this->verNum -1)
        return false;
    if (edges[from][to] == w)
        return false;
    if (edges[from][to] == noEdge)
        ++this->edgeNum;
    edges[from][to] = w;
    return true;
}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::removeEdge(int from, int to) {
    if (from < 0 || from > this->verNum -1 || to < 0 || to > this->verNum -1)
        return false;
    if (edges[from][to] == noEdge)
        return false;
    edges[from][to] = noEdge;
    --this->edgeNum;
    return true;

}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printGraph() const {
    int i, j;
    for (int i = 0; i < this->verNum; ++i) {
        cout<<vertexs[i]<<":";
        for (int j = 0; j < this->verNum; ++j) {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
}

#endif //DATAANDSTRUCT_ADJMATRIX_H
