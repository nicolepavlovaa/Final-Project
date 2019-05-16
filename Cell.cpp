#include "Cell.h"

int Cell::getType() const
{
	return this->type;
}
void Cell::setType(int t)
{
	this->type = t;
}
Cell::Cell() :content(nullptr)
{
	setCellContent("");
	setType(TYPE_EMPTY);
}

Cell::Cell(const char * other) :content(nullptr)
{
	setCellContent(other);
	setType(determineContentType());
}
Cell::Cell(const Cell& other) : content(nullptr)
{
	setCellContent(other.getCellContent());
	setType(other.getType());
}
Cell & Cell::operator=(const Cell& c)
{
	if (this != &c)
	{
		setCellContent(c.getCellContent());
		setType(c.getType());
	}
	return *this;
}
Cell::~Cell()
{
	delete[] content;
}

void Cell::setCellContent(const char * cont)
{
	delete[] content;
	const int length = strlen(cont);
	content = new char[length + 1];
	strcpy(this->content, cont);
}
char * Cell::getCellContent() const
{
	return this->content;
}
int Cell::determineContentType() const
{
	if (content == nullptr) return TYPE_EMPTY;
	else if (Utils().isInt(content)) return TYPE_INT;
	else if (Utils().isDouble(content)) return TYPE_DOUBLE;
	else if (Utils().isString(content)) return TYPE_STRING;
	else if (Utils().isExpression(content)) return TYPE_EXPRESSION;
	else return TYPE_UNKNOWN;
}


