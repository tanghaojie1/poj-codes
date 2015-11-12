#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=30000;
int a[30],b[30],count[30];
int open1,open2,closed1,closed2,n;
char str[maxn];
int cmp(const void *a,const void *b)
{
	return(*(int *)a-*(int *)b);
}
int getmin()
{
	int p;
	if(open1>closed1)
	{
		p=b[open2];open2++;
	}
	else if(open2>closed2)
	{
		p=a[open1];open1++;
	}
	else if(a[open1]<b[open2])
	{
		p=a[open1];open1++;
	}
	else
	{
		p=b[open2];open2++;
	}
    return p;
}
int main()
{
 int i,x,y,sum,s;
 double last;
 while(EOF!=scanf("%s",str))
 {
   if(strcmp(str,"END")==0)
	   break;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(count,0,sizeof(count));
   n=strlen(str);
   sum=n*8;
   x=0;
   for(i=0;i<n;++i)
	   if(str[i]!='_')
	      ++count[str[i]-'A'];
	   else if(str[i]=='_')
		   ++x;
   n=0;
   for(i=0;i<26;++i)
	   if(count[i])
	   {
		   a[++n]=count[i];    
	   }
   if(x)
	   a[++n]=x;
    if(n==1)
   {
	   printf("%d %d 8.0\n",sum,sum/8);
	   continue;
   }
   qsort(a+1,n,sizeof(a[1]),cmp);
   s=0;
   open1=1;closed1=n;
   open2=1;closed2=0;
   s=0;
   for(i=1;i<n;i++)
   {
     x=getmin();
     y=getmin();
     s+=x+y;
     closed2++;
     b[closed2]=x+y;
   }
   last=sum*1.0/double(s);
   memset(str,0,sizeof(str));
   printf("%d %d %.1lf\n",sum,s,last);
 }
return 0;
}
