Project 1: Tokenizer
====================

This program requests input from the user. The user has options to enter a
string that will be tokenized and added to list that stores previously entered
strings. Or to request the string at position i of the list.

The program tokenizes strings by, counting the number of words in the user given string
and allocating enough space to store pointers for those words. Then uses
pointer arithmetic to find the start and end of each word so that word may be
copied into new allocated memory and stored as a token.

Each time a word is tokenized, its appended to a simpled linked list. The
linked list is used so that the user could see what strings were previously
entered into the tokenizer.

NOTE: History starts at index 0
