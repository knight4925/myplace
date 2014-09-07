#include<iostream>
using namespace std;

int main()
{
	char src[]="AABBCD";
	char desc[]="CDAA";

	int len=strlen(src);
	for(int i=0; i<len;i++)
	{
		char tempchar=src[0];
		for(int j=0;j<len-1;j++)
		{
			src[j]=src[j+1];
		}
		src[len-1]=tempchar;
		if(strstr(src,desc)) // strstr(str1,str2):该函数返回str2第一次在str1中的位置，如果没有找到，返回NULL
		{
//此部分用来做测试用的
/*			char src[]="BCDAAB";
			char desc[]="CDAA";
			cout<<strstr(src,desc)<<endl;*/
//此部分用来做测试用的
			cout<<"YYY..........TRUE"<<endl;
			return 0;
		}
	}
	cout<<"XXX..........FALSE"<<endl;
	return 0;
}
