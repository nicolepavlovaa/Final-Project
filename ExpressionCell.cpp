#include "ExpressionCell.h"
#include "Table.h"

ExpressionCell::ExpressionCell() :Cell()
{
	this->value = 0;
	expressionValid = false;
}
ExpressionCell::ExpressionCell(Table& t, char * cont) :Cell(cont)
{
	setType(TYPE_EXPRESSION);
	setValue(calculateValueOfExpression(t, cont));
	if (divisionByZero(t, cont) == false) expressionValid = true;
	else expressionValid = false;
}

ExpressionCell::ExpressionCell(const ExpressionCell & other) :Cell(other)
{
	this->value = other.getValue();
	expressionValid = other.getExpressionValidity();
}

ExpressionCell & ExpressionCell::operator=(const ExpressionCell & other)
{
	Cell::operator=(other);
	if (this != &other)
	{
		this->value = other.getValue();
		expressionValid = other.getExpressionValidity();
	}
	return *this;
}

void ExpressionCell::setValue(double val)
{
	this->value = val;
}
double ExpressionCell::getValue() const
{
	return this->value;
}
bool ExpressionCell::getExpressionValidity() const
{
	return expressionValid;
}
double ExpressionCell::calculateValueOfExpression(Table& t, char * expr) const
{
	char op = expr[Utils().operatorPosition(expr)];
	double fArg = getfirstArg(t, expr);
	double sArg = getsecondArg(t, expr);
	double result = 0;
	if (op == '/' && sArg == 0)
	{
		result = 0;
	}
	else result = Utils().calculate(fArg, op, sArg);
	return result;
}
double ExpressionCell::getfirstArg(Table& t, char * expr) const
{
	char * first = Utils().getSubstring(expr, 2, Utils().operatorPosition(expr) - 1);
	double fArg = 0;

	if (Utils().isDouble(first) || Utils().isInt(first))
	{
		fArg = atof(first);
	}
	else fArg = cellCodeToValue(t, first);
	delete[] first;
	return fArg;
}
double ExpressionCell::getsecondArg(Table& t,char * expr) const
{
	char * first = Utils().getSubstring(expr, 2, Utils().operatorPosition(expr) - 1);
	char * second = Utils().getSubstring(expr, Utils().operatorPosition(expr) + 2, strlen(expr) - strlen(first) - 1);
	double sArg = 0;
	if (Utils().isDouble(second) || Utils().isInt(second))
	{
		sArg = atof(second);
	}
	else sArg = cellCodeToValue(t, second);
	delete[] first;
	delete[] second;
	return sArg;
}
double ExpressionCell::cellCodeToValue(Table& t, char * code) const
{
	int cellRow=0, cellCol=0, sum=0, counter = 0;
	for (int i = 0; i < strlen(code); i++)
	{
		if (code[i] >= '0' && code[i] <= '9')
		{
			sum = sum * pow(10, counter) + (code[i] - '0');
			counter++;
		}
		if (code[i] == 'C')
		{
			cellRow = sum;
			counter = 0;
			sum = 0;
		}
		if (i == strlen(code) - 1)
		{
			cellCol = sum;
		}
	}

	double val;
	if (cellRow > t.getSize() || cellCol > t.getLongestRowLength())
	{
		val = 0;
	}
	else val = t.getCellValue(cellRow, cellCol);
	return val;
}
bool ExpressionCell::divisionByZero(Table& t, char * cont) const
{
	if (getCellContent()[Utils().operatorPosition(getCellContent())] == '/' && getsecondArg(t, getCellContent()) == 0)
	{
		return true;
	}
	return false;
}
void ExpressionCell::printCell() const
{
	if (getExpressionValidity() == true)
	{
		cout << value;
	}
	else cout << "ERROR";
}