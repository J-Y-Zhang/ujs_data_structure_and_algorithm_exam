/**
 * 14. ��֪һ���� n ���������ɵ����У����÷��η�Ѱ�����е����ֵ�ʹδ�ֵ����д���ݹ�ģ
 * �ͣ�������ʱ�临�Ӷ�
 *      ʱ�� => logn
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> v;

/**
 * @brief ����Ѱ�����ֵ�ʹδ�ֵ
 * 
 * @param l ��߽�
 * @param r �ұ߽�
 * @return pair<int, int> first�����ֵ, second�Ǵδ�ֵ
 */
pair<int, int> find(int l, int r)
{
    //���䳤��С�ڵ���2�ǵݹ�߽�
    if(r - l <= 1)
        return {max(v[l], v[r]), min(v[l], v[r])};
    
    //�����������ȥ����
    int mid = (l + r) >> 1;
    auto ansL = find(l, mid), ansR = find(mid + 1, r);

    //����õ��Ľ��, ��ѡ�����ֵ�ʹδ�ֵ
    int max1 = max(ansL.first, ansR.first);
    int max2 = max(min(ansL.first, ansR.first), max(ansL.second, ansR.second));
    
    return {max1, max2};
}

int main(int argc, char const *argv[])
{
    v = {3, 1, 2, 5, 6, 8, 0, 5};
    auto ans = find(0, v.size() - 1);
    printf("���ֵ => %d\n�δ�ֵ => %d\n", ans.first, ans.second);
    return 0;
}