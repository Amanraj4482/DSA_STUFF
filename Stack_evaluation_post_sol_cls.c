#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 100
struct Stack
{
	int capacity;
	int top;
	char *arr;
};
struct Stack *createStack(int capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> arr = (char*)malloc(stack->capacity*sizeof(char));
	return stack;
}
int isFull(struct Stack *stack)
{
	return stack->top==stack->capacity-1;
}
int isEmpty(struct Stack *stack)
{
	return stack->top==-1;
}
void push(struct Stack *stack, char val)
{
	if(isFull(stack))
	{
		printf("Stack Overflow\n");
	}
	stack -> arr[++stack -> top] = val;
}
char pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack Undrflow\n");
		return '\0';
	}
	return stack -> arr[stack -> top--];
}
int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is empty\n");
		return 0;
	}
	return stack -> arr[stack->top];
}
int isoperand(char ch)
{
	return isalnum(ch);
}
int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
int infixtopostfix(const char *infix, char *postfix)
{
	struct Stack *stack = createStack(100);
	int i,j=0,k=0,z;
	char ch, x,y;
	for(i=0;infix[i]!='\0';i++)
	{
		ch = infix[i];
		if(isoperand(ch))
		{
			postfix[j++] = ch;
		}
		else if(ch == '(')
		{
			push(stack, ch);
		}
		else if(ch == ')')
		{
			x=pop(stack);
			while(x != '(')
			{
				postfix[j++] = x;
			}
		}
		else
		{
			while(!isEmpty(stack) && precedence(ch)<=precedence(peek(stack)))
			{
				postfix[j++] = pop(stack);
			}
			push(stack,ch);
		}
	}
	while(!isEmpty(stack))
	{
		postfix[j++] = pop(stack);
	}
	postfix[j] = '\0';

}
int evaluatePostfix(char *postfix)
{
	struct Stack *newstack = createStack(N);
	int i,val1,val2,result;
	char ch;
	for(i=0;postfix[i]!='\0';i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			push(newstack,ch-'0');
		}
		else
		{
			val1=pop(newstack);
			val2=pop(newstack);
			switch(ch)
			{
				case '+':
					result=val2+val1;
					break;
				case '-':
					result=val2-val1;
					break;
				case '*':
					result=val2*val1;
					break;
				case '/':
					result=val2/val1;
					break;
				case '%':
					result=val2%val1;
					break;
				case '^':
					result=val2^val1;
					break;
				default :
					printf("Invalid operator\n");
					
			}
			push(newstack,result);
		}
	}
	result = pop(newstack);
	return result;
}
int main()
{
	char infix[N], postfix[N];
	printf("Enter any infix expression :- ");
	fgets(infix,sizeof(infix),stdin);
	infixtopostfix(infix,postfix);
	printf("Postfix = %s\n",postfix);
	
	printf("Solution = %d",evaluatePostfix(postfix));
	return 0;
}
