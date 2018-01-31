#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long p[35][35];
long long dp(int i,int j){
//	printf("p[%d][%d]is been checking.\n",i,j);
	if(p[i][j]!=-1){
		return p[i][j];
	}else if(j==0){
		return 1;
	}
	
	long long ans=0;
	if(i>j){
		ans=dp(i-1,j)+dp(i,j-1);
	}else{
		ans=dp(i,j-1);
	}
//	printf("The possibility=%d\n",ans);
	return p[i][j]=ans;
}
int main(){
	int n;
	while(cin>>n&&n){
		memset(p, -1, sizeof(p));
		cout << dp(n, n)<<endl;
	}
	return 0;
}
