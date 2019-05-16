#include "EmptyCell.h"

void EmptyCell::setValue()
{
	this->value = 0;
}

double EmptyCell::getValue() const
{
	return (double)this->value;
}

EmptyCell::EmptyCell() :Cell()
{
	setValue();
}
EmptyCell::EmptyCell(const EmptyCell & other) :Cell(other)
{
	this->value = other.getValue();
}
EmptyCell & EmptyCell::operator=(const EmptyCell & other)
{
	Cell::operator=(other);
	if (this != &other)
	{
		this->value = other.getValue();
	}
	return *this;
}
void EmptyCell::printCell() const
{
	cout << " ";
}