#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,m,n;char a[1002],b[1002],f[1002][1002];
	while(EOF!=scanf("%d%s%d%s",&m,a+1,&n,b+1))
	{
	  if(strcmp(a+1,b+1)==0)
	  {
		  printf("0\n");
		  continue;
	  }
	  for(i=0;i<=m;i++)
		f[i][0]=i;
	  for(i=0;i<=n;i++)
		f[0][i]=i;
   	  for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j-1]+1;
			if(a[i]==b[j])
				f[i][j]-=1;
			if(f[i-1][j]+1<f[i][j])
				f[i][j]=f[i-1][j]+1;
			if(f[i][j-1]+1<f[i][j])
				f[i][j]=f[i][j-1]+1;
		}
      printf("%d\n",f[m][n]);
	}
	return 0;
}
