#include "Table.h"
#include "ExpressionCell.h"


int Table::getSize() const
{
	return this->size;
}
Table::Table()
{
	size = 0;
	table = nullptr;
}
Table::Table(const Table& t)
{
	*this = t;
}
Table& Table::operator=(const Table& t)
{
	if (this != &t)
	{
		deleteTable();
		this->table = new vector<Cell*>[t.getSize()];
		for (int i = 0; i < t.getSize(); i++)
		{
			for (vector<Cell*>::iterator it = t.table[i].begin(); it != t.table[i].end(); ++it)
			{
				int type = (*it)->getType();
				char* cont = (*it)->getCellContent();
				Cell* newPtr = createInstance(type, cont);
				table[i].push_back(newPtr);
			}
		}
		setSize(t.getSize());
	}
	return *this;
}

void Table::setSize(int s)
{
	this->size = s;
}
void Table::resize(int r, int c)
{
	vector<Cell*> * newTable = new vector<Cell*>[r + 1];
	Cell* cell = nullptr;
	for (int i = 0; i < r + 1; i++)
	{
		newTable[i]=vector<Cell*>(c + 1);
		for (vector<Cell*>::iterator it = newTable[i].begin(); it != newTable[i].end(); ++it)
		{
			*it = new EmptyCell();
		}
	}

		for (int i = 0; i < getSize(); i++)
		{
			for (auto j = 0; j < table[i].size(); j++)
			{
				newTable[i][j] = table[i][j];
			}
		}
		delete[] table;
		this->table = newTable;
		setSize(r + 1);
}
int Table::getLongestRowLength()
{
	int max = 0;
	for (int i = 0; i < getSize(); i++)
	{
		if ((int)table[i].size() > max)
		{
			max = (int)table[i].size();
		}
	}
	return max;
}
int Table::getLongestColumnContent(int c) const
{
	char str[50];
	int max = 0;
	for (int i = 0; i < getSize(); i++)
	{
		if (printValueLength(table[i][c]) >= max)
		{
			max = printValueLength(table[i][c]);
		}
	}
	return max;
}
Cell* Table::createInstance(int t, char * c)
{
	if (t == TYPE_EMPTY) return new EmptyCell();
	if (t == TYPE_INT) return new IntegerCell(c);
	if (t == TYPE_DOUBLE) return new DoubleCell(c);
	if (t == TYPE_STRING) return new StringCell(c);
	if (t == TYPE_EXPRESSION) return new ExpressionCell(*this, c);
}
void Table::addCell(int r, int c, const char * cont)
{
	if (r-1 >= getSize()-1 && c-1>=getLongestRowLength()-1)
	{
		resize(r-1 , c-1);
	}
	else if (r-1 >= getSize()-1 && c-1 <= getLongestRowLength())
	{
		resize(r-1, getLongestRowLength());
	}
	else if (r-1 <= getSize() - 1 && c-1 >= getLongestRowLength()-1)
	{
		resize(getSize()-1, c-1);
	}
	else if (r-1 <= getSize() - 1 && c-1 <= getLongestRowLength())
	{
		resize(getSize()-1, getLongestRowLength()-1);
	}


	table[r-1][c-1]->setCellContent(cont);
	if (table[r-1][c-1]->determineContentType() == TYPE_EMPTY || table[r-1][c-1]->determineContentType() == TYPE_UNKNOWN)
	{
		table[r-1][c-1] = createInstance(TYPE_EMPTY, table[r-1][c-1]->getCellContent());
	}
	else if (table[r-1][c-1]->determineContentType() == TYPE_INT)
	{
		table[r-1][c-1] = createInstance(TYPE_INT, table[r-1][c-1]->getCellContent());
	}
	else if (table[r-1][c-1]->determineContentType() == TYPE_DOUBLE)
	{
		table[r-1][c-1] = createInstance(TYPE_DOUBLE, table[r-1][c-1]->getCellContent());
	}
	else if (table[r-1][c-1]->determineContentType() == TYPE_STRING)
	{
		table[r-1][c-1] = createInstance(TYPE_STRING, table[r-1][c-1]->getCellContent());
	}
	else if (table[r-1][c-1]->determineContentType() == TYPE_EXPRESSION)
	{
		table[r-1][c-1] = createInstance(TYPE_EXPRESSION, table[r-1][c-1]->getCellContent());
	}
}
Cell * Table::getCell(int r, int c) const
{
	return table[r-1][c-1];
}
double Table::getCellValue(int r, int c) const
{
	return getCell(r, c)->getValue();
}

void Table::deleteTable()
{
	for (int i = 0; i < getSize(); i++)
	{
		for (vector<Cell*>::iterator it = table[i].begin(); it < table[i].end(); ++it)
		{
			delete (*it);
		}
		table[i].clear();
	}
	delete[] table;
}
Table::~Table()
{
	deleteTable();
}

int Table::printValueLength(Cell* c) const
{
	char str[50];
	if (c->getType() == TYPE_EXPRESSION)
	{
		if (((ExpressionCell*)c)->getExpressionValidity() == true) {
			sprintf(str, "%g", c->getValue());
			return strlen(str);
		}
		else return strlen("ERROR");
	}
	if (c->getType() == TYPE_STRING)
	{
		return strlen(c->getCellContent()) - 2;
	}
	if (c->getType() == TYPE_EMPTY)
	{
		return 0;
	}
	if (c->getType() == TYPE_INT || c->getType() == TYPE_DOUBLE)
	{
		sprintf(str, "%g", c->getValue());
		return strlen(str);
	}
	else 
	{
		return strlen(c->getCellContent());
	}
}
void Table::printTable() 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			if (table[i][j]->getType() == TYPE_EXPRESSION)
			{
				double val = ((ExpressionCell*)table[i][j])->calculateValueOfExpression(*this, table[i][j]->getCellContent());
				((ExpressionCell*)table[i][j])->setValue(val);
			}
			cout << setw(getLongestColumnContent(j)+1);
			table[i][j]->printCell();
			cout << " |";
		}
		cout << endl;
	}
}
