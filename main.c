
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct Stack{
	int ele[MAX];
	int top1;
	int top2;
}stack;
int id;
void initialize(stack *s);

void push1(stack *s,int item);
void push2(stack *s,char item);

int pop1(stack *s);
char pop2(stack *s);

int isFull(stack *s);
int isEmpty(stack *s);

void display1(stack *s);
void display2(stack *s);

int main(){
	
	stack s;
	int e1,p1,ch;
    char e2,p2;
    
	initialize(&s);

do
{
	printf("\n\n\n1.Push\n\n");
	printf("\n\n\n2.pop\n\n");
	printf("\n\n\n3.Display Stack\n\n");
	printf("\nEnter you choice\n");
	scanf("%d",&ch);
	if(ch<4){
		printf("\nEnter 1 for integer stack and enter 2 for character stack");
		scanf("%d",&id);
	}
	switch(ch){
		case 1:
			
			
			
			if(id==1)
			{
		     printf("\nEnter element to be pushed\n");
			scanf("%d",&e1);
			 push1(&s,e1);
	     	}
			 else {
			 printf("\nEnter element to be pushed\n");
			 scanf("\n%c",&e2);
			 push2(&s,e2);
	      	}
			 break;
		case 2:
			
			 if(id==1)
			 p1=pop1(&s);
			 else
			 p2=pop2(&s);
			 if(p1!=-1||p2!='$')
			    {
				  if(id==1)
			         printf("\n\nElement popped is %d",p1);
			     else 
			     printf("\n\nElement popped is %c",p2);
			 }
			   break;  
	    case 3:
	    	if(id==1)
	    	 display1(&s);
	    	 
	    	else
	    	   display2(&s);
	    	break;   
	    case 4:
	    	  printf("\nyou exit\n");
	    	  exit(0);
	    default:
	    	 printf("\nWrong choice\n");
	}
	
}while(1);
}
void initialize(stack *s){
	s->top1=-1;
	s->top2=MAX;
}
void push1(stack *s,int item){
	if(isFull(s)){
	printf("\nStack overflow......\n");	
	}
	else{
		s->top1++;
		s->ele[s->top1]=item;
		printf("\nThe element %d is pushed \n",item);
	}
}

void push2(stack *s,char item){
	if(isFull(s)){
      printf("\nStack overflow\n");
	}
	else{
		s->top2--;
		s->ele[s->top2]=item;
		printf("\nThe element %c is pushed \n",item);
	}
}

int pop1(stack *s){
	int item;
	if(isEmpty(s)){
	printf("\nStack Underflow......\n");
	return -1;
		
	}
	else{
	item=s->ele[s->top1];
	s->top1--;
	return item;
	}
}
char pop2(stack *s){
	char item;
	if(isEmpty(s)){
	printf("\nStack Underflow......\n");
	return '$';
		
	}
	else{
	item=s->ele[s->top2];
	s->top2++;
	return item;
	}
}
int isFull(stack *s)
{
	if(s->top1!= s->top2-1)
	{
		return 0;
	}
	else{
		return 1;
	}
}
int isEmpty(stack *s)
{
	if(id==1)
	     if(s->top1==-1){
	     	return 1;
		 }
    else if(id==2){
    	
    	if(s->top2==MAX)
    	 return 1;
	}
	return 0;
}
void display1(stack *s){
	int i;
	
	printf("\element of stack 1 are\n");
	for(i=s->top1;i>-1;i--){
		printf("%d ",s->ele[i]);
	}
}

void display2(stack *s){
	int i;
	printf("\nElement of stack 2 are\n");
	for(i=s->top2;i<MAX;i++){
		printf("\n%c",s->ele[i]);
	}
}



