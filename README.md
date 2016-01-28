# CParser
A parser and tokenizer for a subset of C language, written as a part of undergraduate course on language processor <br />
 <br />
The purpose of the 2 files (tokenizer and parser) was to write a Mini C compiler based on the following subset of C language: <br />
 <br />
1) Data Types : int, char  <br />
2) Arrays : 1-dimensional  <br />
3) Expressions : Arithmetic and Relational <br />
4) Looping statements : for, while <br />
5) Decision statements : if, if – else <br />
6) Program - main () { declarations statement-list } <br />
7) declarations -> data-type identifier-list; declarations | Null <br />
8) data-type -> int | char <br />
9) identifier-list -> id | id, identifier-list | id[number] , identifier-list | id[number] <br />
10) statement_list -> statement ; statement_list | Null <br />
11) statement -> assign-stat | decision_stat | looping-stat <br />
12) assign_stat -> id = expn <br />
13) expn -> simple-expn eprime <br />
14) eprime -> relop simple-expn| Null <br />
15) simple-exp -> term seprime <br />
16) seprime -> addop term seprime | Null <br />
17) term -> factor tprime <br />
18) tprime -> mulop factor tprime | Null <br />
19) factor -> id | num <br />
20) decision-stat -> if ( expn ) stat dprime <br />
21) dprime -> else stat | Null <br />
22) looping-stat -> while (expn) stat | for (assign_stat ; expn ; assign_stat ) stat <br />
23) relop -> = = | != | <= | >=| > | < <br />
24) addop -> + | - <br />
25) mulop -> *| / | % <br />
<br />
<br />
1) tokenizer.cpp first takes the input file (sample1.c) to generate "output.txt", which is a tokenized form of the input. <br />
2) parser.cpp then reads "output.txt" to determine if the program is syntactically correct or not based on the stated Grammar <br />
