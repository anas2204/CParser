# CParser
A parser and tokenizer for a subset of C language, written as a part of undergraduate course on language processor <br />
 <br />
The purpose of the 2 files (tokenizer and parser) was to write a Mini C compiler based on the following subset of C language: <br />
 <br />
 
- "tokenizer.cpp" first takes the input file "sample1.c" to generate "output.txt", which is a tokenized form of the input. <br />
- "parser.cpp" then reads "output.txt" to determine if the program is syntactically correct or not based on the Grammar defined below

---

<b>Data Types </b>: int, char  <br />
<b>Arrays </b>: 1-dimensional  <br />
<b>Expressions </b>: Arithmetic and Relational <br />
<b>Looping statements </b>: for, while <br />
<b>Decision statements</b> : if, if – else <br />
<br />
Grammar: <br />

- Program -> main () { declarations statement-list } <br />
- declarations -> data-type identifier-list; declarations | Null <br />
- data-type -> int | char <br />
- identifier-list -> id | id, identifier-list | id[number] , identifier-list | id[number] <br />
- statement_list -> statement ; statement_list | Null <br />
- statement -> assign-stat | decision_stat | looping-stat <br />
- assign_stat -> id = expn <br />
- expn -> simple-expn eprime <br />
- eprime -> relop simple-expn| Null <br />
- simple-exp -> term seprime <br />
- seprime -> addop term seprime | Null <br />
- term -> factor tprime <br />
- tprime -> mulop factor tprime | Null <br />
- factor -> id | num <br />
- decision-stat -> if ( expn ) stat dprime <br />
- dprime -> else stat | Null <br />
- looping-stat -> while (expn) stat | for (assign_stat ; expn ; assign_stat ) stat <br />
- relop -> = = | != | <= | >=| > | < <br />
- addop -> + | - <br />
- mulop -> *| / | % <br />
