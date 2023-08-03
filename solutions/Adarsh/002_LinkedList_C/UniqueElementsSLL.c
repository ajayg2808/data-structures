/* Accept only unique elements for SLL*/
#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

struct node* root = NULL;

int append(void);
void display(void);

void main(){
   
   int choice;
   int value;

   while(1){
    printf("\n\n");
    printf("Unique Single Linked List Operation : \n");
    printf("1.Append\n");
    printf("2.Display\n");
    printf("3.Quit\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1: value = append();
                if(value == 0){
                    printf("\nDuplicate value present,please enter unique element");
                }
                else{
                    printf("\nElement added to the List");
                }
                break;
        case 2: display();
                break;
        case 3: exit(1);
                break;
        default: printf("Invalid choice \n");
    }
   }
}

int append(){
  
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));

  printf("Enter node data: ");
  scanf("%d", &temp->data);
  temp->link = NULL;

  if(root == NULL){
    root = temp;
    return 1;
  }
  else{
    struct node* p;
    p = root;

    while(p->link != NULL){
        if(p->data == temp->data){
            return 0;
        }
        p = p->link;
    }
    if(p->data == temp->data){
            return 0;
    }
    p->link = temp;
    return 1;
  }
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
