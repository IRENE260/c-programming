using array
#include <stdio.h>
#define MAX 100
int queue[MAX], head = -1, tail = -1;

void push(int data)
{
    if (tail == MAX - 1)
        printf("\nQueue overflow");
    else if(tail == -1)
    {
    	head = 0;
    	tail  = 0;
    	queue[tail] = data;
    }
    else
		queue[++tail] = data;
}

void pop()
{
    int del;
    if (head == -1)
        printf("\nQueue is empty");
    else if(head == tail)
    {
    	printf("\n%d popped", queue[head]);
    	head = -1;
    	tail  = -1;
    }
    else
    {
        del = queue[head++];
        printf("\n%d popped", del);
    }
}

void display()
{
    if (head== -1)
        printf("\nQueue is empty");
    else
    {
        printf("Queue elements: ");
        for (int i = head; i <= tail; i++)
        {
            printf("%d  ", queue[i]);
        }
    }
}

int main()
{
    int ch, element;
    printf("\nOperations are:-");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display");
    printf("\n4.Exit");
    do
    {
        printf("\n____________________\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            push(element);
            printf("Value pushed");
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    } while (ch !=4);

    return 0;
}
output:
operation are:
1.push
2.pop
3.display
4.exit
Enter your choice:1
Enter element to insert :3
value pushed
Enter your choice:2
poped
Enter your choice:3 
Queue is empty
Enter your choice:4
################################################################################################################################################################################
using linked:
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *head = NULL, *tail = NULL;
struct node *newNode;
struct node* temp;

struct node* createNode(int data)
{
    newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("error");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}

void push(int data)
{
    newNode = createNode(data);
    if(tail == NULL)
    {
		head = newNode;
		tail  = newNode;
    }
    else
    {
		head->next = newNode;
		tail = newNode;
    }
    printf("%d pushed", data);
}

void pop()
{
    if(head == NULL)
    {
        printf("\n Queue Empty");
    }
    else
    {
    	printf("%d popped", head->data);
    	temp = head;
    	head = head->next;
    	free(temp);
    	if(head == NULL)
    		tail = NULL;
    }
}

void display()  
{  
    int i;  
    temp=head;  
    if(temp == NULL)  
    {  
        printf("Queue  is empty\n");  
    }  
    else  
    {   
        printf("Queue elements: ");  
        while(temp!=NULL)  
        {  
            printf(" %d  ",temp->data);  
            temp = temp->next;  
        }  
    }  
}    

int main()
{
    int choice;
    int data;
    printf("-\n1: push\n2: pop\n3: display\n4: exit");  
        
    do
    {
        printf("\n____________________\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}
output:
1.push
2.pop
3.display.
4.exit
Enter your choice :
1
Enter value :2
2 pushed
Enter your choice :3
Queue elements :2
Enter your choice :4
