/*
		LabWork#204
		实现加减乘除取余运算
		另:
		1.实现连续计算功能,但不考虑运算符优先级
		2.加入格式控制,去掉整数的小数部分和小数末尾的0
		3.允许用户多次输入,直到输入合法为止
		2025.11.13
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>

//格式化函数
static std::string format(double num)
{
	if (num == static_cast<int>(num))
	{
		//整数时去掉小数部分
		return std::to_string(static_cast<int>(num));
	}
	else
	{
		//使用stringstream以便控制小数位数
		std::stringstream ss;
		ss << std::fixed << std::setprecision(8) << num;
		std::string result = ss.str();
		//去掉末尾的0
		while (result.back() == '0')
		{
			result.pop_back();
		}
		//如果最后是小数点,也去掉
		if (result.back() == '.')
		{
			result.pop_back();
		}
		return result;
	}
}

//输入函数
static bool input(double& num)
{
	std::cout << "Please enter a number:";
	if (!(std::cin >> num)) {
		std::cin.clear(); // 清除错误状态
		std::cin.ignore(10000, '\n'); // 忽略错误输入
		std::cout << "Not a number!\n";
		return false;
	}
	return true;
}

//输出函数
static void output(double& num)
{
	std::cout << "result:" << format(num) << "\n";
}

//主函数
int main()
{
	double num1 = 0, num2 = 0;
	char optr = '=';//operator,运算符
	std::cout << "\t\t\t===Sequential Calculator==="
		<< "\n\tOld-fashioned calculator that performs continuous calculations\n"
		<< "\tin the order of input without considering operator precedence.\n\n";

	//开始
	while (!input(num1));
	while (true)
	{
		std::cout << "Please enter an operator (+, -, *, /, % for modulus, = to exit):";
		std::cin >> optr;

		switch (optr)
		{
		case '+':
			while (!input(num2));
			num1 = num1 + num2;
			output(num1);
			break;

		case '-':
			while (!input(num2));
			num1 = num1 - num2;
			output(num1);
			break;

		case '*':
			while (!input(num2));
			num1 = num1 * num2;
			output(num1);
			break;

		case '/':
			while (!input(num2));
			while (num2 == 0)
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Divisor cannot be 0!\n";
				if (!input(num2)) continue;
			}
			num1 = num1 / num2;
			output(num1);
			break;

		case '%':
			if (num1 != static_cast<int>(num1))
			{
				std::cout << "Operands must be integers for modulus operation!\n"
					<< "Your current operand:" << format(num1) << "is not an integer!\n";
				continue;
			}
			while (!input(num2));
			while (static_cast<int>(num2) == 0 || num2 != static_cast<int>(num2))
			{
				if (static_cast<int>(num2) == 0)
				{
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Divisor cannot be 0!\n";
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Operands must be integers for modulus operation!\n";
				}
				if (!input(num2)) continue;
			}
			num1 = static_cast<int>(num1) % static_cast<int>(num2);
			output(num1);
			break;

		case '=':
			std::cout << "\nYour final result:" << format(num1)
				<< "\nThank you!\n";
			return 0;//正常情况只会在此结束

		default:
			std::cout << "Invalid operator!\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	return 0;//这个不会到达,只是为了消除编译器警告
}