#include <iostream>
#include <cstring>
using namespace std;

bool cbp(char a,char b){
    string s;
    s += a;
    s += b;
    if(s=="TA"||s=="AT"||s=="CG"||s=="GC"){
        return true;
    }
    return false;
}

bool strands(string a, string b){
    if(a.length() != b.length()){
        return false;
    }
    int len=a.length();
    for(int i=0; i<len; i++){
        if(!cbp(a[i], b[i])){
            return false;
        }
    }
    return true;
}

int main(){
    int T;  cin>>T;
    while(T--){
        int n;  cin>>n;
        string s[n+2];
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        int cnt=0;
        bool used[n+2];
        memset(used, 0, sizeof(used));
        for(int i=0; i<n; i++){
        	//use no more than once=>check one distroy one; 
        	//analyze the process£» 
            for(int j=i+1; j<n&&used[i]==false; j++){
                if(strands(s[i], s[j])==1&&used[j]==false){
                    cnt++;
                    used[j]=used[i]=true;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
} 
