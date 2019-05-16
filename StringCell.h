#ifndef __STRINGCELL_H
#define __STRINGCELL_H
#include "Cell.h"

class StringCell :public Cell
{
	double value;
	char * printValue;

public:
	StringCell(); //copy,=
	StringCell(char * cont);
	StringCell(const StringCell& other);
	StringCell & operator=(const StringCell & other);
	~StringCell();

	void setValue();
	void setPrintValue();
	char * getPrintValue();
	virtual double getValue() const;

	virtual void printCell() const;
};

#endif
