#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1001;
int root[MAX];
pair<long long, pair<int,int> >p[MAX];
int parent(int a){
while(root[a]!=a)
    {
        root[a]=root[root[a]];
        a=root[a];
    }
    return a;
}
void union_find(int a,int b)
{
    int d=parent(a);
    int e=parent(b);
    root[d]=root[e];
}
int kruskal(int edges){
    int a,b;
    long long cost,minCost=0;
    for(int i=0;i<edges;i++)
    {
        a=p[i].second.first;
        b=p[i].second.second;
        cost=p[i].first;
        if(parent(a)!=parent(b)){
            minCost+=cost;
            union_find(a,b);
        }
    }
    return minCost;
}

int main(){
    for(int i=0;i<MAX;i++)
        root[i]=i;
 int edges,sc,dest;
 long long cost;
 cout<<"Enter number of nodes"<<endl;
 cin>>edges;
 for(int i=0;i<edges;i++){
    cin>>cost>>sc>>dest;
    p[i]=make_pair(cost, make_pair(sc,dest));

 }
 sort(p,p+edges);
 long long result=kruskal(edges);
 cout<<result<<endl;
}
