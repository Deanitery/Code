#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct P30{
	int mp[1005][1005];
	void solve(){
		int x,y,i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				mp[i][j]=(i-1)*m+j;
		for(i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			printf("%d\n",mp[x][y]);
			int t=mp[x][y];
			for(j=y;j<=m;j++)mp[x][j]=mp[x][j+1];
			for(j=x;j<=n;j++)mp[j][m]=mp[j+1][m];
			mp[n][m]=t;
		}
	}
}p30;
struct Px1{
	#define M 1000005
	#define Ls p<<1
	#define Rs p<<1|1
	#define LL long long
	struct node{
		int L,R;
		int sz;
		LL num;
	}T[M<<2];
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R){
			if(L<=n+m-1){
				T[p].sz=1;
				if(L>m){
					T[p].num=m+1LL*(L-m)*m;
				}else T[p].num=L;
			}
			return;
		}
		int mid=(L+R)>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		T[p].sz=T[Ls].sz+T[Rs].sz;
	}
	LL Query(int x,int p){
		if(T[p].L==T[p].R){
			LL t=T[p].num;
			T[p].sz=0;T[p].num=0;
			return t;
		}
		int mid=T[Ls].R;
		LL ans;
		if(T[Ls].sz>=x)ans=Query(x,Ls);
		else ans=Query(x-T[Ls].sz,Rs);
		T[p].sz=T[Ls].sz+T[Rs].sz;
		return ans;
	}
	void Update(int x,int p,LL v){
		if(T[p].L==T[p].R){
			T[p].sz=1;
			T[p].num=v;
			return;
		}
		int mid=T[Ls].R;
		if(x<=mid)Update(x,Ls,v);
		else Update(x,Rs,v);
		T[p].sz=T[Ls].sz+T[Rs].sz;
	}
	void solve(){
		int x,y,i,cnt=n+m-1;
		Build(1,n+m+q,1);
		for(i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			++cnt;
			LL ans=Query(y,1);
			printf("%lld\n",ans);
			Update(cnt,1,ans);
		}
	}
}px1;
struct P20{
	void solve(){
		
		
		
		
		
	}
};
int main(){
//	freopen("phalanx.in","r",stdin);
//	freopen("phalanx.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if(q<=500)p30.solve();
	else px1.solve();
	return 0;
}
