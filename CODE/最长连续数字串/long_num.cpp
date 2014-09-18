//给出一个字符串如“329ab3iej23239ij2ue2328909i7i4ur90ai2u2090”，
//字符串仅由数字和字母组成，输出其中最长的连续数字串。例如本例就是“2328909”


#include<iostream>
#include<vector>
using namespace std;




int main()
{
	string s="329ab3iej23239ij2ue2328909i7i4ur90ai2u2090";
	vector <char> l1;
	char *p = &s[0];
	char *final;
	int num=0;
	while(*p)
	{

		while (*p >= '0' && *p <= '9')
		{
			l1.push_back(*p);
			p++;
		}
		if(l1.size() > num)
		{
			num = l1.size();
			final = new char[num+1];
			for(int i=0;i<num;i++){
				final[i] = l1[i];				
			}
			final[num] = '\0';
			l1.clear();
		}
		p++;
	}
	cout<<final<<endl;

	return 0;
}