#include "DoublyLinkedList.h"
#include <stdlib.h>

//����Ʈ�� �ʱ�ȭ�Ѵ� 
int InitList(List* list) 
{
	list->Head = NULL;
	list->Tail = NULL;

	return 0;
}

// int ���� data �� ����Ʈ�� Tail �ڿ� �߰��Ѵ� ������ 0 ��ȯ ���н� -1 ��ȯ�ϱ�
int AddNode(List* list, int data)
{
	// newNode Memory �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// list�� ���� ���	
	if (list->Head == NULL && list->Tail == NULL)
	{
		newNode->Data = data;
		list->Head = newNode;
		list->Tail = newNode;
	}
	// list �ڿ� node �߰��ϴ� ���
	else 
	{
		newNode->Data = data;
		Tail->Next = newNode;
		newNode->Prev = Tail;
		list->Tail = newNode;
	}
	return 0;
}

//Head ���κ��� i ��°�� ����� �����͸� �����´� ������ 0 , ���н� -1 ��ȯ�ϱ�
int GetData(List* list, int i)
{
	Node* horse = list->Head;
	int cnt = 0;

	while (horse != NULL)
	{
		if (cnt++ == i)
		{
			return horse->Data;
		}
		horse = horse->Next;
	}
	return 0;
}

// ����Ʈ�� ����� ��ȯ �ϱ�
int GetListSize(List* list)
{
	Node* horse = list->Head;
	int size = 0;

	while (horse != NULL)
	{
		horse = horse->Next;
		size++;
	}
	return size;
}

// i ��°�� ��带 ����� (����� ���ٸ� -1, ����� �����ϸ� 0 ��ȯ)
int RemoveNodeFromList(List* list, int i)
{
	// i��° node search
	Node* horse = list->Head;
	int cnt;
	for (cnt = 1; cnt < i; cnt++)
	{
		horse = horse->Next;
	}
	// remove head node case
	if (horse->Prev == NULL)
	{
		list->Head = horse->Next;
		horse->Next->Prev = NULL;
	}
	// remove tail node case
	else if (horse->Next == NULL)
	{
		list->Tail = horse->Prev;
		horse->Prev->Next = NULL;
	}
	// remove middle node case
	else
	{
		horse->Prev->Next = horse->Next;
		horse->Next->Prev = horse->Prev;
	}
	//
	free(horse);
	return 0;
}

//  ����Ʈ �����ϱ� �����Ұ� ������ -1 ��ȯ ������ 0
int DestroyList(List* list)
{
	int i;
	int size = GetListSize(List * list);

	for (i = 1; i < size + 1; i++)
	{
		RemoveNodeFromList(List * list, int i);
	}
	return 0;
}
/*
int AddNodePtr(List* list, Node* node)
{
	node = list->Head;
	// list size ��ŭ ����
	while (node != NULL)
	{
		num++;
		node = node->Next;
	}
	return node;
}
*/
// i��° ����� �����͸� �����´� 
Node* GetNode(List* list, int i)
{
	Node* horse = list->Head;
	int cnt = 1;
	//i��° ������ ������ node �̵�
	while (cnt != i)
	{
		horse = horse->Next;
		cnt++;
	}
	return horse;
}

//i ��°�� ����Ʈ�� �߰��Ѵ� 
int AddList(List* list, List* inputlist, int i)
{
	size = GetListSize(List * list);
	Node* anchor = GetNode(List * list, int i);

	//list�� head ������ �� ���
	if (i == 1)
	{
		list->Head->Prev = inputlist->Tail;
		inputlist->Tail->Next = list->Head;
	}
	//list�� Tail �ڷ� ���� ���
	else if (i == size + 1)
	{
		list->Tail->Next = inputlist->Head;
		inputlist->Head->Prev = list->Tail;
	}
	else if ((i < size + 1) && (i > 1))
	{
		anchor->Next->Prev = inputlist->Tail;
		inputlist->Tail->Next = anchor->Next;
		anchor->Next = inputlist->Head;
		inputlist->Head->Prev = anchor;
	}
	return 0;
}