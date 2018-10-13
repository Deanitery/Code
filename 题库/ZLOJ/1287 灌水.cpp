#include<bits/stdc++.h>
using namespace std;
#define M 305
struct edge{
	int x,y,c;
	bool operator<(const edge &A)const{
		return c<A.c;}
}E[M*M]; 
int fa[M];
int V[M],n;
int getfa(int v){
	return fa[v]==v?v:fa[v]=getfa(fa[v]);}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&V[i]);
	int x,t=1,cnt=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=t;j++)scanf("%d",&x);
		for(j=++t;j<=n;j++){
			scanf("%d",&x);
			E[++cnt]=(edge){i,j,x};
		}
	}
	for(i=1;i<=n;i++)fa[i]=i;
	int ans=0;
	sort(E+1,E+1+cnt);
	for(i=1;i<=cnt;i++){
		if(getfa(E[i].x)!=getfa(E[i].y)){
			int a=fa[E[i].x],b=fa[E[i].y];
			if(max(V[a],V[b])>=E[i].c){
				if(V[a]>=V[b])fa[a]=b;
				else fa[b]=a;
				ans+=E[i].c;
			}
		}	
	}
	for(i=1;i<=n;i++)getfa(i);
	for(i=1;i<=n;i++)if(fa[i]==i)ans+=V[i];
	printf("%d\n",ans);
}
