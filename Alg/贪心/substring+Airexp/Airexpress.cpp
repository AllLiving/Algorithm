#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T;	cin>>T;
	while(T--){
		int n; cin>>n;
		string s[n+2];
		for(int i=0; i<n; i++){
			cin>>s[i];
		}
		sort(s, s+n);
		
		string rgt;
		bool bgin=true;
		do{
			string tmp;
			for(int i=0; i<n; i++){
				tmp += s[i];
			}
			cout << tmp << endl;
			if(bgin==true){
				rgt = tmp;
				bgin = false;
			}
			if(rgt > tmp)	rgt = tmp;
		}while(next_permutation(s, s+n));
//		cout <<rgt<<endl; /**/
	}
	return 0;
} 
/*
对next_permutaton的使用方法不是很了解；
发现问题：纯属偶然发现某个样例输出的数目不对，
	进而检查函数的实现过程； 
*/
