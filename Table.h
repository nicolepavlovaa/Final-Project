#ifndef __TABLE_H
#define __TABLE_H
#include "Cell.h"
#include "IntegerCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "EmptyCell.h"
#include <vector>
#include <iomanip>

class ExpressionCell;

class Table
{
public:
	Table();
	Table(const Table& t);
	Table & operator=(const Table & t);
	~Table();

	Cell* getCell(int r, int c) const;
	double getCellValue(int r, int c) const;

	Cell* createInstance(int type, char * c);
	void addCell(int row, int col, const char * content);

	int getSize() const; 
	void setSize(int s);

	int getLongestRowLength();
	void printTable();

private: 
	vector<Cell*> * table = nullptr;
	unsigned int size = 0;

	void resize(int r, int c);
	int getLongestColumnContent(int c) const;
	int printValueLength(Cell* c) const;
	void deleteTable();
};
#endif 
