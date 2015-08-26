#include<iostream>
using namespace std;
int main()
{
    int n,Bu[20];
	int i;
	cout<<"Enter the no of processes:";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter The BurstTime for Process p"<<i<<"=	";
		cin>>Bu[i];
	}
	float Twt=0.0,Awt,Wt[10],w=0.0;
	int B[10],Tt=0,temp,j;
	char S[10];
	float A[10],temp1,t;

	for(int i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		S[i]='T';
		Tt=Tt+B[i];
		cout<<"Enter the Arrival Time for process p"<<i<<" =";
		cin>>A[i];
	}
cout<<endl<<endl;
	for(i=1;i>=1;i--)
	{
		for(j=3;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				temp1=A[j-1];
				B[j-1]=B[j];
				A[j-1]=A[j];
				B[j]=temp;
				A[j]=temp1;
			}
		}
	}
     cout<<"Process\tArivalTime\tBurstTime"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<" p"<<i<<"\t"<<A[i]<<"\t\t"<<B[i]<<endl;
	}

	//For the 1st process
		Wt[1]=0;
		w=w+B[1];
		t=w;
		S[1]='F';

		while(w<Tt)
		{
			i=2;
			while(i<=n)
			{
				if(S[i]=='T'&&A[i]<=t)
				{
					Wt[i]=w;
					S[i]='F';
					w=w+B[i];
					t=w;
					i=2;
				}
				else
					i++;
			}
		}
		//calculating average weighting Time
		for(i=1;i<=n;i++)
        {
            int a=(Wt[i]-A[i]);
            cout<<"waiting time for process p"<<i<<"is="<<a<<endl;
            Twt=Twt+a;
        }
		Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt<<"";
	cout<<"Average Weighting Time="<<Awt<<"";

return 0;
}
