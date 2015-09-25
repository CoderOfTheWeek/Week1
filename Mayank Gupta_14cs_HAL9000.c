/*mayank gupta 14cs hal9000
os windows 8.1
compiler devc++*/

#include<stdio.h>
#include<conio.h>
int main()
{ int a[100],b[100],c,d,temp,temp2,sum=0;
printf("enter the length of vector a");
scanf("%d",&c);
for(int i=0;i<c;i++)
{ scanf("%d",&a[i]);//getting vector a
}
printf("enter the length of vector d");
scanf("%d",&d);
for(int i=0;i<d;i++)
{ scanf("%d",&b[i]);//getting vector b
}
if(d!=c)
{ if(d<c)
{ for(int i=d;i<c;i++)
 b[i]=0;
 d=c;}
else
{ for( int j=c;j<d;j++)
a[j]=0;
c=d;}
}
int e[d];
 for(int i=c-2;i>=0;i--){
      for(int j=0;j<=i;j++){
           if(a[j]>a[j+1]){
               temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;//bubble sort a
           }
      }
  }
   for(int i=d-2;i>=0;i--){
      for(int j=0;j<=i;j++){
           if(b[j]>b[j+1]){
               temp2=b[j];
              b[j]=b[j+1];
              b[j+1]=temp2;//bubble sort b
           }
      }
  }
  for( int i=0;i<d;i++)
  {
  	e[i]=a[i]*b[d-i-1];//multiplying smallest element of one vector tho biggest of other
  }
  for(int i=0;i<d;i++)
  { sum=sum+e[i];//summing up the product
}
printf("min dot product is %d",sum);
getch();
}
