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

void deleteNode(struct Node (*head), int index)
{
	struct Node *pCur = NULL;
	int i = 0;

	for(pCur=head;pCur->next;pCur=pCur->next)
	{
		printf("i : %d\n", i);
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
	int i = 0;

	for(pCur=head->next;pCur;pCur=pCur->next)
	{
		printf("Node [%d] : %d\n", i++, pCur->data);
	}
};

struct Node (*gHead) = NULL;

int main(void)
{
	initList(&gHead);

	printf("Before......\n");
	appendNode(gHead, 100);
	appendNode(gHead, 200);
	appendNode(gHead, 300);

	showList(gHead);

	printf("After.......\n");
	deleteNode(gHead, 0);
	showList(gHead);

	return 0;
}
