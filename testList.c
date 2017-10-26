#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
	Node first = newNode(1);
    Node second = newNode(3);
    Node third = newNode(7);
    Node fourth = newNode(87);
    Node temp = calloc(1,sizeof(node));
    
	first -> next = second;
    second -> next = third;
    first -> next -> next = third;
    first -> next -> next -> next = fourth;
    first -> next -> next -> next -> next = NULL;
    
    List list = calloc(1, sizeof(struct _list));
    list -> head = first;

    listPrint(list);
    deleteOdd(list);
    listPrint(list);
	return 0;
}