#include "DoubleCell.h"

DoubleCell::DoubleCell() :Cell()
{
	setType(TYPE_DOUBLE);
	value = 0;
}

DoubleCell::DoubleCell(char * cont) : Cell(cont)
{
	setType(TYPE_DOUBLE);
	setValue();
}

DoubleCell::DoubleCell(const DoubleCell & other) :Cell(other)
{
	this->value = other.getValue();
}

DoubleCell & DoubleCell::operator=(const DoubleCell & other)
{
	Cell::operator=(other);
	if (this != &other)
	{
		this->value = other.getValue();
	}
	return *this;
}

void DoubleCell::setValue()
{
	this->value = atof(getCellContent());
}

double DoubleCell::getValue() const
{
	return this->value;
}
void DoubleCell::printCell() const
{
	cout << value;
}
