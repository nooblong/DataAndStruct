#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>//catch() 任意键继续
#include <windows.h>//system("cls") 清屏

/************************************
* 功能描述：申请一个新结点，并将其初始化
* 输入参数：无
* 输出参数：无
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

void InitList(LinkList *&head)//创建一个头结点
{
    head = (LinkList *) malloc(sizeof(LinkList));
    head->next = NULL;
}

void NewNode(LNode *head)// 创建完成调用addstudent（）函数将新节点尾插法插入链表
{
    LNode *a;
    a = new LNode;//申请空间
    string s;
    cout << "图书编号" << endl;
    cin >> s;
    if (num(s, head) == 1) {
        a->num = s;
        cout << "图书名" << endl;
        cin >> a->name;
        cout << "图书作者: " << endl;
        cin >> a->writer;
        cout << "图书分类:   " << endl;
        cin >> a->fenlei;
        cout << "图书价格:    " << endl;
        cin >> a->price;
        cout << "图书数量:  " << endl;
        cin >> a->coun;

        addstudent(a, head);
    } else
        cout << "编号已重复" << endl;
}

/************************************
* 功能描述：创建新的一个图书结构体，新节点。
* 输入参数：无
* 输出参数：无
************************************/
void addstudent(LNode *a, LNode *head)//添加图书
{
    LNode *p;
    if (head == NULL)//如果链表为空
    {
        head = a;
        a->next = NULL;
        return;//插入完成返回
    } else {
        p = head;//从头结点开始找
        while (p)//p非空则一直循环
        {
            if (p->next == NULL)//找到尾节点
            {
                p->next = a;
                a->next = NULL;
                return;//插入完成返回
            }
            p = p->next;//找下一个节点
        }
    }
}

/************************************
* 功能描述：销毁线性表
* 输入参数：无
* 输出参数：无
************************************/
void DestroyList(LinkList *&head)//销毁线性表
{
    LinkList *pre = head->next, *p = head->next->next; //准备好前驱后置指针
    while (p != NULL) {
        free(pre);//释放内存空间
        pre = p;
        p = pre->next;
    }
    free(pre);
    head->next = NULL;
    cout << "图书信息已清空" << endl;
}

/************************************
* 功能描述：求图书种类个数
* 输入参数：无
* 输出参数：无
************************************/
int ListLength(LinkList *head)//求图书个数
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
* 功能描述：显示所有图书的信息，调用shuchujiedian（）函数
* 输入参数：无
* 输出参数：输出图书的名、号、作者、价格,分类号,数量
************************************/
void DispList(LNode *head)//输出线性表
{
    LinkList *p = head->next;
    if (p == NULL) {
        cout << "现在还没图书信息,请先输入图书信息" << endl;
        return;
    } else {

        while (p != NULL) {
            shuchujiedian(p);
            p = p->next;
        }
    }
    cout << "共有" << ListLength(head) << "个图书" << endl;
}

/************************************
* 功能描述：根据输入的编号删除图书信息
* 输入参数：图书编号
* 输出参数：无
************************************/
void deletestudent(LNode *head)//删除图书信息
{
    string num;
    int m;
    LNode *p, *pre;
    cout << "请输入要删除图书的编号:";
    cin >> num;
    if (head == NULL) {
        cout << "编号输入有误" << endl;
        return;
    } else {
        p = pre = head;
        while (p) {
            if (p->num == num) {
                shuchujiedian(p);
                cout << "是否要删除图书信息?" << endl;
                cout << " 1.是    2.不是    " << endl;
                cin >> m;
                if (m == 1) {
                    if (p == head) {
                        head = head->next;
                        free(p);
                        p = NULL;
                        cout << "图书成绩信息删除!" << endl;
                        return;
                    } else {
                        pre->next = p->next;
                        free(p);
                        p = NULL;
                        cout << "图书信息已删除!" << endl;
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
    cout << "编号输入有误" << endl;

}

/************************************
* 功能描述：根据输入的名查找信息
* 输入参数：图书编号
* 输出参数：无
************************************/
void findstudentname(LNode *head)//按名查图书
{
    string name;
    int i = 0;
    cout << "请输入要查找的图书名" << endl;
    cin >> name;
    LNode *p = head;
    if (head == NULL) {
        cout << "现在还没图书信息,请先输入图书信息" << endl;
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
        cout << "没有该本图书!" << endl;

}

void findstudentnum(LNode *head)//按号查找图书
{
    string num;
    cout << "请输入要查找的图书编号" << endl;
    cin >> num;
    LNode *p = head;
    if (head == NULL) {
        cout << "现在还没图书信息,请先输入图书信息" << endl;
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
    cout << "没有该本图书!" << endl;


}

/************************************
* 功能描述：判断编号是否重复
* 输入参数：无
* 输出参数：无
************************************/
int num(string a, LNode *head)//判断号是否重复
{
    for (LNode *p = head; p != NULL; p = p->next)
        if (p->num == a)
            return 0;
    return 1;
}

/************************************
* 功能描述：根据输入的编号查找信息
* 输入参数：图书号
* 输出参数：无
************************************/
void ChangeMarkByNum(LNode *head)//根据号修改图书
{
    LNode *p;
    string num;
    int m;
    int mark1;
    string mark2;
    string mark3;
    p = head;
    cout << "请输入图书编号: " << endl;
    cin >> num;
    while (p) {
        if (p->num == num) {
            shuchujiedian(p);
            cout << "是否要修改图书信息?" << endl;
            cout << " 1.是    2.不是    " << endl;
            cin >> m;
            if (m == 1) {

                cout << "请输入新的分类号" << endl;
                cin >> mark3;
                cout << "请输入新的价格" << endl;
                cin >> mark2;
                cout << "请输入新的数量" << endl;
                cin >> mark1;
                p->coun = mark1;
                p->fenlei = mark2;
                p->price = mark3;

                cout << "信息修改成功!" << endl;
                shuchujiedian(p);
                return;
            }
            if (m == 2) {
                cout << "图书信息保留!" << endl;
                return;
            }
            break;
        }
        p = p->next;
    }
    cout << "对不起，不存在编号为" << num << "的图书" << endl;
}

/************************************
* 功能描述：输出一个结点信息
* 输入参数：无
* 输出参数：输出图书的名、号、作者、分类号和数量
************************************/
void shuchujiedian(LNode *p)//输出一个结点信息
{

    cout << "编号:" << p->name;
    cout << setw(8) << "图书名:" << p->name;
    cout << setw(8) << "作者:" << p->writer;
    cout << setw(8) << "分类号:" << p->fenlei;
    cout << setw(8) << "价格：" << p->price;
    cout << setw(8) << "数量:" << p->coun << endl;;


}


/************************************
* 功能描述：保存链表数据到文件
* 输入参数：无
* 输出参数：无
************************************/
void Save(LNode *head)//保存链表数据到文件
{

    LNode *p1;
    int h;
    ofstream out;
    h = ListLength(head);
    out.open("xuesheng.txt", ios::app);
    if (!out) {
        cout << "打开文件失败！" << endl;
    }
    p1 = head->next;
    out << h << endl;
    while (p1) {
        out << p1->num << setw(5) << p1->name << setw(5) << p1->writer << setw(5) << p1->coun << setw(5) << p1->fenlei
            << setw(5) << p1->price << setw(5) << endl;
        p1 = p1->next;
    }
    out.close();
    cout << "保存成功！" << endl;
    cout << "输入任意字符！继续……";
    getch();


}

void qing() {
    ofstream out;
    out.open("xuesheng.txt", ios::trunc);
    if (!out) {
        cout << "打开文件失败！" << endl;
    }
    cout << "清除成功！" << endl;
    out.close();
    cout << "输入任意字符！继续……";
    getch();
}

/************************************
* 功能描述：交换两个图书信息
* 输入参数：无
* 输出参数：无
************************************/
void huan(LNode *q, LNode *p) {
    LNode change;
    change.name = q->name;//将q结点的信息给change
    change.num = q->num;
    change.writer = q->writer;
    change.coun = q->coun;
    change.price = q->price;
    change.fenlei = q->fenlei;


    q->name = p->name;//将p结点的信息给q
    q->num = p->num;
    q->writer = p->writer;
    q->coun = p->coun;
    q->price = p->price;
    q->fenlei = p->fenlei;

    p->name = change.name;//将change结点的信息给p
    p->num = change.num;
    p->writer = change.writer;
    p->coun = change.coun;
    p->price = change.price;
    p->fenlei = change.fenlei;

}

/************************************
* 功能描述：按编号排序
* 输入参数：无
* 输出参数：图书信息
************************************/
void pai(LNode *head) {
    LNode change, *p, *q, *r;
    r = head->next;
    if (r == NULL) {
        cout << "现在还没图书信息,请先输入图书信息" << endl;
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
* 功能描述：显示菜单，根据用户的输入完成相应的功能
* 输入参数：你要选择的功能的序号
* 输出参数：选择的功能
************************************/
void menu(LNode *head)// 显示菜单，根据用户的输入
{

    int choose;
    int m = 0;
    cout << "   图书 管理 系 统      " << endl;
    cout << "         1.----采编入库         " << endl;
    cout << "         2.----浏览图书信息         " << endl;
    cout << "         3.----删除图书信息         " << endl;
    cout << "         4.----查找图书信息         " << endl;
    cout << "         5.----修改图书信息         " << endl;
    cout << "         6.----保存图书信息         " << endl;
    cout << "         7.----清除已有信息         " << endl;
    cout << "         8.----清除文件信息         " << endl;
    cout << "         9.----按编号排序           " << endl;
    cout << "         0.----安全退出系统         " << endl;

    cin >> choose;/*取得用户的选择*/
    while (1) {
        if (choose < 0 || choose > 10) {
            cout << "您输入的选项不存在，请重新输入" << endl;
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
            //创建新的一个tushu结构体，新节点
            cout << "输入任意字符！继续……" << endl;
            getch();
            break;
        case 2:
            system("cls");
            DispList(head);//输出图书信息
            cout << "输入任意字符！继续……" << endl;
            getch();
            break;
        case 3:
            system("cls");
            deletestudent(head);//删除图书信息
            cout << "输入任意字符！继续……" << endl;
            getch();
            break;
        case 4:
            system("cls");
            cout << "请选择" << endl;
            cout << "1.按图书名查找     2.按编号查找" << endl;
            cin >> m;
            if (m == 1)
                findstudentname(head);//根据名查找图书信息
            else
                findstudentnum(head);//按照号查找图书信息
            cout << "输入任意字符！继续……" << endl;
            getch();
            break;

        case 5:
            system("cls");
            ChangeMarkByNum(head);//根据用户输入的号修改图书
            getch();
            break;
        case 6:
            system("cls");
            Save(head);//保存数据
            break;

        case 7:
            system("cls");
            DestroyList(head);//清空图书信息
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
