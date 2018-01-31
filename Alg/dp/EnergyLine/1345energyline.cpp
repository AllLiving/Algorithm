#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a[205][205], e[205];
/*
a 用于直接表示计算量， 联系3个量；
于是记录， 免去多余计算，区别于朴素递归； 
*/
int dp(int i, int j){
	if(a[i][j]!=-1){
		return a[i][j];//记录； 
	}else if(i==j){
		return a[i][j]=0;
	}
	
	int ans=0;
	/*
	此处还是使用了递归，形式上而已；
	=>递归还是会将整个思路向精细化的方向发展，不同于递推； 
	状态转移方程还是非常明晰；
	下一个状态与之前的若干个状态之间有紧密联系；
	另，
	递归的使用也并没有浪费太多的资源，
	由于合理地记录从而没有重复计算；*/ 
	for(int k=i; k<j; k++){
		ans=max(ans, dp(i,k)+dp(k+1,j)+e[i]*e[j+1]*e[k+1]);
	}
	return a[i][j]=ans;
}

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		memset(a, -1, sizeof(a));
		for(int i=0; i<N; i++){
			int tmp;
			scanf("%d",&tmp);
			e[i]=e[i+N]=tmp;
		}
		int v=0;
		for(int i=0; i<N; i++){
			v=max(v, dp(i, i+N-1));
		}
		printf("%d\n",v);
	}
	return 0;
} 
