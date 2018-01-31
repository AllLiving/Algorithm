#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a[6],wgt[6]={3, 5, 6, 11, 2, 8};
double v[6]={0.01, 0.05, 0.25, 0.50, 0.10, 1};
double g[10][10020];
//30 3  1  10  4  2  0

//״̬��Ӳ������i��ʣ������w�� 
//�����Լ۱�����Ӳ�����ࣻ 
double dp(int i, int w){
	if(g[i][w]>0)	return g[i][w];
//	���һ�����ࣻ 
	if(i==0){
		int num=min(w/wgt[i], a[i]);//�������ޣ� 
		double maxv=0;
		for(int k=0; k<=num; k++){
			maxv=max(maxv, k*v[i]);
		}
		g[i][w]=maxv;
		return g[i][w];
	}
	
	double maxv=0;
	for(int k=0; k<=a[i]; k++){
		if(w >= k*wgt[i]){
//			��������ֵ�� ������һ�����ࣻ 
			maxv=max(maxv, dp(i-1,w-k*wgt[i])+k*v[i]);
		}
	}
	return g[i][w]=maxv;
}

int main(){
	int m;
	while(cin>>m){
		for(int i=0; i<6; i++) 	cin>>a[i];
		memset(g, 0, sizeof(g));
		cout<<dp(5,m)<<endl;
		printf("done.\n");
	}
	return 0;
} 
