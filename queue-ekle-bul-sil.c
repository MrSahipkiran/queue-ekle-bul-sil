#include <stdio.h>
#include <stdlib.h>
	struct node{
		int data;
		struct node *next;
	};
	struct node *front=NULL;
	struct node *rear= NULL;
	
	
	int enqueue(int x){
		if(front == NULL){//this shows list is empty
			struct node *new=(struct node*)malloc(sizeof(struct node));
			new -> data = x;
			new -> next = NULL;
			front = rear = new;
			printf("\nThe number was added successfully.\t");
		}
		
		else{			//this shows list isn't empty
			struct node *new=(struct node*)malloc(sizeof(struct node));
			new -> data = x;
			new -> next = NULL;
			rear -> next = new;
			rear = new;
			printf("\nThe number was added successfully.");
		}
	}
	
	int dequeue(){//this only delete
		struct node *temp;
		temp = front;
		front = front ->next;
		free(temp);
	}
	
	int searchDelete(){
		struct node *temp=front;
		struct node *previous=front;
		printf("which do you want to search and delete the number	");
		int x;
		scanf("%d",&x);

		while(temp!=NULL){
			if(temp->data==x){
				printf("the number(%d) was founded in %x ,and it was deleted\n",temp->data,temp);
				previous -> next = temp -> next ;
				free(temp);
				break;
			}
			else{
				previous=temp;
				temp = temp -> next;
			}
		}
		return 1;
	}

	int searchDisplay(){
		struct node *temp=front;
		int x;
		printf("which do you want to search the number	");
		scanf("%d",&x);
		while(temp!=NULL){
			if(temp->data==x){
				printf("\nthe number(%d) was founded in %x\n",x,temp);
				break;
			}
			else{
				temp = temp -> next;
			}
		}
		return 1;
	}

	int display(){
		struct node *temp=front;
		while(temp != NULL){
		printf("the number(%d)is in %x \n",temp->data,temp);
		temp=temp->next;
		}
	}
	
	
	
	
	
int main(int argc, char *argv[]) {
	int number=0;
	while(1){
		printf("could you enter the number which want to add to list , -1 for exit\\t");
		scanf("%d",&number);
		if(number==-1)break;
		enqueue(number);
	}
	while(1){
		printf("\n1 for display\t2 for search and display\t3for search and delete \t -1 for exit\t");
		scanf("%d",&number);
		if(number == -1 ) break;
		switch(number){
			case 1:
				display();
				break;
			case 2:
				searchDisplay();
				break;
			case 3:
				searchDelete();
				break;
		}
		
	}
	return 0;
}
