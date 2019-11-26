package huffman;

import java.lang.reflect.Array;

public class IntHuffmanTree<T> extends AbstractHuffmanTree<T> {

    IntHuffmanTree(int initSize){
        size = initSize;
        hfTree = (Node[])Array.newInstance(Node.class, 2*size);
        hfCode = (HuffmanCode[])Array.newInstance(HuffmanCode.class, size);
    }

    @Override
    void selectMin(int m, int p) {

    }

    @Override
    void createHuffmanTree(T[] d, double[] w) {
        int i = 0, min1 = 0, min2 = 0;//最小树，次最小树的下标，
        for (i = size; i < 2 * size; i++) {
            //给size个叶节点赋值
            hfTree[i].data = d[i-size];
            hfTree[i].weight = w[i-size];
        }
        for (i = size - 1; i > 0; i--) {
            //合并产生size-1个新节点
            selectMin(i+1, min1);
            hfTree[min1].parent = i;
            selectMin(i+1, min2);
            hfTree[min2].parent = i;

            hfTree[i].weight = hfTree[min1].weight + hfTree[min2].weight;
            hfTree[i].left = min1;
            hfTree[i].right = min2;
        }
    }

    @Override
    void huffmanEncoding() {

    }

    @Override
    void printHuffmanCode() {

    }
}
