#include<iostream>
using namespace std;

struct minmax
{
    int min;
    int max;
};


struct minmax minMax(int *arr,int size);

int main()
{
    int arr[] = {1,2,3,4,59};
    int *a;
    int size = sizeof(arr)/sizeof(arr[0]);
    minmax m1 = minMax(arr,size);
    cout<<"min:"<<m1.min<<endl<<"max:"<<m1.max;
    return 0;
}

struct minmax minMax(int *arr,int size)
{
    minmax m;
    m.max=m.min=arr[0];
    for(int i=0; i<size;i++){
        if(arr[i]>=m.max) m.max = arr[i];
        else if(arr[i]<=m.min) m.min = arr[i];
    }
    return m;
}
