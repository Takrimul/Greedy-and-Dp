#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1<<28)
#define pi 3.1415926536
#define pb push_back
int mem[100][100];
#define EV -1
int lcs(int i,int j, string &S,string &W)
{

    if(i==S.size()||j==W.size())
        return 0;
    if(mem[i][j]!=EV)
        return mem[j][j];
    int ans=0;
    if(S[i]==W[j])
    {
        ans=1+lcs(i+1,j+1,S,W);
    }
    else
    {
        int v1=lcs(i+1,j,S,W);
        int v2=lcs(i,j+1,S,W);
        ans=max(v1,v2);
    }
    mem[i][j]=ans;
    return mem[i][j];
}

int main()
{
    string S,W;
    cin>>S>>W;
    memset(mem,-1,sizeof(mem));
    int res=lcs(0,0,S,W);
    cout<<res<<endl;
//    for(int i=0;i<S.size();i++){
//        for(int j=0;j<W.size();j++){
//            cout<<mem[i][j]<<" ";
//        }
//        cout<<endl;
//    }

}
