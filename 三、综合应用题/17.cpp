/* 
 * 15. ��֦��������Щ?
 *      1 => �� Լ������ ��ȥ ������Լ������ ������
 *      2 => �� �޽纯�� ��ȥ �ò������Ž� ������
*/

#include<bits/stdc++.h>
using namespace std;

// ��Ʒ�ṹ��
struct Obj
{
    int w, v;
    double p;
};

int n;                     // ��n����Ʒ
int ans;                   // ��, ����ֵ
const int maxW;            // ����������
vector<Obj> arr(n + 1);    // ��Ʒ����

/**
 * @brief           �Ҽ�֦�õ��޽纯��, ���Ͻ�(�����װ���ټ�ֵ, ����̰��˼��)
 * 
 * @param i         ��ǰѡ�����Ʒ�±�(��Ʒ�Ѿ����� ��λ�����ļ�ֵ ����������)
 * @param curW      ��ǰ��������Ʒ��������
 * @param curV      ��ǰ��������Ʒ���ܼ�ֵ
 * @return double
 */
double bound(int i, int curW, int curV)
{  
    // i����Ʒû��ѡ, ���Դӵ� i + 1 ����Ʒ��ʼ����
    i++; 

    // �����ܶ�װ
    for(; i <= n and curW + arr[i].w <= maxW; i++)
        curW += arr[i].w, curV += arr[i].v;

    // ����װ����, ��ɵ�λ������С�ݼ���װ(�����Ǽ�֦�����Ͻ�, �����ټ���֦)
    if(i <= n)
        return curV + (maxW - curW) * arr[i].p;

    return curV;
}

// ���ݵ���������
void dfs(int i, int curW, int curV)
{
    // Ҷ�ӽ��
    if(i > n)
    {
        // ���´�
        ans = max(ans, curV);
        return;
    }

    // ��Ҷ�ӽ��

    // ѡ����Ʒ
    // ���֦��Լ������, ���ز���ѡ
    if(curW + arr[i].w <= maxW)
        dfs(i + 1, curW + arr[i].w, curV + arr[i].v);

    // ��ѡ����Ʒ
    // ���Ҽ�֦���޽纯�����Լ����ò������Ž������(������ѡ����Ʒ��û��ǰ;)
    if(bound(i, curW, curV) > ans)
        dfs(i + 1, curW, curV);
}



