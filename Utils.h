#ifndef __UTILS_H
#define __UTILS_H
#include <regex>

using namespace std;

class Utils
{
public:

	bool isExpression(const char * content) const;
	bool isDouble(const char * content) const;
	bool isInt(const char * content) const;
	bool isString(const char * content) const;
	char * getSubstring(char * string, int position, int length) const;
	double calculate(double first, char op, double second) const;
	bool isOperator(char c) const;
	int operatorPosition(char * arr) const;

};
#endif