/**
 * 6. ��������, ����Ѱ����ӽ�tar����
 *      ʱ�� => O(logn)
 *      �ռ� => O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    vector<int> v{1, 2, 3, 4, 7, 9, 11};
    int tar = 5;
    int n = v.size();

    //�� <= tar �ĵ�һ����
    int l = 0, r = n - 1, mid;
    while(l < r)
        if(v[mid = (l + r + 1) >> 1] > tar)
            r = mid - 1;
        else
            l = mid;

    auto t1 = l;

    //����Ѿ��ҵ�tar������, ֱ�ӷ���(û�б�tar���ӽ�tar������)
    if(v[t1] == tar)
    {
        cout << v[t1];
        return;
    }

    //�� >= tar �ĵ�һ����
    l = 0, r = n - 1;
    while(l < r)
        if(v[mid = (l + r) >> 1] >= tar)
            r = mid;
        else
            l = mid + 1;
    auto t2 = l;

    //�Ƚϲ�������
    if(tar - v[t1] <= v[t2] - tar)
        cout << v[t1];
    else
        cout << v[t2];

    return 0;
}