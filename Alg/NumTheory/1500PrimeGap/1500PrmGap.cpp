#include <bits/stdc++.h>
using namespace std;

int prm[1300000];
bool Is_Prime(int n){
	for(int i=2; i<=sqrt(n*1.0); i++){
		if((n%i) == 0)	return false;
	}
	return true;
}

int main(){
	int cnt=0;
	for(int i=2; i<=1299709; i++){
		if(Is_Prime(i)) prm[cnt++]=i;
	}
	
	int n;
	while(cin>>n && n){
        for(int i = 0; i < 100000; i++)  
        {  
            if(prm[i] == n)//输入的是素数  
            {  
                cout << "0" << endl;  
                break;  
            }  
            else{  
                if(n < prm[i] && i != 0){  
                    cout << prm[i] - prm[i - 1] << endl;  
                    break;  
                }  
            }  
        }  
	}
}
