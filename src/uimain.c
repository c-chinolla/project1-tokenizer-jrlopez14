#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcmp
#include <ctype.h>   // for atoi, used to convert string to integer to get an index
#include "tokenizer.h"
#include "history.h"

#define MAX_LENGTH 32 // Max size of string to be given by user

int main()
{
  
  List *history = init_history(); // Initiates history list
  char **tokens, str[MAX_LENGTH], c; // Initializes tokens, str for input from user, and c to
                                     // read input into str 
  int i, index = 0;                  // i for position of str, index to store index for get
                                     // history function.
  
  printf("\tWelcome to the tokenizer!");
  printf("\n--------------------------------------\n");
  printf("Special commands: \"q\" to quit\n");
  printf("                  \"!n\" to get string of item with id:n\n");
  printf("Enter a string to tokenize \n");
  while(strcmp(str,"q") != 0){ 
    printf("\n> ");
    i = 0;
    while( (c = getchar()) != '\n'){  // Stores value of read character into str
      str[i] = c;                     // until enter is pressed
      i++;
    }
    str[i] = '\0';                   // Stores input into str
    if(strcmp(str,"q") == 0){        // If "q" is entered, exit loop
      goto done;
    }
    else if(str[0] == '!'){
      index  = atoi(str+1);          // If string begins with !, get string of item
      printf("%s", get_history(history,index)); // with id of the number that follows !
    }
    else{
      tokens = tokenize(str);  // tokenize the string entered
      print_tokens(tokens);   // prints tokens
      add_history(history,str); // adds str to history of tokenized strings
    }
  }  
 done:
  if(history->root != NULL) free_tokens(tokens);
  printf("\n\tHistory:\n");
  print_history(history); // prints history
  free_history(history);  // frees history  
  return 0;
}
