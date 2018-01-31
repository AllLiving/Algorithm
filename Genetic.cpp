#include <bits/stdc++.h>
using namespace std;

bool exist(int n[], int len, int a){
	bool ext=false;
	for(int i=0; i<len; i++){
		if(n[i] == a){
			ext = true;
			break;
		}
	}
	return ext;
}

int main(){
	int len;
	while(cin >> len){
		int p[2][len+2];
		for(int ps=0; ps<2; ps++){
			for(int i=0; i<len; i++){
				cin >> p[ps][i];
			}
		}
		int sta, end;
		cin >> sta >> end;
//		cout << "len=" << len << endl;
		
		int s[2][len+2];
		for(int ps=0; ps<2; ps++){
			int sub[len];
			for(int i=sta, sb=0; i<=end; i++){
				sub[sb++] = p[ps][i];
			}
//			printf("sub=");
//			for(int i=0; i<end-sta+1; i++)
//				cout << sub[i] <<' ';
//			cout << endl;
			
			int smk=-1, si=0;
			for(int i=0; i<len&&si<sta; i++){
				smk = i;
				if(!exist(sub, end-sta+1, p[1-ps][i]))
					s[ps][si++] = p[1-ps][i];
			}
			for(int i=sta; i<=end; i++){
				s[ps][si++] = p[ps][i];
			}
			for(int i=smk+1; i<len; i++){
				if(!exist(sub, end-sta+1, p[1-ps][i]))
					s[ps][si++] = p[1-ps][i];
			}
		}
		
		for(int ps=0; ps<2; ps++){
			cout << s[ps][0];
			for(int i=1; i<len; i++){
				cout << ' ' << s[ps][i];
			}cout<<endl;
		}
	}
}
