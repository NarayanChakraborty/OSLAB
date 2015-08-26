/* 2.simulate Shortest Job First (preemptive)      */
#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,Bt[10],wt[10],B[10],A[10],Tt=0;
    char s[20],start[20];
    int max=0,min,Time=0,z[50];
    float Twt=0.0,Awt;
    int w=0,flag=0,t=0;
    cout<<"\n Enter no. of processes ::";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\n Enter the Burst time for process P"<<i<<"=";
        cin>>Bt[i];
        cout<<"\n Enter the Arrival time for process P"<<i<<"=";
        cin>>A[i];
        B[i]=Bt[i];
        if(B[i]>max)
            max=B[i];
        if(A[i]>Time)
            Time=A[i];
        wt[i]=0;
        s[i]='T';
        start[i]='F';
        Tt+=B[i];
    }
    i=1;k=0;
    z[k]=0;
    k++;
    while(t<Time)
    {
        if(A[i]<=t && B[i]!=0)
        {
            if(flag==0)
                wt[i]=wt[i]+w;
            B[i]=B[i]-1;
            if(B[i]==0)
                s[i]='F';
            start[i]='T';
            t++;
            w=w+1;
            if(s[i]!='F')
            {
                j=1;
                flag=1;
                while(j<=n&&flag!=0)
                {
                    if(s[j]!='F'&&B[i]>B[j]&&A[i]<=t&&i!=j)
                    {
                        flag=0;
                        z[k]=w;
                        wt[i]=wt[i]-w;
                        i=j;
                        k++;
                    }
                    else
                        flag=1;
                    j++;
                }
            }
            else
            {
                i++;
                j=1;
                while(A[j]<=t && j<=n)
                {
                    if(B[i]>B[j] && s[j]!='F')
                    {
                        flag=0;
                        i=j;
                    }
                    j++;
                }
            }
        }
        else
        {
            if(flag==0)
                i++;
        }
    }
    while(w<Tt)
    {
        min=max+1;
        i=1;
        while(i<=n)
        {
            if(min>B[i]&&s[i]=='T')
            {
                min=B[i];
                j=i;
            }
            i++;
        }
        i=j;
        if(w==Time &&start[i]=='T')
        {
            w+=B[i];
            z[k]=w;
            k++;
            s[i]='F';
        }
        else
        {
            wt[i]+=w;
            w+=B[i];
            z[k]=w;
            k++;
            s[i]='F';
        }
    }
    cout<<"\n..............................................\n";
    cout<<"\nPno\tBt\tAt\tWt";
    cout<<"\n..............................................\n";
    for(i=1;i<=n;i++)
    {
        wt[i]=wt[i]-A[i];
        cout<<"\nP"<<i<<"\t"<<Bt[i]<<"\t"<<A[i]<<"\t"<<wt[i];
    }
    cout<<"\n..............................................\n";
    cout<<"\n\n Gannt Chart ::\n";
    for(i=0;i<k;i++)
        cout<<z[i]<<"\t";
    for(i=1;i<=n;i++)
        Twt+=wt[i];
    cout<<"\n\n Total waiting Time ::"<<Twt;
    Awt=Twt/n;
    cout<<"\n\n Average waiting Time ::"<<Awt;
}
