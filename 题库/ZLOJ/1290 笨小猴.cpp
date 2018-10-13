#include<bits/stdc++.h>
using namespace std;
int cnt[35];
char s[105];
int main(){
	scanf("%s",s);
	int n=strlen(s),Max=-1,Min=-1,i;
	memset(cnt,-1,sizeof(cnt));
	for(i=0;i<n;i++){
		if(cnt[s[i]-'a']==-1)cnt[s[i]-'a']=0;
		cnt[s[i]-'a']++;
	}
	for(i=0;i<=25;i++){
		if((Max==-1||Max<cnt[i])&&cnt[i]!=-1)Max=cnt[i];
		if((Min==-1||Min>cnt[i])&&cnt[i]!=-1)Min=cnt[i];
	}
	bool flag=1;
	int num=Max-Min;
	if(num==1||num==0)flag=0;
	for(i=2;i*i<=num;i++)
		if(num%i==0){
			flag=0;break;
		}
	if(!flag)printf("No Answer\n0\n");
	else printf("Lucky Word\n%d\n",num);
}
