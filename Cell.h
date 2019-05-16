#ifndef __CELL_H
#define __CELL_H
#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <cstring>
#include "Utils.h"

using namespace std;

#define TYPE_EMPTY 0
#define TYPE_INT 1
#define TYPE_DOUBLE 2
#define TYPE_STRING 3
#define TYPE_EXPRESSION 4
#define TYPE_UNKNOWN 5


class Cell
{
	int type;
	char * content;

public:
	Cell();
	Cell(const char * cont);
	Cell(const Cell& other);
	Cell & operator=(const Cell & other);
	virtual ~Cell();

	int getType() const;
	virtual void setType(int t);
	void setCellContent(const char * cont);
	char * getCellContent() const;

	int determineContentType() const;
	
	virtual double getValue() const = 0;
	virtual void printCell() const = 0;
};
#endif 
