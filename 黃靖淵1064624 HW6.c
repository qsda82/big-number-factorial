#include <stdio.h>
#include <stdlib.h>
#define LEN 150 

void big_number(int *a,int *b,int *c,int n)
{
 int tail=LEN-1,i;
 a[tail]=1;
 b[tail]=1;
 for(i=1;i<=n-2;i++)
 {
 int j;
 for(j=tail;j>=0;j--)
  c[j]=a[j]+b[j];

 for(j=tail;j>=0;j--)
 {
  if(c[j]>=10)	
   c[j-1]=c[j-1]+(c[j]/10);
  c[j]=c[j]%10;
 }
 for(j=tail;j>=0;j--)
  b[j]=a[j];
 for(j=tail;j>=0;j--) 
  a[j]=c[j]; 
 }
}

void print(int *c)
{
 int i,x=0;
 for(i=0;i<LEN;i++)
  if(c[i]!=0)
   break; 
 for(;i<LEN;i++)
  printf("%d",c[i]);
 printf("��\n");
}

void main()
{
 int n;
 int a[LEN]={0},b[LEN]={0},c[LEN]={0};
 printf("�п�J�z�Q���D�ߤl�ƶq�����ơ]1~500�^�G ");
 scanf("%d",&n);
 if((n==1)||(n==2))
  printf("��%d���ɦ@���ߤl1��",n);
 else
 {
  while((n>500)||(n<1))
  {
  	printf("��J���~�A�ЦA����J\n");
	printf("�п�J�z�Q���D�ߤl�ƶq�����ơ]1~500�^�G ");
    scanf("%d",&n);
    printf("��%d�ɴ��@���ߤl",n);
  }
  
 printf("��%d�ɴ��@���ߤl",n);
 big_number(a,b,c,n);
 print(c);	
 system("pause");
 } 
}	

 
