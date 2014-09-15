#include<iostream>
using namespace std;

int mystrlen(char * c){
	if(*c == '\0'){
		return 0;
	}
	return mystrlen(++c)+1;
}

void test(char c[10]){
	cout<<sizeof(c)<<endl;
}

int main()
{

//	char *s = "abcdefg";
// 	char c[10]={'a','b','c','d','e','f'};
// 	cout<<strlen(s)<<endl;
// 	cout<<sizeof(s)<<endl;
	char c[10];
	test(c);
//	cout<<sizeof(c)<<endl;
// 	cout<<strlen(c)<<endl;

//	cout<<mystrlen(s)<<endl;


	return 0;

}