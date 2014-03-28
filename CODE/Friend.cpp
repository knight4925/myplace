#include<iostream>
#include<string>
using namespace std;

class boy;

class girl{
	char *name;
	int age;
public:
	girl(char* n,int a){
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
	}
	void prt(boy &);                  //声明公有成员函数, 所谓的友元成员。此函数不仅可访问girl中的私有和保护成员，也可访问boy中的私有和保护成员
	~girl(){
		delete name;
	}
};

class boy{
	char *name;
	int age;
public:
	boy(char* n,int a){
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
	}
	friend void girl::prt(boy &);    //声明友元函数
	~boy(){
		delete name;
	}
};

void girl::prt(boy &b){
	cout<<"girl \'s name: "<<name<<"  age:"<<age<<"\n";   //因为是成员函数，故可直接访问
	cout<<"boy \'s name: "<<b.name<<" age:"<<b.age<<"\n"; //此处不可直接访问。是友元函数，必须通过对象引用
}

int main(){
	girl g("Stacy",15);
	boy b1("Jim",16);
	g.prt(b1); //prt是girl的成员函数，故按此方法调用
	           //友元函数可以直接调用，不用通过对象

	return 0;
}

