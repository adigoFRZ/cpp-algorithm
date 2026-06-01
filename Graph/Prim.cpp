#include <iostream>
#include <vector>
using namespace std;
typedef struct Node
{
    int n;
    int to;
    int weight;
    Node* next;
    Node(int i=-1,int to=-1,int weight=0):n(i),to(to),weight(weight)
    {
        next=nullptr;
    }
}Node;
class Prim
{
private:
    vector<Node*> Vertex;
    vector<int> visited; 
    int n;
    int weightTotal=0;
public:
    Prim()
    {
        cout<<"Please enter the number of vertices"<<endl;
        cin>>n;
        Vertex=vector<Node*>(n+1);
        visited=vector<int>(n+1);
        for(int i=1;i<=n;i++)
        {
            Vertex[i]=new Node();
            visited[i]=0; 
        }
    }
    void make_graph(int n,int to,int weight)
    {
        Node* cur=Vertex[n];
        Node* node=new Node(n,to,weight);
        if(cur->next==nullptr)
        {
            Vertex[n]->next=node;
            node->next=nullptr;
        }
        else
        {
            while(cur->next!=nullptr)
            {cur=cur->next;}
            cur->next=node;
            node->next=nullptr;
        }
    }
    void show()
    {
        for(int i=1;i<n+1;i++)
        {
            Node* cur=Vertex[i]->next;
            while(cur!=nullptr)
            {
                cout<<i<<"->"<<cur->to;
                cout<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }
    }
    int Minimum_Spanning_Tree(int start=1)
    {
        visited[start]=1;
        for(int i=1;i<=n-1;i++)
        {
            int from=-1;
            int target=-1;
            int minWeight=114514;
            for(int k=1;k<=n;k++)
            {
                if(visited[k]==1)
                {
                    Node* cur=Vertex[k]->next;
                    while(cur!=nullptr)
                    {
                        if(cur->weight<=minWeight&&visited[cur->to]==0)
                        {
                            minWeight=cur->weight;
                            from=cur->n;
                            target=cur->to;
                        }
                        cur=cur->next;
                    }
                }
            }
            if(target!=-1)
            {
                visited[target]=1;
                weightTotal += minWeight;
                cout<<from<<"->"<<target<<"weight="<<minWeight<<endl;
            }
        }
        return weightTotal;
    }
};
int main()
{
    Prim P;
    P.make_graph(1,2,6);
    P.make_graph(1,3,1);
    P.make_graph(1,4,5);
    
    P.make_graph(2,1,6);
    P.make_graph(2,3,5);
    P.make_graph(2,5,3);
    
    P.make_graph(3,5,6);
    P.make_graph(3,1,1);
    P.make_graph(3,2,5);
    P.make_graph(3,4,4);
    P.make_graph(3,6,4);

    P.make_graph(4,1,5);
    P.make_graph(4,3,4);
    P.make_graph(4,6,2);

    P.make_graph(5,2,3);
    P.make_graph(5,3,6);
    P.make_graph(5,6,6);

    P.make_graph(6,5,6);
    P.make_graph(6,3,4);
    P.make_graph(6,4,2);
    cout<<P.Minimum_Spanning_Tree()<<endl;
    return 0;
}