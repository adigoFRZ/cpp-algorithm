#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
//10个数字，数字大小随便
using namespace std;
void Hash_STL_Test()
{
    unordered_map<int,int> map;
    map[114514]=1;
    map[1]=2;
    map[2]=3;
    int name=map[114514];
    cout<<name<<endl;
}
struct Pair
{
    int key;
    int value;
    Pair* next;
    Pair(int key,int value)
    {
        this->key=key;
        this->value=value;
        this->next=nullptr;
    }
};
class HashTable
{
private:
    vector<Pair*> buckets;
public:
HashTable()
{
    buckets=vector<Pair*>(10,nullptr);
}
~HashTable()
{
    for(Pair* bucket : buckets)
    {
        Pair* cur;
        while(cur!=nullptr)
        {
            Pair* temp=cur;
            cur=cur->next;
            delete temp;
        }
    }
    buckets.clear();
} 
int HashFunction(int key)
{
    int index=key%7;
    return index;
}
void index_to_value(int key,int value)
{
    int index=HashFunction(key);
    Pair *p=new Pair(key,value);
    if(buckets[index]==nullptr)
    {
        buckets[index]=p;
        return;
    }
    Pair *cur=buckets[index];
    while(cur->next!=nullptr)
    {cur=cur->next;}
    cur->next=p;
}
void remove(int key)
{
    int index=HashFunction(key);
    Pair* cur=buckets[index];
    Pair* pre=nullptr;
    if(cur==nullptr){cout<<"桶是空桶,没有这个key"<<endl;return;}
    while(cur!=nullptr)
    {
        if(cur->key==key)
        {
            if(pre==nullptr)
            {
                buckets[index]=cur->next;
            }
            else
            {
                pre->next=cur->next;
            }
            delete cur;
            return;
        }
        pre=cur;
        cur=cur->next;
    }
}
Pair* Get_selected_key_pair(int key)
{
    int index=HashFunction(key);
    Pair* cur=buckets[index];
    if(cur==nullptr) {cout<<"桶是空桶,没有这个key"<<endl;return nullptr;}
    while(cur->key!=key)
    {
        if(cur->next==nullptr)
        {   
            cout << "桶里有元素,但是没有这个key" << endl;
            return nullptr;
        }
        cur=cur->next;
    }
    return cur;
}

void print()
{   
    for(Pair* show:buckets)
    {
        while(show!=nullptr)
        {
            cout<<"key="<<show->key<<" "<<"value="<<show->value<<endl;
            if(show->next!=nullptr)show=show->next;
            else break;
        }
    }
}
};
int main()
{
    HashTable HT;
    HT.index_to_value(6,123);
    HT.index_to_value(34,1);
    HT.index_to_value(0,12);
    HT.print();
    cout<<"execute done"<<endl;
    return 0;
}