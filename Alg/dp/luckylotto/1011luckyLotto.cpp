#include <iostream>
#include <cstring>
#include <set> 
#include <algorithm>
using namespace std;

long long dp[15][2005];
int p[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int main() {  
	int cases; cin>>cases;
	int cnum=1;
	while(cases--){
		int n,m;
		cin>>n>>m;
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=m; i++) 	dp[1][i]=1;
		for(int i=2; i<=n; i++)
		{
			for(int j=p[i-1]; j<=m; j++){
//				printf("From dp[%d][%d]=%d---------",i,j-1,dp[i][j-1]);
				if(j%2==0)
					dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
				else	dp[i][j]=dp[i][j-1];
//				printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			}
		} 
		long long sum=0;
		for(int i=1; i<=m; i++){
			sum+=dp[n][i];
		}
		
		printf("Case %d: n = %d, m = %d, # lists = %lld\n",cnum++,n,m,sum);
	} 
    return 0;  
} /**/
/*
n m分别限制可能性；
故而作为状态转移的参照系； 
*/
