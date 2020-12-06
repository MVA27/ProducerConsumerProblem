#include<stdio.h>
#include<conio.h>
#define BUFFER_SIZE 5

int n = BUFFER_SIZE;
int buffer[10],producerIndex = 0,consumerIndex = 0, full = 0,empty = BUFFER_SIZE, s=1;
int x = 0;


void wait(int *value){ 
	*value = *value - 1;
}

void signal(int *value){ 
	*value = *value + 1;
}

void producer()
{
	if(full == BUFFER_SIZE)
	{
		printf("\nBUFFER OVERFLOW..!! CANNOT PRODUCE ANYMORE \n");
		return;
	}

	if(s == 1)
	{
		wait(&s);				
		wait(&empty);			

		printf("\nENTER AN ELEMENT : ");
		scanf("%d",&x);
		buffer[producerIndex] = x;
		printf("\nPRODUCER PRODUCED : %d \n",buffer[producerIndex]);
		producerIndex = (producerIndex + 1) % n;

		signal(&full);	 
		signal(&s);		 

	}
}

void consumer()
{
	if(empty == BUFFER_SIZE)
	{
		printf("\nBUFFER UNDERFLOW..!! CANNOT CONSUME ANYTHING \n");
		return;
	}
	if(s == 1)
	{
		wait(&s);	
		wait(&full);


		printf("\nCONSUMER CONSUMED : %d \n",buffer[consumerIndex]);
		buffer[consumerIndex] = 0;
		consumerIndex = (consumerIndex + 1) % n;

		signal(&empty);	
		signal(&s);	
	}
}

void main()
{
	int choice;
	
	do{
		printf("\nENTER 1 TO PRODUCE : ");
		printf("\nENTER 2 TO CONSUME : ");
		printf("\nENTER 3 TO EXIT : ");
		printf("\nINPUT : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				producer();
				break;

			case 2:
				consumer();
				break;

			case 3:
				break;

			default:
				printf("\nYOU HAVE ENTERED A WORNK INPUT ");
				break;
		}
	}while(choice!=3);
}
