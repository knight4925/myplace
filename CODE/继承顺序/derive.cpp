#include <iostream>
#include <string>
using namespace std;

//
//一、先执行静态成员的构造函数，如果静态成员只是在类定义中声明了，而没有实现，是不用构造的。必须初始化后才执行其构造函数。
//二、? 任何抽象基类的构造函数按照它们被继承的顺序构造（不是初始化列表中的顺序）
//三、? 任何虚拟基类的构造函数按照它们被继承的顺序构造（不是初始化列表中的顺序）
//四、任何非虚拟基类的构造函数按照它们被继承的顺序构造（不是初始化列表中的顺序）
//五、任何成员对象的构造函数按照它们声明的顺序构造
//六、类自己的构造函数
//
//抽象类A
class A
{
public:
	A()
	{
		cout<<"抽象类A的构造函数"<<endl;
	}
	//纯虚函数fun
	virtual void fun1() = 0;
};

//抽象类B
class B
{
public:
	B()
	{
		cout<<"抽象类B的构造函数"<<endl;
	}
	//纯虚函数fun
	virtual void fun2() = 0;
};

//普通类C
class C
{
public:
	C()
	{
		cout<<"类C的构造函数"<<endl;
	}
};

//普通类D
class D
{
public:
	D()
	{
		cout<<"类D的构造函数"<<endl;
	}
};

//普通类E
class E
{
public:
	E()
	{
		cout<<"类E的构造函数"<<endl;
	}
};

//普通类F
class F
{
public:
	F()
	{
		cout<<"类F的构造函数"<<endl;
	}
};

//普通类G
class G
{
public:
	G()
	{
		cout<<"类G的构造函数"<<endl;
	}
};

//普通类H
class H
{
public:
	H()
	{
		cout<<"类H的构造函数"<<endl;
	}
};
//普通类M
class M
{
public:
	M()
	{
		cout<<"类M的构造函数"<<endl;
	}
};

class Test: public A,public B,virtual public C,virtual public D,public E,public F
{
public:
	Test():B(),A(),D(),C(),F(),E()
	{
		cout<<"类Test的构造函数"<<endl;
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

H Test::h;  // 先执行静态成员的构造函数，如果静态成员只是在类定义中声明了，而没有实现，是不用构造的。必须初始化后才执行其构造函数。

int main(int argc, char* argv[])
{
	Test test;
	return EXIT_SUCCESS;
}