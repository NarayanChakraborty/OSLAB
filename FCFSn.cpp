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
    cout<<"Process Execution:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"process p["<<i+1<<"]"<<endl;
    }
    float avg=(float)(t/n);
    cout<<"total Burst Time = "<<t<<endl;
    cout<<"Avarage Burst Time = "<<avg<<endl;

}
