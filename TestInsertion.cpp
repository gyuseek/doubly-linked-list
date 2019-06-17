#include "TestInsertion.h"
#include "Tester.h"
#include <stdlib.h>

//�ڷᱸ���� ������� ����
#include "DoublyLinkedList.h"

void TestInsertion()
{
	//�ڷᱸ���� �ʱ�ȭ�Ѵ� 
	List* myList = (List*)malloc(sizeof(List));
	InitList(myList);

	//�׽�Ʈ�� ���
	Tester<List*, int> tester((VaFunc_t)AddNode, "����߰��ϱ�", 7);

	//�׽�Ʈ���̽� �ۼ� (�Լ���ȯ�� ��) - ����
	tester.TestRegisteredFunc(0, myList, 1);
	tester.TestRegisteredFunc(0, myList, 3);
	tester.TestRegisteredFunc(0, myList, 4);
	tester.TestRegisteredFunc(0, myList, 7);
	tester.TestRegisteredFunc(0, myList, 11);
	tester.TestRegisteredFunc(0, myList, 18);
	tester.TestRegisteredFunc(0, myList, 29);

	//�׽�Ʈ���̽� �ۼ� ( ������ ��)
	tester.DataChecker(1, myList->Head->Data);
	tester.DataChecker(3, myList->Head->Next->Data);
	tester.DataChecker(4, myList->Head->Next->Next->Data);
	tester.DataChecker(7, myList->Head->Next->Next->Next->Data);
	tester.DataChecker(11, myList->Head->Next->Next->Next->Next->Data);
	tester.DataChecker(18, myList->Head->Next->Next->Next->Next->Next->Data);
	tester.DataChecker(11, myList->Head->Next->Next->Next->Next->Next->Previous->Data);

	//�޸� ���� Ȯ��
	DestroyList(myList);
	tester.MemoryLeakChecker();

}
