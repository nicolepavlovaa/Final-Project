#include "IntegerCell.h"


IntegerCell::IntegerCell() :Cell()
{
	setType(TYPE_INT);
	this->value = 0;
}
IntegerCell::IntegerCell(char * c) :Cell(c)
{
	setType(TYPE_INT);
	setValue();
}
IntegerCell::IntegerCell(const IntegerCell & other) :Cell(other)
{
	this->value = other.getValue();
}
IntegerCell & IntegerCell::operator=(const IntegerCell & other)
{
	Cell::operator=(other);
	if (this != &other)
	{
		this->value = other.getValue();
	}
	return *this;
}
void IntegerCell::setValue()
{
	this->value = atoi(getCellContent());
}
double IntegerCell::getValue() const
{
	return (double)this->value;
}
void IntegerCell::printCell() const
{
	cout << value;
}
