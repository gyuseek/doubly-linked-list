#include "Tester.h"
#include "TestSearch.h"


void TestSearch()
{
	//�׽�Ʈ ��� 
	Tester<List*, int> tester((VaFunc_t)GetNode, "��� ã��", 10);
	list* myList = (list*)malloc(sizeof(list));
	InitList(myList);
	Node* myNode1 = (Node*)malloc(sizeof(Node));
	Node* myNode2 = (Node*)malloc(sizeof(Node));

	//�׽�Ʈ �ϱ� 
	AddNodePtr(myList, myNode1);
	tester.DataChecker((int)myNode1, (int)myList->Tail);
	AddNodePtr(myList, myNode2);
	tester.DataChecker((int)myNode2, (int)myList->Tail);
	
	//�޸𸮴���
	DestroyList(myList);
	tester.MemoryLeakChecker();	
}