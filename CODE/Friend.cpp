#include<iostream>
#include<string>
using namespace std;

class boy;

//��һ����ĳ�Ա������Ϊ��һ�������Ԫ����ʱ�������ȶ����Ա�������ڵ��ࡣ���⣬����������һ��Ҫ����һ����girl�Ķ���ֻ������������ͨ��������������Ԫ������

class girl{
	char *name;
	int age;
public:
	girl(char* n,int a){
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
	}
	void prt(boy &);                  //�������г�Ա����, ��ν����Ԫ��Ա���˺��������ɷ���girl�е�˽�кͱ�����Ա��Ҳ�ɷ���boy�е�˽�кͱ�����Ա
	~girl(){
		delete name;
	}
};

class boy{
	char *name;
	int age;
	friend girl;                     //������Ԫ�࣬�������Ԫ�����ɲ�����

public:
	boy(char* n,int a){
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
	}
//	friend void girl::prt(boy &);    //������Ԫ����
	~boy(){
		delete name;
	}
};

void girl::prt(boy &b){
	cout<<"girl \'s name: "<<name<<"  age:"<<age<<"\n";   //��Ϊ�ǳ�Ա�������ʿ�ֱ�ӷ���
	cout<<"boy \'s name: "<<b.name<<" age:"<<b.age<<"\n"; //�˴�����ֱ�ӷ��ʡ�����Ԫ����������ͨ����������
}

int main(){
	girl g("Stacy",15);
	boy b1("Jim",16);
	g.prt(b1); //prt��girl�ĳ�Ա�������ʰ��˷�������
	           //��Ԫ��������ֱ�ӵ��ã�����ͨ������

	return 0;
}

