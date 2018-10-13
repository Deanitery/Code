#include<bits/stdc++.h>
using namespace std;
int cnt[105],A[105];
int tot,len,sum,odd,n;
bool flag,dp[3005];
int t=0;
int pos[3005],nxt[105];
void dfs(int x,int p,int r){
    printf("A:%d %d %d %d\n",x,p,r,nxt[p]);
    if(r>nxt[p])return;
    puts("Noreturn");
    t++;
    if(t>=100000){
//		puts("TLE");
//		return;
		exit(0);
	}
    if(flag)return;
    if(!dp[r])return;
    if(x==tot+1){
        flag=1;
        return;
    }
//    printf("B:%d %d %d\n",x,p,r);
    if(r==0){
        if((odd<tot-x)||(tot-x-odd)%2==1)return;
        dfs(x+1,1,len);
        return;
    }
    while(p<=n&&!cnt[A[p]])p++;//,puts("While"),printf("p:%d\n",p);
//  if(r-A[p]<0)return;
//	p=pos[r];
    for(int i=p;i<=n;i++){
        bool flag=0;
//        puts("For");
//        printf("i:%d\n",i);
        for(int j=1;j<=cnt[A[i]]&&j*A[i]<=r;j++){
//        	puts("For");
            cnt[A[i]]-=j;
            odd-=(A[i]%2)*j;
//            printf("j:%d\n",j);
            flag=1;
            dfs(x,i+1,r-j*A[i]);
            cnt[A[i]]+=j;
            odd+=(A[i]%2)*j;
        }
        if(!flag)break;
    }
}
int main(){
//	system("data.exe");
//	freopen("data.in","r",stdin);
    scanf("%d",&n);
    int x,i,odd=0,c=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>50)continue;
        A[++c]=x;
        cnt[x]++;
        odd+=x%2;
        len=max(x,len);
        sum+=x;
    }
    n=c;
    sort(A+1,A+1+n);
    n=unique(A+1,A+1+n)-A-1;
    dp[0]=1;
    for(int i=n;i>=1;i--){
		for(int j=A[i];j<=sum;j++)
			dp[j]|=dp[j-A[i]];
		nxt[i]=nxt[i+1]+A[i]*cnt[A[i]];
	}
	for(int i=1,j=1;i<=sum;i++){
		while(j<=n&&i>=A[j])j++;
		if(i>=A[j-1])pos[i]=j-1;
//		printf("num:%d val:%d\n",i,A[pos[i]]);
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",A[i]);
//	puts("");
//printf("%d\n",len);
    for(;;len++){
        if(sum%len)continue;
        tot=sum/len;
        printf("tot:%d len:%d\n",tot,len);
        if(len%2){
            if(odd<tot||(tot-odd)%2)
                continue;
        }else if(odd%2)continue;
        dfs(1,1,len);
        if(flag)break;
    }
    printf("%d\n",len);
    return 0;
}
