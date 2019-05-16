#include "Utils.h"
using namespace std;

bool Utils::isExpression(const char * content) const
{
	regex reg("^=(R[1-9][0-9]*C[1-9][0-9]*|[0-9]+)[+*\/^-](R[1-9][0-9]*C[1-9][0-9]*|[0-9]+)");
	if (regex_match(content, reg))
	{
		return true;
	}
	return false;
}

bool Utils::isDouble(const char * content) const
{
	regex reg("^([+-]?[1-9][0-9]*\.[0-9]+|0\.([0-9])+)");
	if (regex_match(content, reg))
	{
		return true;
	}
	return false;

}
bool Utils::isInt(const char * content) const
{
	regex reg("^([+-]?[1-9][0-9]{0,8}[0-7]?|0)");
	if (regex_match(content, reg))
	{
		return true;
	}
	return false;
}
bool Utils::isString(const char * content) const
{
	regex reg("^\".*\"");
	if (regex_match(content, reg))
	{
		return true;
	}
	return false;
}

char * Utils::getSubstring(char * string, int position, int length) const
{
	int c = 0;
	char * substring = new char[length + 1];
	while (c < length)
	{
		substring[c] = string[position + c - 1];
		c++;
	}
	substring[c] = '\0';
	return substring;
}

double Utils::calculate(double first, char op, double second) const
{
	if (op == '+')
	{
		return first + second;
	}
	if (op == '-')
	{
		return first - second;
	}
	if (op == '*')
	{
		return first * second;
	}
	if (op == '/')
	{
		return first / second;
	}
	if (op == '^')
	{
		return pow(first, second);
	}
}
bool Utils::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int Utils::operatorPosition(char * arr) const
{
	for (int i = 0; i < strlen(arr); i++)
	{
		if (isOperator(arr[i]))
		{
			return i;
		}
	}
}