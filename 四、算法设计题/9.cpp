/**
 * 9. ��֪ n �����ɵļ��ϣ�ÿ�������Ҫʹ��ͬһ��Դ��������Դ���κ�ʱ��ֻ�ܱ�һ��
 * ���ռ�á�ÿ�������һ����ʼʱ��ͽ���ʱ�䣬һ��ĳ�����ʼִ�У��м䲻�ܱ���ϣ�
 * ֱ����ִ����ϡ����������ʱ�䰲��û�г�ͻ���������������ݡ�ʹ�û��ݷ�����㷨��
 * ��һ�����Ż���ŷ�����ʹ�ñ����ŵĻ�����ﵽ���
 *      ʱ�� => O(2^n)
 *      �ռ� => O(n)(�ݹ�ջ)
 */

//�ⲻ����̰��???????
//�������ʹ��̰��, ������������˵�, O(n)����
//���ݾ�ȫ���б�������

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> v;
int n, ans = INT_MIN;

int getNum()
{
    int ans = 0;
    unordered_set<int> hash;
    for(int i = 0; i < n; i++)
    {
        int l = v[i].first, r = v[i].second;

        //flag == true ? �ܿ����� : ���ܿ�����
        bool flag = true;

        //�Ӹû��ʼ���������붼û�л�����ص�
        for(int j = l; j <= r; j++)
            if(hash.count(j))
            {
                flag = false;
                break;
            }

        //û���ص��;ٰ�û
        if(flag)
        {
            for(int j = v[i].first; j <= v[i].second; j++)
                hash.insert(j);
            ans++;
        }
    }

    return ans;
}

void dfs(int x)
{
    if(x == n)
    {
        ans = max(ans, getNum());
        return;
    }
    
    //ȫ����
    for(int i = x; i < n; i++)
    {
        swap(v[x], v[i]);
        dfs(x + 1);
        swap(v[x], v[i]);
    }
}

int main(int argc, char const *argv[])
{   
    //init
    v = {{1, 4}, {2, 3}, {4, 5}};
    n = v.size();

    //ȫ����
    dfs(0);

    //check
    cout << ans << endl;
    return 0;
}