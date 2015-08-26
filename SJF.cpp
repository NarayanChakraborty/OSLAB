#include<iostream>
using namespace std;

int main()
{
    int  n;
    cout<<"Enter The number of process"<<endl;
    cin>>n;
    int Bu[n];float t=0;
    cout<<"Enter brust time for each process"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Brust time for process p["<<i<<"]=";
        cin>>Bu[i];
        cout<<endl;
        t+=Bu[i];
    }
    //burst time compare
     cout<<"Process Execution:"<<endl;
    for(int i=0;i<n;i++)
    {
      int test=Bu[i];
      for(int j=i+1;j<n;j++)
      { int k=i;
          if(Bu[j]<test)
          {
              test=Bu[j];
          }
          cout<<"Process p "<<k<<"\t"<<test<<endl;
      }
    }

    float avg=(float)(t/n);
    cout<<"total Burst Time = "<<t<<endl;
    cout<<"Avarage Burst Time = "<<avg<<endl;

}
