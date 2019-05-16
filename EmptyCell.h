#ifndef __EMPTYCELL_H
#define __EMPTYCELL_H
#include "Cell.h"

class EmptyCell :public Cell
{
	int value;

public:
	EmptyCell();
	EmptyCell(const EmptyCell& other);
	EmptyCell & operator=(const EmptyCell & other);

	void setValue();
	virtual double getValue() const;
	virtual void printCell() const;
};

#endif