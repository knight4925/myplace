#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int Partiton(int p[], int first,int last){

	int pos = first - 1;
	int j = first;
	int par = p[last];
	for(int i  =first ; i < last ; i++){		
		if (par > p[i]){
			pos++;
			swap(p[pos],p[j]);			
		}		
		
		j++;
	}
	swap(p[pos+1],p[last]);

	cout<<"********"<<endl;
	for(int k=first;k<last;k++)
		cout<<p[k]<<" ";
	
	cout<<endl;
	system("pause");

	return pos+1;
}


void QuickSort(int p[], int first,int last)
{
	
	if(first < last){
		int pos = Partiton(p,first,last);
		cout<<"first:"<<first<<",last:"<<last<<", pos:"<<pos<<endl;
		QuickSort(p,first,pos-1);
		QuickSort(p,pos+1,last);
	}		
}

int main(){

	int num[] ={2,5,9,7,8,4,1,3,6}; 
	int len = sizeof(num)/sizeof(int);
	QuickSort(num, 0,len-1);

	for(int i=0;i<len;i++)
		cout<<num[i]<<" ";

	cout<<endl;

	return 0;
}