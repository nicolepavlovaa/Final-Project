#ifndef __DOUBLE_CELL
#define __DOUBLE_CELL
#include "Cell.h"

class DoubleCell : public Cell
{
	double value;
	
public:
	DoubleCell();
	DoubleCell(const DoubleCell& other);
	DoubleCell & operator=(const DoubleCell & other);
	DoubleCell(char * cont);

	void setValue();
	virtual double getValue() const; 
	virtual void printCell() const;
};
#endif
