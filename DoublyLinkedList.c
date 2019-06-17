#include "DoublyLinkedList.h"
#include <stdlib.h>

// initialize List 
int InitList(List* list)
{
	list->Head = NULL;
	list->Tail = NULL;

	return 0;
}

// input the data of int type to tail of list(suc = 0, fail = -1) 
int AddNode(List* list, int data)
{
	// make newNode Memory 
	Node* newNode = (Node*)malloc(sizeof(Node));

	// no list	
	if(list->Head == NULL && list->Tail == NULL)
	{
		newNode->Data = data;
		list->Head = newNode;
		list->Tail = newNode;
	}
	// input node to tail of list
	else
	{
		newNode->Data = data;
		list->Tail->Next = newNode;
		newNode->Prev = list->Tail;
		list->Tail = newNode;
	}
}

	// input the data of int type to tail of list(suc = 0, fail = -1) 
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
	return -1;
}

// return the list size
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

// remove the i node data(suc = 0, fail = -1)
int RemoveNodeFromList(List* list, int i)
{
	// node search
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

// remove the list(suc = 0, fail =-1)
int DestroyList(List* list)
{
	int i;
	for (i = 1; i < GetListSize(List * list)+1; i++)
	{
		RemoveNodeFromList(List * list, int i)
	}
	return 0;
}
// return pointer of nowNode
int AddNodePtr(List* list, Node* node)
{
	int num = 0;
	Node* node = list->Head;

	while (num == GetListSize(List * list))
	{
		num++;
		node = node->Next;
	}
	return node;
}

//  get the point of i node
Node* GetNode(List* list, int i)
{
	return NULL;
}

// add list to i node(suc = 0. fail = -1)
int AddList(List* list1, List* list2, int i)
{
	return 0;
}
