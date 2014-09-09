#include <iostream>  
using namespace std;  
  
//���ҵ�һ��ֻ����һ�ε��ַ�����1������  
//copyright@ Sorehead && July  
//July��updated��2011.04.24.  
char find_first_unique_char(char *str)  
{  
    int data[256];  
    char *p;  
      
    if (str == NULL)  
        return '\0';  
	
    memset(data, 0, sizeof(data));    //����Ԫ����ȫ����ʼ��Ϊ0  
    p = str;  
    while (*p != '\0')  
        data[(unsigned char)*p++]++;  //�����ַ���������Ӧλ��++����ͬʱ���±�ǿ��ת����  
	
    while (*str != '\0')  
    {  
        if (data[(unsigned char)*str] == 1)  //�������Ǹ���һ��ֻ���ִ���Ϊ1���ַ�  
            return *str;  
		
        str++;  
    }  
	
    return '\0';  
}  

int main()  
{  
    char *str = "afaccde";  
    cout << find_first_unique_char(str) << endl;  
    return 0;  
}  