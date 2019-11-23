import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AdjList<Vertex, Edge> extends Graph<Vertex, Edge> {

    public static void main(String[] args) {
        AdjList<String, Integer> adjList = new AdjList<>(5, String.class, Integer.class);
        adjList.createGraph(new String[]{"v1","v2","v3","v4","v5"}, new Integer[]{
                0, 1, 1, 0, 0,
                1, 0, 0, 0, 1,
                1, 0, 0, 1, 1,
                0, 0, 1, 0, 1,
                0, 1, 1, 1, 0});
        adjList.printGraph();

    }

    public void test(AdjList adjList) {

    }

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
    class VerNode {
        public Vertex vertex;//顶点信息
        EdgeNode firstEdge;

        VerNode(EdgeNode firstEdge) {
            this.firstEdge = firstEdge;
        }
    }

    VerNode[] verList;
    int[] topOrder;//拓bu序列

    void dfs(int start) {
        //从start开始深度优先遍历图
    }

    AdjList(int size, Class<Vertex> vertexType, Class<Edge> edgeType) {
        verNum = size;
        edgeNum = 0;
        verList = (VerNode[]) Array.newInstance(VerNode.class, size);
        visited = new Boolean[verNum];
        TE = (MstEdge[]) Array.newInstance(MstEdge.class, verNum - 1);
        topOrder = new int[verNum];

        for (int i = 0; i < verList.length; i++) {
            verList[i] = new VerNode(null);
        }

    }

    @Override
    void createGraph(Vertex[] V, Edge[] E) {
        int i, j;
        for (i = 0; i < verNum; i++) {
            verList[i].vertex = V[i];
        }
        for (i = 0; i < verNum; i++) {
            int startNum = i*5;
            for (int k = 0; k < verNum; k++) {
                if (!E[k + startNum].equals(0)){
                    //如果不是0
                    insertEdge(i, k, E[k + startNum]);
                }
            }
        }
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
        if (ifOverstep(from, to)) {
            return false;
        } else {
            EdgeNode p = verList[from].firstEdge;//might be null
            while (p != null && p.to != to)//有下个节点且不为最后边节点
                p = p.next;
            return p != null;
        }
    }

    @Override
    boolean insertEdge(int from, int to, Edge w) {
        if (!ifOverstep(from, to)) {
            return false;
        } else {
            EdgeNode p = verList[from].firstEdge;
            EdgeNode pre = null, s;
            while (p != null && p.to < to) {
                //查找插入位置，单链表按to的值有序
                pre = p;
                p = p.next;
            }
            if (p != null && p.to == to) {
                //该边已存在，修改权值
                if (p.weight != w)
                    p.weight = w;
                else
                    return false;
            } else {
                //该边不存在
                s = new EdgeNode(to, w, p);
                //如果为首元节点
                if (p == verList[from].firstEdge) {
                    verList[from].firstEdge = s;
                } else {
                    pre.next = s;
                    ++edgeNum;
                }
            }
            return true;
        }
    }

    @Override
    boolean removeEdge(int from, int to) {
        if (ifOverstep(from, to)) {
            return false;
        } else {

            EdgeNode p = verList[from].firstEdge;
            EdgeNode pre = null;
            while (p != null && p.to < to) {
                pre = p;
                p = p.next;
            }
            if ((p == null) || (p.to > to))
                return false;

            if (p.to == to) {
                if (p == verList[from].firstEdge)
                    verList[from].firstEdge = p.next;
                else
                    pre.next = p.next;
                --edgeNum;
                return true;
            }
            return true;
        }
    }

    @Override
    void printGraph() {
        int i;
        for (i = 0; i < verNum; i++) {
            System.out.print(verList[i].vertex + ":");
            EdgeNode p = verList[i].firstEdge;
            printList(p);
            System.out.println();
        }
    }

    boolean ifOverstep(int from, int to) {
       if (from < 0 || from > verNum -1 || to < 0 || to > verNum -1) {
           System.out.println("overstep!");
           return false;
       }
       return true;
    }

    private void printList(EdgeNode p){
        while (p != null) {
            System.out.print(verList[p.to].vertex + " ");
            p = p.next;
        }
    }
}
