#include  <iostream>
#include <stack>
using namespace std;

int covn(int n, int base){
	int sum=0;
	string prodt;
	char div;
	stack<char> aft;
	for( ; (n/base); ){
		sum += (n%base);
		if(n%base > 9){
			div = 'A'+(n%base - 10);
		}else	div = (n%base)+'0';
		aft.push(div);
		n /= base;
	}
	sum += (n%base);
	if(n%base > 9){
		div = 'A'+(n%base - 10);
	}else	div = (n%base)+'0';
	aft.push(div);
	
	while(!aft.empty()){
		prodt += aft.top();
		aft.pop();
	}
	return sum;
}

int main(){
	int n, base[3]={10, 12, 16};
	for(n=2992; n<=9999; n++){
		bool avl=true;
		for(int i=1; i<3; i++){
			if(covn(n, base[0]) != covn(n, base[i]))	avl=false;
		}
		if(avl)	cout<<n<<endl;
	}
	return 0;
}
