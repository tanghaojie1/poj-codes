#include<cstdio>
#include<cstring>
const int INF=900000000;  //
int N,M,sum,top,size;
int S,T,found,h[500],vh[500],a[500],in[500],flag[500];
int d[500][500],c[500][500],augc,ans,path[500][3];
char b[500];

void aug(int x)
{
   int i,minh=size,augco=augc;
   if(x==T)
   {
	   found=1;
	   ans+=augc;
	   return ;
   }
   for(i=0;i<size;++i)
	   if(c[x][i]>0)
	   {
		   if(h[i]+1==h[x])
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[S]>=size)
				   return ;
			   if(found)
				   break;
			   augco=augc;
		   }
		   if(h[i]<minh)
			   minh=h[i];
	   }
     if(!found)
	 {
		 vh[h[x]]--;
		 if(vh[h[x]]==0)
			 h[S]=size;
		 h[x]=minh+1;
		 vh[h[x]]++;
	 }
	 else
	 {
		 c[x][i]-=augc;
		 c[i][x]+=augc;
	 }
}

void SAP()
{
     memset(h,0,sizeof(h));
	 memset(vh,0,sizeof(vh));
	 vh[0]=size;   //从0开始计数...
	 ans=0;
	 while(h[S]<size)
	 {
		 found=0;
		 augc=INF;
		 aug(S);
	 }
	 printf("%d\n",ans);
}


void dfs(int x)
{
	int i;
	if(flag[x])
		return ;
	flag[x]=1;
	for(i=0;i<size;i++)
		if(!flag[i]&&c[x][i])
			dfs(i);
}

int main()
{   
	int i,j,x,t;
	while(EOF!=scanf("%d %d",&N,&M))
	{
	
	    size=2*N+2;
		S=0;
		T=2*N+1;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				c[i][j]=0,d[i][j]=0;
        
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x); 
			c[i+N][T]=x;
			d[i+N][T]=1;
		}

		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			c[S][i]=x;
			d[S][i]=1;
		}

		while(M--)
		{
			scanf("%d %d",&i,&j);
			c[i][j+N]=INF;
			d[i][j+N]=1;
		}
		
		SAP();

		for(i=0;i<size;i++)
			flag[i]=0;
		dfs(S);
		t=size-1;
		sum=0;
	 for(i=0;i<=t;i++)
   for(j=0;j<=t;j++)
    if(flag[i] && !flag[j] && d[i][j])
     sum++,path[sum][0]=i<j?i:j,path[sum][1]=i<j?j:i;
  printf("%d\n",sum);
  for(i=1;i<=sum;i++)
  {
   if(path[i][0]==S)
    printf("%d -\n",path[i][1]);
   else if(path[i][1]==T)
    printf("%d +\n",path[i][0]-N);
  }


	    
	}
	return 0;
}


