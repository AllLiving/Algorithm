#include <bits/stdc++.h>
using namespace std;

int Tm;
double Min, unit=sqrt(0.5), x, y;
//顺逆时针不能颠倒； 
double Drc[8][2] = {{1,0}, {0, -1}, {0, 1}, {-1, 0}, {-1*unit, -1*unit}, 
                    {unit, -1*unit}, {-1*unit, unit}, {unit, unit}};
//double Drc[8][2]={{1,0}, {unit, unit}, {0,1}, {-1*unit, unit}, 
//				{-1, 0}, {-1*unit, -1*unit}, {0,-1}, {unit, -1*unit}};
struct pos{
	double x, y;
	int dir;
	pos(){
		dir = x = y = 0;
	}
};
double dst(pos p){
	return ((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
}
void Dfs(int time, pos p){
	if(time<=Tm){
		Min=min(dst(p), Min);//必须在比较之后； 
		pos tmp=p;
		tmp.x += 10*Drc[tmp.dir][0];
		tmp.y += 10*Drc[tmp.dir][1];
		Dfs(time+1, tmp);
		
		if(p.dir+1<8){
			p.dir++;
			Dfs(time+1, p);
		}
	}
}

int main(){
	int t;	
	cin >> t;
	while(t--){
		cin >> Tm >> x >> y;
		Min = 10000000;
		pos p;
		Dfs(0, p);
        printf("%.6f\n", sqrt(Min));
//		cout<<fixed<<setprecision(6)<<sqrt(Min)<<endl;
	}
	return 0;
}/**/   
