#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char Id;
    int dead;
    int profit;
};

bool comaparison(Job a, Job b)
{
    return (a.profit>b.profit);
}

void printJobSchedules(Job arr[], int n)
{
    sort(arr, arr+n, comaparison);
    int result[n];

    bool slot[n];
    for(int i=0; i<n; i++)
        slot[i]=false;

    for(int i=0; i<n; i++)
    {
        for(int j=min(n,arr[i].dead)-1; j>=0; j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }

        }
    }
    for(int i=0; i<n; i++)
        if(slot[i])
            cout<<arr[result[i]].Id<<" ";
}
//int main()
//{
//    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
//                   {'d', 1, 25}, {'e', 3, 15}};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    cout << "Following is maximum profit sequence of jobs \n";
//
//    // Function call
//    printJobSchedules(arr, n);
//    return 0;
//}

int main()
{

    int n;
    char a;
    int dead,pt;
    cout<<"enter job no"<<endl;
    cin>>n;
    Job Jobs[n];
    cout<<"Enter jobId, deadLine and Profit";

    for(int i=0; i<n; i++)
    {
        scanf("%c",&Jobs[i].Id);
        scanf("%d",&Jobs[i].dead);
        scanf("%d",&Jobs[i].profit);
    }
    printJobSchedules(Jobs,n);
    return 0;

}
