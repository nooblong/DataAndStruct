public class AdjList<Vertex, Edge> extends Graph<Vertex, Edge> {
    //边节点类型
    private class EdgeNode {
        int to;//边的终点编号
        Edge weight;
        EdgeNode next;

        EdgeNode() {
        }

        EdgeNode(int to, Edge weight, EdgeNode next) {
            this.to = to;
            this.weight = weight;
            this.next = next;
        }
    }

    //顶点节点类型
    private class VerNode {
        Vertex vertex;//顶点信息
        EdgeNode firstEdge;
    }

    @Override
    void createGraph(Vertex[] V, Edge[] E) {

    }

    @Override
    void dfsTraverse() {

    }

    @Override
    void bfsTraverse() {

    }

    @Override
    boolean topSort() {
        return false;
    }

    @Override
    void prim() {

    }

    @Override
    void kruskal() {

    }

    @Override
    void printMst() {

    }

    @Override
    boolean searchEdge(int from, int to) {
        return false;
    }

    @Override
    boolean insertEdge(int from, int to, Edge w) {
        return false;
    }

    @Override
    boolean removeEdge(int from, int to) {
        return false;
    }

    @Override
    void printGraph() {

    }
}
