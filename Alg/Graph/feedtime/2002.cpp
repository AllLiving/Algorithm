#include <iostream>
#include <cstring>
using namespace std;

char mp[755][755]; //map 
int cls[999999], w, h;

void cck(){//检测程序 
	printf("\nThe map is\n");
	for(int i=0; i<=h; i++){
		for(int j=0; j<=w; j++){
			printf("%c",mp[i][j]);
		}printf("\n");
	}
}
int main(){
	int n=0;	cin>>w>>h;
	for(int i=0; i<=h; i++){
		for(int j=0; j<=w+1; j++){
			if((i*j)==0){//为map加边框 
				mp[i][j]='*';
			}else if(j==w+1){
				mp[i][j]='*';
			}else	cin >> mp[i][j];
		}
	}
	
//	search rest all position;
//	printf("deal with digits.\n");
	memset(cls, 0, sizeof(cls));
	for(int i=1; i<=h; i++){//遍历map 
		for(int j=1; j<=w; j++){
			if(mp[i][j] == '.'){//为一块草地分类 
				char a[]={0, mp[i-1][j], mp[i][j-1], mp[i-1][j-1], mp[i-1][j+1]};
				int sta=0, ngh[]={0, 0, 0, 0, 0}, maxn=0;
				for(int k=1; k<=4; k++){//检查周遭的类别 
//					printf("checking %c\n",a[k]);
					if(isdigit(a[k])){
						sta++;
						ngh[k]=a[k]-'0';
						maxn=max(maxn, a[k]-'0');
//						printf("maxn=%d\n",maxn);
					}
				}
				
				if(sta==0){
					mp[i][j]=(++n)+'0';
					cls[n]++;
				}else if(sta == 1){
					mp[i][j] = maxn+'0';
					cls[maxn]++;
				}else{
//					printf("maxn=%d\n",maxn);
					mp[i][j]=maxn+'0';
					cls[maxn]++;
					for(int i=1; i<=4; i++){
						if(ngh[i]<maxn&&ngh[i]>0){
//							printf("checking %d Merge...",ngh[i]);
							cls[maxn] += cls[ngh[i]];
							cls[ngh[i]]=0;
						}
					}
				}
//				cck();
//				if(i > 4)
//					system("PAUSE");
			}
		}
	}

	int ans=0;
	for(int i=1; i<=n; i++){
//		printf("cls[%d]=%d\n",i,cls[i]);
		ans=max(ans, cls[i]);
	}cout<<ans<<endl;
	
	return 0;
}
/*
10 8
...*....**
..**....**
...*....**
...**.*.**
***.**.***
...**.*.**
...*.*****
...***..**
*/
