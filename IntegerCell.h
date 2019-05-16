#ifndef __INTEGERCELL_H
#define __INTEGERCELL_H
#include "Cell.h"

class IntegerCell :public Cell
{
	int value;

public:
	IntegerCell();
	IntegerCell(char * c);
	IntegerCell(const IntegerCell& other);
	IntegerCell & operator=(const IntegerCell & other);

	void setValue();
	virtual double getValue() const;

	virtual void printCell() const;
};

#endif