#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a[205][205], e[205];
/*
a ����ֱ�ӱ�ʾ�������� ��ϵ3������
���Ǽ�¼�� ��ȥ������㣬���������صݹ飻 
*/
int dp(int i, int j){
	if(a[i][j]!=-1){
		return a[i][j];//��¼�� 
	}else if(i==j){
		return a[i][j]=0;
	}
	
	int ans=0;
	/*
	�˴�����ʹ���˵ݹ飬��ʽ�϶��ѣ�
	=>�ݹ黹�ǻὫ����˼·��ϸ���ķ���չ����ͬ�ڵ��ƣ� 
	״̬ת�Ʒ��̻��Ƿǳ�������
	��һ��״̬��֮ǰ�����ɸ�״̬֮���н�����ϵ��
	��
	�ݹ��ʹ��Ҳ��û���˷�̫�����Դ��
	���ں���ؼ�¼�Ӷ�û���ظ����㣻*/ 
	for(int k=i; k<j; k++){
		ans=max(ans, dp(i,k)+dp(k+1,j)+e[i]*e[j+1]*e[k+1]);
	}
	return a[i][j]=ans;
}

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		memset(a, -1, sizeof(a));
		for(int i=0; i<N; i++){
			int tmp;
			scanf("%d",&tmp);
			e[i]=e[i+N]=tmp;
		}
		int v=0;
		for(int i=0; i<N; i++){
			v=max(v, dp(i, i+N-1));
		}
		printf("%d\n",v);
	}
	return 0;
} 
