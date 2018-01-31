#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
	int n, T;
	cin >> T;
	while(T--){
		cin >> n;
		set<int> ftg;
		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			ftg.insert(tmp);
		}
		
		set<int>::iterator it;
		vector<int> vt;
		for(it=ftg.begin(); it!=ftg.end(); it++){
			vt.push_back(*it) ;
		}
		
		n=vt.size();
//		for(int i=0; i<n; i++){
//			cout<<vt[i];
//		}cout<<endl;

		int cnt=0;
		for(int i=0; i<n-2; i++){
			for(int j=i+1; j<n-1; j++){
				int pin=j+1;
				while(vt[i]+vt[j] > vt[pin]&&pin < n){
					cnt++;
					pin++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
