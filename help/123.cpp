#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>//catch() ���������
#include <windows.h>//system("cls") ����

/************************************
* ��������������һ���½�㣬�������ʼ��
* �����������
* �����������
************************************/

using namespace std;

struct LNode {
    string name;
    string num;
    string writer;
    string fenlei;
    string price;
    string coun;
    LNode *next;
};
typedef LNode LinkList;

void shuchujiedian(LNode *p);

void addstudent(LNode *a, LNode *head);

int num(string a, LNode *head);

void InitList(LinkList *&head)//����һ��ͷ���
{
    head = (LinkList *) malloc(sizeof(LinkList));
    head->next = NULL;
}

void NewNode(LNode *head)// ������ɵ���addstudent�����������½ڵ�β�巨��������
{
    LNode *a;
    a = new LNode;//����ռ�
    string s;
    cout << "ͼ����" << endl;
    cin >> s;
    if (num(s, head) == 1) {
        a->num = s;
        cout << "ͼ����" << endl;
        cin >> a->name;
        cout << "ͼ������: " << endl;
        cin >> a->writer;
        cout << "ͼ�����:   " << endl;
        cin >> a->fenlei;
        cout << "ͼ��۸�:    " << endl;
        cin >> a->price;
        cout << "ͼ������:  " << endl;
        cin >> a->coun;

        addstudent(a, head);
    } else
        cout << "������ظ�" << endl;
}

/************************************
* ���������������µ�һ��ͼ��ṹ�壬�½ڵ㡣
* �����������
* �����������
************************************/
void addstudent(LNode *a, LNode *head)//���ͼ��
{
    LNode *p;
    if (head == NULL)//�������Ϊ��
    {
        head = a;
        a->next = NULL;
        return;//������ɷ���
    } else {
        p = head;//��ͷ��㿪ʼ��
        while (p)//p�ǿ���һֱѭ��
        {
            if (p->next == NULL)//�ҵ�β�ڵ�
            {
                p->next = a;
                a->next = NULL;
                return;//������ɷ���
            }
            p = p->next;//����һ���ڵ�
        }
    }
}

/************************************
* �����������������Ա�
* �����������
* �����������
************************************/
void DestroyList(LinkList *&head)//�������Ա�
{
    LinkList *pre = head->next, *p = head->next->next; //׼����ǰ������ָ��
    while (p != NULL) {
        free(pre);//�ͷ��ڴ�ռ�
        pre = p;
        p = pre->next;
    }
    free(pre);
    head->next = NULL;
    cout << "ͼ����Ϣ�����" << endl;
}

/************************************
* ������������ͼ���������
* �����������
* �����������
************************************/
int ListLength(LinkList *head)//��ͼ�����
{
    int n = 0;
    LinkList *p = head->next;
    while (p->next != NULL) {
        n++;
        p = p->next;
    }
    return (n + 1);
}

/************************************
* ������������ʾ����ͼ�����Ϣ������shuchujiedian��������
* �����������
* ������������ͼ��������š����ߡ��۸�,�����,����
************************************/
void DispList(LNode *head)//������Ա�
{
    LinkList *p = head->next;
    if (p == NULL) {
        cout << "���ڻ�ûͼ����Ϣ,��������ͼ����Ϣ" << endl;
        return;
    } else {

        while (p != NULL) {
            shuchujiedian(p);
            p = p->next;
        }
    }
    cout << "����" << ListLength(head) << "��ͼ��" << endl;
}

/************************************
* ������������������ı��ɾ��ͼ����Ϣ
* ���������ͼ����
* �����������
************************************/
void deletestudent(LNode *head)//ɾ��ͼ����Ϣ
{
    string num;
    int m;
    LNode *p, *pre;
    cout << "������Ҫɾ��ͼ��ı��:";
    cin >> num;
    if (head == NULL) {
        cout << "�����������" << endl;
        return;
    } else {
        p = pre = head;
        while (p) {
            if (p->num == num) {
                shuchujiedian(p);
                cout << "�Ƿ�Ҫɾ��ͼ����Ϣ?" << endl;
                cout << " 1.��    2.����    " << endl;
                cin >> m;
                if (m == 1) {
                    if (p == head) {
                        head = head->next;
                        free(p);
                        p = NULL;
                        cout << "ͼ��ɼ���Ϣɾ��!" << endl;
                        return;
                    } else {
                        pre->next = p->next;
                        free(p);
                        p = NULL;
                        cout << "ͼ����Ϣ��ɾ��!" << endl;
                        return;
                    }
                }


                if (m == 2) {
                    return;
                }
            } else {
                pre = p;
                p = p->next;
            }

        }
    }
    cout << "�����������" << endl;

}

/************************************
* ���������������������������Ϣ
* ���������ͼ����
* �����������
************************************/
void findstudentname(LNode *head)//������ͼ��
{
    string name;
    int i = 0;
    cout << "������Ҫ���ҵ�ͼ����" << endl;
    cin >> name;
    LNode *p = head;
    if (head == NULL) {
        cout << "���ڻ�ûͼ����Ϣ,��������ͼ����Ϣ" << endl;
        return;
    }
    while (p) {
        if (p->name == name) {
            shuchujiedian(p);
            i++;
        }
        p = p->next;
    }
    if (i == 0)
        cout << "û�иñ�ͼ��!" << endl;

}

void findstudentnum(LNode *head)//���Ų���ͼ��
{
    string num;
    cout << "������Ҫ���ҵ�ͼ����" << endl;
    cin >> num;
    LNode *p = head;
    if (head == NULL) {
        cout << "���ڻ�ûͼ����Ϣ,��������ͼ����Ϣ" << endl;
        return;
    }
    p = head;
    while (p) {
        if (p->num == num) {
            shuchujiedian(p);
            return;
        }
        p = p->next;
    }
    cout << "û�иñ�ͼ��!" << endl;


}

/************************************
* �����������жϱ���Ƿ��ظ�
* �����������
* �����������
************************************/
int num(string a, LNode *head)//�жϺ��Ƿ��ظ�
{
    for (LNode *p = head; p != NULL; p = p->next)
        if (p->num == a)
            return 0;
    return 1;
}

/************************************
* ������������������ı�Ų�����Ϣ
* ���������ͼ���
* �����������
************************************/
void ChangeMarkByNum(LNode *head)//���ݺ��޸�ͼ��
{
    LNode *p;
    string num;
    int m;
    int mark1;
    string mark2;
    string mark3;
    p = head;
    cout << "������ͼ����: " << endl;
    cin >> num;
    while (p) {
        if (p->num == num) {
            shuchujiedian(p);
            cout << "�Ƿ�Ҫ�޸�ͼ����Ϣ?" << endl;
            cout << " 1.��    2.����    " << endl;
            cin >> m;
            if (m == 1) {

                cout << "�������µķ����" << endl;
                cin >> mark3;
                cout << "�������µļ۸�" << endl;
                cin >> mark2;
                cout << "�������µ�����" << endl;
                cin >> mark1;
                p->coun = mark1;
                p->fenlei = mark2;
                p->price = mark3;

                cout << "��Ϣ�޸ĳɹ�!" << endl;
                shuchujiedian(p);
                return;
            }
            if (m == 2) {
                cout << "ͼ����Ϣ����!" << endl;
                return;
            }
            break;
        }
        p = p->next;
    }
    cout << "�Բ��𣬲����ڱ��Ϊ" << num << "��ͼ��" << endl;
}

/************************************
* �������������һ�������Ϣ
* �����������
* ������������ͼ��������š����ߡ�����ź�����
************************************/
void shuchujiedian(LNode *p)//���һ�������Ϣ
{

    cout << "���:" << p->name;
    cout << setw(8) << "ͼ����:" << p->name;
    cout << setw(8) << "����:" << p->writer;
    cout << setw(8) << "�����:" << p->fenlei;
    cout << setw(8) << "�۸�" << p->price;
    cout << setw(8) << "����:" << p->coun << endl;;


}


/************************************
* ���������������������ݵ��ļ�
* �����������
* �����������
************************************/
void Save(LNode *head)//�����������ݵ��ļ�
{

    LNode *p1;
    int h;
    ofstream out;
    h = ListLength(head);
    out.open("xuesheng.txt", ios::app);
    if (!out) {
        cout << "���ļ�ʧ�ܣ�" << endl;
    }
    p1 = head->next;
    out << h << endl;
    while (p1) {
        out << p1->num << setw(5) << p1->name << setw(5) << p1->writer << setw(5) << p1->coun << setw(5) << p1->fenlei
            << setw(5) << p1->price << setw(5) << endl;
        p1 = p1->next;
    }
    out.close();
    cout << "����ɹ���" << endl;
    cout << "���������ַ�����������";
    getch();


}

void qing() {
    ofstream out;
    out.open("xuesheng.txt", ios::trunc);
    if (!out) {
        cout << "���ļ�ʧ�ܣ�" << endl;
    }
    cout << "����ɹ���" << endl;
    out.close();
    cout << "���������ַ�����������";
    getch();
}

/************************************
* ������������������ͼ����Ϣ
* �����������
* �����������
************************************/
void huan(LNode *q, LNode *p) {
    LNode change;
    change.name = q->name;//��q������Ϣ��change
    change.num = q->num;
    change.writer = q->writer;
    change.coun = q->coun;
    change.price = q->price;
    change.fenlei = q->fenlei;


    q->name = p->name;//��p������Ϣ��q
    q->num = p->num;
    q->writer = p->writer;
    q->coun = p->coun;
    q->price = p->price;
    q->fenlei = p->fenlei;

    p->name = change.name;//��change������Ϣ��p
    p->num = change.num;
    p->writer = change.writer;
    p->coun = change.coun;
    p->price = change.price;
    p->fenlei = change.fenlei;

}

/************************************
* �������������������
* �����������
* ���������ͼ����Ϣ
************************************/
void pai(LNode *head) {
    LNode change, *p, *q, *r;
    r = head->next;
    if (r == NULL) {
        cout << "���ڻ�ûͼ����Ϣ,��������ͼ����Ϣ" << endl;
        return;
    }
    while (r) {
        p = r;
        q = r->next;
        while (q) {
            if ((q->num) < (p->num))
                huan(q, p);
            q = q->next;
        }
        r = r->next;
    }
    DispList(head);
}



/************************************
* ������������ʾ�˵��������û������������Ӧ�Ĺ���
* �����������Ҫѡ��Ĺ��ܵ����
* ���������ѡ��Ĺ���
************************************/
void menu(LNode *head)// ��ʾ�˵��������û�������
{

    int choose;
    int m = 0;
    cout << "   ͼ�� ���� ϵ ͳ      " << endl;
    cout << "         1.----�ɱ����         " << endl;
    cout << "         2.----���ͼ����Ϣ         " << endl;
    cout << "         3.----ɾ��ͼ����Ϣ         " << endl;
    cout << "         4.----����ͼ����Ϣ         " << endl;
    cout << "         5.----�޸�ͼ����Ϣ         " << endl;
    cout << "         6.----����ͼ����Ϣ         " << endl;
    cout << "         7.----���������Ϣ         " << endl;
    cout << "         8.----����ļ���Ϣ         " << endl;
    cout << "         9.----���������           " << endl;
    cout << "         0.----��ȫ�˳�ϵͳ         " << endl;

    cin >> choose;/*ȡ���û���ѡ��*/
    while (1) {
        if (choose < 0 || choose > 10) {
            cout << "�������ѡ����ڣ�����������" << endl;
            cin >> choose;
        } else
            break;
    }

    switch (choose) {
        case 0:
            exit(0);
        case 1:
            system("cls");
            NewNode(head);
            //�����µ�һ��tushu�ṹ�壬�½ڵ�
            cout << "���������ַ�����������" << endl;
            getch();
            break;
        case 2:
            system("cls");
            DispList(head);//���ͼ����Ϣ
            cout << "���������ַ�����������" << endl;
            getch();
            break;
        case 3:
            system("cls");
            deletestudent(head);//ɾ��ͼ����Ϣ
            cout << "���������ַ�����������" << endl;
            getch();
            break;
        case 4:
            system("cls");
            cout << "��ѡ��" << endl;
            cout << "1.��ͼ��������     2.����Ų���" << endl;
            cin >> m;
            if (m == 1)
                findstudentname(head);//����������ͼ����Ϣ
            else
                findstudentnum(head);//���պŲ���ͼ����Ϣ
            cout << "���������ַ�����������" << endl;
            getch();
            break;

        case 5:
            system("cls");
            ChangeMarkByNum(head);//�����û�����ĺ��޸�ͼ��
            getch();
            break;
        case 6:
            system("cls");
            Save(head);//��������
            break;

        case 7:
            system("cls");
            DestroyList(head);//���ͼ����Ϣ
            getch();
            break;
        case 8:
            system("cls");
            qing();
            break;
        case 9:
            system("cls");
            pai(head);
            break;
        default:
            break;
    }
    menu(head);
}

int mai1n() {
    menu(new LNode());
    return 0;
}
