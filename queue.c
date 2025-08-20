#include <stdio.h>
#define MAXSIZE 20


int queue[MAXSIZE];
int front=-1;
int rear=-1;

void Enqueue(int value){
    if(rear==MAXSIZE-1){
        printf("Queue Overflow");

    }else{
        front=0;
        rear++;
        queue[rear]=value;
        printf("inserted value %d",value);
    }   
}
void Dequeue(){
    if(front<=rear){
        printf("Value Deleted %d",queue[front]);
        front++;
    }
    else{
       printf("underflow");
       front =-1;

    }
}


int main(){
int choice,value;

while(1){
printf("\nEnter any value\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Exit\n");
	scanf("%d",&choice);
	
	switch(choice){
	case 1:
	printf("Enter the Number of Enqueue: ");
        scanf("%d",&value);
        Enqueue(value);
       	break;
	case 2:
	 Dequeue();
	break;
	case 3:
	printf("Exit program");
	return 0;
	
	default:"Wrong choice";
	}
}
return 0;
}