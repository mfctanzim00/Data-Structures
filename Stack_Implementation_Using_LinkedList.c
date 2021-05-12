#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack
{
    Node rear;
} Stack;


Node* getNewNode(int value)
{
    Node* newNode=(struct Stack*)malloc(sizeof(struct Stack));
    newNode->data=value;
    newNode->prev=newNode->next=NULL;

    return newNode;
}

int isEmpty(struct Stack** stack)
{
    return ((*stack)==NULL);
}

void push(struct Stack** rear, struct Node* currentNode)
{
    struct Node* temp = (*rear);
    if(temp!=NULL)
    {
        (temp)->next=currentNode;
         currentNode->prev=temp;
    }
     (*rear)=currentNode;
}

void Print(struct Stack** stack)
{
    struct Node* temp = (*stack);
	if(temp==NULL) return;

	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

struct Node* Search(struct Stack** rear, int key)
{
    struct Node* temp=(*rear);
    while(temp!=NULL)
    {
        if(temp->data==key)
            return temp;
        temp=temp->prev;
    }
    return temp;
}

void pop(struct Stack** stack)
{
    struct Node* temp=(*stack);
    if(temp==NULL)
    {
        Print("Nothing To Pop. Please Insert First!\n");
        return;
    }
    printf("Popped Element = %d\n", temp->data);
    temp=temp->prev;
    (*stack)=temp;
}

struct Node* Top(struct Stack** stack)
{
    struct Node* temp=(*stack);
    if(temp==NULL)return NULL;

    return temp;
}

struct Node* maximum(struct Stack** stack)
{
    struct Node* answer;
    struct Node* temp=(*stack);

    if((*stack)==NULL)
        return NULL;

    answer=(*stack);
    while(temp!=NULL)
    {
        if(temp->data>answer->data)
            answer=temp;
        temp=temp->prev;
    }
    return answer;
}

struct Node* minimum(struct Stack** stack)
{
    struct Node* answer;
    struct Node* temp=(*stack);

    if((*stack)==NULL)
        return NULL;

    answer=(*stack);
    while(temp!=NULL)
    {
        if(temp->data<answer->data)
            answer=temp;
        temp=temp->prev;
    }
    return answer;
}

int Size(struct Stack** stack)
{
    struct Node* temp=(*stack);
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->prev;
    }
    return count;
}

struct Node* Successor(struct Stack** rear, struct Node* currentNode)
{
    struct Node* temp=(*rear);
    struct Node* answer=NULL;

    if(currentNode==NULL)
        return answer;
    while(temp!=NULL)
    {
        if(answer==NULL)
        {
            if(temp->data > currentNode->data)
                answer=temp;
        }
        else if((answer->data > temp->data) && (temp->data > currentNode->data))
            answer=temp;
        temp=temp->prev;
    }
    return answer;
}

struct Node* Predecessor(struct Stack** rear, struct Node* currentNode)
{
    struct Node* temp=(*rear);
    struct Node* answer=NULL;

    if(currentNode==NULL)
        return answer;
    while(temp!=NULL)
    {
        if(answer==NULL)
        {
            if(temp->data < currentNode->data)
                answer=temp;
        }
        else if((answer->data < temp->data) && (temp->data < currentNode->data))
            answer=temp;
        temp=temp->prev;
    }
    return answer;
}

int main()
{
    struct Stack* stack=NULL;

    if(isEmpty(&stack))
        printf("Stack List is Empty!\n");

    push(&stack, getNewNode(7));
    push(&stack, getNewNode(5));
    push(&stack, getNewNode(9));
    push(&stack, getNewNode(11));
    push(&stack, getNewNode(15));

    //stack=NULL;
    if(isEmpty(&stack))
         printf("Stack List is Empty!\n");
    else
    {
        printf("Current List in The stack : ");
        Print(&stack);
        printf("Current stack size is %d\n", Size(&stack));
    }

    if(isEmpty(&stack)==0)
        printf("Top Element of The stack is %d\n", Top(&stack)->data);

    if(isEmpty(&stack))
        printf("Stack List is Empty\n");
    else
        printf("Maximum & Minimum Value in stack is %d and %d respectively\n", maximum(&stack)->data, minimum(&stack)->data);


    if(isEmpty(&stack)==0)
    {
        struct Node* successor = Successor(&stack, Search(&stack, 9));
        struct Node* predecessor = Predecessor(&stack, Search(&stack, 9));
        printf("Successor and Predecessor of the node with key 9 in the stack is ");
        if(successor==NULL)
            printf("NULL ");
        else
            printf("%d ",successor->data);
        printf("and ");
        if(predecessor==NULL)
            printf("NULL ");
        else
            printf("%d ", predecessor->data);
        printf("respectively\n");
    }
    pop(&stack);
    pop(&stack);

    if(isEmpty(&stack))
         printf("Stack list is Empty!\n");
    else
    {
        printf("Current List in The stack : ");
        Print(&stack);
        printf("Current stack size is %d\n", Size(&stack));
    }

    return 0;
}
