#include <iostream>
#include <algorithm>
using namespace std;

int dpy[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
#define mincost 2
#define maxcost 7
int main(){
	int T; cin>>T;
	while(T--){
		int n;	cin >> n;
		
		int minsz, head_min;
		if(n%maxcost >= mincost){
			minsz = (n/maxcost);
			for(int i=1; i<10; i++){
				if(dpy[i]==n%maxcost&&minsz){
					if(i==4){
						minsz--;
						head_min=20;
					}else if(i==7){
						minsz--;
						if(!minsz){
							head_min=22;
						}else{
							minsz--;
							head_min=200;
						}
						/*
						78=>22=>00的数据转换， 
						没有考虑到相邻数据的转换，
						分析问题不彻底；除以8的状态只适合计算位数；
						只看到了问题与情况，
						没有看到多次使用的规律； 
						*/
					}else{
						head_min=i;
					}break;
				}else if(dpy[i]==n%maxcost&&!minsz){
					head_min=i;
					break;
				}
			}
		}else if(n%maxcost == 1){
			minsz = (n-7)/maxcost;
//			printf("min_size=%d\n",minsz);
			head_min=10; 
		}else{
			minsz = (n/maxcost)-1;
			head_min = 8;
		}
		
		int maxsz, head_max;
		if(n&1){
			maxsz=(n-2)/2;
//			printf("max_size=%d\n",maxsz);
			head_max=7;
		}else{
			maxsz=n/2-1;
//			printf("max_size=%d\n",maxsz);
			head_max=1;
		}
		
		printf("%d",head_min);
		for(int i=0; i<minsz; i++){
			cout<<8;
		}cout<<' ';
		printf("%d",head_max);
		for(int i=0; i<maxsz; i++){
			cout << 1;
		}cout<<endl;
	}
	return 0;
} 

/**
10
22 11111

28
68
*/
