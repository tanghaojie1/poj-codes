#include<stdio.h>
int i,j,k,m,t,map[25][25];
int main()
{
  int t=0;
  while(1)
  {
	for(i=1;i<=20;++i)
    {
	  for(j=1;j<=20;++j)
			map[i][j]=100; 
	  map[i][i]=0;
	}
    for(i=1;i<=19;++i)
    {
	  scanf("%d",&k);
	  while(k--)
	   {
		 scanf("%d",&j);
		 map[i][j]=map[j][i]=1;
	   }
    }
    for(k=1;k<=20;++k)
       for(i=1;i<=20;++i)
          for(j=1;j<=20;++j)
		     if(map[i][j]>map[i][k]+map[k][j])
			    map[i][j]=map[i][k]+map[k][j]; 
    scanf("%d",&k);
    printf("Test Set #%d\n",++t);
    while(k--)
    {
	  scanf("%d%d",&i,&j);
	  printf("%d to %d: %d\n",i,j,map[i][j]);
	}
	printf("\n");
  }
  return 0;
}
