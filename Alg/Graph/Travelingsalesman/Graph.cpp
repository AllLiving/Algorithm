#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#define inf 99999
using namespace std;

int x[25],y[25];
double dst[25][25], c[1<<19][25];
void dist(int a, int b){
	double dx=x[a]-x[b], dy=y[a]-y[b];
	dst[b][a]=dst[a][b]=sqrt(dx*dx+dy*dy);
}

int main(){
	int T;	cin>>T;
	while(T--){
		memset(dst, 0, sizeof(dst));
		int n;	cin>>n;
		for(int i=0; i<n; i++){
			cin >> x[i] >> y[i];
		}
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				dist(i,j);
			}
		}
		int nst=1<<(n-2);//set of n-2 elems;
		for(int i=0; i<nst; i++){
			for(int j=0; j<n; j++){
				c[i][j]=inf;
			}
		}
		for(int j=0; j<n; j++){
			c[0][j]=dst[0][j];
		}
		for(int i=1; i<nst; i++){
			for(int j=1; j<n-1; j++){
				for(int k=1; k<n-1; k++){
					if((1<<(k-1))&i){
						c[i][j]=min(c[i][j], dst[j][k]+c[i-(1<<(k-1))][k]);
//						printf("c[%d][%d]=%lf\n",i,j,c[i][j]);
					}
				}
			}
		}
		
		double ans=inf;
		for(int i=1; i<n; i++){
			ans=min(ans, dst[i][n-1]+c[nst-1][i]);
		}
		
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}
