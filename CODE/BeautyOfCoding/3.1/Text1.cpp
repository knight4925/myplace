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
		if(strstr(src,desc)) // strstr(str1,str2):�ú�������str2��һ����str1�е�λ�ã����û���ҵ�������NULL
		{
//�˲��������������õ�
/*			char src[]="BCDAAB";
			char desc[]="CDAA";
			cout<<strstr(src,desc)<<endl;*/
//�˲��������������õ�
			cout<<"YYY..........TRUE"<<endl;
			return 0;
		}
	}
	cout<<"XXX..........FALSE"<<endl;
	return 0;
}
