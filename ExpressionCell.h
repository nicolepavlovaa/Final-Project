#ifndef __EXPRESSIONCELL_H
#define __EXPRESSIONCELL_H
#include "Cell.h"
using namespace std;

class Table;

class ExpressionCell : public Cell
{
	double value;
	bool expressionValid;

	double cellCodeToValue(Table& t, char * code) const;
	double getfirstArg(Table& t, char * expr) const;
	double getsecondArg(Table& t, char * expr) const;
	bool divisionByZero(Table& t, char * cont) const;

public:
	ExpressionCell();
	ExpressionCell(Table& t, char * cont);
	ExpressionCell(const ExpressionCell& other);
	ExpressionCell & operator=(const ExpressionCell & other);

	void setValue(double val);
	virtual double getValue() const;
	bool getExpressionValidity() const;
	double calculateValueOfExpression(Table& t, char * expr) const;
	
	virtual void printCell() const;
};

#endif