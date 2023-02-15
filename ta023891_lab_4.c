#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node *tmp = head;
	int length = 0;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		length++;
	}
	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	if(head == NULL)
		return NULL;

	node *tmp = head;
	int size = length(head);
	char *string = malloc(sizeof(char) * (size + 1));
	tmp = head;

	for(int i = 0; i < size + 1; i++)
	{
		string[i] = tmp->letter;
		//printf("Letter: %c \n", tmp->letter);
		if(tmp->next != NULL)
			tmp = tmp->next;
	}
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->letter = c;

	if(*pHead == NULL)
	{
		*pHead = newNode;
		return;
	}

	node *tmp = *pHead;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = newNode;
	//printf("Inserted char: %c\n", c);
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node *tmp = *pHead;
	node *next;
	while(tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str = NULL;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		//printf("string Length: %d\n", strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}
		//printf("Head: %c\n", *head);

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}