#include "Test.h"
#include "Tester.h"
#include "DoublyLinkedList.h"
static void TestInsertion()
{
	list* myList = (list*)malloc(sizeof(list));

	Tester<List*, int> tester((VaFunc_t)AddNode, "노드추가", 10);

	tester.TestRegisteredFunc(0, myList, 0);
	tester.TestRegisteredFunc(0, myList, 1);
	tester.TestRegisteredFunc(0, myList, 2);
	tester.TestRegisteredFunc(0, myList, 3);
	tester.TestRegisteredFunc(0, myList, 4);
	tester.DataChecker(0, myList->Head->Data);
	tester.DataChecker(1, myList->Head->Next->Data);
	tester.DataChecker(2, myList->Head->Next->Next->Data);
	tester.DataChecker(3, myList->Head->Next->Next->Next->Data);
	tester.DataChecker(4, myList->Head->Next->Next->Next->Next->Data);

	tester.MemoryLeakChecker();
}

static void TestSearch()
{
	Tester<List*, int> tester((VaFunc_t)GetNode, "노드 찾기", 10);
	
	list* myList = (list*)malloc(sizeof(list));
	InitList(myList);

	Node* myNode1 = (Node*)malloc(sizeof(Node));
	Node* myNode2 = (Node*)malloc(sizeof(Node));
	AddNodePtr(myList, myNode1);
	tester.DataChecker((int)myNode1, (int)myList->Tail);
	AddNodePtr(myList, myNode2);
	tester.DataChecker((int)myNode2, (int)myList->Tail);

	DestroyList(myList);
	tester.MemoryLeakChecker();
}

static void TestDelete()
{
	list* myList = (list*)malloc(sizeof(list));
	InitList(myList);
}


void TestDoublyLinkedList()
{
	TestInsertion();
	TestDelete();
	TestSearch();
}
