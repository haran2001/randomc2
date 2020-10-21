//infix to postfix notations using stacks

//1) stack implementaion using arrays
//Assumptions:
//1) wihtout fpe(fully parenthesised expression ), precedence of operators considered
//2)^ doesnt apprear in the expression , only */+- operators are used
//contraints :using c language :
//1)cant use the operator ^, need to use pow() from math.h library
//2)stack creation with create(),push(), pop(),isempty(),isfull().

//Referances:
//1)https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
//2)Lectre PPT and DSA applications Sartaj Sahni


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaration of stack
#define MAXSIZE 100//preprocessor directive used , maxsize int cant be declared
//definition of ADT
struct lifo()
{
        char stack[MAXSIZE];//string
        int top;
}
typedef struct  lifo stack;
//declaration of ADT(abstract data type)
stack s;

//creation of stack
void create(stack s*)
{
        s->top=-1;
}
//pushing elements to stack
void push(stack *s,char element)
{
        {       if(s->top==(MAXSIZE-1))
                {       printf("Stack full\n");
                        exit(1);
                }
                else
                {       s->top++;
                        s->stack[s->top]=element;
                }
        }
}
//pop elemensts
int pop(stack *s)
{
        {       if(s->top==-1)
                {
                        printf("\nStack empty");
                        exit(1);
                }
                else
                {
                        return s->stack[--s->top];
                }
}
//peek function (current pointer)
char peek(stack* stack)
{
            return stack->stack[stack->top];
}
//isempty function
int isEmpty(struct Stack* stack)
{
            return stack->top == -1 ;
} int isEmpty(struct Stack* stack)
{
            return stack->top == -1 ;
}
//function to check the precedence of operators
int prec(char ch)
{
            switch (ch)
            {
                    case '+':
                    case '-':
                            return 1;
                    case '*':
                    case '/':
                            return 2;

            }
                return -1;
}

//program to covert infix to postfix using stacks
void infix_postfix(char *in) //in=input expression scanned into string
{
        int i=0,k=-1;
        stack op,temp;
        for(i=0;in[i];i++)
        {
                //if operand , append to output
                if((in[i] >= 'a' && in[i] <= 'z')||(in[i] >= 'A' && in[i] <= 'Z'))
                        push(op,in[i]);
                //if '(' push onto stack
				 if(in[i] == '(')
                        push(temp,'(');
                //if ')'pop and append till '('
                if (in[i] == ')')
                         {
                                 while (!isEmpty(temp) && peek(temp) != '(')
                                  {
                                        in[++k] = pop(temp);
                                        if (!isEmpty(temp) && peek(temp) != '(')
                                        return -1;

                                        else
                                        pop(temp);
                                }

                        }

                // if an operator is encountered check for the precedence of the operator using precedence function
                else
                {
                        while (!isEmpty(temp) && Prec(in[i]) <= Prec(peek(temp)))
                                in[++k] = pop(temp);
                        push(temp, in[i]);

                }
                // pop and append the rest of the stack
                while (!isEmpty(temp))
                {       in[++k] = pop(temp);
                        in[++k] = '\0';
                        printf( "%s", in );
                }

        }
}
//test
void main()
{

}