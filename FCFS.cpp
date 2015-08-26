#include<iostream>

using namespace std;

int main()
{
	int n,Bu[20];
	cout<<"Enter the no of processes:";
	cin>>n;
    float Twt,Awt,A[10],Wt[10],w;
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter The BurstTime for Process p"<<i<<"=	";
		cin>>Bu[i];
	}

	int B[10];
	Twt=0.0;
	for(int i=1;i<=n;i++)
	{
		B[i]=Bu[i];
	}

	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}

	//Calculating Average Weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt;
	cout<<"\n ";
	cout<<"Average Weighting Time="<<Awt<<"";
}
