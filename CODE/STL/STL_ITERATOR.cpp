#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<string> v1;
	ifstream file("test.txt");
	if(file.fail()){
		cout<<"open file text.txt failed"<<endl;
		return 1;
	}
	copy(istream_iterator<string>(file),istream_iterator<string>(),inserter(v1,v1.begin()));   //输入迭代器   //把值复制到迭代器，依次为开始，结束，向量 
	                                                                                           //insertor是一个输入迭代器的函数（迭代器适配器）
	copy(v1.begin(),v1.end(),ostream_iterator<string>(cout," "));  //输出迭代器   //把值复制到输出流，依次为开始，结束，输出流
	cout<<endl;

	return 0;
}