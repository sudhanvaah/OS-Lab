#include<iostream>
using namespace std;
main()
{
    int i,j,n,temp,burst[10],pno[10],arr[10],wait[10],turn[10],fin[10];
    float avwt=0,avtat=0;
    cout<<"Enter number of processes ";
    cin>>n;
    cout<<"\nEnter arrival times and burst times for\n";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i<<" ";
        cin>>arr[i]>>burst[i];
        pno[i]=i;
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=pno[i];
                pno[i]=pno[j];
                pno[j]=temp;
            }
        }
    fin[0]=burst[0];
    for(i=1;i<n;i++)
        fin[i]=fin[i-1]+burst[i];
    wait[0]=0;
    for(i=1;i<n;i++)
        wait[i]=fin[i]-arr[i]-burst[i];
    for(i=0;i<n;i++)
        turn[i]=fin[i]-arr[i];
    for(i=0;i<n;i++)
    {
        avwt+=wait[i];
        avtat+=turn[i];
    }
    avwt/=n;
    avtat/=n;
    cout<<"\nProcess\t\tBurst time\tTurnaround time\t\tWaiting time";
    for(i=0;i<n;i++)
        cout<<"\nP"<<pno[i]<<"\t\t"<<burst[i]<<"\t\t"<<turn[i]<<"\t\t\t"<<wait[i];
    cout<<"\n\nAverage waiting time: "<<avwt;
    cout<<"\nAverage turn around time: "<<avtat;
}
