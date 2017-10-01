#include <vector>
#include <cstdio>
#include <iostream>

#include "LinkedList.cpp"
using namespace std;

void t1()
{
	LinkedList<int> listOfInts;
	for (int i = 0; i < 5; i++)
		listOfInts.addFirst(i);

	cout << "expected 4 3 2 1 0" << endl << "actual\t ";
	for (auto &item : listOfInts)
		cout << item << " ";
	cout << endl;
}

void t2()
{
	LinkedList<int> listOfInts;
	for (int i = 0; i < 5; i++)
		listOfInts.addLast(i);

	cout << "expected 0 1 2 3 4" << endl << "actual\t ";
	for (auto &item : listOfInts)
		cout << item << " ";
	cout << endl;
}

void t3()
{
	LinkedList<int> listOfInts;
	listOfInts.insertAt(10, 0);
	for (int i = 0; i < 5; i++)
		listOfInts.addLast(i);

	listOfInts.insertAt(20, 2);
	listOfInts.insertAt(30, 7);

	cout << "expected 10 0 20 1 2 3 4 30" << endl << "actual\t ";
	for (auto &item : listOfInts)
		cout << item << " ";
	cout << endl;
}

void t4()
{
	LinkedList<int> listOfInts;
	for (int i = 0; i < 5; i++)
		listOfInts.addLast(i);

	cout << "removed " << listOfInts.remove(2) << endl;

	cout << "expected 0 1 3 4" << endl << "actual\t ";
	for (auto &item : listOfInts)
		cout << item << " ";
	cout << endl;
}

int main()
{
	t1();
	t2();
	t3();
	t4();

	return 0;
}