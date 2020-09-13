#includes "tokenizer.h"

// Returns 1 if c is a space, 0 if non space character
int space_char(char c)
{
  if( c == ' ' && c != '\0') return 1;
  return 0;
}

// Returns 1 if c is a non space character, 0 if space character
int non_space_char(char c)
{
  if( c != ' ' && c != '\0') return 1;
  return 0;
}

// Returns a pointer to the start of the first word in a string.
char *word_start(char *s)
{
  int i = 0;
  while(space_char(s[i]) i++;
  return &s[i];
}

  // Returns a pointer to the end of the given word.
char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(word[i]) i++;
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

