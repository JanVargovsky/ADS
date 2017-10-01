#include <vector>
#include <cstdio>
#include <iostream>

#include "LinkedList.cpp"
using namespace std;

void t1()
{
	LinkedList<int> list;
	for (int i = 0; i < 5; i++)
		list.addFirst(i);

	cout << "expected 4 3 2 1 0" << endl << "actual\t ";
	for (auto &item : list)
		cout << item << " ";
	cout << endl;
}

void t2()
{
	LinkedList<int> list;
	for (int i = 0; i < 5; i++)
		list.addLast(i);

	cout << "expected 0 1 2 3 4" << endl << "actual\t ";
	for (auto &item : list)
		cout << item << " ";
	cout << endl;
}

void t3()
{
	LinkedList<int> list;
	list.insertAt(10, 0);
	for (int i = 0; i < 5; i++)
		list.addLast(i);

	list.insertAt(20, 2);
	list.insertAt(30, 7);

	cout << "expected 10 0 20 1 2 3 4 30" << endl << "actual\t ";
	for (auto &item : list)
		cout << item << " ";
	cout << endl;
}

void t4()
{
	LinkedList<int> list;
	for (int i = 0; i < 5; i++)
		list.addLast(i);

	cout << "removed " << list.remove(2) << endl;

	cout << "expected 0 1 3 4" << endl << "actual\t ";
	for (auto &item : list)
		cout << item << " ";
	cout << endl;
}

void t5()
{
	struct MyStruct
	{
		~MyStruct() {
			cout << "D ";
		}
	};

	LinkedList<MyStruct*> list;
	for (int i = 0; i < 5; i++)
		list.addFirst(new MyStruct());

	cout << "expected D D D D" << endl << "actual\t ";
	list.clear([](auto t) -> void { delete t; });
	cout << endl;
}

int main()
{
	t1();
	t2();
	t3();
	t4();
	t5();

	return 0;
}