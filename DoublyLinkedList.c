#include "DoublyLinkedList.h"
#include <stdlib.h>

//리스트를 초기화한다 
int InitList(List* list) 
{
	list->Head = NULL;
	list->Tail = NULL;

	return 0;
}

// int 형의 data 를 리스트에 Tail 뒤에 추가한다 성공시 0 반환 실패시 -1 반환하기
int AddNode(List* list, int data)
{
	// newNode Memory 할당
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// list가 없는 경우	
	if (list->Head == NULL && list->Tail == NULL)
	{
		newNode->Data = data;
		list->Head = newNode;
		list->Tail = newNode;
	}
	// list 뒤에 node 추가하는 경우
	else 
	{
		newNode->Data = data;
		Tail->Next = newNode;
		newNode->Prev = Tail;
		list->Tail = newNode;
	}
	return 0;
}

//Head 노드로부터 i 번째의 노드의 데이터를 가져온다 성공시 0 , 실패시 -1 반환하기
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

// 리스트의 사이즈를 반환 하기
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

// i 번째의 노드를 지운다 (지울게 없다면 -1, 지운게 성공하면 0 반환)
int RemoveNodeFromList(List* list, int i)
{
	// i번째 node search
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

//  리스트 제거하기 제거할게 없으면 -1 반환 성공시 0
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
	// list size 만큼 진행
	while (node != NULL)
	{
		num++;
		node = node->Next;
	}
	return node;
}
*/
// i번째 노드의 포인터를 가져온다 
Node* GetNode(List* list, int i)
{
	Node* horse = list->Head;
	int cnt = 1;
	//i번째 도달할 때까지 node 이동
	while (cnt != i)
	{
		horse = horse->Next;
		cnt++;
	}
	return horse;
}

//i 번째에 리스트를 추가한다 
int AddList(List* list, List* inputlist, int i)
{
	size = GetListSize(List * list);
	Node* anchor = GetNode(List * list, int i);

	//list의 head 앞으로 들어갈 경우
	if (i == 1)
	{
		list->Head->Prev = inputlist->Tail;
		inputlist->Tail->Next = list->Head;
	}
	//list의 Tail 뒤로 들어가는 경우
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