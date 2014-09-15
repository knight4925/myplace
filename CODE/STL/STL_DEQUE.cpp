#include <iostream>
#include <deque>
using namespace std;

void put_deque(deque<int> Mydeque,char *name){
	deque<int>::iterator pdeque;
	cout<<"the contents of "<<name<<" : ";
	for(pdeque=Mydeque.begin();pdeque!=Mydeque.end(); pdeque++){
		cout<<*pdeque<<" ";
	}
	cout<<endl;
}

int main(){
	deque<int> deq1;       //����˫�˶���deq1�����ʼΪ��
	deque<int> deq2(10,6); //deq2���������10��ֵΪ6��Ԫ��
	deque<int>::iterator i;
	put_deque(deq1,"deq1");
	put_deque(deq2,"deq2");
	deq1.push_back(2);
	deq1.push_back(4);
	cout<<"deq1.push_back(2) and deq1.push_back(4): "<<endl;
	put_deque(deq1,"deq1");
	deq1.push_front(5);
	deq1.push_front(7);
	cout<<"deq1.push_front(5) and deq1.push_front(7): "<<endl;
	put_deque(deq1,"deq1");
	deq1.insert(deq1.begin()+1,3,9); //�ڶ���λ�ò���3��9��Ԫ����Ӧ����
	cout<<"deq1.insert(deq1.begin()+1,3,9): "<<endl;
	put_deque(deq1,"deq1");
	cout<<"dep1.at(4)="<<deq1.at(4)<<endl; //���������ຯ��
	cout<<"dep1[4]="<<deq1[4]<<endl;  //�±��0��ʼ
	deq1.at(1)=10;
	deq1[2]=12;
	cout<<"deq1.at(1)=10 and deq1[2]=12 :"<<endl;
	put_deque(deq1,"deq1");
	deq1.pop_front();
	deq1.pop_back();
	cout<<"deq1.pop_front() and deq1.pop_back(): "<<endl;
	put_deque(deq1,"deq1");
	deq1.erase(deq1.begin()+1);      //���deq1�еĵ�2��Ԫ��
	cout<<"deq1.erase(deq1.begin()+1) :"<<endl;
	put_deque(deq1,"deq1");
	deq2.assign(8,1);      //��deq2��ֵ����ʾ�����8��1
	cout<<"deq2.assign(8,1): "<<endl;  
	put_deque(deq2,"deq2");

	return 0;
}