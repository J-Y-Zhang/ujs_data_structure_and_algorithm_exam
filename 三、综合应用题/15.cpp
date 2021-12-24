#include<bits/stdc++.h>
using namespace std;

// s�Ƿָ���, ���� s[i][j] = k ����˼�� ��A(i)...A(j)���˷��������ٵ�˳����, ���һ���ָ�����k
vector<vector<int>> dp, s;
vector<int> p;
int n = 6;

void matrixChainMul()
{
    // �߽�, �Լ����Լ�����Ҫ��, dp��Ҫ�б߽��
    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;
    
    // ��С����ö�ٳ���, ��Ϊ�������ȵ�dp(������)���ǽ����ڸ��̳��ȵ�dp(������)֮��(�Ե����ϵ���)
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n - len + 1; i++) //ö�����
        {
            // j���յ�, Ҫ��1����Ϊ, ��, �Լ�ģ��һ��, �����1, ����Ϊ2, ��ô�յ�Ӧ����1 + 2 - 1
            int j = i + len - 1;

            // dp[i][j]�� ��i�ֿ� Ϊ�߽���û�����, ��Ȼ��ʼ����INT_MAXҲ����ȫOK��
            dp[i][j] = dp[i][i] + dp[i + 1][j] + p[i] * p[i + 1] * p[j + 1];

            // ǰ��Ҳ˵��, �ָ�����i
            s[i][j] = i;

            // ö�ٳ���i֮��ķָ���, ����˳������ν, ��Ϊ���̵�����������
            for(int k = i + 1; k < j; k++)
            {
                //����״̬ת��
                int t = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]; 

                // ����ָ����ʹ, �õ��ĳ˷������ȵ�ǰ��Сֵ��С, �ǾͲ�����
                if(t < dp[i][j])
                    dp[i][j] = t, s[i][j] = k;
            }
        }
}


int main()
{
    //init
    p = {0, 30, 35, 15, 5, 10, 20, 25};
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
    s = vector<vector<int>>(n + 1, vector<int>(n + 1));
    
    //dp
    matrixChainMul();

    //check
    printf("        dp��������: \n");
    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= n; j++)
            if(i > j)
                printf("       ");
            else
                printf("%7d", dp[i][j]);
    
    puts("");
    printf("        �ָ�����s����: \n");
    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= n; j++)
            if(i > j)
                printf("       ");
            else
                printf("%7d", s[i][j]);
}