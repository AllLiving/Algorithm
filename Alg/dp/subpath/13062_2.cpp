#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	int dp[n][n];
	memset(dp, -1, sizeof(dp));
	dp[0][1]=dp[0][0]=1;
	while(cin>>n){
		for(int i=0; i<=n; i++){
			for(int j=i; j<=n; j++){
				/*
				有已知条件推导问题；
				有明确的入手点与推算过程； 
				*/
				if(i==0){
					dp[i][j]=1;
				}else if(j>i){
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				}else if(i==j){
					dp[i][j]=dp[i-1][j];
				} 
//				printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			}
		}
		cout<<dp[n][n]<<endl;
	}
	return 0;
} 
