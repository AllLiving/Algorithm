#include <iostream>
using namespace std;

int n;
void pft(int s){
    for(int i=0; i<n; i++){
        if((1<<i)&s){
            printf("%c",'A'+i);
        }
    }printf("\n");
}

void subset(int entry, int s){
//	printf("entry=%d pin=%d s=%d\n",entry, pin, s);
    pft(s);
    for(int i=0; i<n; i++){
        if(entry&(1<<i)) continue;
        entry |= (1<<i);
        subset(entry, s|(1<<i));
    }
}

int main(){
    cin >> n;
    subset(0, 0);
    return 0;
}                                 

