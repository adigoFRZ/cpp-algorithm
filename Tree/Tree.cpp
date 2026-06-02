#include <iostream>
using namespace std;
typedef struct BTNode
{
    char n;
    BTNode* LNode;
    BTNode* RNode;
    BTNode(char n)
    {
        this->n=n;
        LNode=nullptr;
        RNode=nullptr;
    }
}BTNode;
BTNode* create_tree()
{
    char x;
    cin>>x;
    BTNode* node=new BTNode(x);
    if(node->n=='#')
    {
        return nullptr;
    }
    else
    {
        node->LNode=create_tree();
        node->RNode=create_tree();
    }
    return node;
}
void pre_show(BTNode* root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->n<<" "<<endl;
    pre_show(root->LNode);
    pre_show(root->RNode);
}

void mid_show(BTNode* root)
{
    if(root==nullptr)
    {
        return;
    }
    mid_show(root->LNode);
    cout<<root->n<<" "<<endl;
    mid_show(root->RNode);
}

void last_show(BTNode* root)
{
    if(root==nullptr)
    {
        return;
    }
    last_show(root->LNode);
    last_show(root->RNode);
    cout<<root->n<<" "<<endl;
}
int main()
{
    BTNode* root=create_tree();
    mid_show(root);
    return 0;
}