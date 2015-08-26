#include<iostream>
using namespace std;
int main()
{
  int i,j,n,time,remain,flag=0,ts;
  int sum_wait=0,sum_turnaround=0,at[10],bt[10],b[10];
   cout<<"Enter no of Processes : ";
   cin>>n;
  remain=n;
  for(i=0;i<n;i++)
  {
    cout<<"\nEnter arrival time for Process P"<<i+1<<" =";
    cin>>at[i];
    cout<<"\nand burst time for the process";
    cin>>bt[i];
    b[i]=bt[i];
  }
  cout<<"Enter time slice = ";
  cin>>ts;
  cout<<"\n\nProcess\t|Turnaround time|waiting time\n\n";
  for(time=0,i=0;remain!=0;)
  {
    if(b[i]<=ts && b[i]>0)
    {
      time+=b[i];
      b[i]=0;
      flag=1;
    }
    else if(b[i]>0)
    {
      b[i]-=ts;
      time+=ts;
    }
    if(b[i]==0 && flag==1)
    {
      remain--;
      cout<<"P["<<i+1<<"]\t|\t"<<time-at[i]<<"\t|\t"<<time-at[i]-bt[i]<<"\n";
      sum_wait+=time-at[i]-bt[i];
      sum_turnaround+=time-at[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
  cout<<"\nAvg sum_wait ="<<sum_wait*1.0/n;
  cout<<"Avg sum_turnaround ="<<sum_turnaround*1.0/n;
  return 0;
}
