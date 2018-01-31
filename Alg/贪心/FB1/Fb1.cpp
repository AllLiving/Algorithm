#include <iostream>
#include <cstring>
using namespace std;

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, бн
// 2^31 = 2,147,483,648;
long long num[2150000000];

long long F(int n){
	if(num[n] == -1){
		num[n]=F(n-1)+F(n-2);
	}
	return num[n];
}

int main(){
	memset(num, -1, sizeof(num));
	num[0]=0;
	num[1]=num[2]=1;
	
	int n;
	while(cin>>n){
//		for(int i=0; i<=n; i++){
//			cout << F(i) <<' ';
//		}cout<<endl;
		cout<<F(n)<<endl;
	}
	return 0;
}
