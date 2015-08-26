#include<iostream>
using namespace std;
int main()
{
  int f,p;
  int pages[50],frame[10],hit=0,count[50],time[50];
  int i,j,page,flag,least,minTime,temp;

  cout<<"Enter no of frames : ";
  cin>>f;
  cout<<"Enter no of pages : ";
  cin>>p;

  for(i=0;i<f;i++)
  {
    frame[i]=-1;
  }
  for(i=0;i<50;i++)
  {
    count[i]=0;
  }
  cout<<"Enter page string references : \n";
  for(i=0;i<p;i++)
  {
    cin>>pages[i];
  }
  cout<<"\n";
  for(i=0;i<p;i++)
  {
    count[pages[i]]++;
    time[pages[i]]=i;
    flag=1;
    least=frame[0];
    for(j=0;j<f;j++)
    {
      if(frame[j]==-1 || frame[j]==pages[i])
      {
        if(frame[j]!=-1)
        {
            hit++;
        }
        flag=0;
        frame[j]=pages[i];
        break;
      }
      if(count[least]>count[frame[j]])
      {
        least=frame[j];
      }
    }
    if(flag)
    {
      minTime=50;
      for(j=0;j<f;j++)
      {
        if(count[frame[j]]==count[least] && time[frame[j]]<minTime)
        {
          temp=j;
          minTime=time[frame[j]];
        }
      }
      count[frame[temp]]=0;
      frame[temp]=pages[i];
    }
    for(j=0;j<f;j++)
    {
      cout<<frame[j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"Page hit = "<<hit;
  return 0;
}
