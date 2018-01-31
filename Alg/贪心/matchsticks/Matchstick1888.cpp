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
//			printf("min_size=%d\n",minsz);
			int tmp=1;
			if(minsz==0){
				tmp=0;
			}
			for(int i=tmp; i<10; i++){
				if(dpy[i]==n%maxcost){
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
23 11111
*/
