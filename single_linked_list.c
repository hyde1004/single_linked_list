#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Node
{
	int data;
	struct Node (*next);
};

void initList(struct Node (**head))
{
	(*head) = (struct Node *) malloc(sizeof(struct Node));
	memset((*head), 0, sizeof(struct Node));

	(*head)->data = 0;
	(*head)->next = NULL;
};

void appendNode(struct Node (*head), int data)
{
	struct Node *pCur = NULL;
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	memset(node, 0, sizeof(struct Node));

	node->data = data;
	node->next = NULL;

	for(pCur=head;pCur->next;pCur=pCur->next)
	{
	}

	pCur->next = node;
};

/* index : 0 ==> first node,
 * index : 1 ==> second node,
 * index : n ==> (n+1)th node,
 */
void deleteNode(struct Node (*head), int index)
{
/* pCur : a previous node 
 * pCur-> next : a node to be deleted 
 * pCur->next->next : a next node
 * */
	struct Node *pCur = NULL;
	int i = 0;

	for(pCur=head;pCur->next;pCur=pCur->next)
	{
//		printf("i : %d\n", i);	
//		printf("pCur : %p, pCur->next : %p\n", pCur, pCur->next);
		if (i<index)
			i++;
		else
			break;
	}

	pCur->next = (pCur->next)->next;
	free(pCur->next);
}

void showList(struct Node (*head))
{
	struct Node *pCur = NULL;

	for(pCur=head->next;pCur;pCur=pCur->next)
	{
		printf("[ %p | %d ] ---> ", pCur, pCur->data);
	}
	printf("NULL\n");
};

struct Node (*gHead) = NULL;

int main(void)
{
	initList(&gHead);

	appendNode(gHead, 100);
	appendNode(gHead, 200);
	appendNode(gHead, 300);

	printf("Show List\n");
	showList(gHead);

	printf("\n\nAfter deleting 2nd node\n");
	deleteNode(gHead, 1);
	showList(gHead);

	return 0;
}
