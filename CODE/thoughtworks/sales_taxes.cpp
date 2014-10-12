

// һ����Ʒ��˰Ϊ10 %
// �飬ʳ���ҩƷ������˰��
// ���ڵ�һ����Ʒ����˰15%
// ���ڵ�ʳ���˰Ϊ5%
// ���궫�����˵�������Ʒ�ͻ��ѣ�����˰���ܵĻ��� �� �ܵ�˰
// С�������λ�����һλ�� 0 �� ���ڵ��� 5 ����

// CD: 16.49=14.99*(10% + 1)

//ÿ���޶���������ַ�����

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;


void read_input(vector<string> & input){      //���빺�ﵥ
	
	string str;
// 	while (1)
// 	{
// 		getline(cin,str);
// 		if(str == "EOF")
// 		{
// 			break;
// 		}
// 		input.push_back(str);
// 	}
	ifstream in("input3.txt");
	char line[1024];
	while (in.getline(line, sizeof(line)))
	{
		input.push_back(line);
	}
}

void print_output(vector<string> object,vector<string> & output,vector<string> money,double final_money, double final_rate){  //����۸�

	size_t i;
	for(i=0;i<object.size();i++){
		output.push_back(object[i]+":"+money[i]);
	}

	for(i=0;i<output.size();i++){
		cout<<output[i]<<endl;
	}
	cout<<"Sales Taxes:"<<setiosflags(ios::fixed)<<setprecision(2)<<final_rate<<endl;
	cout<<"Total:"<<setiosflags(ios::fixed)<<setprecision(2)<<final_money<<endl;
}

void calculate_rate(vector<string> & input,vector<double> & rate,vector<string> & object){

	map<string, double> rate_index;
	rate_index.insert(make_pair(string("book"), 0.0));
	rate_index.insert(make_pair(string("food"), 0.0));
	rate_index.insert(make_pair(string("medical"), 0.0));
	rate_index.insert(make_pair(string("other"), 0.1));
	size_t i;
	for(i=0;i<input.size();i++){
		
		int pos;
		int at;

		at = input[i].find(" at");
		object.push_back(input[i].substr(0,at));

		pos = input[i].find("book");
		if (pos < input[i].size()){
			rate.push_back(rate_index["book"]);
			continue;
		}
		pos = input[i].find("chocolate");
		if (pos < input[i].size()){
			rate.push_back(rate_index["food"]);
			continue;
		}
		pos = input[i].find("pill");
		if (pos < input[i].size()){
			rate.push_back(rate_index["medical"]);
			continue;
		}
		rate.push_back(rate_index["other"]);
	}

	for(i=0;i<input.size();i++){
		int pos = input[i].find("imported");
		if (pos < input[i].size()){
			rate[i] += 0.05;
		}
	}
// 	for (i=0;i<rate.size();i++)
// 	{
// 		cout<<rate[i]<<endl;
// 		cout<<object[i]<<endl;
// 	}

}

double rounding(double number)
{
	int number_temp=int(number*100+0.5);
	if (number_temp%10 != 0)
	{
		number_temp = (number_temp%10)>5 ? number_temp: (number_temp/10)*10+5;
	}
	number=number_temp/100.0; 

	return number;
}

void calculate_money(vector<string> & input,vector<double> & rate,vector<string> &money,double & final_rate,double & final_money){
	size_t i;
	double money_temp;
	double money_initial=0.0;
	string money_str;
	int pos;
	int at;
	int number_pos;
	int number;
	final_money =0.0;

	for(i=0;i<input.size();i++){
			
		at = input[i].find(" at");

		money_temp = atof(input[i].substr(at+4,input[i].size()-at-4).c_str());
//		cout<<money_temp<<"--->";

		money_initial += money_temp;

		money_temp += money_temp*rate[i];
//		cout<<money_temp<<"--->";
		money_temp=rounding(money_temp);
//		cout<<money_temp<<endl;

		number_pos = input[i].find(" ");
		int number = atoi(input[i].substr(0,number_pos).c_str());

		money_temp=number*money_temp;

		stringstream ss;
		ss<<money_temp;
		ss>>money_str;
		money.push_back(money_str);	
		final_money += money_temp;
	}

	money_initial = (int)(money_initial*100)/100.0;
	final_money = (int)(final_money*100)/100.0;
	final_rate = final_money-money_initial;

//	cout<<final_rate<<"  "<<final_money<<endl;
}


int main()
{
	// ����ĵ�һ���ո�ǰΪ��������һ���ո��Ϊ�Ƿ����
	// at ��Ŀո��Ϊ�۸�
	vector<string> input;		
	read_input(input);

	vector<double> rate;
	vector<string> object;	
	calculate_rate(input,rate,object);


	vector<string> money;
	double final_rate;
	double final_money;
	calculate_money(input,rate,money,final_rate,final_money);


	vector<string> output;

	print_output(object,output,money,final_money,final_rate);


	return 0;
}