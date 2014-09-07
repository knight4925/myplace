#include <iostream>
using namespace std;

#define NUM 7
int money[NUM] = {1, 2, 5, 10, 20, 50, 100};

// 母函数解法
int NumOfCoins(int value)
{
	int i , j , k , c1[1010] , c2[1010];
	for(i = 0 ; i <= value ; ++i)
	{
		c1[i] = 1;
		c2[i] = 0;
	}
	//第一层循环是一共有 n 个小括号，而刚才已经算过一个了   
    // i 就是代表的母函数中第几个大括号中的表达式 
	for(i = 1 ; i < NUM ; ++i)
	{
		for(j = 0 ; j <= value ; ++j)   //j 就是指的已经计算出的各项的系数
		{
			for(k = 0 ; k+j <= value ; k += money[i])  //k 就是指将要计算的那个括号中的项
				c2[k+j] += c1[j];
		}
		for(j = 0 ; j <= value ; ++j)  // 刷新一下数据，继续下一次计算，就是下一个括号里面的每一项
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