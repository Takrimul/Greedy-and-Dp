#include<bits/stdc++.h>
using namespace std;
int data_table[101][101];
struct Item{
    int id;
    int weight;
    int value;
};
int maxProfit(Item arr[],int n,int capacity){
    int wt,val;
    for(int i=0;i<=n;i++)
        data_table[i][0]=0;
    for(int j=0;j<=capacity;j++)
        data_table[0][j]=0;

    for(int i=1;i<=n;i++){
        wt=arr[i].weight;
        val=arr[i].value;
        for(int j=1;j<=capacity;j++){
            if(wt<=j)
                data_table[i][j]=max(data_table[i-1][j],data_table[i-1][j-wt]+val);
            else
                data_table[i][j]=data_table[i-1][j];
        }
    }


    return data_table[n][capacity];


}

int main(){
    cout<<"Enter number of items and max capacity : "<<endl;
    int n,W;
    cin>>n>>W;
    cout<<"Enter items : "<<endl;
    int wt,val;
    Item items[100];
    for(int i=1;i<=n;i++){
        cin>>wt>>val;
        items[i].id=i;
        items[i].weight=wt;
        items[i].value=val;
    }

    cout<<"maximum profit: "<<maxProfit(items,n,W);
}
/*
4 5

2 3
3 4
4 5
5 6

*/
