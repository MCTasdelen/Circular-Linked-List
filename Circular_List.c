#include<stdio.h>
#include<stdlib.h>


struct Node {
	int value;
	struct Node* next;
};


struct Node* insert(struct Node* p, int value)
{
	struct Node* temp;
	temp = malloc(sizeof(struct Node));
	temp->value = value;
	
	if (p == NULL)
	{
		p=temp;
		temp->next =temp;
		
	}
	else
	{
		struct Node* iter = p;
		while (iter->next != p)
		{
			iter = iter->next;
		}
		iter->next = temp;
		temp->next = p;
	}
	

}
 
void Print(struct Node* p)
{
	struct Node* cir = p;
	printf("%d\n", cir->value);
	cir=cir->next;

	while (cir!=p)
	{
		printf("%d\n", cir->value);
		cir= cir->next;
	}
}
void Delete(struct Node* head, int n)
{
	int flag = 0;
	struct Node* count = head;
	while (count->next != head)
	{	flag++;
		count = count->next;
		
	}
	if (n <= flag)
	{
		if (n == 1)
		{
			struct Node* cur = head;
			while (cur->next != head)
			{
				cur = cur->next;
			}
			struct Node* temp = head;
			head = temp->next;
			cur->next = head;

			free(temp);
		}
		else {
			struct Node* p = head;
			for (int i = 0; i < (n - 2); i++)
			{
				p = p->next;
			}
			struct Node* temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
	}
	else
	{
		printf("element count exceeded\n");
	}
}
int main()
{
	struct Node* head=NULL;
	head = insert(head, 10);
	head = insert(head, 20);
	head = insert(head, 510);
	head = insert(head, 140);
	head = insert(head, 150);
	Print(head);
	printf("Please enter n'th position for delete:\n");
	int n;
	scanf_s("%d", &n);
	Delete(head, n);
	Print(head);



}




