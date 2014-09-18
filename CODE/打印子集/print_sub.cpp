//打印子集：假设集合[1,2,3,4]，则其子集为4个有3个元素的子集，6个有2个元素的子集，4个有1个元素的子集。
//给出一个集合，按照元素数目从大到小的方式，打印该集合的子集



//一个集合的所有子集即它的幂集个数为2的n次方个，n为该集合的元素个数。
//每个字符有两种情况，即是否打印，以0或1来表示，这样根据集合中每个元素是否打印，就可以得到一串二进制数，这个二进制数转化成十进制就是0~2N，
//那么我们每次打印一个子集时，只需要进行一次循环，判断该元素对应的那一位的值即可。



//1. 求集合全排列
//说明：给定集合S={a1,a2,a3},则对应的全排列为
//{a1,a2,a3},{a1,a3,a2},{a2,a1,a3},{a2,a3,a1},{a3,a1,a2},{a3,a2,a1}

/*
#include <iostream>
using namespace std;

const int ListLength=3;     //字符串数组的长度

void Swap(char &c, char &s) //交换字符c和s
{
	char temp=c;
	c=s;
	s=temp;
}
//递归是自顶向下逐步拓展需求，最后自下向顶运算。即由f(n)拓展到f(1)，再由f(1)逐步算回f(n)
//迭代是直接自下向顶运算，由f(1)算到f(n)。

void Perm(char *List, int m, int k)    // m为起始位置，第一次调用时为0
{
	static int count=0;
	if(m==k)
	{
		for(int i=0; i<=ListLength-1; i++)
		{
			cout<<List[i];
		}            
		cout<<endl;
	}
	else
	{
		for(int i=m; i<=k; i++)
		{
			Swap(List[m],List[i]);
			Perm(List, m+1, k);     // 迭代
			Swap(List[m],List[i]);               
		}        
	}      
}

int main()
{
    char List[ListLength]={'a','b','c'};
    Perm(List, 0, ListLength-1);
    system("pause");
    return 0; 
}
*/

#include <iostream>
using namespace std;

template<typename T>
void print(T * array, unsigned int count, unsigned int index)
{
	unsigned int mask =1;
	unsigned int pos;
	for(pos=0; pos < count; pos ++)
	{
		if(mask & index) cout << array[pos]<<",";
		mask <<= 1;
	}
}

void PrintSet()
{
	int set[]={1, 3, 9, 27,81};//5个元素的集合   5个元素，对应5位，最大为
	for(unsigned int index=0; index < 32; index++)
	{
		cout<< "subset " << index<< " is {" << flush;
		print(set, 5, index);
		cout <<"}"<< endl;
	}
}

int main()
{
	PrintSet();

	return 0;
}