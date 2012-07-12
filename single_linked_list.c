#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Node 
{
	int data;
	struct Node *next;
};

struct Node *gHead = NULL;

void InitList(struct Node **head)
{
	*head = (struct Node *) malloc(sizeof(struct Node));
	(*head)->data = 0;
	(*head)->next = NULL;
};

void AppendNode(struct Node *head, int data)
{
	struct Node *pCur = NULL;
	struct Node *node = NULL;
	node = (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;


	for(pCur = head; pCur->next; pCur = pCur->next)
	{
	}

	pCur->next = node;
};

/* index : 0 ==> first node,
 * index : 1 ==> second node,
 * index : n ==> (n+1)th node,
 */
void DeleteNode(struct Node *head, int index)
{
/* pCur : a previous node 
 * pCur-> next : a node to be deleted 
 * pCur->next->next : a next node
 * */
	struct Node *pCur = NULL;
	struct Node *pTemp = NULL;
	int i = 0;

	for(pCur = head; pCur->next; pCur = pCur->next)
	{
		if (i<index)
			i++;
		else
			break;
	}

	pTemp = pCur->next;
	pCur->next = pCur->next->next;

	free(pCur);
};

void ShowList(struct Node *head)
{
	struct Node *pCur = NULL;

	printf("** List of Nodes **\n");
	for(pCur = head; pCur; pCur = pCur->next)
	{
		printf("[ %p | %d ] ---> ", pCur, pCur->data);
	}
	printf("NULL\n\n");
};


void FreeList(struct Node *head)
{
	while(head->next)
	{
		DeleteNode(head, 0);
	}

	free(head);
}

int main(void)
{
	printf("** Single Linked List **\n");

	InitList(&gHead);

	printf("* Add Nodes *\n");
	AppendNode(gHead, 100);
	AppendNode(gHead, 200);
	AppendNode(gHead, 300);

	printf("* Show List *\n");
	ShowList(gHead);

	printf("* Delete Nodes *\n");
	DeleteNode(gHead, 1);
	ShowList(gHead);

	FreeList(gHead);
//	gHead = NULL;

	return 0;
}
