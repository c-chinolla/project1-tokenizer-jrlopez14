Project 1: Tokenizer
====================

This program requests an input string from the user, based on the contents of
this string, the program may react differently. There are several key phrases
the user may enter such as "exit", "history", or "!n" that have their own
unique response. However, if these are entered, the string will be tokenized
and added to a list that contains all the previously tokenized strings. The
"exit" string will terminate the program. "history" will print all the
previously tokenized strings. And, "!n" will print the nth string in the history. 

The program tokenizes strings by, counting the number of words in the user given string
and allocating enough space to store pointers for those words. Then uses
pointer arithmetic to find the start and end of each word so that word may be
copied into new allocated memory and stored as a token.

Each time a word is tokenized, its appended to a simpled linked list. The
linked list is used so that the user could see what strings were previously
entered into the tokenizer.

NOTE: History starts at index 0
