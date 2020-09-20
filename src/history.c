#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
}

void add_history(List *list, char *str)
{
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  char *inStr = copy_str(str,i+1);
  Item *item = malloc(sizeof(Item));
  Item *temp = list->root;

  item->str = inStr;
  item->next = NULL;
  int count = 0;

  if(list->root == NULL){
    item->id = count;
    list->root = item;
  }
  else{
    count = 1;
    while(temp->next != NULL){
      count++;
      temp = temp ->next;
    }
    temp->next = item;
    item->id = count;
  }
}
char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

void print_history(List *list)
{
  Item *temp = list->root;
  printf("\n");
  while(temp != NULL){
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
  printf("\n");
}

void free_history(List *list)
{
  Item *temp;
  while(list->root != NULL){
    temp = list->root;
    list->root = list->root->next;
    free(temp);
  }
  free(list);
}
