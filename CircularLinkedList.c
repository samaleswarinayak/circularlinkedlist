/*Write a menu driven program to implement Circular Linked lIst */
#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void insert_begin();
void insert_end();
void insert_afternode();
void insert_location();
void delete_begin();
void delete_end();
void delete_afternode();
void delete_location();

struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
main()
{
	int choice;
	while(1)
	{
		printf("\n0.Exit\n1.Creation \n2.Traverse\n3.Insert at Beginning\n4.Insert at End\n5.Insert After Given Node\n6.Insert at a Specific Location\n7.Delete from Beginning\n8.Delete from End\n9.Delete after Given Node\n10.Delete from a specific location\n");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:exit(0);
			case 1:create();
					break;
			case 2:traverse();
					break;
			case 3:insert_begin();
					break;
			case 4:insert_end();
					break;
			case 5:insert_afternode();
					break;
			case 6:insert_location();
					break;
			case 7:delete_begin();
					break;
			case 8:delete_end();
					break;
			case 9:delete_afternode();
					break;
			case 10:delete_location();
					break;
			default:printf("\nWrong Choice\n");
		}
	}
}
void create()
{
	int total,item,index;
	struct node *newnode,*temp;
	if(start == NULL)
	{
		printf("\nEnter the total number of nodes you want to keep\n");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			printf("\nEnter the value to keep in the node\n");
			scanf("%d",&item);
			temp->info = item;
			temp->next = temp;
			start = temp;
			for(index=2;index<=total;index++)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				printf("\nEnter the value to keep in the node\n");
				scanf("%d",&item);
				newnode->info = item;
				newnode->next = start;
				temp->next = newnode;
				temp = newnode;
			}
			printf("\nList is created\n");
		}
	}
	else
	{
		printf("\nList is already present\n");
	}	
}
void traverse()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		printf("\nValues of list are\n");
		do
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
		while(temp!=start);
		printf("\n");
	}
}
void insert_begin()
{
	struct node *newnode,*temp;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = newnode;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp->next != start)
			{
				temp = temp->next;
			}
			newnode->next = start;
			start = newnode;
			temp->next = newnode;
		}
	}
}
void insert_end()
{
	struct node *temp,*newnode;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = newnode;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp->next != start)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = start;
		}
	}
}
void insert_afternode()
{
	struct node *newnode,*temp;
	int item,value;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = newnode;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			printf("\nEnter the node after which you want to insert\n");
			scanf("%d",&value);
			temp=start;
			do
			{
				temp=temp->next;
			}
			while(temp!=start && temp->info!=value);
			if(temp == start)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				newnode->next = temp->next;
				temp->next = newnode;
			}
		}
	}
}
void insert_location()
{
	struct node *newnode,*ptr,*temp;
	int count=1,loc;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = newnode;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			printf("\nEnter the location at which you want to insert\n");
			scanf("%d",&loc);
			temp=start;
			do
			{
				ptr=temp;
				temp=temp->next;
				count++;
			}
			while(temp!=start && count!=loc);
			if(temp == start)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr->next = newnode;
				newnode->next = temp;
			}
		}
	}			
}
void delete_begin()
{
	struct node *temp,*ptr;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		ptr = start;
		while(ptr->next != start)
		{
			ptr = ptr->next;
		}
		printf("\nDeleted node = %d\n",temp->info);
		start = start->next;
		ptr->next = start;
		free(temp);
	}
}
void delete_end()
{
	struct node *temp,*ptr;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		while(temp->next != start)
		{
			ptr = temp;
			temp = temp->next;
		}
		printf("\nDeleted node = %d\n",temp->info);
		ptr->next = start;
		free(temp);
	}
}
void delete_afternode()
{
	struct node *ptr,*temp;
	int value;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the node after which you want to delete\n");
		scanf("%d",&value);
		temp=start;
		do
		{
			temp=temp->next;
		}
		while(temp!=start && temp->info!=value);
		if(temp == start)
		{
			printf("\nNode is not present\n");
		}
		else
		{
			ptr = temp->next;
			temp->next = ptr->next;
			printf("\nDeleted node = %d\n",ptr->info);
			free(ptr);
		}
	}	
}
void delete_location()
{
	struct node *ptr,*temp;
	int loc,count=1;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the location from which you want to delete\n");
		scanf("%d",&loc);
		temp=start;
		do
		{
			ptr = temp;
			temp = temp->next;
			count++;
		}
		while(temp!=start && count!=loc);
		if(temp == start)
		{
			printf("\nNode is not present\n");
		}
		else
		{
			ptr->next = temp->next;
			printf("\nDeleted node = %d\n",temp->info);
			free(temp);
		}		
	}	
}
