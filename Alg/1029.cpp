#include <iostream>
#include <cstring>
using namespace std;

int m, d;
string ns[112];

string merge(string a, string b){
	string l,s;
	l="";	s="";
	for(int i=a.length()-1; i>=0; i--)	l += a[i];
	for(int i=b.length()-1; i>=0; i--)	s += b[i];
	if(a.length() < b.length()){
		l="";	s="";
		for(int i=b.length()-1; i>=0; i--)	l += b[i];
		for(int i=a.length()-1; i>=0; i--)	s += a[i];
	}
	
	string tmp;
	int nb=0;
	for(int i=0; i<s.length(); i++){
//		cout << s[i]<<' '<<l[i] << endl;
		int cb=( (s[i]-'0')+(l[i]-'0') )%10;
		tmp += ( (nb+cb)+'0' );
//		cout<<"tmp="<<tmp<<endl;
		nb = ( (s[i]-'0')+(l[i]-'0') )/10;
	}
	
	if(l.length() > s.length()){
		tmp += ( (nb+(l[s.length()]-'0'))+'0' );
		for(int i=s.length()+1; i<l.length(); i++)
		{
			tmp += l[i];
		}
	}else if(l.length()==s.length()&&nb>0)
		tmp += (nb+'0');
	
	
	string fn;
	for(int i=tmp.length()-1; i>=0; i--)
		fn += tmp[i];
//	printf("a=%s\nb=%s\nfn=%s\n",&a[0],&b[0],&fn[0]);
	return fn;
}

string F(int n){
	if(n <= 0)	return "1";
	if(ns[n]!="")	return ns[n];
	string s1=F(n-1), sd=F(n-m); 
	ns[n]=merge(s1, sd);
	return ns[n];
}

int main(){
//	string s1, s2;
//	while(cin >> s1 >> s2){
//		cout<<merge(s1,s2)<<endl;
//	}
//	
	
	while(cin >> m >> d){
		if(m==0&&d==0) break; 
		for(int i=0; i<=110; i++)	ns[i]="";
		cout << F(d) << endl;
	} 
	return 0;
}
