#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand((int)time(0));// 产生随机种子，否则每次的随机结果都是一样
    int n = 20000;
    double start, end;
    int** x = new int* [n];
    for (int i = 0; i < n; i++)
        x[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            x[i][j] = i * j;
        }
    int* y = new int[n];
    for (int i = 0; i < n; i++)
        y[i] = i;
    int* result = new int[n];
    for (int i = 0; i < n; i++)
        result[i] = 0;
    cout << "平凡算法的时间和结果" << endl;
    start = clock();
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            result[i] += x[i][j] * y[j];
    end = clock();
    cout << "时间为" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << endl;
    cout << "利用cache缓存的结果" << endl;
    start = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i] = x[i][j] * y[j];
    end = clock();
    cout << "运行的时间为" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;


    cout << "平凡算法的时间" << endl;
    int a = 0;
    start = clock();
    for (int i = 0; i < n; i++)
        a += x[0][i];
    end = clock();
    cout << "运行的时间为" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << "非平凡算法的时间" << endl;
    //电脑为八核的，计算数目为10000
    a = 0;
    start = clock();
    for (int j = 0; j < 16; j++)
    {
        int mysum = 0;
        for (int i = j * 1250; i < (j + 1) * 1250; i++)
            mysum += x[0][i];
        a += mysum;
    }
    end = clock();
    cout << "运行的时间为" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;

}