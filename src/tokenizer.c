#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

// Returns 1 if c is a space, 0 if non space character
int space_char(char c)
{
  if( (c == '\t' || c == ' ') && c != '\0') return 1;
  return 0;
}

// Returns 1 if c is a non space character, 0 if space character
int non_space_char(char c)
{
  if( (c !=  '\t' && c != ' ') && c != '\0') return 1;
  return 0;
}

// Returns a pointer to the start of the first word in a string.
char *word_start(char *s)
{
  int i = 0;
  while(space_char(s[i])) i++;
  return &s[i];
}

// Returns a pointer to the end of the given word.
char *word_terminator(char *word)
{
  word = word_start(word);
  int i = 0;
  while(non_space_char(word[i])) i++;
  return &word[i];
}

// Returns the number of words within a string
int count_words(char *s)
{
  int i = 0;
  int count = 0;

  // Loops through String counting the times a space character follows a nonspace character.
  while(s != word_terminator(s)){
    s = word_terminator(s);
    count++;
  }
  return count;
}
  
char *copy_str(char *inStr, short len)
{
  char *outStr = malloc(len * sizeof(char));
  int i = 0;
  while( i <= len){
    outStr[i] = inStr[i];
    i++;
  }
  return outStr;
}

char **tokenize(char *str)
{
  int numWords = count_words(str);
  char **tokens = malloc( (numWords+1) * sizeof(char *) );

  char * start_of_word = word_start(str);
  char * end_of_word = word_terminator(str);
  int i;
  for(i = 0; i < numWords; i++){
    //printf("\ni: %d",i);
    //printf("\n\nWord: %s",start_of_word);
    //printf("\tLength: %ld",end_of_word-start_of_word);
    tokens[i] = copy_str(start_of_word,end_of_word-start_of_word);
    //printf("\nCopied String: %s", tokens[i]);

    start_of_word = word_start(end_of_word);
    end_of_word = word_terminator(start_of_word);
    //printf("\nRemaining String: %s", start_of_word);
  }
  tokens[i] = NULL;
  return tokens;
}
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    printf("%s\n", tokens[i]);
    i++;
  }
}
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
