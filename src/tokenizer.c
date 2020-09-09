#includes "tokenizer.h"

int space_char(char c)
{
  if( c == ' ' && c != '0') return 1;
  return 0;
}

int non_space_char(char c)
{
  if( c != ' ' && c != '0') return 1;
  return 0;
}

char *word_start(char *s)
{

}

char *word_terminator(char *word)
{

}

int count_words(char *s)
{

}

