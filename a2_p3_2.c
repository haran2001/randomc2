//implementing stack using linked list

#include<stdio.h>
#include<stdlib.h>

//structure for stack node using linked list
struct lifo {
	int value;
	struct lifo *next;
};

typedef struct lifo stack;

stack *top;

//initialize a stack
void create(stack **top){
	*top = NULL;
}

//push operation
void push(stack **top, int element){
	stack *new;
	new = (stack*)malloc(sizeof(struct lifo));
	if(new == NULL){
		printf("Stack overflow\n");
		exit(-1);
	}

	else{
		new->value = element;
		new->next  = (*top);
		*top = new;
	}
}

//pop operation
int pop(stack **top){
	int t;
	stack *p;
	if(*top == NULL){
		// printf("hello\n");
		printf("Stack is Empty\n");
		exit(-1);
	}

	else{
		t = (*top)->value;
		//p is used to store the address of top beforehand so that it can accessed for deletion/free pointer(top) later
		p = *top; 		
		(*top) = (*top)->next;
		free(p);
		return t;
	}
}

//check if stack is empty
int isEmpty(stack **top){
	if(*top == NULL)
		return 1;
	else
		return 0;
}


//main function
int main(){
	stack **top, **ptr;
	int del;
	top = (stack**)malloc(sizeof(struct lifo*));
	create(top);

	//some test cases
	push(top, 1);
	push(top, 2);
	push(top, 3);

	printf("%d %d %d\n", pop(top), pop(top), pop(top));
	return 0;
}