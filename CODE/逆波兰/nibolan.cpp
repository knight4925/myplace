/*
 * biao.cpp
 *
 *  Created on: 2011-11-25
 *      Author: allenjin
 */
                //---------------// ����ѹջ//---------------//
#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class Stack{   //�Զ����ջ��ʽ������
public:  
	Stack(){Top=0;}
    T top(){return a[Top];}
    void pop(){Top--;}
    bool isempty(){
		if(Top==0)return true;
        else   return false;}
    void push(T b)
    {
        Top++;
        a[Top]=b;
	}
 private:
    T a[100];int Top;
 };

void chpost(char inorder[],char post[],int& m)//����׺���ʽת��Ϊ��׺���ʽ������m���ٺ�׺���ʽ����
{
    int n=strlen(inorder);//��ȡ��׺���ʽ�ĳ���
    Stack<char> czf;//����һ��char�Ͷ�ջ���ڴ�Ų�����;
    for(int i=0;i<n;i++)
     {
           if(inorder[i]>='0'&&inorder[i]<='9')//��Ϊ��������ֱ����ӵ���׺���ʽ������
           {
               post[m]=inorder[i];
                m++;
           }
           if(inorder[i]=='(')	
			   czf.push(inorder[i]);//��Ϊ������ֱ��ѹ���ջ
           if(inorder[i]=='+')//��Ϊ��+����ջ���Ƚ����ȼ����ϵ���ջ���������ӵ������У��ڽ���+��ѹջ
           {
                  if(!czf.isempty()&&(czf.top()=='*'||czf.top()=='/'||czf.top()=='-'))
                      { post[m++]=czf.top();czf.pop();czf.push(inorder[i]);}
                  else{czf.push(inorder[i]);}
           }
           if(inorder[i]=='-')//��Ϊ��-����ջ���Ƚ����ȼ����ϵ���ջ���������ӵ������У�����-��ѹջ
           {
                if(!czf.isempty()&&(czf.top()=='*'||czf.top()=='/'))
                {
                    post[m++]=czf.top();czf.pop();czf.push(inorder[i]);
                }else{czf.push(inorder[i]);}
           }
           if(inorder[i]=='*'||inorder[i]=='/')		czf.push(inorder[i]);//��Ϊ��*����/��ֱ��ѹջ
           if(inorder[i]==')')//��������������ջ�еĲ��������ε���ֱ����������������
           {
               while(czf.top()!='(')
               {post[m++]=czf.top();czf.pop();}
                  czf.pop();//����������
           }
      }
       while(!czf.isempty())//��ջ��ʣ��Ԫ�����ε�������׺���ʽ������
             {post[m++]=czf.top();czf.pop();}
}

int yusuan(char post[],int n)//ͨ����׺���ʽ��ֵ
{
       Stack<int>ss;//����int�Ͷ�ջ��Ų�������ÿ��������
        int a,b,c,result;
	for(int i=0;i<n;i++)
	{
       if(post[i]>='0'&&post[i]<='9')
       {
			ss.push((post[i]-'0'));//��char��תΪint��
       }

       if(post[i]=='-')
       {
			b=ss.top();ss.pop();a=ss.top();ss.pop();
			c=a-b;ss.push(c);
	   }
       if(post[i]=='+')
       {
			b=ss.top();ss.pop();a=ss.top();ss.pop();
			c=a+b;ss.push(c);
       }
       if(post[i]=='*')
       {
			b=ss.top();ss.pop();a=ss.top();ss.pop();
            c=a*b;ss.push(c);
       }
       if(post[i]=='/')
       {
			b=ss.top();ss.pop();a=ss.top();ss.pop();
			c=a/b;ss.push(c);
       }
	}
    result=ss.top();//�õ����ջ��Ԫ��
    ss.pop();//���ջ
    return result;
}
int main(void)
{

     char in[100];char a;int i=0;
     cout<<"��������׺���ʽ��#��ʾ��������";
     while(cin>>a)//ѭ����ȡ����ֱ��������#������
     {
          if(a=='#')break;
          in[i++]=a;
     }
     char po[100];int n=0;
     chpost(in,po,n);
     cout<<"��׺���ʽΪ:";
     for(int j=0;j<n;j++)cout<<po[j]<<"";
     cout<<endl;
     cout<<"������Ϊ:"<<yusuan(po,n)<<endl;
	 
	 return 0;
}