/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

struct vct{
	int x, y;
};
double Calen(vct a, vct b){
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
struct brge{
	friend bool operator<(brge a, brge b){
		return a.len > b.len;
	}
	double len;
	int l,r;
};
int prt[105];
bool Is_circle(int n){
	int pin=prt[n];
	while(pin != -1){
		pin = prt[pin];
		if(pin == n){
			return true;
		}
	}
	return false;
}

int main(){
	int n, clst; 
	memset(prt, -1, sizeof(prt));
	vct v[102];
//	brge bc[9999];
	priority_queue<brge> q;
	while(cin>>n>>clst){
		for(int i=0; i<n; i++){
			cin>>v[i].x>>v[i].y;
		}
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				brge bc; 
				bc.l = i;
				bc.r = j;
				bc.len = Calen(v[i], v[j]);
				printf("pair[%d][%d]=%lf\n",i,j,bc.len);
				q.push(bc);
			}
		}
		
		int cnt=0;
		while(!q.empty()){
			brge tmp=q.top();
			printf("Checking dst[%d][%d]=%lf\n",tmp.r, tmp.l, tmp.len);
			if(prt[tmp.l] != -1 && prt[tmp.r] != -1){
			} else{
				if(prt[tmp.l] == -1){
					prt[tmp.l]=tmp.r;
				}else if(prt[tmp.r] == -1){
					prt[tmp.r] = tmp.l;
				}
				printf("The dst[%d][%d]=%lf\n",tmp.r, tmp.l, tmp.len);
			}
			q.pop();
		}
	}
	return 0;
}/**/


#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> lowc;
const int max_vertexs = 100;
double g[max_vertexs][max_vertexs];
int father[max_vertexs];
typedef struct point{
    int x;
    int y;
}P;
float CalDistance(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
void get_prim(double a[max_vertexs][max_vertexs], int vcount, int f[max_vertexs]){
    }

int main(int argc, const char * argv[]) {
    int n,class_num;
    while (cin>> n >> class_num) {
        if (n == 0) break;
        int x,y;
        vector<point> v;
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point p1;
            p1.x = x;
            p1.y = y;
            v.push_back(p1);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i+1; j < n; j ++) {
                g[i][j] = g[j][i] = CalDistance(v[i], v[j]);
            }
        }
        lowc.clear();        // 使用prim算法求解最小生成树
        int i, j, k;
        double lowcost[max_vertexs];
        int closet[max_vertexs];
        int used[max_vertexs];
        for (int i = 0; i < n; i ++) {
            lowcost[i] = g[0][i];
            closet[i] = 0;
            used[i] = 0;
            father[i] = -1;
        }
        used[0] = 1;
        for (i = 1; i < n; i++) {
            j = 0;
            while (used[j]) {
                j++;
            }
            for (k = 0; k < n; k ++) {
                if (!used[k] && (lowcost[k] < lowcost[j])) {
                    j = k;
                }
            }
            father[j] = closet[j];
            lowc.push_back(lowcost[j]);
            used[j] = 1;
            for (k = 0; k < n; k ++) {
                if (!used[k] && (g[j][k] < lowcost[k])) {
                    lowcost[k] = g[j][k];
                    closet[k] = j;
                }
            }
        }

        sort(lowc.begin(), lowc.end());
        cout <<  setprecision(2) << setiosflags(ios::fixed)<< lowc[n-class_num] << endl;
        
    }
    return 0;
}/***/


