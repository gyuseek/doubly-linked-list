#include "Tester.h"
#include "TestSearch.h"


void TestSearch()
{
	//테스트 등록 
	Tester<List*, int> tester((VaFunc_t)GetNode, "노드 찾기", 10);
	list* myList = (list*)malloc(sizeof(list));
	InitList(myList);
	Node* myNode1 = (Node*)malloc(sizeof(Node));
	Node* myNode2 = (Node*)malloc(sizeof(Node));

	//테스트 하기 
	AddNodePtr(myList, myNode1);
	tester.DataChecker((int)myNode1, (int)myList->Tail);
	AddNodePtr(myList, myNode2);
	tester.DataChecker((int)myNode2, (int)myList->Tail);
	
	//메모리누수
	DestroyList(myList);
	tester.MemoryLeakChecker();	
}