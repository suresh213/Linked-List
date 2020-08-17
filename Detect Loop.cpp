#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};
struct Node *head=NULL;

void insert(Node** head, int value){
	Node* newnode = new Node(); 
    newnode->data = value; 
    newnode->next = *head; 
    *head = newnode; 
}

int detectloop(Node *head){
	struct Node *slow=head,*fast=head;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			return 1;
		}
	}
	return 0;
}

int main(){
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	
	head->next->next->next=head;
	
	detectloop(head)?cout<<"Found":cout<<"Not Found";
}
