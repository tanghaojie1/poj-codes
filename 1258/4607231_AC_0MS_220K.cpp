#include<stdio.h>
int a[110][110],min[110];
int main()
{
	int n,i,j,k,c,sum;
	while(EOF!=scanf("%d",&n))
	{	
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
    for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=0;sum=0;
	for(i=1;i<n;i++)
	{
		c=110000;
		for(j=2;j<=n;j++)
			if(min[j]>0&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    sum=sum+c;
		min[k]=0;
		for(j=2;j<=n;j++)
           if(a[k][j]>0&&a[k][j]<min[j])
			   min[j]=a[k][j];
	}
		printf("%d\n",sum);
	}
    return 0;
}
