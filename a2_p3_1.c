//implementing stack using array
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//structure for stack using array 
struct lifo{
	int st[MAX_SIZE];
	int top;
};

typedef struct lifo stack;

//initialize top to -1
void create(stack *s){
	s->top = -1;
}

//add element to top
void push(stack *s, int element){
	if(s->top == (MAX_SIZE-1)){
		printf("Stack overflow\n");
		exit(0);
	}

	else{
		s->top++;
		s->st[s->top] = element;
	}
}

//remove element from top
int pop(stack *s){
	if(s->top == -1){
		printf("The stack is empty\n");
		exit(0);
	}

	else{
		return (s->st[s->top--]);
	}
}

//check for empty stack
int isEmpty(stack *s){
	if(s->top == -1)
		return 1;
	else
		return 0;
}

//check for stack overflow
int isFull(stack *s){
	if(s->top == (MAX_SIZE-1))
		return 1;
	else 
		return 0;
}

//main function
int main(){
	stack *s = (stack*)malloc(sizeof(struct lifo));
	create(s);
	int del = 0;
	
	printf("Is it Empty : %d\n", isEmpty(s));
	printf("Is it Full : %d\n", isFull(s));
	
	//some test cases
	push(s, 1);
	push(s, 2);
	push(s, 3);
	
	for(int i=0; i<3; i++){
		printf("%d\n", s->st[i]);
	}
	
	for(int i=0; i<3; i++){
		del = pop(s);
		printf("%d\n", del);
	}
	
	printf("Is it Empty : %d\n", isEmpty(s));
	printf("Is it Full : %d\n", isFull(s));

	return 0;
}