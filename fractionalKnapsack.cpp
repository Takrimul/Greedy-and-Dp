#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
    Item(int value,int weight){
    this->value;
    this->weight;
    }
};

bool comparison(struct Item a,struct Item b){
double r1=(double)a.value/(double)a.weight;
double r2=(double)b.value/(double)b.weight;
return r1>r2;
}

double fractionalKnapsack(int W,struct Item arr[],int n){
    sort(arr,arr+n,comparison);
    int curWeight=0;
    double finalValue=0.0;
    for(int i=0;i<n;i++){
        if(curWeight+arr[i].weight<=W)
        {
            curWeight+=arr[i].weight;
            finalValue+=arr[i].value;

        }
        else{
            int remain=W-curWeight;
            finalValue += arr[i].value
                          * ((double)remain
                             / (double)arr[i].weight);
        }
    }
    return finalValue;

}
int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}

//int main(){
//    int n,W,val,wt;
//    cout<<"Enter the number of data and Limit of Weight"<<endl;
//    cin>>n,W;
//    Item items[n];
//    for(int i=0;i<n;i++){
//            cin>>val;
//            cin>>wt;
//        items[i].value=val;
//        items[i].weight=wt;
//    }
//    cout<<"Max value is :"<<fractionalKnapsack(W,items,n);
//
//
//}
