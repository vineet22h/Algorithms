#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
	int top;
	int capacity;
	int* array;
};
struct stack *createStack(int capacity)
{
	struct stack *s = malloc(sizeof(struct stack));
	if(!s)
	{
	    printf("memory error");
    }
    s->capacity = capacity;
    s->top = -1;
    s->array = malloc(s->capacity*sizeof(int));
    return s;
}
void reSize(struct stack *s)
{
	s->capacity = s->capacity*2;
	realloc(s->array,s->capacity*sizeof(int));
}
int isFull(struct stack *s)
{
	return s->top == s->capacity;
}
int isEmpty(struct stack *s)
{
	return s->top == -1;
}
void push(struct stack *s,int data)
{
	if(isFull(s))
	{
	    printf("full");
    } 
	s->array[++s->top]=data;
}
int pop(struct stack *s)
{
	if(isEmpty(s))
	{
		printf("stack is empty");
		return 0;
	}
	return s->array[s->top--];
}
int peek(struct stack *s)
{
    if(isEmpty(s))
        return -1;
    return s->array[s->top];
} 
int isOperand(char c)
{
    if((c >= 'A' && c<= 'Z') || (c >='a' && c <= 'z'))
        return 1;
    return 0;
}
int Prec(char c)
{
    switch(c)
    {
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default:return 0;
    }
}
void infix_Postfix(struct stack *s,char *st)
{
    char *out = malloc(sizeof(char)*strlen(st));
    int k = -1;
    for(int i=0;i<strlen(st);i++)
    {
        if(isOperand(st[i]))
            out[++k] = st[i];
        else if(st[i] == '(') 
            push(s,st[i]);
        else if(st[i] == ')')
        {
            while (!isEmpty(s) && peek(s) != '(') 
                out[++k] = pop(s); 
            if (!isEmpty(s) && peek(s) != '(') 
                return -1; // invalid expression              
            else
                pop(s); 
        }
        else
        {
             while (!isEmpty(s) && Prec(st[i]) <= Prec(peek(s))) 
                out[++k] = pop(s); 
            push(s,st[i]); 
        }
        
    }
    while (!isEmpty(s)) 
        out[++k] = pop(s ); 
  
    out[++k] = '\0'; 
    printf( "%s", out ); 
   
}
void main()
{
    char *st =  "a+b*(c^d-e)^(f+g*h)-i";
   	struct stack *s = createStack(strlen(st));
   	infix_Postfix(s,st);
}