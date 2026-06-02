#include <iostream>
#include <vector>
using namespace std;
typedef struct Node 
{
    bool ltag=0;
    bool rtag=0;
    char n;
    Node* lchild;
    Node* rchild;
    Node(char n)
    {
        this->n=n;
        lchild=nullptr;
        rchild=nullptr;
    }
}Node;
Node* Build_Tree()
{
    char x;
    cin>>x;
    if(x=='#')
    {
        return nullptr;
    }
    Node* node=new Node(x);
    node->lchild=Build_Tree();
    node->rchild=Build_Tree();
    return node;
}
void pre_show(Node* root)
{
    if(root==nullptr)
    {return;}
    pre_show(root->lchild);
    cout<<root->n<<" ";
    pre_show(root->rchild);
}
Node* m_pre=nullptr;
void inorder_thread(Node* root)
{   
    if(root==nullptr)
    {
        return;
    }
    inorder_thread(root->lchild);
    if(root->lchild==nullptr)
    {
        root->ltag=1;
        root->lchild=m_pre;
    }
    if(m_pre!=nullptr&&m_pre->rchild==nullptr)
    {
        m_pre->rtag=1;
        m_pre->rchild=root;
    }
    m_pre=root;
    inorder_thread(root->rchild);
}
Node* p_pre=nullptr;
void preorder_thread(Node* root)
{
    
    if(root==nullptr)
    {return;}
    if(root->lchild==nullptr)
    {
        root->ltag=1;
        root->lchild=p_pre;
    }
    if(p_pre!=nullptr&&p_pre->rchild==nullptr)
    {
        p_pre->rtag=1;
        p_pre->rchild=root;
    }
    p_pre=root;
    if(root->ltag==0)
    {
        preorder_thread(root->lchild);
    }
    if(root->rtag==0)
    {
        preorder_thread(root->rchild);
    }
    
}
Node* l_pre=nullptr;
void lastorder_thread(Node* root)
{
    if(root==nullptr){return;}
    lastorder_thread(root->lchild);
    lastorder_thread(root->rchild);
    if(root->lchild==nullptr)
    {
        root->lchild=l_pre;
        root->ltag=1;
    }
    if(l_pre->rchild==nullptr&&l_pre!=nullptr)
    {
        l_pre->rtag=1;
        l_pre->rchild=root;
    }
    l_pre=root;
}

Node* find_inorder_next(char x,Node* root)
{   
    Node* cur=root;
    while(cur!=nullptr&&cur->ltag!=1)
    {
        cur=cur->lchild;
    }
    while(cur!=nullptr)
    {
        if(cur->n==x)
        {
            //前驱
            if(cur->ltag==1)
            {
                cout<<"Pre is "<<cur->lchild->n;
            }
            else
            {
                Node* temp=cur->lchild;
                while(temp!=nullptr&&temp->ltag==0)
                {
                    temp=temp->rchild;
                }
                cout<<"Pre is "<<temp->n;
            }
            //后继
            if(cur->rtag==1)
            {
                cout<<"Next is "<<cur->rchild->n;
            }
            else
            {
                Node* temp1=cur->rchild;
                while(temp1!=nullptr&&temp1->rtag==0)
                {
                    temp1=temp1->lchild;
                }
                cout<<"Next is "<<temp1->n;
            }
            return nullptr;
        }
        else
        {
            if(cur->rtag==0)
            cur=cur->rchild;
            else
            {
                cur=cur->lchild;
                while(cur!=nullptr&&cur->rtag==0)
                {
                    cur=cur->lchild;
                }
            }
        }
    }
    cout<<"not found"<<endl;
    return nullptr;
}

int main()
{
    Node* root;
    root=Build_Tree();
    inorder_thread(root);
    find_inorder_next('g',root);
    return 0;
}