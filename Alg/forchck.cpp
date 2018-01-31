#include <bits/stdc++.h>
using namespace std;
//#define T

int main(){
	int n,m, nice[102];
	while(cin >> n >> m){
		memset(nice, 0, sizeof nice);
		bool ptn[n+2][m+2];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> ptn[i][j];
				if(ptn[i][j] ==  1)	nice[i]++;
			}
		}
		
		int grps=0;
		for(int glindex=0; glindex<n; glindex++){
			bool cp=false;
			int min=150, gl=0;
			for(int i=0; i<n; i++){
				if(nice[i] < min){
					min = nice[i];
					gl = i;
				}
			}
//			printf("Girl[%d]\n", gl);
			for(int j=0; j<m; j++){
				if(ptn[gl][j]){
					cp=true;
					for(int i=0; i<n; i++)		ptn[i][j] = 0;
					for(int j=0; j<m; j++)		ptn[gl][j] = 0;
					break;
				}
			}
			nice[gl] = 150;
			if(cp)	grps++;
			for(int i=0; i<n; i++){
				if(nice[i] < 150) nice[i]=0;
				for(int u=0; u<m; u++){
					if(ptn[i][u] == 1) nice[i]++;
				}
			}
			#ifdef T
			printf("\n"); 
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<ptn[i][j]<<' ';
				}cout<<endl;
			}
			#endif
		}
		cout<<grps<<endl;
	}
	return 0;
}
