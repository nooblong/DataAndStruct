public abstract class Graph<VertexType,EdgeType> {

    protected int verNum, edgeNum;
    Boolean visited[];
    protected MstEdge[] TE;

    protected class MstEdge {
        int vex1, vex2;
        EdgeType weight;

        @Override
        public boolean equals(Object obj) {
            return weight.equals(((MstEdge)obj).weight);
        }
    }

    public int numOfVertex(){
        return verNum;
    }

    public int numOfEdge(){
        return edgeNum;
    }

    abstract void createGraph(final VertexType[] V, final EdgeType[] E, int num);
    abstract void dfsTraverse();
    abstract void bfsTraverse();
    abstract boolean topSort();
    abstract void prim();
    abstract void kruskal();
    abstract void printMst();
    abstract boolean searchEdge(int from, int to);
    abstract boolean insertEdge(int from, int to, EdgeType w);
    abstract boolean removeEdge(int from, int to);
    abstract void printGraph();
}