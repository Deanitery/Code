#include<bits/stdc++.h>
using namespace std;
#define M 105 
int n,m; 
int L[M],dp[M],V[M],low,up;
int mark[M];
struct edge{
	int b,c;
};
vector<edge>E[M];
struct node{
	int p,c;
	bool operator<(const node &A)const{
		return c>A.c;}
};
priority_queue<node>Q;
int Dijk(){
	int i; 
	memset(mark,0,sizeof(mark));
	for(i=1;i<=n;i++)dp[i]=V[i];
	for(i=1;i<=n;i++){
		if(L[i]>up||L[i]<low)continue;
		Q.push((node){i,dp[i]});
	}
	while(!Q.empty()){
		node x=Q.top();Q.pop();
		int u=x.p;
		if(mark[u])continue;
		mark[u]=1;
		for(i=0;i<E[u].size();i++){
			int d=E[u][i].b,e=E[u][i].c;
			if(L[d]<low||L[d]>up)continue;
			if(dp[d]>dp[u]+e){
				dp[d]=dp[u]+e;
				Q.push((node){d,dp[d]});
			}
		}		
	}
	return dp[1];
}
int main(){
	int b,c,x,i,j; 
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&V[i],&L[i],&x);
		for(j=1;j<=x;j++){
			scanf("%d %d",&b,&c);
			E[b].push_back((edge){i,c});
		}
	}
	int ans=2e9;
	for(i=L[1]-m;i<=L[1];i++){
		low=i;
		up=low+m;
		ans=min(ans,Dijk());
	}
	printf("%d\n",ans);
}
