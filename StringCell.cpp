#include "StringCell.h"

StringCell::StringCell() :Cell()
{
	value = 0;
}

StringCell::StringCell(char * cont) :Cell(cont)
{
	setType(TYPE_STRING);
	setValue();
}
StringCell::StringCell(const StringCell & other) :Cell(other)
{
	this->value = other.getValue();
	setPrintValue();
}
StringCell & StringCell::operator=(const StringCell & other)
{
	Cell::operator=(other);
	if (this != &other)
	{
		this->value = other.getValue();
		setPrintValue();
	}
	return *this;
}

void StringCell::setValue()
{
	setPrintValue();
	regex reg1("^([+-]?[1-9][0-9]*\.[0-9]+|0\.([0-9])+)");
	regex reg2("^([+-]?[1-9][0-9]{0,8}[0-7]?|0)");
	if (regex_match(printValue, reg1))
	{
		this->value = atof(printValue);
	}
	else if (regex_match(printValue, reg2))
	{
		this->value = atoi(printValue);
	}
	else this->value = 0;
}

double StringCell::getValue() const
{
	return this->value;
}
void StringCell::setPrintValue()
{
	this->printValue = Utils().getSubstring(getCellContent(), 2, strlen(getCellContent()) - 2);
}

char * StringCell::getPrintValue()
{
	return this->printValue;
}

void StringCell::printCell() const
{
	cout << printValue;
}
StringCell::~StringCell()
{
	delete[] printValue;
}