#include <iostream>
using namespace std;

int main(){
	int n, m;
	n=m=5;
	int map[n+3][m+3];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];
		}
	}
	int drct[5];
	for(int i=1; i<5; i++){
		cin >> drct[i];
	}
	
	
	
	return 0;
}
