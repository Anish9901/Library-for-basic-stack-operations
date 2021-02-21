#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define size 1000
bool isfull();
bool empty();
struct stack
{
    int *arr; //stack as an array
    int top;  //pointer to the top element of the stack.
};
struct stack *s;

void allocate_stack()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (int *)malloc(size * sizeof(int));
}
/*void allocate_stack_string()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->arr = (char *)malloc(size*sizeof(char));
}*/

//Stack-> = (int*)malloc(size*(sizeof(int)));-------------------->This cannot be done outside a function...(debug).
//Stack top = -1;
void push(int n)
{
    /*if(s->top == -1)//stack empty
    {
        s->top++;
    }*/
    s->top++;
    if (isfull()==1)
    {
        printf("Stack is full!!!\n");
        return;
    }
    s->arr[s->top] = n;
}
void pop()
{
    if (s->top != -1)
    {
        s->top--;
    }
    else
    {
        //printf("No poping can be performed ");
        empty();
    }
}
int top()
{
    return s->arr[s->top];
    //printf("Index of the top element is: %d\n", s->top);
    //printf("Value of top element is: %d\n", s->arr[s->top]);
}
bool empty()
{
    if (s->top == -1)
    {
        //printf("Stack is empty\n");
        return true;
    }
    else
    {
        //printf("Stack is not empty.\n");
        return false;
    }
}
bool isfull()
{
    if (s->top >= size)
    {
        //printf("Stack is full no more pushing\n");
        return true;
    }
    else
    {
        //printf("Stack is not full more pushing can be done");
        return false;
    }
}
void printstack()
{
    int x = s->top;
    while (x != -1)
    {
        printf("%d ", s->arr[x]);
        x--;
        //s->top--;
    }
    if(s->top==-1)
    {
        printf("NULL");
    }
    printf("\n");
}
