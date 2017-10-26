#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
	Node first = newNode(1);
    Node second = newNode(5);
    Node third = newNode(4);
    Node fourth = newNode(9);
    
	first -> next = second;
    second -> next = third;
    first -> next -> next = third;
    first -> next -> next -> next = fourth;
    first -> next -> next -> next -> next = NULL;
    
    List list = calloc(1, sizeof(struct _list));
    list -> head = first;

    Node first1 = newNode(11);
    Node second1 = newNode(13);
    Node third1 = newNode(15);
    Node fourth1 = newNode(17);
    
	first1 -> next = second1;
    second1 -> next = third1;
    first1 -> next -> next = third1;
    first1 -> next -> next -> next = fourth1;
    first1 -> next -> next -> next -> next = NULL;
	List list1 = calloc(1, sizeof(struct _list));
	list1 -> head = first1;


	orderedDelete (list);

    listPrint(list);
    // listPrint(list1);
    



	return 0;
}