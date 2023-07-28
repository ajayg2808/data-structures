/* Single linked list operations */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;
int len;

void append(void);
void addatafter(void);
int length(void);
void display(void);
void delete(void);

void main(){

    int choice;

    while(1){
        printf(" Single Linked List Operations : \n");
        printf("1.Append\n");
        printf("2.AddAtAfter\n");
        printf("3.Length\n");
        printf("4.Display\n");
        printf("5.Delete\n");
        printf("6.Quit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1: append();
                    break;
            case 2: addatafter();
                    break;
            case 3: len = length();
                    printf("Length is = %d\n",len);
                    break;
            case 4: display();
                    break;
            case 5: delete();
                    break;
            case 6: exit(1);
                    break;
            default: printf(" Invalid choice \n");
        }
    }

}

void append(){

   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));

   printf("Enter node data: ");
   scanf("%d", &temp->data);
   temp->link = NULL;

   if(root == NULL){ //List is empty
      
      root = temp;  //holds first node address
   }
   else{
      struct node* p;
      p = root;

      while(p->link != NULL){
        p = p -> link;
      }

      p -> link = temp;
   }

}

int length(){

    int count = 0;
    struct node* temp;
    temp = root;

    while(temp != NULL){
    count++;
    temp = temp->link;
    }

    return count;
}

void display(){

    struct node* temp;
    temp = root;

    if(temp == NULL){
        printf("List is empty \n\n");
    }
    else{
        printf("----------------------------------------------------------------------------\n");
        while(temp != NULL){
            printf("[Node_Address = %d] -- \t[Node_Data = %d --> Node_Link = %d]\n",temp,temp->data,temp->link);
            temp = temp->link;
        }
        printf("----------------------------------------------------------------------------");
        printf("\n\n");
    }
}

void addatafter(){

    struct node* temp;
    struct node* p;
    int loc;
    int i = 1;
    int len = length();

    printf("Enter the location to add after");
    scanf("%d", &loc);

    if(loc > len){
        printf(" Invalid location....\nCurrently list having %d nodes",len);
    }
    else{
       p = root;
       while(i < loc){
        p = p -> link;
        i++;
       }
       temp = (struct node*)malloc(sizeof(struct node));
       printf("Enter node data: ");
       scanf("%d", &temp->data);
       temp->link = NULL;

       temp -> link = p -> link;  //Right side connection
       p -> link = temp;          //Left side connection

    }

}

void delete(){

    struct node* temp;
    int loc;
    printf("Enter the location to delete");
    scanf("%d",&loc);

    if(loc > length()){
        printf("Data not present at this location");
    }
    else if( loc == 1){
        temp = root;
        root = temp -> link;
        temp -> link = NULL;
        free(temp);  
    }
    else{
        struct node* p;    // node before delete node
        struct node* q;    // Node to delete
        p = root;
        int i = 1;

        while(i < loc-1){
            p = p -> link;
            i++;
        }
        q = p -> link;            // Here q node points to delete node
        p -> link = q -> link;    
        q -> link = NULL;
        free(q);        
    }

}
