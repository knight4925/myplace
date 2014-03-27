#include<iostream>
#include<map>
using namespace std;

int main(){
	map<char,int,greater<char> > map1; //定义变量
	map<char,int,greater<char> >::iterator mapIter;  //char是键的类型，int是值的类型  //从大到小排：greater<char>，一路画大于号。从小到大排：less<char>,一路画小于。

//	map1['c']=3;//初始化，与数组类似也可以用map1.insert(map<char,int,less<char> >::value_type('c',3));
	map1.insert(map<char,int,less<char> >::value_type('c',3));   //空格是必须要有的
	map1['d']=4;
	map1['a']=1;
	map1['b']=2;
	for(mapIter=map1.begin();mapIter!=map1.end();++mapIter)
		cout<<" "<<(*mapIter).first<<": "<<(*mapIter).second; //first对应定义中的char键，second对应定义中的int值
	cout<<endl;
	map<char,int,greater<char> >::const_iterator ptr;
	ptr=map1.find('d');                            //检索对应于d键的值
	cout<<" "<<(*ptr).first<<"键对应于值： "<<(*ptr).second<<endl;

	return 0;

}