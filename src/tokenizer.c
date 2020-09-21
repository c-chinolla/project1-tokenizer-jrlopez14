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
  word = word_start(word);   // If given word starts with empty space, remove empty space.
  int i = 0;
  while(non_space_char(word[i])) i++; // Moves through string until space character is found.
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
  char *outStr = malloc( (len + 1)  * sizeof(char)); // Allocates the right amount of space
  int i = 0;
  while( i <= len){
    outStr[i] = inStr[i]; // Assigns the ith position of new string the value of the ith
    i++;                 // value of incoming string.
  }
  return outStr;
}

char **tokenize(char *str)
{
  int i;
  int numWords = count_words(str);    // Allocates a char pointer for each word in string + 1 
  char **tokens = malloc( (numWords+1) * sizeof(char *) );
  char *start_of_word = word_start(str); // Start of first word
  char *end_of_word = word_terminator(str); // End of first word
  
  for(i = 0; i < numWords; i++){  // Uses pointer arithmetic to find length of word
    tokens[i] = copy_str(start_of_word,end_of_word-start_of_word); 
    start_of_word = word_start(end_of_word); // Gets start of next word
    end_of_word = word_terminator(start_of_word); // Gets end of next word
  }
  tokens[i] = NULL; // Sets last pointer to null;
  return tokens;
}
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){ // Loops through tokens until NULL
    printf("%s\n", tokens[i]); // prints each token;
    i++;
  }
}
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){ // Loops through tokens until NULL
    free(tokens[i]); // frees the allocated memory of the string pointed to by tokens[i]
    i++;
  }
  free(tokens); // free the allocated memory for the pointers
}
