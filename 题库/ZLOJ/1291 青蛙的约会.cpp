#include<bits/stdc++.h>
using namespace std;
#define LL long long
void exgcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(b==0){
		d=a;x=1;y=0;
		return;
	}
	exgcd(b,a%b,d,y,x);
	y-=(a/b)*x;
	return;
}
int main(){
	LL m,n,Fx,Fy,L;
	LL x,y,d;
	scanf("%lld %lld %lld %lld %lld",&Fx,&Fy,&m,&n,&L);
	if(n<m){
		swap(n,m);
		swap(Fx,Fy);
	}
	exgcd(n-m,L,d,x,y);
	LL f=Fx-Fy;
	if(f%d!=0)puts("Impossible");
	else printf("%lld\n",((x*f/d)%(L/d)+L/d)%(L/d));
}
