#include<iostream>
#include<map>
using namespace std;

int main(){
	map<char,int,greater<char> > map1; //�������
	map<char,int,greater<char> >::iterator mapIter;  //char�Ǽ������ͣ�int��ֵ������  //�Ӵ�С�ţ�greater<char>��һ·�����ںš���С�����ţ�less<char>,һ·��С�ڡ�

//	map1['c']=3;//��ʼ��������������Ҳ������map1.insert(map<char,int,less<char> >::value_type('c',3));
	map1.insert(map<char,int,less<char> >::value_type('c',3));   //�ո��Ǳ���Ҫ�е�
	map1['d']=4;
	map1['a']=1;
	map1['b']=2;
	for(mapIter=map1.begin();mapIter!=map1.end();++mapIter)
		cout<<" "<<(*mapIter).first<<": "<<(*mapIter).second; //first��Ӧ�����е�char����second��Ӧ�����е�intֵ
	cout<<endl;
	map<char,int,greater<char> >::const_iterator ptr;
	ptr=map1.find('d');                            //������Ӧ��d����ֵ
	cout<<" "<<(*ptr).first<<"����Ӧ��ֵ�� "<<(*ptr).second<<endl;

	return 0;

}