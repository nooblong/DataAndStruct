//#include <iostream>
//
//using namespace std;
//
//class linkList {
//private:
//    struct Node {
//        int data;
//        Node *next;
//
//        Node(const int value, Node *p = nullptr) {
//            data = value;
//            next = p;
//        }
//
//        Node(Node *p = nullptr) {
//            next = p;
//        }
//    };
//
//    Node *head;
//    Node *tail;
//    int curLength;
//public:
//    void create(int num) {
//        head = tail = new Node;
//        Node *p;
//        for (int i = 0; i < num; i++) {
//            p = new Node(i, nullptr);
//            tail->next = p;
//            tail = p;
//            curLength++;
//        }
//    }
//
//    void print() {
//        cout << endl;
//        Node *p = head->next;
//        for (int i = 0; i < curLength; ++i) {
//            cout << p->data << " ";
//            p = p->next;
//        }
//    }
//
//    Node *getPos(int num) {
//        Node *p = head;
//        int count = 0;
//        while (count <= num) {
//            p = p->next;
//            count++;
//        }
//        return p;
//    }
//
//    void remove(int num) {
//        Node *pre, *p;
//        pre = getPos(num);
//        p = pre->next;
////        cout << "\nremove" << p->data << endl;
//        if (p == tail) {
//            tail = pre;
//            pre->next = nullptr;
//            delete p;
//        } else {
//            pre->next = p->next;
//            delete p;
//        }
//        curLength--;
//    }
//
//    int sort2(){
//        for (int i = 1; i < curLength; i += 2) {
//            remove(i);
//        }
//        if (curLength <= 3)
//            return 1;
//        else
//            return 0;
//    }
//
//};
//
//int main() {
//
//    linkList ls{};
//    ls.create(20);
//    ls.print();
//    ls.remove(3);
//    ls.sort2();
//    ls.print();
//    return 0;
//}
