/**
 * 8. �� n ����ͬʱ�˴���������֪ÿ���˵����غʹ�������������ÿ��������������ȣ�������
 * ֻ�ܳ��� 2 ���ˣ�ʹ��̰�Ĳ�������㷨����������Ҫ�Ĵ�����Ŀ
 *      ʱ�� => O(nlogn)
 *      �ռ� => O(1)
 */

//��������˫ָ��(һ��̰��)

#include<bits/stdc++.h>
using namespace std;

const int CAP = 250;//ÿ�Ҵ�������

int main(int argc, char const *argv[])
{
    //init
    vector<int> v{90, 70, 180, 160};
    int n = v.size();

    //greed(̰��)
    sort(v.begin(), v.end());
    int i = 0, j = n - 1, ans = 0;
    while(i < j)
    {
        //����Ҫ��һ�Ҵ������ص�����
        ans++;

        //����������ܲ��ܼ���ȥ
        if(v[i] + v[j] <= CAP)
            i++;
            
        j--;
    }

    if(i == j)
        ans++;

    //check
    printf("������Ҫ%d�Ҵ�", ans);
    return 0;
}