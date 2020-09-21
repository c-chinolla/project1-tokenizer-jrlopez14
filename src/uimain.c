#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_LENGTH 32 // Max size of string to be given by user

int strcmp(char *str1, char *str2);
int str_to_num(char *str);

int main()
{
  printf("%d", strcmp("history", "hello"));
  List *history = init_history(); // Initiates history list
  char **tokens, str[MAX_LENGTH], c; // Initializes tokens, str for input from user, and c to
                                     // read input into str 
  int i, index = 0;                  // i for position of str, index to store index for get
                                     // history function.
  
  printf("\tWelcome to the tokenizer!");
  printf("\n--------------------------------------\n");
  printf("Special commands: \"exit\" to stop\n");
  printf("                  \"history\"\n");
  printf("                  \"!n\" for nth item in history\n");
  printf("Enter a string to tokenize \n");
  while(strcmp(str,"q") != 0){ 
    printf("\n> ");
    i = 0;
    while( (c = getchar()) != '\n'){  // Stores value of read character into str
      str[i] = c;                     // until enter is pressed
      i++;
    }
    str[i] = '\0';                   // Stores input into str
    if(strcmp(str,"exit") == 0){        // If "q" is entered, exit loop
      goto done;
    }
    else if(strcmp("history",str) == 0){
      printf("%d", strcmp("history", str));
      print_history(history);
    }
    else if(str[0] == '!'){
      index  = str_to_num(str+1);          // If string begins with !, get string of item
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
  free_history(history);  // frees history  
  return 0;
}

int strcmp(char *str1, char *str2)
{
  int i;
  for(i = 0; str1[i] == str2[i]; i++){
    if( str1[i] == '\0') return 0;
  }
  return str1[i] - str2[i];
}
int str_to_num(char *str){
  int number = 0;
  int i = 0;
  while(str[i] != '\0'){
    number = number * 10;
    number = number + (str[i]-'0');
    i++;
  }
  return number;
}
