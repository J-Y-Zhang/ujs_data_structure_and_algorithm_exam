#include<bits/stdc++.h>
using namespace std;

const int n = 5; // 5̨�豸, 5����ҵ

vector<vector<int>> c;      // ����ҵ���ĵĳɱ�("c[i][j] = x" �ĺ����� "i���豸 �� j����ҵ �ɱ�Ϊ x")
vector<int> bestX(n + 1);   // ���ĳɱ����ٵ����񷽰� ("bestX[i] = j" �ĺ�����  "i���豸��j����ҵ")
int minCost = INT_MAX;      // ��, ��С�ɱ�, ��ʼΪ�������������С

struct NodeType
{ 
    int idx;			    // ��ǰ�Ѿ�Ϊ idx���豸 �������ҵ��
    vector<int> x;		    // x[i]Ϊ i���豸 ������� ��ҵ���(�˹��ľ��ǽ�����)
    vector<bool> vis;		// vis[i] ��ʾ����i�Ѿ�����
    int cost;			    // �Ѿ��������ҵ����Ҫ�ĳɱ�
    int lb;	        	    // �½�(lowerBound), ��֦��

    // �������ȶ�������, ÿ������ѡ���½���͵Ľ��
    // (�����ܶ����֦, ��ʵ������С��д�ɴ��ڱ�Ť, ����С���Ѱ����ȶ��д��ûѧ����������)
    bool operator<(const NodeType &s) const
    {
        return lb > s.lb; 
    }

    // ���캯��
    NodeType()
    {
        x.resize(n + 1);
        vis.resize(n + 1);
        cost = lb = idx = 0;
    }
};

// ��֦�õ��޽纯��(����̰��˼��)
void bound(NodeType &node)
{  
    int t = 0;

    // Ϊÿ����û��ҵ���豸�����������ҵ(��Ȼ, �����ҵ�����������豸��)
    for(int i = node.idx + 1; i <= n; i++) 
    {  
        int minc = INT_MAX; //����̨�豸��˵�ɱ���͵���ҵ

        for(int j = 1; j <= n; j++)
            if(!node.vis[j] and c[i][j] < minc)
                minc = c[i][j];

        t += minc;
    }

    // ��ͳɱ����ǵ�ǰ��cost + Ϊÿ��û��ҵ���豸�����������ҵ, Ҳ�����½� 
    node.lb = node.cost + t;
}


void bfs()
{
    // bfs�õ����ȶ���
    priority_queue<NodeType> q;

    // �����, idx��Ϊ0���������κ�����
    NodeType root;
    bound(root);
    q.push(root);
    root.idx = 0;

    // ����bfs
    while(!q.empty())
    {
        auto t = q.top();
        q.pop();

        // ���һ���豸Ҳ�Ѿ��������ҵ��, Ҷ�ӽ��
        if(t.idx == n)
        {
            // ���Ը��´�
            if(t.cost < minCost)
            {
                minCost = t.cost;
                for(int i = 1; i <= n; i++)
                    bestX[i] = t.x[i];
            }

            // Ҷ�ӽ�㲻������κκ��ӽ��, ֱ��continue
            continue;
        }
        
        // Ϊ��һ̨�豸������ҵ
        t.idx++;

        // ѭ��ÿһ����ҵ, ����������һ̨�豸
	    for(int i = 1; i <= n; i++)	
	    {  
            // �����ҵ�Ѿ����豸����, ֱ��continue
            if(t.vis[i]) 	
                continue;

            // �� i����ҵ ����� idx���豸, ͬʱ��ȻҪ����vis��cost
            t.x[t.idx] = i;
            t.vis[i] = true;
            t.cost += c[t.idx][i];

            // ��֦
            bound(t);
            if(t.lb <= minCost)
                q.push(t);

            // ��һ�������Ҫ��t��������, ����Ҫ��ԭt֮ǰ��״̬
            t.vis[i] = false;
            t.cost -= c[t.idx][i];
       }  
    }
}

int main(int argc, char const *argv[])
{
    // init
    c = {{}, {0, 10, 4, 8, 7, 5}, {0, 7, 5, 4, 8, 9}, 
    {0, 6, 9, 2, 9, 8}, {0, 8, 7, 10, 5, 6}, {0, 9, 10, 7, 5, 8}};

    // bfs
    bfs();

    // check
    for(int i = 1; i <= n; i++)
        printf("%d ", bestX[i]);
    puts("");
    printf("MinCost = %d\n", minCost);

    return 0;
}