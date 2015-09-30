//Shortest job first
#include<iostream>
using namespace std;
main()
{
	int i,j,n,temp,total,fintime[10],pno[10],wait[10],turnaround[10],burst[10];
    float avgw=0.0,avgt=0.0;
	cout<<"Enter number of processes ";
	cin>>n;
	for(i=0;i<n;i++)
	{
        cout<<"\nEnter burst time of P"<<i<<" ";
        cin>>burst[i];
		pno[i]=i;	
	}
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(burst[i]>burst[j])	
            {
			temp=burst[i];
			burst[i]=burst[j];
			burst[j]=temp;
			temp=pno[i];
			pno[i]=pno[j];
	        pno[j]=temp;
            }
        }
    }
    fintime[0]=burst[0]; 		
    for(i=1;i<n;i++)
        fintime[i]=fintime[i-1]+burst[i];
    wait[0]=0;
    for(i=1;i<n;i++)
        wait[i]=fintime[i-1];
    for(i=0;i<n;i++)
        turnaround[i]=burst[i]+wait[i];
    for(i=0;i<n;i++)
    {
        avgw+=wait[i];
        avgt+=turnaround[i];
    }
    avgw/=n;
    avgt/=n;
    cout<<"\nProcess\t\tBurst time\tTurnaround time\t\tWaiting time";
    for(i=0;i<n;i++)
        cout<<"\nP"<<pno[i]<<"\t\t"<<burst[i]<<"\t\t"<<turnaround[i]<<"\t\t\t"<<wait[i];
    cout<<"\n\nAverage waitng time: "<<avgw;
    cout<<"\nAverage turn arround time: "<<avgt;
}
