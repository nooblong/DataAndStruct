package huffman;

public abstract class AbstractHuffmanTree<T> {
    class Node{
        T data;
        double weight;
        int parent, left, right;
        Node(){
            weight = parent = left = right = 0;
        }
    }

    class HuffmanCode {
        T data;
        String code;
        HuffmanCode(){
            code = "";
        }
    }

    Node[] hfTree;//保存哈夫曼树
    HuffmanCode[] hfCode;//保存哈夫曼编码
    int size;
    abstract void selectMin(int m, int p);

    public AbstractHuffmanTree(){

    }
    abstract void createHuffmanTree(T[] d, double[] w);
    abstract void huffmanEncoding();
    abstract void printHuffmanCode();
}
