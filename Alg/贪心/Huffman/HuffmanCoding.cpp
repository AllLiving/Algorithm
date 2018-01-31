#include <iostream>  
#include <queue>  
#include <vector>  
using namespace std;  
//�ص�����Ƶ�ʵĵ���! 
int main(){
	int n;	cin>>n;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=0; i<n; i++){
		char c; cin>>c;
		int f;	cin>>f;
		q.push(f); 
	}
	
	int bt=0;
	while(q.size()>1){
		int tmp=0;
		tmp += q.top(); 	q.pop();
		tmp += q.top();		q.pop();
		q.push(tmp); 
		bt += tmp;
	}
	cout << bt << endl;
	return 0;
} 

  /*
struct HuffmanNode{     //�����������ڵ�  
    char character;  
    int frequency;  
    HuffmanNode *lchild,*rchild;  
    HuffmanNode():character(0),frequency(0),lchild(NULL),rchild(NULL){}  
};  
typedef HuffmanNode *HTNode;  
  
struct cmp{          //�ض�������  ������������������ 
    bool operator()(HuffmanNode *a,HuffmanNode *b)  
    {  
        return a->frequency > b->frequency;  
    }  
};  
int main()  
{  
    int n;  
    priority_queue<HTNode,vector<HTNode>,cmp> pq;    //ʹ��priority_queue���нڵ�洢���ܹ���ʱ����  
    while( cin >> n)  
    {  
        for(int i = 0; i < n; i++)  
        {  
            HTNode tmpNode = new HuffmanNode;       //�Խڵ���д洢  
            cin >> tmpNode->character >> tmpNode->frequency;  
            pq.push(tmpNode);  
        }  
        int BT = 0;  
        while(pq.size()>1)  
        {  
            HTNode tmp1 = new HuffmanNode;  //���Ƶ����С�������ڵ���кϲ�  
            tmp1 = pq.top();  
            pq.pop();  
            HTNode tmp2 = new HuffmanNode;  
            tmp2 = pq.top();  
            pq.pop();  
            HTNode tmp = new HuffmanNode;  
            tmp->frequency = tmp1->frequency +tmp2->frequency;  
            tmp->lchild = tmp1;  
            tmp->rchild = tmp2;  
            BT +=  tmp1->frequency + tmp2->frequency;  
            pq.push(tmp);                 //ÿһ�ζ�priority_queue���в��������Զ���������  
        }  
        cout << BT << endl;  
    }  
    return 0;  
}    /***/  
