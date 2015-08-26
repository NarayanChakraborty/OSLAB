#include<iostream>
using namespace std;
int main()
{
  int n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w;
	cout<<"Enter the no of processes:";
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		cout<<"Enter The BurstTime for Process p"<<j<<"=	";
		cin>>Bu[j];
	}
	int B[10],P[10],j;
	w=0.0;
	int max;
	Twt=0.0;
	max=1;
	int i;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		//cout<<"Burst time for process p"<<i<<"=	";
		//cout<<B[i];
		cout<<"Enter the priority for process P"<<i<<"=	";
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}
	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				cout<<"waiting time for process P "<<i<<"="<<Wt[i];
				cout<<"\n";
				w=w+B[i];
			}
			i++;
		}
		j++;
	}

	//calculating average weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt<<"";
	cout<<"Average Weighting Time="<<Awt<<"";

}
