# CParser
A parser and tokenizer for a subset of C language, written as a part of undergraduate course on language processor

The purpose of the 2 files (tokenizer and parser) was to write a Mini C compiler based on the following subset of C language:


Data Types : int, char
Arrays : 1-dimensional
Expressions : Arithmetic and Relational
Looping statements : for, while
Decision statements : if, if – else
Program - main () { declarations statement-list }
declarations -> data-type identifier-list; declarations | Null
data-type -> int | char
identifier-list -> id | id, identifier-list | id[number] , identifier-list | id[number]
statement_list -> statement ; statement_list | Null
statement -> assign-stat | decision_stat | looping-stat
assign_stat -> id = expn
expn -> simple-expn eprime
eprime -> relop simple-expn| Null
simple-exp -> term seprime
seprime -> addop term seprime | Null
term -> factor tprime
tprime -> mulop factor tprime | Null
factor -> id | num
decision-stat -> if ( expn ) stat dprime
dprime -> else stat | Null
looping-stat -> while (expn) stat | for (assign_stat ; expn ; assign_stat ) stat
relop -> = = | != | <= | >=| > | <
addop -> + | -
mulop -> *| / | %


1) tokenizer.cpp first takes the input file to generate "output.txt", which is a tokenized form of the input.
2) parser.cpp then reads "output.txt" to determine if the program is syntactically correct or not based on the stated Grammar
