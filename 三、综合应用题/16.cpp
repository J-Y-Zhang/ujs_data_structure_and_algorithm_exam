/**
 * 16. �� 4 ����ҵҪ������̨���� M1 �� M2 ��ɵ���ˮ������ɼӹ���ÿ����ҵ�ӹ���˳����
 * ���� M1 �ϼӹ���Ȼ���� M2 �ϼӹ����ڻ��� M1 �� M2 �ӹ���ҵ i �����ʱ��ֱ�Ϊ ai �� bi��
 * �ң�a1��a2��a3��a4��=��4��5��12��10������b1��b2��b3��b4��=��8��2��15��9����ʹ��̰�ķ��� 4
 * ����ҵ�����ŵ��ȷ���������������ֵ
 */

//JohnSon�㷨

#include<bits/stdc++.h>
using namespace std;

struct Work{
    int a, b;
    int id;
};

int main(int argc, char const *argv[])
{
    vector<Work> v = {{4, 8, 1}, {5, 2, 2}, {12, 15, 3}, {10, 9, 4}};
    vector<Work> v1, v2;

    for(int i = 0; i < 4; i++)
        if(v[i].a < v[i].b)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
            
    v.clear();
    
    sort(v1.begin(), v1.end(), [](const Work& w1, const Work& w2){
        return w1.a < w2.a;
    });

    sort(v2.begin(), v2.end(), [](const Work& w1, const Work& w2){
        return w1.b > w2.b;
    });

    for(const auto& val : v1)
        cout << val.id << " ";
    for(const auto& val : v2)
        cout << val.id << " ";
}