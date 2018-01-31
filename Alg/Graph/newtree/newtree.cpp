#include <iostream>
#include <vector>
using namespace std;

int main(){
	bool c[25];
	int n, w[25];
	vector<int> tr[25]; 
	cin >> n;
	for(int tnk=1; tnk<=n; tnk++){
		int a, b, color, wgt;
		cin>>a>>b>>color>>wgt;
		
		tr[a].push_back(b);
		c[tnk]=(color==1);
		w[tnk]=wgt;
	}
	return 0;
}
