#include<stdio.h>
#include<string.h>
const int INF=100000000;
int N,x,y,i,j,k,v,map[110][110],d[110],minv,last;
bool flag[110];
int main()
{
   while(EOF!=scanf("%d%d%d",&N,&x,&y))
   {
      for(i=1;i<=N;++i)
      {
        for(j=1;j<=N;++j)
           map[i][j]=INF;
        map[i][i]=0;
      }
      for(i=1;i<=N;++i)
      {
         scanf("%d%d",&k,&v);
         map[i][v]=0;
         for(j=1;j<k;++j)
         {
            scanf("%d",&v);
            map[i][v]=1;
         }               
      } 
      memset(flag,false,sizeof(flag));
      for(i=1;i<=N;++i)
           d[i]=map[x][i];
      d[x]=0;flag[x]=true; 
      for(i=1;i<N;++i)
      {
         minv=INF;last=-1;
         for(j=1;j<=N;++j)
            if(!flag[j]&&d[j]<minv)
               minv=d[j],last=j;
         if(last==-1)
             break;
         flag[last]=true;
         if(flag[y])
             break;
         for(j=1;j<=N;++j)
            if(!flag[j]&&minv+map[last][j]<d[j])
                d[j]=minv+map[last][j];            
      }
      if(d[y]==INF)
          printf("-1\n");
      else 
          printf("%d\n",d[y]); 
   } 
}
