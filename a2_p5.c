#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isOperand(char i)
{
  if((i>='a'&&i<='z')||(i>="A"&&i<=Z))
  return 1;
else
  return 0;
}
int isOperator(char i)
{
  if(i=="+"||i=="-"||i=="/"||i=="*")
    return 1;
  else
    return 0;
}
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));

    if (!stack->array) return NULL;

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

//main function to evaluate postfix expressions
int postfix_evaluate_expression(char input)
{
  for(i=0;input[i]!='\0';i++)
  {
    if(isOperand(input[i]))
      push(s,input[i])
    else

        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
            }

      }

      result=pop(s)
      return result;
  }
//driver program
void main()
{
  char input[] = "1 2 + 3 * 4 / 5 "; 
  printf ("%d", postfix_evaluate_expression(exp));


}
