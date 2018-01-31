#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	while(cin >> n && n!="0"){
		long long ans=0;
		for(int i=0; i<n.length(); i++){
			ans *= 9;
			if(n[i] > '4')	ans--;
			ans += n[i]-'0';
		}
		printf("%s: %ld\n",n.c_str(), ans);
	}
	
}
