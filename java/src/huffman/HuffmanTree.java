package huffman;

import java.lang.reflect.Array;

public class HuffmanTree<T> extends AbstractHuffmanTree<T> {

    public static void main(String[] args) {
        HuffmanTree<Character> huffmanTree = new HuffmanTree<>(4);
        huffmanTree.createHuffmanTree(new Character[]{'a', 'b', 'c', 'd'}, new double[]{2, 3, 6, 9});
        huffmanTree.printHuffmanTree();
        huffmanTree.huffmanEncoding();
        huffmanTree.printHuffmanCode();
    }

    HuffmanTree(int initSize) {
        size = initSize;
        hfTree = (Node[]) Array.newInstance(Node.class, 2 * size);
        for (int i = 0; i < hfTree.length; i++) {
            hfTree[i] = new Node();
        }
        hfCode = (HuffmanCode[]) Array.newInstance(HuffmanCode.class, size);
        for (int i = 0; i < hfCode.length; i++) {
            hfCode[i] = new HuffmanCode();
        }
    }

    @Override
    int selectMin(int m, int p) {
        int j = m;
        while (hfTree[j].parent != 0)
            j++;
        for (p = j, j += 1; j < 2 * size; j++) {
            if ((hfTree[j].weight < hfTree[p].weight) && 0 == hfTree[j].parent)
                p = j;
        }
        return p;
    }

    @Override
    void createHuffmanTree(T[] d, double[] w) {
        int i = 0, min1 = 0, min2 = 0;//最小树，次最小树的下标，
        for (i = size; i < 2 * size; i++) {
            //给size个叶节点赋值
            hfTree[i].data = d[i - size];
            hfTree[i].weight = w[i - size];
        }
        for (i = size - 1; i > 0; i--) {
            //合并产生size-1个新节点
            min1 = selectMin(i + 1, min1);
            hfTree[min1].parent = i;
            min2 = selectMin(i + 1, min2);
            hfTree[min2].parent = i;

            hfTree[i].weight = hfTree[min1].weight + hfTree[min2].weight;
            hfTree[i].left = min1;
            hfTree[i].right = min2;
        }
    }

    @Override
    void huffmanEncoding() {
        int father, p;
        for (int i = size; i < 2 * size; i++) {
            hfCode[i - size].data = hfTree[i].data;
            p = i;
            father = hfTree[p].parent;
            while (father != 0) {
                if (hfTree[father].left == p) {
                    hfCode[i - size].code = '0' + hfCode[i - size].code;
                } else {
                    hfCode[i - size].code = '1' + hfCode[i - size].code;
                }
                p = father;
                father = hfTree[p].parent;
            }
        }
    }

    @Override
    void printHuffmanCode() {
        for (int i = 0; i < size; i++) {
            System.out.print(hfCode[i].data + " " + hfCode[i].code + "\n");
        }
    }

    void printHuffmanTree() {
        for (int i = 1; i < hfTree.length; i++) {
            System.out.print(String.format("%5s", hfTree[i].data + " "));
            System.out.println(String.format("%1g", hfTree[i].weight) + " " + hfTree[i].parent + " " + hfTree[i].left + " " + hfTree[i].right);
        }
    }
}
