#include <iostream>
#include <vector>
using namespace std;

void showVector(vector<int> arr)
{
    for (vector<int>::iterator it=arr.begin(); it!=arr.end();it++)
    {
        cout<<*it<<endl;
    }
}
void BubbleSort(vector<int>& arr)
{
    int i,j,k;
    for(i=0;i<arr.size();i++)
    {
        for(j=0;j<arr.size()-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int flag=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=flag;
            }
        }
    }
}
void SelectionSort(vector<int>& arr)
{
    int i,j,k;
    for(i=0;i<arr.size();i++)
    {
        int flag=i;
        int value=arr[i];
        for(j=i;j<arr.size()-1;j++)
        {
            if(arr[flag]>arr[j])
            {
                flag=j;
                value=arr[j];
            }
        }
        arr[flag]=arr[i];
        arr[i]=value;
    }
}
void InsetionSort(vector<int>& arr)
{
    int i,j;
    for(i=0;i<arr.size();i++)
    {
        for(j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int flag=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=flag;
            }
        }
    }
}
vector<int> MergeSortAuxiliary(vector<int> arrLeft,vector<int> arrRight)
{
    arrLeft.push_back(114514);
    arrRight.push_back(114514);
    int i=0,j=0;
    vector<int> sortedArr;
    while(i!=(arrLeft.size()-1)||j!=(arrRight.size()-1))
    {
        if(arrLeft[i]<arrRight[j])
        {
            sortedArr.push_back(arrLeft[i]);
            i++;
        }
        else
        {
            sortedArr.push_back(arrRight[j]);
            j++;
        }
    }
    return sortedArr;
}
void MergeSort(vector<int>& arr)
{
    int front,rear,middle;
    front=0;
    rear=arr.size();
    if(front>=rear-1){return;}
    middle=(front+rear)/2;
    vector<int> arrLeft(arr.begin()+front,arr.begin()+middle);
    vector<int> arrRight(arr.begin()+middle,arr.begin()+rear);
    MergeSort(arrLeft);
    MergeSort(arrRight);
    arr=MergeSortAuxiliary(arrLeft,arrRight);
}

int main()
{
    vector<int> arr={64, 34, 25, 12, 22, 11, 90, 100};
    int n = arr.size();
    MergeSort(arr);
    showVector(arr);
    return 0;
}