#include <iostream>
#include <vector>
using namespace std;
typedef struct Node
{
    int i;
    int to;
    int weight;
    Node* next;
    Node(int i=-1,int to=-1,int weight=1):i(i),to(to),weight(weight),next(nullptr)
    {
    }
}Node;
class Graph
{
private:
    int n;
    vector<Node*> Vertex;
    vector<bool> visited;
public:
    Graph()
    {
        cout<<"Please enter the number of vertices"<<endl;
        cin>>n;
        Vertex=vector<Node*>(n+1);
        visited=vector<bool>(n+1);
        for(int i=1;i<=n;i++)
        {
            Vertex[i]=new Node();
        }
    }
    void make_graph(int i,int to,int weight)
    {
        Node* node=new Node(i,to,weight);
        if(Vertex[i]->next==nullptr)
        {
            Vertex[i]->next=node;
            node->next=nullptr;
        }
        else
        {
            Node* cur=Vertex[i];
            if(cur->next==nullptr)
            {
                cur->next=node;
                cur->next->next=nullptr;
            }
            else
            {
                while(cur->next!=nullptr)
                {
                    cur=cur->next;
                }
                cur->next=node;
                cur->next->next=nullptr;
            }

        }
    }
    void DFS(int i)
    {
        cout<<i<<"->";
        visited[i]=1;
        Node* cur=Vertex[i];
        if(cur->next==nullptr)
        {return;}
        while(cur->next!=nullptr&&visited[cur->next->to]!=1)
        {
            cur=cur->next;
            visited[cur->to]=1;
            DFS(cur->to);
        }
    }   
    void BFS(int i)
    {

    }
};
int main()
{
    Graph G;
    G.make_graph(1,2,1);
    G.make_graph(1,4,1);
    G.make_graph(4,3,1);
    G.make_graph(3,5,1);
    G.make_graph(3,2,1);
    G.BFS(1);
    return 0;
}