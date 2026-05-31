#include <iostream>
#include <vector>
using namespace std;
#define Radix 10
int b=1;  
class RadixSort
{
private:
typedef struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
}Node;
typedef struct Bucket
{
    Node* head;
    Node* rear;
    Bucket()
    {
        this->head=nullptr;
        this->rear=nullptr;
    }
}Bucket;
    vector<Bucket*> buckets;    
public:
    Node* p= new Node(0); 
    RadixSort()
    {
        buckets=vector<Bucket*>(Radix);
        for(int i=0;i<Radix;i++)
        {
            buckets[i]=new Bucket();
        }
    }
    ~RadixSort()
    {
        Node* cur=p;
        while(cur!=nullptr)
        {
            Node* temp=cur->next;
            delete cur;
            cur=temp;
        }
        for(int i=0;i<10;i++)
        {
            delete buckets[i];
        }
    }
    void create_chain()
    {
        int i=0;
        Node* cur=p;
        while(i!=-1)
        {
            cout<<"Please enter a number within three digits, enter -1 to stop"<<endl;
            cin>>i;
            if(i==-1){break;}
            Node* node=new Node(i);
            cur->next=node;
            node->next=nullptr;
            cur=cur->next;
        }
    }
    void show()
    {
        Node* cur=p->next;
        while(cur!=nullptr)
        {
            cout<<cur->data<<endl;
            cur=cur->next;
        }
    }
    void put_into_bucket()
    {
        Node* cur=p->next;
        p->next=nullptr;  
        int flag;
        while(cur!=nullptr)
        {
            Node* next=cur->next;
            cur->next=nullptr;
            flag=cur->data/b%Radix;
            if(buckets[flag]->head==nullptr)
            {
                buckets[flag]->head=cur;
                buckets[flag]->rear=cur;
            }
            else
            {
                buckets[flag]->rear->next=cur;
                buckets[flag]->rear=buckets[flag]->rear->next;
            }
            cur=next;
        }
    }
    void draw_out_bucket()
    {
        Node* temp=p;
        for(int i=0;i<Radix;i++)
        {
            if(buckets[i]->head==nullptr)
            {continue;}
            else
            {
                temp->next=buckets[i]->head;
                temp=buckets[i]->rear;
                buckets[i]->head=nullptr;
                buckets[i]->rear=nullptr;
            }
        }
        temp->next=nullptr;
    }   
};
int main()
{
    int i=0;
    RadixSort RS;
    RS.create_chain();
    while(i<3)
    {
        RS.put_into_bucket();
        RS.draw_out_bucket();
        i++;
        b=b*Radix;
    }
    RS.show();
    return 0;
}