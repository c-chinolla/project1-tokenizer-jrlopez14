#include <stdio.h>
#include <stdlib.h>
#include "history.h"


// Initializes list and sets root to NULL;
List *init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

// Adds string to the history list
void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item)); // Allocates memory for a new item.
  Item *temp = list->root; 

  item->str = str; // Sets value to the str field of new item
  item->next = NULL; // Sets value of the next field to NULL
  int count = 0;

  if (list->root == NULL) { // If List is empty new item becomes the root.
    item->id = count;   
    list->root = item;
  } else {             // If list is not empty, traverse through list until next is NULL
    count = 1;
    while (temp->next != NULL) {
      count++;
      temp = temp ->next;
    }                    // Appends Item with correct id
    temp->next = item;
    item->id = count;
  }
}

// Gets the string at position id of linked list
char *get_history(List *list, int id)
{
  Item *temp = list->root; // Starts at root 
  while (temp != NULL) {   // Loops through the contents of list
    if (temp->id == id) {  // until item with the specified id is found
      return temp->str;  // if found, returns the string field of that item 
    }
    temp = temp->next; 
  }
  return NULL; // if id not found, returns NULL
}

// Prints the strings held in history
void print_history(List *list)
{
  Item *temp = list->root; // Starts at root
  printf("\n");
  while (temp != NULL) { // Traverses through contents of list until NULL
    printf("%d: %s\n", temp->id, temp->str); // Prints id and str of that item
    temp = temp->next;
  }
  printf("\n");
}

// Frees the allocated memory of history
void free_history(List *list)
{
  Item *temp;                // temp to store old head
  while (list->root != NULL) { // Traverse through the list by setting
    temp = list->root;       // the root to be the next of current root
    list->root = list->root->next; // new root is the next of current root
    free(temp);              // frees the old root item
  }
  free(list);                // frees the memory allocated for list 
}
