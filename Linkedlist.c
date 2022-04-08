#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>

struct node{
    int data;
    struct node *link;
};

void insert(struct node**, int);
void display(struct node *);
void insertbeg(struct node **, int);
void insertmid(struct node **, int, int);
void delete(struct node **, int);
void rev(struct node **);
void assending(struct node **);


int main(){
    
    struct node *ll;
    ll = NULL;

    insert(&ll,2);
    insert(&ll,5);
    insert(&ll,4);
    insertbeg(&ll,100);
    insertmid(&ll,2,16);
    display(ll);
    delete(&ll,5);
    printf("After Delete\n");
    display(ll);
    rev(&ll);
    printf("After Reverse\n");
    display(ll);
    assending(&ll);
    printf("After Assending\n");
    display(ll);
    
    

    
}

void insert(struct node **ll, int a){
    struct node *temp;
    
    if(*ll==NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a;
        temp->link=NULL;

        *ll = temp;
    }
    else{
        struct node *temp = *ll;

        while(temp->link!=NULL){
            temp=temp->link;
        }
        struct node *n;
        n=(struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->link = NULL;
        temp->link = n;

    }
}

void insertbeg(struct node **ll, int a){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->link = *ll;
    *ll = temp;
}

void insertmid(struct node **ll, int pos, int a){
    struct node *temp = *ll;

    while(temp->data!=pos){
        temp = temp->link;
    }
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->link = temp->link;
    temp->link = n;
}

void delete(struct node **ll, int a){
    struct node *temp = *ll;
    struct node *previous;

    while(temp->data!=a){
        previous = temp;
        temp = temp->link;
    }
    previous->link = temp->link;
    free(temp);
}

void rev(struct node **ll){
    struct node *temp = *ll;
    struct node *p = NULL, *n;

    while(temp!=NULL){
        n = temp->link;
        temp->link = p;
        p = temp;
        temp = n;
    }
    *ll = p;
}

void assending(struct node **ll){
    struct node *temp = *ll;
    struct node *ptr; 
    int t;
    

    while (temp->link!=NULL)
    {
        ptr = temp->link;
        while (ptr!=NULL)
        {
            if (temp->data > ptr->data)
            {  
                t = temp->data;
                temp->data = ptr->data;
                ptr->data = t;
            }
            ptr = ptr->link;
            
        } 
        temp = temp->link;     
    }
   
}


void display(struct node *ll){
    struct node *temp = ll;

    while (temp!=NULL)
    {
        printf("%d", temp->data);
        temp = temp->link;
        printf("\n");
    }  
    printf("\n\n");
}
