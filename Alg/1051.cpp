#include<iostream>
#include<cstdio>
using namespace std;

#define PI 3.1415927//圆周率

int main()
{
	double diameter;
	int revolutions;
	double time;

	for(int i = 1; ; i++)//终止条件是 revolution 为0
	{
		cin >> diameter >> revolutions >> time;
		if(revolutions == 0)	break;
		
		//周长；
		double distance = PI*diameter*revolutions/12/5280;
		//一个小时3600秒
		double hour = time / 3600;
		//速度 = 距离 / 时间
		double speed = distance / hour;

		printf("Trip #%d: %.2f %.2f\n",i,distance,speed);

	}
	return 0;
}
