// Header file for linked lists stuff
// DO NOT CHANGE THIS FILE

// header guard
#ifndef LIST_H_
#define LIST_H_

#define FALSE 0
#define TRUE (!FALSE)

// Node and list structures
// DO NOT CHANGE THIS
typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node head;
} list;

typedef struct _node {
    int value;
    Node next;
} node;

// Warm up activities

Node newNode (int value);
// This function returns the length of a linked list
int listLength (List l);

// This function prints a linked list in the format
// 1 -> 2 -> 3 -> X
void listPrint (List l);

// This function returns the value of the nth item
// in a list
int listGetNth (List l, int n);

// This function returns TRUE if val exists in the list,
// FALSE otherwise
int listContains (List l, int val);

void listInsertHead (List l, int val);
void listInsertTail (List l, int val);
void listDeleteHead (List l);
void listDeleteTail (List l);

// Pair activities
int listIsOrdered (List l);
int listCountFavourite (List l);
int listGetMiddle (List l);
void listInsertNth (List l, int n, int val);
void listDeleteNth (List l, int n);

// Week 12: Oddly Specific Deletion
void deleteOdd (List l);

// Week 13 activities:
int listFindLargest (List l);
void listDeleteLargest (List l);
int listSum (List l);

// int listDeleteContains (List l);
int listsIdentical(List first, List second);
int listDeleteOdd(List list);
void listConcatenate (List to, List from);
void orderedDelete (List l);
void orderList(List l);
Node FindTheHead(Node odd);
int listDeleteContains (List list, int value);



#endif // !defined(LIST_H_)
