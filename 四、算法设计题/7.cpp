/**
 * 7. ��֪�����ַ��� A �� B����Ҫ��ʹ�����ٵ��ַ����������� A ת��Ϊ B��ʹ�ö�̬�滮����
 * ����㷨�������ǵ����ű༭���루���� A ת��Ϊ B �������ַ�����������������ִ�е��ַ���
 * ����������1��ɾ��һ���ַ�����2������һ���ַ�����3����һ���ַ��滻��һ���ַ�
 *      ʱ�� => O(mn)
 *      �ռ� => O(mn)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    string s1 = "horse", s2 = "ros";
    int m = s1.size(), n = s2.size();
    s1 = " " + s1, s2 = " " + s2;//dp��Ŀ�±��1��ʼ���Ǵ����Ҿ�ϲ

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    //�߽�
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;
    for(int i = 0; i <= n; i++)
        dp[0][i] = i;
    
    //��ֵdp, ע����ز���©
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            //����ɾ
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;

            //��
            int t = (s1[i] == s2[j] ? 0 : 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t);
        }
    
    printf("��С�༭����Ϊ%d", dp[m][n]);
    return 0;
}