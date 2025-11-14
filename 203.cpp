/*
		LabWork#203
		求三角形周长,并判断该三角形是否为等腰三角形.
		另:
			1.加入了输入合法性检查.
			2.使用vector存储边长和边名.
		2020.11.13
*/
#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<double> sides(3);
	std::vector<std::string> side_names = { "a", "b", "c" };
	std::cout << "Awaiting input\n";
	//输入三边长
	for (int i = 0; i < 3; ++i)
	{
		std::cout << side_names[i] << "=";
		if (!(std::cin >> sides[i]))//判断输入合法性
		{
			std::cout << "Not a number.";
			return -2;
		}
		if (sides[i] <= 0)//同上
		{
			std::cout << "Negative number cannot be a length.";
			return -3;
		}
	}
	//将边长赋值给变量a,b,c
	double a = sides[0], b = sides[1], c = sides[2];
	//判断能否构成三角形
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		std::cout << "Inputted lengths cannot form a triangle.";
		return -1;
	}
	//计算周长
	std::cout << "Perimeter of the triangle is " << a + b + c;
	//判断是否等腰
	if (a == b || a == c || b == c)
	{
		std::cout << "\nThe triangle is an isosceles triangle.";
	}
	else
	{
		std::cout << "\nThe triangle is NOT an isosceles triangle.";
	}
	return 0;
