#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>

struct node {
    int data;
    struct node *link;
};

void insert (struct node **, int);
void display (struct node *);
void merge(struct node *, struct node *, struct node **);


int main(){

    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    insert(&first, 2);
    insert(&first, 7);
    insert(&first, 12);
    printf("First Linkedlist\n");
    display(first);

    insert(&second, 3);
    insert(&second, 8);
    insert(&second, 11);
    printf("Second Linkedlist\n");
    display(second);

    merge(first, second, &third);
    printf("After Merge \n");
    display(third);

    
}

void insert(struct node **ll, int a){
    struct node *temp;

    if (*ll == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a;
        temp->link = NULL;

        *ll = temp;
    }

    else{
        struct node *temp = *ll;

        while(temp->link!=NULL){
            temp = temp->link;

        }

        struct node *n;

        n = (struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->link = NULL;

        temp->link = n;

    }
    
}

void merge (struct node *p, struct node *q, struct node **ll){
    struct node *temp;

    while (p!=NULL && q!=NULL)
    {
        if(*ll == NULL)
        {
            *ll = (struct node *)malloc(sizeof(struct node));
            temp = *ll;
        }
        else
        {
            temp->link = (struct node *)malloc(sizeof(struct node));
            temp=temp->link;
        }

        if(p->data<q->data)
        {
            temp->data = p->data;
            p = p->link;
        }
        else
        {
            if(q->data<p->data)
            {
                temp->data = q->data;
                q = q->link;
            }
            else
            {
                if(p->data == q->data){
                    temp->data = q->data;
                    p = p->link;
                    q = q->link;
                }
            }
        }
    }

    while(p!=NULL){
        temp->link = (struct node *)malloc(sizeof(struct node));
        temp = temp->link;
        temp->data = p->data;
        p = p->link;

    }

    while(q!=NULL){
        temp->link = (struct node *)malloc(sizeof(struct node));
        temp = temp->link;
        temp->data = q->data;
        q = q->link;

    }
    temp->link = NULL; 
}


void display(struct node *ll){

    struct node *temp = ll;

    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp -> link;
    }
    
}

