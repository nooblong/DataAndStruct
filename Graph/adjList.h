//
// Created by lyl on 2019/11/21.
//

#ifndef DATAANDSTRUCT_ADJLIST_H
#define DATAANDSTRUCT_ADJLIST_H

#include "graph.h"
using namespace std;
class mstEdge;

template <class VertexType, class EdgeType>
class adjList : public graph<VertexType, EdgeType>{
private:
    struct edgeNode{
        int to;//边的终点符号，在顶点表中的下标
        EdgeType weight;//边上的权值
        edgeNode *next;//
        edgeNode(){}
        edgeNode(int t, EdgeType w, edgeNode *n = nullptr){
            to = t;
            weight = w;
            next = n;
        }
    };
    struct verNode{
        VertexType vertex;//顶点信息
        edgeNode *firstEdge;
        verNode(edgeNode *h = nullptr){
            firstEdge = h;
        }
    };

    verNode *verList;
    int *topOrder;
    void dfs(int start) const;

public:
    adjList(int size) {
         this->verNum = size;
         this->edgeNum = 0;
         verList = new verNode[size];
         this->visited = new bool[size];
         this->TE = new mstEdge[verNum - 1];
    }

    ~adjList() {

    }

    void createGraph(const VertexType *V, const EdgeType *E) override;

    void dfsTraverse() const override;

    void bfsTraverse() const override;

    bool topSort() const override;

    void prim(EdgeType noEdge) const override;

    void kruskal() const override;

    void printMst() const override;

    bool searchEdge(int from, int to) const override;

    bool insertEdge(int from, int to, EdgeType w) override;

    bool removeEdge(int from, int to) override;

    void printGraph() const override;
};

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::createGraph(const VertexType *V, const EdgeType *E) {

}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::dfsTraverse() const {

}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::bfsTraverse() const {

}

template<class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::topSort() const {
    return false;
}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::prim(EdgeType noEdge) const {

}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::kruskal() const {

}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::printMst() const {

}

template<class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::searchEdge(int from, int to) const {
    return false;
}

template<class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w) {
    return false;
}

template<class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::removeEdge(int from, int to) {
    return false;
}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::printGraph() const {

}

template<class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::dfs(int start) const {

}

#endif //DATAANDSTRUCT_ADJLIST_H
