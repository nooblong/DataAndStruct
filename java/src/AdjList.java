import java.lang.reflect.Array;
import java.util.*;

public class AdjList<Vertex, Edge> extends Graph<Vertex, Edge> {

    public static void main(String[] args) {
        AdjList<String, Integer> adjList = new AdjList<>(5, String.class, Integer.class);
        adjList.createGraph(new String[]{"v1","v2","v3","v4","v5"}, new Integer[]{
                0, 1, 1, 0, 0,
                1, 0, 0, 0, 1,
                1, 0, 0, 1, 1,
                0, 0, 1, 0, 1,
                0, 1, 1, 1, 0}, 5);
        adjList.printGraph();
        adjList.dfsTraverse();
        System.out.println("----adjList2----");
        AdjList<String, Integer> adjList2 = new AdjList<>(4, String.class, Integer.class);
        adjList2.createGraph(new String[]{"v1","v2","v3","v4"}, new Integer[]{
//                0,0,2,1,
//                6,0,0,0,
//                0,0,0,4,
//                0,5,0,0
                0,0,2,1,
                0,0,0,0,
                0,0,0,4,
                0,0,0,0
        }, 4);
        adjList2.insertEdge(0, 2, 2);
        adjList2.printGraph();
        adjList2.dfsTraverse();
        System.out.println("----adjList3----");
        AdjList<String,Integer> adjList3 = new AdjList<>(7, String.class, Integer.class);
        adjList3.createGraph(new String[]{"A","B","C","D","E","F","G"});
        adjList3.insertEdge(0, 1, 1);
        adjList3.insertEdge(0, 2, 1);
        adjList3.insertEdge(1, 0, 1);
        adjList3.insertEdge(1, 3, 1);
        adjList3.insertEdge(1, 4, 1);
        adjList3.insertEdge(2, 0, 1);
        adjList3.insertEdge(2, 4, 1);
        adjList3.insertEdge(2, 5, 1);
        adjList3.insertEdge(3, 1, 1);
        adjList3.insertEdge(3, 6, 1);
        adjList3.insertEdge(4, 1, 1);
        adjList3.insertEdge(4, 2, 1);
        adjList3.insertEdge(4, 6, 1);
        adjList3.insertEdge(5, 2, 1);
        adjList3.insertEdge(5, 6, 1);
        adjList3.insertEdge(6, 3, 1);
        adjList3.insertEdge(6, 4, 1);
        adjList3.insertEdge(6, 5, 1);
        adjList3.printGraph();
        adjList3.dfsTraverse();
        adjList3.bfsTraverse();
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
        EdgeNode p = verList[start].firstEdge;
        System.out.println(">" + verList[start].firstEdge + "---" + verList[start].vertex);
         visited[start] = true;
         while (p != null){
             if (visited[p.to] == false){
                 dfs(p.to);
             }
             p = p.next;
         }
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
    void createGraph(Vertex[] V, Edge[] E, int num) {
        int i, j;
        for (i = 0; i < verNum; i++) {
            verList[i].vertex = V[i];
        }
        for (i = 0; i < verNum; i++) {
//            int startNum = (int)(i*Math.sqrt(verNum));
            int startNum = i*num;
            for (int k = 0; k < verNum; k++) {
                if (!E[k + startNum].equals(0)){
                    //如果不是0
                    insertEdge(i, k, E[k + startNum]);
                }
            }
        }
    }

    void createGraph(Vertex[] V){
        for (int i = 0; i < verNum; i++) {
            verList[i].vertex = V[i];
        }
    }

    @Override
    void dfsTraverse() {
        int count = 0;
        for (int i = 0; i < verNum; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < verNum; i++) {
            if (!visited[i]){
                dfs(i);
                count++;
            }
        }
        System.out.println("count: " + count);
    }

    @Override
    void bfsTraverse() {
        int count = 0;
        Queue<Integer> queue = new LinkedList<>();
        EdgeNode p;
        for (int j = 0; j < verNum; j++) {
            visited[j] = false;
        }
        for (int i = 0; i < verNum; i++) {
            if (visited[i] == true)
                continue;
            System.out.println(verList[i].vertex + " ");
            visited[i] = true;
            queue.offer(i);
            count++;
            while (!queue.isEmpty()){
                int v = queue.peek();
                queue.remove();
                p = verList[v].firstEdge;
                while (p != null){
                    //查找顶点v未被访问的邻接点
                    if ( visited[p.to] == false){
                        System.out.println(verList[p.to].vertex + " ");
                        visited[p.to] = true;
                        queue.offer(p.to);
                    }
                    p = p.next;
                }
            }
        }
        System.out.println("count: " + count);
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
            System.out.print(verList[p.to].vertex + "(" + p.weight + ")" + " ");
            p = p.next;
        }
    }
}
