//��ӡ�Ӽ������輯��[1,2,3,4]�������Ӽ�Ϊ4����3��Ԫ�ص��Ӽ���6����2��Ԫ�ص��Ӽ���4����1��Ԫ�ص��Ӽ���
//����һ�����ϣ�����Ԫ����Ŀ�Ӵ�С�ķ�ʽ����ӡ�ü��ϵ��Ӽ�



//һ�����ϵ������Ӽ��������ݼ�����Ϊ2��n�η�����nΪ�ü��ϵ�Ԫ�ظ�����
//ÿ���ַ���������������Ƿ��ӡ����0��1����ʾ���������ݼ�����ÿ��Ԫ���Ƿ��ӡ���Ϳ��Եõ�һ�����������������������ת����ʮ���ƾ���0~2N��
//��ô����ÿ�δ�ӡһ���Ӽ�ʱ��ֻ��Ҫ����һ��ѭ�����жϸ�Ԫ�ض�Ӧ����һλ��ֵ���ɡ�



//1. �󼯺�ȫ����
//˵������������S={a1,a2,a3},���Ӧ��ȫ����Ϊ
//{a1,a2,a3},{a1,a3,a2},{a2,a1,a3},{a2,a3,a1},{a3,a1,a2},{a3,a2,a1}

/*
#include <iostream>
using namespace std;

const int ListLength=3;     //�ַ�������ĳ���

void Swap(char &c, char &s) //�����ַ�c��s
{
	char temp=c;
	c=s;
	s=temp;
}
//�ݹ����Զ���������չ����������������㡣����f(n)��չ��f(1)������f(1)�����f(n)
//������ֱ�����������㣬��f(1)�㵽f(n)��

void Perm(char *List, int m, int k)    // mΪ��ʼλ�ã���һ�ε���ʱΪ0
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
			Perm(List, m+1, k);     // ����
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
	int set[]={1, 3, 9, 27,81};//5��Ԫ�صļ���   5��Ԫ�أ���Ӧ5λ�����Ϊ
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