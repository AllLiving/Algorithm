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
��next_permutaton��ʹ�÷������Ǻ��˽⣻
�������⣺����żȻ����ĳ�������������Ŀ���ԣ�
	������麯����ʵ�ֹ��̣� 
*/
