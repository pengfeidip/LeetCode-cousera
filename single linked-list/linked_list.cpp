#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	MyLinkedList* list= new MyLinkedList() ;
	list->addAtHead(5);
	list->addAtHead(4);
	list->addAtTail(199);
	list->printVal();

	list->addAtIndex(0, 100);
	list->printVal();

	cout << "É¾³ýºó£º " << endl;
	list->deleteAtIndex(4);
	list->printVal();
} 