#include <iostream>
using namespace std;

struct tr{
	tr *l, *r;
	int v;
	tr(){
		l = r = NULL;
	}
};

inline void insert(tr *t, int v){
	tr *pin=t;
	if(v > pin->v){
		if(t->r == NULL){
			tr *p=new tr;
			p->v = v;
			pin->r = p;
		}else insert(pin->r, v);
	}else if(v <= pin->v){
		if(t->l == NULL){
			tr *p=new tr;
			p->v = v;
			pin->l = p;
		}else insert(pin->l, v);
	}
}

inline void pre(tr *t){
	printf(" %d",t->v);
	if(t->l != NULL){
		pre(t->l);
	}
	if(t->r != NULL){
		pre(t->r);
	}
}

inline void inn(tr *t){
	if(t->l != NULL){
		inn(t->l);
	}
	printf(" %d",t->v);
	if(t->r != NULL){
		inn(t->r);
	}
}

void pst(tr *t){
	if(t->l != NULL){
		pst(t->l);
	}
	if(t->r != NULL){
		pst(t->r);
	}
	printf(" %d",t->v);
}

int main(){
	int T;
	bool kg=false;
	while(cin >> T){
		int n; cin>>n;
		tr *t=new tr;
		t->v = n;
		for(int i=1; i<T; i++){
			cin>>n;
			insert(t, n);
		}
		if(kg==true){
			printf("\n");
		}
		kg=true;
		printf("Inorder:");
		inn(t);
		printf("\nPreorder:");
		pre(t);
		printf("\nPostorder:");
		pst(t);
		cout<<endl;
	}
	return 0;
}
