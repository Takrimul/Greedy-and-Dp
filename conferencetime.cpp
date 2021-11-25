#include<bits/stdc++.h>
using namespace std;

struct Conference
{
    char id;
    int start;
    int finish;
};

bool comparison(Conference a, Conference b)
{
    return a.finish<b.finish;
}

void ConferenceSchedule(Conference arr[],int n){
    sort(arr,arr+n,comparison);
    vector<char>res;
    int prevfinish=arr[0].finish;
    res.push_back(arr[0].id);
    for(int i=1;i<n;i++){
        if(arr[i].start>=prevfinish){
                res.push_back(arr[i].id);
                prevfinish=arr[i].finish;
        }
    }
    for(auto it=res.begin();it!=res.end();it++)
        cout<<*it<<" ";

}

int main(){
     cout<<"Enter the number of total conference"<<endl;
     int n,start,finish;
     char id;
     cin>>n;
     Conference tasks[n];
     for(int i=0;i<n;i++){
        cin>>id>>start>>finish;
        tasks[i].id=id;
        tasks[i].start=start;
        tasks[i].finish=finish;

     }
     ConferenceSchedule(tasks,n);
}

