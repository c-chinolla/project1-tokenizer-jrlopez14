#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_LENGTH 32

int main()
{

  List *history = init_history();
  char **tokens, str[MAX_LENGTH], c;
  int i, index = 0, getHistory = 0;
  printf("\tWelcome to the tokenizer!");
  printf("\n--------------------------------------\n");
  printf("Enter a string to tokenize or \"q\" to quit.\n");
  while(strcmp(str,"q") != 0){
    printf("\n> ");
    i = 0;
    while( (c = getchar()) != '\n'){
      str[i] = c;
      i++;
    }
    str[i] = '\0';
    if(strcmp(str,"q") == 0){
      goto done;
    }
    else if(str[0] == '!'){
      index  = atoi(str+1);
      printf("%s", get_history(history,index));
    }
    else{
      tokens = tokenize(str);
      print_tokens(tokens);
      add_history(history,str);
    }
  }  
 done:

  printf("\n\tHistory:\n");
  print_history(history);
  free_tokens(tokens);
  free_history(history);
  return 0;
}
