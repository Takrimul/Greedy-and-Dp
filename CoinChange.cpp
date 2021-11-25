#include<iostream>
#include<cstring>
using namespace std;
#define inf (1<<28)
int mem[1000][1000];
int coin1[1000],coin[3];
int w;
int coinChange(int i,int w,int coin[])
{

    if(w==0)return 0;
    if(i==2)return inf;
    if(w<0)return inf;
    if(mem[i][w]!=-1)
        return mem[i][w];

       int a= coinChange(i+1,w,coin);
        int b=1+coinChange(i,w-coin[i],coin);
    mem[i][w]=min(a,b);
    return mem[i][w];

}
int main()
{

    memset(mem,-1,sizeof(mem));
    int n,v,cnt=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>v;
    if(v==100)cnt++;
    sum+=v;
        coin1[i]=v;
    }
   w=sum/2;
   coin[0]=100;
   coin[1]=200;
    int res=coinChange(0,w,coin);
    if(res==inf)
        cout<<"NO"<<endl;
    else
    cout <<"YES"<< endl;
    return 0;
}
