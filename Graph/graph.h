//
// Created by LYL on 2019/11/19.
//

#ifndef DATAANDSTRUCT_GRAPH_H
#define DATAANDSTRUCT_GRAPH_H

template<class VertexType, class EdgeType>
class graph {

protected:
    struct mstEdge {
        int vex1, vex2;
        EdgeType weight;
        bool operator<(const mstEdge &e) const {
            return weight < e.weight;
        }
    };
    mstEdge *TE = new mstEdge;
    bool *visited;
    int verNum, edgeNum;//顶点数，边数
public:
    int numOfVertex() const { return verNum;}
    int numOfEdge() const { return edgeNum;}
    virtual void createGraph(const VertexType V[], const EdgeType E[]) = 0;
    virtual void dfsTraverse()const = 0;
    virtual void bfsTraverse()const = 0;
    virtual bool topSort()const = 0;//拓扑排序
    virtual void prim(EdgeType noEdge)const = 0;//prim算法
    virtual void kruskal()const = 0;//Kruskal算法
    virtual void printMst()const = 0;//输出最小生成树
    virtual void searchEdge(int from, int to)const = 0;//查找边
    virtual bool insertEdge(int from, int to, EdgeType w) = 0;//插入权值为w的边
    virtual bool removeEdge(int from, int to) = 0;//删除边
    virtual void printGraph()const = 0;//输出图
};

#endif //DATAANDSTRUCT_GRAPH_H
