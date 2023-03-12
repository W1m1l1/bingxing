#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand((int)time(0));// ����������ӣ�����ÿ�ε�����������һ��
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
    cout << "ƽ���㷨��ʱ��ͽ��" << endl;
    start = clock();
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            result[i] += x[i][j] * y[j];
    end = clock();
    cout << "ʱ��Ϊ" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << endl;
    cout << "����cache����Ľ��" << endl;
    start = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i] = x[i][j] * y[j];
    end = clock();
    cout << "���е�ʱ��Ϊ" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;


    cout << "ƽ���㷨��ʱ��" << endl;
    int a = 0;
    start = clock();
    for (int i = 0; i < n; i++)
        a += x[0][i];
    end = clock();
    cout << "���е�ʱ��Ϊ" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << "��ƽ���㷨��ʱ��" << endl;
    //����Ϊ�˺˵ģ�������ĿΪ10000
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
    cout << "���е�ʱ��Ϊ" << double(end - start) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;

}