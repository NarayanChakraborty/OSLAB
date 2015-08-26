#include<iostream>

using namespace std;
int main()
{
 int frame[10],length[10],index,highest;
 int i,j,k,nf,np=0,temp;
 int flag=0,pf=0,found=0;
 cout<<"Enter no. of Frames:";
 cin>>nf;
 for(i=0;i<nf;i++)
  frame[i]=-1;
  cout<<"enter the no of pages=";
  int p;
  cin>>p;
 cout<<"Enter pages reference:\n";
 int page[p];
 for(i=0;i<p;i++)
 {
  cin>>temp;
  page[i]=temp;
  np++;
 }
 for(i=0;i<np;i++)
 {
  flag=0;
  for(j=0;j<nf;j++)
  {
   if(frame[j]==page[i])
   {
    cout<<"\n\thi";
    flag=1;break;
   }
  }
  if(flag==0)
  {
   for(j=0;j<nf;j++)
   {
    for(temp=i+1;temp<np;temp++)
    {
     length[j]=0;
     if (frame[j]==page[temp])
     {length[j]=temp-i;break;}
    }
   }
   found=0;
   for(j=0;j<nf;j++)
   {
    if(length[j]==0)
    {
     index=j;
     found=1;
     break;
    }
   }
   if(found==0)
   {
    highest=length[0];
    index=0;
    for(j=1;j<nf;j++)
    {
     if(highest<length[j])
     {
      highest=length[j];
      index=j;
     }
    }
   }
   frame[index]=page[i];
   cout<<"\nFault:  ";
   pf++;
  }
  for(k=0;k<nf;k++)
  cout<<frame[k]<<"   ";
 }
 cout<<"\nNumber of page faults is: "<<pf;
return 0;
}
