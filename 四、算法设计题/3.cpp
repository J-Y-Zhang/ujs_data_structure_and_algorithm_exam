/**
 * 3. �жϻ��Ĵ�(�ַ�����@��β)
 *      ˫ָ��
 *      ʱ�� => O(n)
 *      �ռ� => o(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    string s = "abcdcba@";
    //j = s.size() - 2 ��Ϊ�˺���@
    int i = 0, j = s.size() - 2;

    //judge
    bool ans = true;
    while(i < j)
        if(s[i++] != s[j--])
        {
            ans = false;
            break;
        }
    
    //check
    cout << (ans ? s + " �ǻ��Ĵ�" : s + " ���ǻ��Ĵ�");
    return 0;
}