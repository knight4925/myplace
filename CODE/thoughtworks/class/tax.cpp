#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;


class Sales_List{
	map<string, double> rate_index;
	vector<string> input;
	vector<string> output;
	vector<string> money;
	vector<string> object;
	vector<double> rate;
	double final_money;
	double final_rate;
	
public:
	Sales_List();
   	void read_input();
	void print_output();
	void calculate_rate();
	void calculate_money();
};


Sales_List::Sales_List()
{
	rate_index.insert(make_pair(string("book"), 0.0));
	rate_index.insert(make_pair(string("food"), 0.0));
	rate_index.insert(make_pair(string("medical"), 0.0));
	rate_index.insert(make_pair(string("other"), 0.1));
}

void Sales_List :: read_input(){      //读入购物单
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
	ifstream in("input2.txt");
	char line[1024];
	while (in.getline(line, sizeof(line)))
	{
		input.push_back(line);
	}
}

void Sales_List :: print_output(){  //输出价格单

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



void Sales_List::calculate_rate(){   //计算每条税率

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

void Sales_List::calculate_money(){     //计算价格
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

		money_initial += money_temp;

		money_temp += money_temp*rate[i];
		money_temp=rounding(money_temp);

		number_pos = input[i].find(" ");
		int number = atoi(input[i].substr(0,number_pos).c_str());

		money_temp=number*money_temp;

		stringstream ss;
		ss<<money_temp;
		ss>>money_str;
		money.push_back(money_str);	
		final_money += money_temp;
	}

	final_rate = final_money-money_initial;
}


int main()
{
	// 输入的第一个空格前为数量，第一个空格后为是否进口
	// at 后的空格后为价格

	Sales_List My_list;
	My_list.read_input();
	My_list.calculate_rate();
	My_list.calculate_money();
	My_list.print_output();

	return 0;
}