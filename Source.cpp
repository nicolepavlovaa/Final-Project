#include "Table.h"
#include "Cell.h"
#include "ExpressionCell.h"
#include "IntegerCell.h"
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	Table t;
	t.addCell(7, 1, "1000");
	t.addCell(4, 2, "100");
	t.addCell(4, 3, "8");
	t.addCell(4, 1, "3");
	t.addCell(3, 3, "5050");
	//t.addCell(9, 9, "=R3C3+R5C1");
	t.addCell(1, 1, "1000");
	t.addCell(1, 2, "=R7C1+R4C2");
	//cout << "print value: "<<t.printValueLength(t.getTable()[3][1]) << endl << endl;
	t.addCell(1, 4, "\"stringcell\"");
	t.addCell(6, 4, "\"Hello Worldddddd!\"");
	t.addCell(10, 6, "10");
	t.addCell(1, 5, "=R1C2+R4C3");
	//t.addCell(3, 5, "=R4C2+R4C3");
	//cout <<"longest row: "<< t.longestRowLength() << endl;
	//cout << "longest col content: " << t.getLongestColumnContent(4) << endl;
	t.addCell(1, 6, "=R1C2+R1C2");
	t.addCell(1, 10, "=R1C6+R1C15");
	t.addCell(1, 7, "=R3C3+R4C1");
	t.addCell(1, 15, "5");
	t.printTable();
	Table t1(t);
	cout << endl << endl;
	t1.printTable();
	char anna[7] = "\"anna\"";
	char beta[6] = "=10-8";
	StringCell a(anna);
	StringCell b;
	b = a;
	cout << "String Cell: "<< b.getPrintValue() << endl;
	ExpressionCell c(t, beta);
	ExpressionCell d;
	d = c;
	cout << "Expression Cell: " << d.getValue() << endl;
	//t.deleteTable();
	system("pause");
	return 0;
}