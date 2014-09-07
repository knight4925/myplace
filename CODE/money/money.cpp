#include <iostream>
using namespace std;

#define NUM 7
int money[NUM] = {1, 2, 5, 10, 20, 50, 100};

// ĸ�����ⷨ
int NumOfCoins(int value)
{
	int i , j , k , c1[1010] , c2[1010];
	for(i = 0 ; i <= value ; ++i)
	{
		c1[i] = 1;
		c2[i] = 0;
	}
	//��һ��ѭ����һ���� n ��С���ţ����ղ��Ѿ����һ����   
    // i ���Ǵ����ĸ�����еڼ����������еı��ʽ 
	for(i = 1 ; i < NUM ; ++i)
	{
		for(j = 0 ; j <= value ; ++j)   //j ����ָ���Ѿ�������ĸ����ϵ��
		{
			for(k = 0 ; k+j <= value ; k += money[i])  //k ����ָ��Ҫ������Ǹ������е���
				c2[k+j] += c1[j];
		}
		for(j = 0 ; j <= value ; ++j)  // ˢ��һ�����ݣ�������һ�μ��㣬������һ�����������ÿһ��
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	return c1[value];
}

int main()
{
	NumOfCoins(1000000);
	return 0;
}