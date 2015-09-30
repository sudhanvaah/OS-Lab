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
		pno[i]=i;		// storing order of processes/process name
	}
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(burst[i]>burst[j])		// sorting based on the burst time of processes
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
    fintime[0]=burst[0]; 		// time at which process 0 finished execution;In fcfs,we had r[0]=burst[0]+a[0],but in this case we don't have arrival time.
    for(i=1;i<n;i++)
                           // if next process arrives instantly at the time at which previous ends
        fintime[i]=fintime[i-1]+burst[i]; //time at which previous process finished execution+the burst time of this process gives the finish time of current process
                         // No second case as in fcfs
    wait[0]=0;             // waiting time of first process is 0
    for(i=1;i<n;i++)   //now we calculate the waiting time for other processes
        wait[i]=fintime[i-1];  // process i waits till process i-1 finishes its execution, so this is its waiting time
    for(i=0;i<n;i++) // Turnaround time
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
