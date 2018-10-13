#include<bits/stdc++.h>
using namespace std;
#define M 20005
int fa[2*M];
struct node{
	int a,b,c;
	bool operator<(const node &A)const{
		return c>A.c;}
}T[M*5];
int getfa(int v){
	return fa[v]==v?v:fa[v]=getfa(fa[v]);}
int main(){
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&T[i].a,&T[i].b,&T[i].c);
	for(i=1;i<=2*n;i++)fa[i]=i;
	sort(T+1,T+1+m);
	for(i=1;i<=m+1;i++){
		int x=T[i].a,y=T[i].b,z=T[i].c;
		if(getfa(x)==getfa(y)){
			printf("%d\n",z);
			break;
		}
		fa[fa[x]]=fa[getfa(y+n)];
		fa[fa[y]]=fa[getfa(x+n)];
	}
	return 0;	
}
