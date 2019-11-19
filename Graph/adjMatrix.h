//
// Created by LYL on 2019/11/19.
//

#ifndef DATAANDSTRUCT_ADJMATRIX_H
#define DATAANDSTRUCT_ADJMATRIX_H

#include "graph.h"
template <class VertexType, class EdgeType>
class adjMatrix : public graph<VertexType,EdgeType>{
private:
    VertexType *vertexs;//顶点向量
    EdgeType **edges;//邻接矩阵
    EdgeType noEdge;//无边标志
    void dfs(int start)const ;//从start顶点出发深度优先遍历图
public:
    adjMatrix(int size, EdgeType noEdgeFlag);
    ~adjMatrix();
    void createGraph(const VertexType V[], const EdgeType E[]);

    void dfsTraverse() const override;

    void bfsTraverse() const override;

    bool topSort() const override;

    void prim(EdgeType noEdge) const override;

    void kruskal() const override;

    void printMst() const override;

    void searchEdge(int from, int to) const override;

    bool insertEdge(int from, int to, EdgeType w) override;

    bool removeEdge(int from, int to) override;

    void printGraph() const override;
};

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::createGraph(const VertexType *V, const EdgeType *E) {

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
void adjMatrix<VertexType, EdgeType>::searchEdge(int from, int to) const {

}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w) {
    return false;
}

template<class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::removeEdge(int from, int to) {
    return false;
}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printGraph() const {

}

#endif //DATAANDSTRUCT_ADJMATRIX_H
