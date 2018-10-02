#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct edge{
	int to,cost;
};
vector<edge>E1[M],E2[M];
int n,m,K,P,in[M][55];
int dp[M][55],dis[M];
bool vis[M];
struct node{
	int pos,len;
	bool operator<(const node &x)const{
		return len>x.len;
	}
};
priority_queue<node>Q;
void Add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
void Dijk(){
	Q.push((node){n,0});
	memset(dis,63,sizeof(dis));
	dis[n]=0;
	while(!Q.empty()){
		node now=Q.top();Q.pop();
		int x=now.pos;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<E2[x].size();i++){
			int y=E2[x][i].to,z=E2[x][i].cost;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				Q.push((node){y,dis[y]});
			}
		}
	}
} 
int dfs(int x,int f){
	int &res=dp[x][f];
	if(in[x][f])return res=-1;
	if(dp[x][f]!=0)return res;
	res=(x==n);in[x][f]=1;
	for(int i=0;i<E1[x].size();i++){
		int y=E1[x][i].to,z=E1[x][i].cost;
		if(dis[x]+f-dis[y]>=z){
			int lim=dis[x]+f-dis[y]-z,v;
			if(v=dfs(y,lim)==-1)return res=-1;
			Add(res,v);
			printf("%d %d->%d %d\n",y,lim,x,f);
		}
	}
	printf("%d %d %d\n",x,f,res);
	in[x][f]=0;
	return res;
}
void Clear(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=K;j++)
			dp[i][j]=0;
		E1[i].clear();
		E2[i].clear();		
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&K,&P);
		int i,x,y,z;
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			E1[x].push_back((edge){y,z});
			E2[y].push_back((edge){x,z});
		}
		Dijk();
		for(i=1;i<=n;i++){
			printf("dis:%d %d\n",i,dis[i]);
//			for(int j=0;j<=K;j++){
////				printf("%d %d %d\n",i,j,dp[i][j]);
//			}
		}
puts("enter");
		printf("%d\n",dfs(1,K));
		Clear();
	}
	return 0;
}
