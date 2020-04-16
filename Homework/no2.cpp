#include <iostream>

using namespace std;

int delete2(int data[], int curLength) {
    //报数报到2的变为0
    int num = 0;
    for (int i = 1; i < curLength; i += 2) {
        data[i] = 0;
        num++;
    }
    return num;//删除了多少个数
}

int delete3(int data[], int curLength) {
    //报数报到3的变为0
    int num = 0;
    for (int i = 2; i < curLength; i += 3) {
        data[i] = 0;
        num++;
    }
    return num;//删除了多少个数
}

int *merge(int *data, int length) {
    //把数组中的0去掉，拿出不是0的，返回新数组
    int *newData = new int[length];
    int p = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] != 0) {
            newData[p] = data[i];
            p++;
        }
    }
    return newData;
}

int mainH2() {
    int times = 0;
    cin >> times;//输入次数
    int *data = new int[times]();
    for (int k = 0; k < times; ++k) {
        cin >> data[k];//输入每次的人数
    }

    for (int a = 0; a < times; ++a) {
        //为每次单独计算剩下的人数
        int preLength = data[a];//删掉0前的长度
        int noZeroLength = data[a];//不算0时的长度
        int *cal = new int[noZeroLength]();
        for (int i = 0; i < data[a]; ++i) {
            //初始化数组为1到n
            cal[i] = i + 1;
        }
        while (true) {
            //循环进行删除人
            if (noZeroLength <= 3) {
                //判断是否小于3个人
                break;
            }
            noZeroLength = preLength - delete2(cal, noZeroLength);//删除报到2的人，更新当前长度
            int *tmp = merge(cal, preLength);//得到删除0后的数组
            cal = tmp;//替换原数组
            preLength = noZeroLength;//更新有0时的数组长度

            if (noZeroLength <= 3) {
                //判断是否小于3个人
                break;
            }
            noZeroLength = preLength - delete3(cal, noZeroLength);//删除报到3的人，更新当前长度
            tmp = merge(cal, preLength);//得到删除0后的数组
            cal = tmp;//替换原数组
            preLength = noZeroLength;//更新有0时的数组长度
        }
        cout << "queue: ";
        for (int j = 0; j < noZeroLength; ++j) {
            cout << cal[j] << " ";
        }
        cout << endl;
    }


    return 0;
}

