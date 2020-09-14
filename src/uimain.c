#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char a[] = " bye bye goodbye";
  char b[] = { ' ','h','e','l','l','o',' ','h','i',' ','h','i','\0'};
  char *c;

  char *start_of_word;
  char *end_of_word;

  printf("\nString: %s", a);
  start_of_word = word_start(a);
  printf("\nStart of the word: %s", start_of_word);
  printf("\nString: %s", a);
  end_of_word = word_terminator(a);
  printf("\nEnd of the word: %s\n", end_of_word);
  printf("\nNumber of words: %d\n", count_words(a));

  printf("\nString: %s", b);
  start_of_word = word_start(b);
  printf("\nStart of the word: %s", start_of_word);
  printf("\nString: %s", b);
  end_of_word = word_terminator(b);
  printf("\nEnd of the word: %s\n", end_of_word);
  printf("\nNumber of words: %d\n", count_words(b));

  c = copy_str(b,13);
  printf("\nCopy Address:%p\t\tOriginal Address: %p\n",c,b);
  printf("Copy String: %s\t\tOriginal String:%s\n",c,b);

  char **tokenz = tokenize(c);

  return 0;
}
