/*
		LabWork#201
		输入一个字符,如果为小写,转换为大写输出,否则,输出其后继字符的ASCII码值.
		2020.11.13
*/
#include<iostream>
#include<string>

int main()
{
	std::string ipt;
	std::cout << "Awaiting input (1 single character)\n";
	getline(std::cin, ipt);
	//检查是否为单个字符
	if (ipt.length() != 1)
	{
		std::cout << "Not a single character!";
		return -1;
	}
	//取第一个
	char fst = ipt[0];
	if (fst >= 'a' && fst <= 'z')
	{
		char cap = fst - 32;
		std::cout << cap;
	}
	else
	{
		int nxt = fst + 1;
		std::cout << nxt;
	}
	return 0;
}