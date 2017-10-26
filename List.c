#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void listInsertTail (List l, int val)
{
	Node new = calloc(1,sizeof(node));
	new -> value = val;

	Node temp;
	temp = l -> head;

	if (temp == NULL) 
	{
		l -> head = new;
		new -> next = NULL;
	} else {

		while (temp -> next != NULL)
		{
			temp = temp -> next;
		}

		temp -> next = new;
		new -> next = NULL;
	}
}

void listInsertHead (List l, int val)
{
	Node new = calloc (1,sizeof(node));
	new -> value = val;

	l -> head = new;
	new -> next = NULL;
}

void listDeleteHead (List l)
{
	Node temp;

	temp = l -> head;
	if (temp != NULL)
	{
		l -> head = temp -> next;
		free(temp);
	}
}

void listDeleteTail (List l)
{
	Node temp, before;
	temp = l -> head;

	if (temp != NULL)
	{
		if (temp -> next == NULL)
		{
			l -> head = temp -> next;
			free(temp);
		} else {

			while (temp -> next != NULL)
			{
				before = temp;
				temp = temp -> next;
			}

			before -> next = temp -> next;
			free(temp);
		}
	}
}

void listDeleteNth (List l, int n)
{
	Node temp,before;
	temp = l -> head;

	if (temp != NULL)
	{
		if (n == 0)
		{
			l -> head = temp -> next;
			free(temp);
		} else {

			for (int i = 0; i < n; ++i)
			{
				before = temp;
				temp = temp -> next;
			}

			before -> next = temp -> next;
			free(temp);
		}
	}
}

void listInsertNth (List l, int n, int val)
{	
	Node new = calloc (1,sizeof(node));
	new -> value = val;

	Node temp,before;
	temp = l -> head;

	if (temp != NULL)
	{
		if (n == 0)
		{
			new -> next = l -> head;
			l -> head = new;
		} else {

			for (int i = 0; i < n; ++i)
			{
				before = temp;
				temp = temp -> next;
			}

			before -> next = new;
			new -> next = temp;
		}
	} else {

		l -> head = new;
		new -> next = NULL;
	}
}


int listIsOrdered (List l)
{
	Node temp, before;
	int max;

	temp = l -> head;

	if (temp != NULL)
	{
		if (temp -> next == NULL)
		{
			return TRUE;
		} else {

			max = temp -> value;

			while (temp != 	NULL)
			{
				if (temp -> value > max)
				{
					max = temp -> value;
				}
				before = temp;
				temp = temp -> next;
			}
		}
	} else {
		return TRUE;
	}

	if (max > before -> value) {
	    
	    return FALSE;
	} else if (max == before -> value) {
	    
	    return TRUE;
	}

	return FALSE;
}

void orderList(List l) {

	Node temp, after;
	int temp1;

	temp = l -> head;

	while(temp != NULL) {
		
		after = temp -> next;
		while(after != NULL) {
			if(temp -> value > after -> value) {
				temp1 = temp -> value;
				temp -> value = after -> value;
				after -> value = temp1;
			}
			after = after -> next;
		}
		temp = temp -> next;
	}
	
}

int listDeleteContains (List list, int value) {
    
    Node temp, before;
    
    temp = list -> head;
    
    if (temp -> value == value) {
        
        list -> head = temp -> next;
        free (temp);
    } else {
        
        while (temp != NULL) {
            
            if (temp -> value == value) {
            
                before -> next = temp -> next;
                return EXIT_SUCCESS;
            }
            before = temp;
            temp = temp -> next;
        }
    }
    
    return -1;
}

void listDeleteLargest (List l)
{
	int max = listFindLargest(l);

	Node temp,before;
	temp = l -> head;

	if (temp -> value == max)
	{
		l -> head = temp -> next;
		free(temp);
	} else
	{
		while (temp != NULL)
		{
			if (temp -> value == max)
			{
				before -> next = temp -> next;
				free(temp);
				break;
			}

			before = temp;
			temp = temp -> next;
		}
	}	
}

int listFindLargest (List l)
{
	Node temp;

	temp = l -> head;
	int max = temp -> value;

	if (temp != NULL)
	{
		while(temp != NULL) {

			if(temp -> value > max)
			{
				max = temp -> value;
			}
			temp = temp -> next;
		}
	}

	return max;
}

int listLength (List l) {

	int i = 0;
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
	
		return 0;
	} else {
		temp = l -> head;
		while(temp != NULL) {
			i++;
			temp = temp -> next;
		}
	}
	
	return i;
}

int listsIdentical(List first, List second)
{
	Node temp1, temp2;

	temp1 = first -> head;
	temp2 = second -> head;

	int len1, len2;

	len1 = listLength(first);
	len2 = listLength(second);

	if (len1 != len2)
	{
		return FALSE;
	} else {

		while (temp1 != NULL)
		{
			if (temp1 -> value != temp2 -> value)
			{
				return FALSE;
			}

			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
	}
	return TRUE;
}

Node FindTheHead(Node odd) 
{
	Node temp, pBefore;

	temp = odd;

	while(temp -> value % 2 != 0 && temp -> next != NULL)
	{
		pBefore = temp;
		temp = temp -> next;
		free(pBefore);
	}

	if (temp -> next == NULL && temp -> value % 2 != 0)
	{
		return NULL;
	}

	return temp;
}

void deleteOdd (List l)
{
	Node temp, before;

	temp = l -> head;
	temp = FindTheHead(temp);
	l -> head = temp;

	while (temp != NULL)
	{
		if (temp -> value % 2 != 0)
		{
			before -> next = temp -> next;
			free(temp);
			temp = before;
		}
		before = temp;
		temp = temp -> next;
	}

	if (l -> head == NULL)
	{
		printf("%p\n", l -> head);
	}
}

void listConcatenate (List to, List from)
{
	Node temp1, temp2;

	temp1 = to -> head;
	temp2 = from -> head;

	if (temp1 != NULL)
	{
		while (temp1 -> next != NULL)
		{
			temp1 = temp1 -> next;
		}

		temp1 -> next = temp2;
		from -> head = NULL;
	} else {

		to -> head = temp2;
		from -> head = NULL;
	}
}

void orderedDelete (List l)
{
	Node temp, before;

	temp = l -> head;

	while (temp != NULL)
	{
		if (before -> value >= temp -> value)
		{
			before -> next = temp -> next;
			free (temp);
			temp = before;
		}
		
		before = temp;
		temp = temp -> next;
		
	}
}

Node newNode (int value)
{
    Node new = calloc(1, sizeof(struct _node));
    new -> value = value;
    return new;
}

void listPrint (List l) {

	int i = 0;
	Node temp = calloc(1,sizeof(node));
	
	if(l -> head == NULL) {
	
		printf("X");
		
	} else {
	
		temp = l -> head;
		while(temp != NULL) {
		
			printf("%d -> ",temp -> value);
			temp = temp -> next;
		}
		
		printf("X");
	}
	printf("\n");
	
}