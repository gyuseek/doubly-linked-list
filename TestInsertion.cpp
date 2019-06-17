#include "TestInsertion.h"
#include "Tester.h"
#include <stdlib.h>

//자료구조를 헤더파일 포함
#include "DoublyLinkedList.h"

void TestInsertion()
{
	//자료구조를 초기화한다 
	List* myList = (List*)malloc(sizeof(List));
	InitList(myList);

	//테스트를 등록
	Tester<List*, int> tester((VaFunc_t)AddNode, "노드추가하기", 7);

	//테스트케이스 작성 (함수반환값 평가) - 삽입
	tester.TestRegisteredFunc(0, myList, 1);
	tester.TestRegisteredFunc(0, myList, 3);
	tester.TestRegisteredFunc(0, myList, 4);
	tester.TestRegisteredFunc(0, myList, 7);
	tester.TestRegisteredFunc(0, myList, 11);
	tester.TestRegisteredFunc(0, myList, 18);
	tester.TestRegisteredFunc(0, myList, 29);

	//테스트케이스 작성 ( 변수값 평가)
	tester.DataChecker(1, myList->Head->Data);
	tester.DataChecker(3, myList->Head->Next->Data);
	tester.DataChecker(4, myList->Head->Next->Next->Data);
	tester.DataChecker(7, myList->Head->Next->Next->Next->Data);
	tester.DataChecker(11, myList->Head->Next->Next->Next->Next->Data);
	tester.DataChecker(18, myList->Head->Next->Next->Next->Next->Next->Data);
	tester.DataChecker(11, myList->Head->Next->Next->Next->Next->Next->Previous->Data);

	//메모리 누수 확인
	DestroyList(myList);
	tester.MemoryLeakChecker();

}
