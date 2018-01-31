#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int prm[1250];
int prm_sum[1250];
bool Is_Prime(int n){
	for(int i=2; i<=sqrt(n*1.0); i++){
		if((n%i) == 0)	return false;
	}
	return true;
}

int main(){
	int cnt=0;
	for(int i=2; i<=10000; i++){
		if(Is_Prime(i)) prm[cnt++]=i;
	}
		
//	printf("\tseq=");
//	for(int i=0; i<10; i++){
//		printf("  %d", prm[i]);
//	}cout<<endl;
	
	int sum=0;
	for(int i=0; i<=cnt; i++){
		int sum=0;
		for(int j=0; j<=i; j++){
			sum += prm[j];
		}
		prm_sum[i+1]=sum;
	}
	
//	printf("sum_seq=");
//	for(int i=0; i<10; i++){
//		printf("  %d", prm_sum[i]);
//	}cout<<endl;
	
	int n;
	while(cin >> n&&n){
		int i, j, comp=0;
		for(i=0; i<cnt; i++){
			for(j=0; j<i; j++){
				if(n == (prm_sum[i]-prm_sum[j])){
					comp++;
//					printf("found=%d\n",(prm_sum[i]-prm_sum[j]));
				}
			}
		}
		
		cout<<comp<<endl;
//		for(int k=j; k<i; k++){
//			printf("%d ",prm[k]);
//		}cout<<endl;
	}
	
	return 0;
}
