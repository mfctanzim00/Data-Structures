#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Queue
{
    Node head;
} Queue;


Node* getNewNode(int value)
{
    Node* newNode=(struct Queue*)malloc(sizeof(struct Queue));
    newNode->data=value;
    newNode->prev=newNode->next=NULL;

    return newNode;
}

int isEmpty(struct Queue** queue)
{
    return ((*queue)==NULL);
}

void push(struct Queue** head, struct Node* currentNode)
{
    struct Node* temp = (*head);
    if(temp==NULL)
    {
        (*head) = currentNode;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = currentNode;
    currentNode->prev = temp;
}

void Print(struct Queue** queue)
{
    struct Node* temp = (*queue);
    if(temp == NULL)
        return;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* Search(struct Queue** head, int key)
{
    struct Node* temp=(*head);
    while(temp!=NULL)
    {
        if(temp->data==key)
            return temp;
        temp=temp->next;
    }
    return temp;
}

void pop(struct Queue** queue)
{
    struct Node* temp=(*queue);
    if(temp==NULL)
    {
        Print("Nothing To Pop. Please Insert First!\n");
        return;
    }
    printf("Popped Element = %d\n", temp->data);
    temp=temp->next;
    (*queue)=temp;
}

struct Node* Front(struct Queue** queue)
{
    struct Node* temp=(*queue);
    if(temp==NULL)return NULL;

    return temp;
}

struct Node* maximum(struct Queue** queue)
{
    struct Node* answer;
    struct Node* temp=(*queue);

    if((*queue)==NULL)
        return NULL;

    answer=(*queue);
    while(temp!=NULL)
    {
        if(temp->data>answer->data)
            answer=temp;
        temp=temp->next;
    }
    return answer;
}

struct Node* minimum(struct Queue** queue)
{
    struct Node* answer;
    struct Node* temp=(*queue);

    if((*queue)==NULL)
        return NULL;

    answer=(*queue);
    while(temp!=NULL)
    {
        if(temp->data<answer->data)
            answer=temp;
        temp=temp->next;
    }
    return answer;
}

int Size(struct Queue** queue)
{
    struct Node* temp=(*queue);
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

struct Node* Successor(struct Queue** head, struct Node* currentNode)
{
    struct Node* temp=(*head);
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
        temp=temp->next;
    }
    return answer;
}

struct Node* Predecessor(struct Queue** head, struct Node* currentNode)
{
    struct Node* temp=(*head);
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
        temp=temp->next;
    }
    return answer;
}

int main()
{
    struct Queue* queue=NULL;

    if(isEmpty(&queue))
        printf("Queue List is Empty!\n");

    push(&queue, getNewNode(7));
    push(&queue, getNewNode(5));
    push(&queue, getNewNode(9));
    push(&queue, getNewNode(11));
    push(&queue, getNewNode(15));

    //queue=NULL;
    if(isEmpty(&queue))
         printf("Queue List is Empty!\n");
    else
    {
        printf("Current List in The Queue : ");
        Print(&queue);
        printf("Current Queue size is %d\n", Size(&queue));
    }

    if(isEmpty(&queue)==0)
        printf("Front Element of The Queue is %d\n", Front(&queue)->data);

    if(isEmpty(&queue))
        printf("Queue List is Empty\n");
    else
        printf("Maximum & Minimum Value in Queue is %d and %d respectively\n", maximum(&queue)->data, minimum(&queue)->data);


    if(isEmpty(&queue)==0)
    {
        struct Node* successor = Successor(&queue, Search(&queue, 9));     ///Immediate Greater than 9
        struct Node* predecessor = Predecessor(&queue, Search(&queue, 9));   ///Immediate smaller than 9
        printf("Successor and Predecessor of the node with key 9 in the Queue is ");
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
    pop(&queue);
    pop(&queue);

    if(isEmpty(&queue))
         printf("Queue List is Empty!\n");
    else
    {
        printf("Current List in The Queue : ");
        Print(&queue);
        printf("Current Queue size is %d\n", Size(&queue));
    }

    return 0;
}
