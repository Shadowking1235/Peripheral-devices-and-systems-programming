#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

int main()
{
	struct Node *head = (struct Node *)malloc(sizeof(struct Node));
	head->data = 0;
	head->next = NULL;

	// Simulate arrival of processes
	int time = 0;
	int toRun = 2;
	printf("Processes appear every second. Every process take %ds to run.\n", toRun);
	for (int i = 1; i <= 10; i++)
	{
		if (time > 0 && time % toRun == 0)
		{
			struct Node *oldHead = head;
			head = head->next;
			free(oldHead);
		}
		printf("Current queue:");
		struct Node *current = head;
		while (current->next != NULL)
		{
			printf(" %d", current->data);
			current = current->next;
		}
		printf(" %d", current->data);
		printf("\n");
		printf("Process %d enters queue\n", i);
		current->next = (struct Node *)malloc(sizeof(struct Node));
		struct Node *newItem = current->next;
		newItem->data = i;
		newItem->next = NULL;
		time++;
	}
}