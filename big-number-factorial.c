﻿#include <stdio.h>
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
 printf("對\n");
}

void main()
{
 int n;
 int a[LEN]={0},b[LEN]={0},c[LEN]={0};
 printf("請輸入您想知道兔子數量的期數（1~500）： ");
 scanf("%d",&n);
 if((n==1)||(n==2))
  printf("第%d期時共有兔子1對",n);
 else
 {
  while((n>500)||(n<1))
  {
  	printf("輸入錯誤，請再次輸入\n");
	printf("請輸入您想知道兔子數量的期數（1~500）： ");
    scanf("%d",&n);
    printf("第%d時期共有兔子",n);
  }
  
 printf("第%d時期共有兔子",n);
 big_number(a,b,c,n);
 print(c);	
 system("pause");
 } 
}	
