#include <iostream>
#include <string>
using namespace std;

//
//һ����ִ�о�̬��Ա�Ĺ��캯���������̬��Աֻ�����ඨ���������ˣ���û��ʵ�֣��ǲ��ù���ġ������ʼ�����ִ���乹�캯����
//����? �κγ������Ĺ��캯���������Ǳ��̳е�˳���죨���ǳ�ʼ���б��е�˳��
//����? �κ��������Ĺ��캯���������Ǳ��̳е�˳���죨���ǳ�ʼ���б��е�˳��
//�ġ��κη��������Ĺ��캯���������Ǳ��̳е�˳���죨���ǳ�ʼ���б��е�˳��
//�塢�κγ�Ա����Ĺ��캯����������������˳����
//�������Լ��Ĺ��캯��
//
//������A
class A
{
public:
	A()
	{
		cout<<"������A�Ĺ��캯��"<<endl;
	}
	//���麯��fun
	virtual void fun1() = 0;
};

//������B
class B
{
public:
	B()
	{
		cout<<"������B�Ĺ��캯��"<<endl;
	}
	//���麯��fun
	virtual void fun2() = 0;
};

//��ͨ��C
class C
{
public:
	C()
	{
		cout<<"��C�Ĺ��캯��"<<endl;
	}
};

//��ͨ��D
class D
{
public:
	D()
	{
		cout<<"��D�Ĺ��캯��"<<endl;
	}
};

//��ͨ��E
class E
{
public:
	E()
	{
		cout<<"��E�Ĺ��캯��"<<endl;
	}
};

//��ͨ��F
class F
{
public:
	F()
	{
		cout<<"��F�Ĺ��캯��"<<endl;
	}
};

//��ͨ��G
class G
{
public:
	G()
	{
		cout<<"��G�Ĺ��캯��"<<endl;
	}
};

//��ͨ��H
class H
{
public:
	H()
	{
		cout<<"��H�Ĺ��캯��"<<endl;
	}
};
//��ͨ��M
class M
{
public:
	M()
	{
		cout<<"��M�Ĺ��캯��"<<endl;
	}
};

class Test: public A,public B,virtual public C,virtual public D,public E,public F
{
public:
	Test():B(),A(),D(),C(),F(),E()
	{
		cout<<"��Test�Ĺ��캯��"<<endl;
	}
	void fun1()
	{
	}
	void fun2()
	{
	}
private:
	G g;
	static H h;
	static M m;
};

H Test::h;  // ��ִ�о�̬��Ա�Ĺ��캯���������̬��Աֻ�����ඨ���������ˣ���û��ʵ�֣��ǲ��ù���ġ������ʼ�����ִ���乹�캯����

int main(int argc, char* argv[])
{
	Test test;
	return EXIT_SUCCESS;
}