/* You are given two empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: 807
Explanation: 342 + 465 = 807
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* next;
};

void insert(struct node** head, int num){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;
    if(*head != NULL){
	new_node->next = *head;
    }
    *head = new_node;
}

void add(struct node* head1, struct node* head2, int nums[], int size){
    int sum;
    int extra = 0;
    for(int i = 0; i < size; i++){
	sum = head1->num + head2->num;
	if(extra == 1){
	    sum++;
	    extra = 0;
	}

	if(sum >= 10 && i < size - 1){
	    sum = sum - 10;
	    extra++;
	}
	nums[i] = sum;
	head1 = head1->next;
	head2 = head2->next;
    }
}

void print(struct node* head){
    while(head != NULL){
	printf("%d\n", head->num);
	head = head->next;
    }
}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int num;
    int size;

    printf("Enter size of list: ");
    scanf("%d", &size);
    int sum[size];

    for(int i = 0; i < size; i++){
	printf("Enter number: ");
	scanf("%d", &num);
	insert(&head1, num);
    }

    for(int i = 0; i < size; i++){
	printf("Enter number: ");
	scanf("%d", &num);
	insert(&head2, num);
    }

    add(head1, head2, sum, size);

    for(int i = size - 1; i >= 0; i--){
	printf("%d", sum[i]);
    }
    

    return 0;
}
