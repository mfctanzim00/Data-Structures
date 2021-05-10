#include<stdio.h>
#include<stdlib.h>

struct List{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct List* getNewNode(int value)
{
    struct List* newNode=(struct List*)malloc(sizeof(struct List));
    newNode->data=value;
    newNode->prev=newNode->next=NULL;

    return newNode;
}

int isEmpty(struct List** head)
{
    return ((*head)==NULL);
}

void insert(struct List** head, int value)
{
    struct List* newNode=getNewNode(value);
    if((*head)!=NULL){
          (*head)->prev=newNode;
          newNode->next=(*head);
    }
    (*head)=newNode;
}

void Print(struct List** head)
{
    printf("Current List : ");
	struct List* temp = (*head);

	while(temp != NULL) {
		  printf("%d ",temp->data);
		  temp = temp->next;
	}
	printf("\n");
}

struct List* Search(struct List** head, int key)
{
    struct List* temp=(*head);
    while(temp!=NULL){
           if(temp->data==key)
                return temp;
           temp=temp->next;
    }
    return temp;
}

struct List* Delete(struct List** head, struct List* NodeToBeDeleted)
{
    struct List* temp=(*head);

    if(temp==NULL || NodeToBeDeleted==NULL)return NULL;

    if(temp->data==NodeToBeDeleted->data){
           (*head)=temp->next;
           return temp;
    }
    temp=NodeToBeDeleted;
    temp=temp->prev;
    temp->next=NodeToBeDeleted->next;

    temp=NodeToBeDeleted;
    return temp;
}

struct List* maximum(struct List** head)
{
    struct List* answer;
    struct List* temp=(*head);

    if((*head)==NULL)
           return NULL;

    answer=(*head);
    while(temp!=NULL){
           if(temp->data>answer->data)
                 answer=temp;
           temp=temp->next;
    }
    return answer;
}

struct List* minimum(struct List** head)
{
    struct List* answer;
    struct List* temp=(*head);

    if((*head)==NULL)
           return NULL;

    answer=(*head);
    while(temp!=NULL){
           if(temp->data<answer->data)
                answer=temp;
           temp=temp->next;
    }
    return answer;
}

struct List* Successor(struct List** head, int key)
{
    struct List* temp=(*head);
    struct List* answer=NULL;

    while(temp!=NULL){
          if(answer==NULL){
                 if(temp->data>key)
                      answer=temp;
          }
          else if((answer->data>temp->data) && (temp->data>key))
                 answer=temp;
          temp=temp->next;
    }
    return answer;
}

struct List* Predecessor(struct List** head, int key)
{
    struct List* temp=(*head);
    struct List* answer=NULL;

    while(temp!=NULL){
          if(answer==NULL){
                 if(temp->data<key)
                      answer=temp;
          }
          else if((answer->data<temp->data) && (temp->data<key))
                 answer=temp;
          temp=temp->next;
    }
    return answer;
}

int main()
{
    struct List* head=NULL;
    insert(&head, 10);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 9);

    Print(&head);

    //head=NULL;

    ///=================== isEmpty =====================
    if(isEmpty(&head))
         printf("List is empty\n");


    ///==================== Search+Delete ====================
    struct List* deletedNode = Delete(&head, Search(&head, 7));

    printf("After deletion of number 7\n");
    Print(&head);


    ///=================== Maximum & Minimum =================
    struct List* max = maximum(&head);
    if(max==NULL)
        printf("Empty List!\n");
    else
        printf("maximum = %d\n", max->data);

    struct List* min= minimum(&head);
    if(min==NULL)
        printf("Empty List!\n");
    else
        printf("minimum = %d\n", min->data);


    ///=================== Successor & Predecessor ============
    struct List* successor = Successor(&head, 6);  ///Immediate Greater than 6
    if(successor==NULL)
        printf("Successor of 6 is NULL\n");
    else
        printf("Successor of 6 is %d\n", successor->data);


    struct List* predecessor = Predecessor(&head, 6);  ///Immediate smaller than 6
    if(predecessor==NULL)
        printf("Predecessor of 6 is NULL\n");
    else
        printf("Predecessor of 6 is %d\n", predecessor->data);

}
