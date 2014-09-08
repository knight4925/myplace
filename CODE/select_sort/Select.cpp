#include<iostream>
using namespace std;

bool Select_Sort(int p[] , int len){

	int temp,pos;
	int i;
	for(i=0;i<len;i++){
		temp=p[i];
		pos = i;
		for(int j=i;j<len;j++){
			if(temp > p[j]){
				temp = p[j];
				pos = j;				
			}			
		}
		swap(p[i],p[pos]);
	}
    if( i == len )
		return true;
	else 
		return false;
}

void swap(int &a , int &b){
	int t;
	t=a;
	a=b;
	b=t;

}

int main()
{
	int p[]={10,3,8,6,11,15,1,5,9,7,2,4};
	int len = sizeof(p)/sizeof(int);
	Select_Sort(p,len);
	
	for(int i=0;i<len;i++)
		cout<<p[i]<<" ";
	cout<<endl;

	return 0;
}