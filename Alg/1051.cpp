#include<iostream>
#include<cstdio>
using namespace std;

#define PI 3.1415927//Բ����

int main()
{
	double diameter;
	int revolutions;
	double time;

	for(int i = 1; ; i++)//��ֹ������ revolution Ϊ0
	{
		cin >> diameter >> revolutions >> time;
		if(revolutions == 0)	break;
		
		//�ܳ���
		double distance = PI*diameter*revolutions/12/5280;
		//һ��Сʱ3600��
		double hour = time / 3600;
		//�ٶ� = ���� / ʱ��
		double speed = distance / hour;

		printf("Trip #%d: %.2f %.2f\n",i,distance,speed);

	}
	return 0;
}
