/*
Parser: Parses a given Cpp input file according to the subset of grammar taken, to check for compile time errors
*/

#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<cstdlib>

using namespace std;

FILE* fp=NULL;
char *token=NULL;

int linenum=0;      //Global Line variable to record where the 1st compiler error occurred

int check(char *str)
{
	if(strncmp(str,token,strlen(str))==0)
        {
            printf("Matched: %s\n",str);
            fgets(token,200,fp); linenum ++; return 0;
        }

    else
    return 1;

}

int Program();
int Declarations();
int Datatype();
int IdentifierList1();
int IdentifierList2();
int StatementList();
int Statement();
int Assignstat();
int Expn();
int Eprime();
int Simpleexpn();
int Seprime();
int Term();
int Tprime();
int Factor();
int Decisionstat();
int Mulop();
int Addop();
int Dprime();
int Relop();
int Loopingstat();

int Datatype()
{
	return ( check("int") &&
			 check("char")
			);
}

int IdentifierList2()
{
    return ( (check(",") || IdentifierList1()) &&
             (check ("[") || check("NUM:") || check("]") || check(",") || IdentifierList1()) &&
             (check("[") || check("NUM:") || check("]")) &&
              0
            );
}

int IdentifierList1()
{
	return ( check("ID:") ||
             IdentifierList2()
            );
}

int Mulop()
{
    return ( check("*") &&
             check("/") &&
             check("%")
            );
}

int Addop()
{
    return ( check("+") &&
             check("-")
            );
}

int Relop()
{
    return ( check("==") &&
             check("!=") &&
             check("<=") &&
             check(">=") &&
             check(">") &&
             check("<")
            );
}

int Expn()
{
    return ( Simpleexpn() ||
             Eprime()
            );
}

int Dprime()
{
    return ( (check("else") ||
             StatementList()) &&
             0
            );
}

int Decisionstat()
{
    return ( check("if") ||
             check("(") ||
             Expn() ||
             check(")") ||
             StatementList() ||
             Dprime()
            );
}

int Factor()
{
    return ( check("ID:") &&
             check("NUM:")
            );
}

int Tprime()
{
    return ( (Mulop() ||
             Factor() ||
             Tprime()) &&
             0
            );
}

int Term()
{
    return ( Factor() ||
             Tprime()
            );
}

int Seprime()
{
    return ((Addop() ||
             Term() ||
             Seprime()) &&
             0
            );
}

int Simpleexpn()
{
    return ( Term() ||
             Seprime()
            );
}

int Eprime()
{
    return ( (Relop() ||
             Simpleexpn()) &&
             0
            );
}

int Assignstat()
{
    return ( check("ID:") ||
             check("=") ||
             Expn()
            );
}

int Statement()
{
    return ( Assignstat() &&
             Decisionstat() &&
             Loopingstat()
            );
}

int StatementList()
{
	return( ( Statement() ||
		  check(";") ||
		  StatementList() )
		  &&
		  0);
}

int Declarations()
{
	return( (Datatype() ||
		IdentifierList1() ||
		check(";") ||
		Declarations() )
		&&
		0
		);
}

int Loopingstat()
{
    return ( (check("while") ||
             check("(") ||
             Expn() ||
             check(")") ||
              check("{") ||
             StatementList() ||
              check("}"))
                &&
             (check("for") ||
              check("(") ||
              Assignstat() ||
              check(";") ||
              Expn() ||
              check(";") ||
              Assignstat() ||
              check(")") ||
              check("{") ||
              StatementList() ||
              check("}")
              )
            );
}

int Program()
{
	return
	   (check("int") ||
	   check("ID:main") ||
	   check("(") || check(")") ||
	   check("{") ||
	   Declarations() ||
	   StatementList() ||
	   check("return") ||
	   check("NUM:0") ||
	   check(";") ||
       check("}")
	   );
}

int main()
{
	fp = fopen("output.txt","r");
	int res=-1;

	token = (char *) malloc (200*sizeof(char));
    memset(token,'\0',sizeof(token));

	fgets(token,200,fp);

	res = Program();

	if (res==0)
        {printf("\nProgram successfully Parsed\n");}

    else
        {printf("Error Encountered around Line: %d",linenum);}

	fclose(fp);

	return 0;
}
