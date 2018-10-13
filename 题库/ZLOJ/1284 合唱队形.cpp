#include<bits/stdc++.h>
using namespace std;
#define M 105
int dp1[M][235],dp2[M][235];
int A[M];
void check(int &x,int y){
	if(x==-1||x>y)x=y;}
int main(){
	int n,i,j;
	scanf("%d",&n);
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	for(i=1;i<=n;i++)scanf("%d",&A[i]);
	dp1[0][100]=0;
	for(i=0;i<=n;i++)
		for(j=100;j<=230;j++){
			if(dp1[i][j]==-1)continue;
			if(A[i+1]>j)check(dp1[i+1][A[i+1]],dp1[i][j]);
			check(dp1[i+1][j],dp1[i][j]+1);
		}
	dp2[n+1][100]=0;	
	for(i=n+1;i>=1;i--)
		for(j=100;j<=230;j++){
			if(dp2[i][j]==-1)continue;
			if(A[i-1]>j)check(dp2[i-1][A[i-1]],dp2[i][j]);
			check(dp2[i-1][j],dp2[i][j]+1);
		}
	int ans=1e9;	
	for(i=1;i<=n;i++){
		if(dp1[i][A[i]]==-1||dp2[i][A[i]]==-1)continue;
		ans=min(ans,dp1[i][A[i]]+dp2[i][A[i]]);	
	}
	printf("%d\n",ans);
}
