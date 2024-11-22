#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack * ptr, int value)
{
    if (isFull(ptr))
    {
        cout<<"Stack Overflow! Cannot push "<<value<< " value from the stack"<<endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        cout<<"Stack Underflow! Cannot pop from the stack"<<endl;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main ()
{
    struct stack *sp = (struct stack *) malloc (sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int *) malloc (sp->size*sizeof(int));

    cout <<"Before pushing, Full : "<<isFull(sp)<<endl;
    cout <<"Before pushing, Empty : "<<isEmpty(sp)<<endl;
    isFull(sp);

    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
    // push(sp,9); // stack Overflow

    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    cout<<"Poped element : "<<pop(sp)<<endl;
    // cout<<"Poped element : "<<pop(sp)<<endl; // stack Underflow

    cout <<"After pushing, Full : "<<isFull(sp)<<endl;
    cout <<"After pushing, Empty : "<<isEmpty(sp)<<endl;
    return 0;
}