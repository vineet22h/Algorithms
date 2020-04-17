#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int data;
	struct node *next;
};

struct node* createNode() {
	struct node *newNode = malloc(sizeof(struct node));
	if(!newNode) 
		return 0;
	return newNode;
}
struct node* addItem(struct node **head,int data,int position) {
	struct node *p,*q;
	struct node *newNode = createNode();
	int i =1;
	newNode->data = data;
	p = *head;
	if (position == 1) {
		newNode->next = *head;
		*head = newNode;

	}
	else {
		
		while (i<position && p!=NULL) {
			i++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
	return *head; 
}
void print(struct node *head) {
	while(head) {
		printf("%d  ",head->data);
		head = head->next;
	}

}

struct node* merge(struct node **head1,struct node **head2) {
	struct node *p,*q ;
	p = *head1;
	while(1) {	
		q=p;
		p = p->next;
		if(p==NULL)
			break;	
	}
	q->next = *head2;
	return *head1;
}
void swap(struct node *p,struct node *q) {
	int temp;
	temp = p->data;
	p->data = q->data;
	q->data = temp;
}

struct node* bubbleSort(struct node **head) {

	struct node *p,*q;
	p = *head;
	q = p->next;
	while (q!=NULL) {

		if(p->data > q->data) {
			swap(p,q);
			p = *head;
			q = p->next;
		}
		else {
			p = q;
			q = q->next;
		}
	}
	return *head;

}
void main() {
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *join = NULL;
	struct node *sort = NULL;
	head1 = addItem(&head1,5,1);
	addItem(&head1,7,2);
	addItem(&head1,4,3);
	addItem(&head1,2,4);
	printf("First list : ");
	print(head1);
	printf("\nSecond list : ");

	head2 = addItem(&head2,9,1);
	addItem(&head2,6,2);
	addItem(&head2,3,3);
	print(head2);

	printf("\nAfter merge : ");
	join = merge(&head1,&head2);
	print(join);

	printf("\nAfter sorting : ");
	sort = bubbleSort(&join);
	print(sort);

}