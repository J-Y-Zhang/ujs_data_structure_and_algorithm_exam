/**
 * 5. ����ͼ(�ڽӱ�洢)����������Ķ�
 *      ע: ͼ��ȡͼʵ����ҵ�е�ͼ
 *      ʱ�� => O(n)
 *      �ռ� => O(1)
 */

#include<bits/stdc++.h>
using namespace std;

//��
struct Edge{   
    int idx;
    int weight;
    Edge* next;
};

struct Vertex{
    int idx;
    Edge* head;
};

void init();

vector<Vertex*> graph;

int main(int argc, char const *argv[])
{
    init();

    int tar = 3;//C���

    //���
    int inDegree = 0;
    for(const auto& v : graph)
    {
        auto p = v->head;
        while(p)
        {
            if(p->idx == tar)
            {
                inDegree++;
                break;
            }
            p = p->next;
        }
    }
    printf("C������Ϊ%d\n", inDegree);

    //����
    int outDegree = 0;
    for(auto p = graph[tar]->head; p; p = p->next)
        outDegree++;
    printf("C������Ϊ%d", outDegree);
}

void init()
{
    graph.push_back(NULL);//�±��1��ʼ
    auto A = new Vertex({1, NULL});   
    auto B = new Vertex({2, NULL});   
    auto C = new Vertex({3, NULL});   
    auto D = new Vertex({4, NULL});   
    auto E = new Vertex({5, NULL});   
    auto F = new Vertex({6, NULL});   
    auto G = new Vertex({7, NULL});   
    auto H = new Vertex({8, NULL});   
    auto I = new Vertex({9, NULL});   
    A->head = new Edge({2, 12, new Edge({5, 9, new Edge({3, 3, NULL})})});
    B->head = new Edge({5, 6, new Edge({4, 2, NULL})});
    C->head = new Edge({6, 6, NULL});
    D->head = new Edge({3, 2, new Edge({5, 4, new Edge({7, 5, NULL})})});
    E->head = new Edge({6, 4, NULL});
    F->head = new Edge({1, 10, new Edge({4, 7, NULL})});
    G->head = new Edge({2, 8, NULL});
    H->head = new Edge({7, 12, new Edge({9, 10, NULL})});
    graph.push_back(A), graph.push_back(B), graph.push_back(C);
    graph.push_back(D), graph.push_back(E), graph.push_back(F);
    graph.push_back(G), graph.push_back(H), graph.push_back(I);
}