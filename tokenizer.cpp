/*
Tokenizer - Given a Cpp program, it tokenizes the input into:
1) Keyword
2) Relational Operator
3) Logical Operator
4) Math Operator
5) Special Symbol
6) Identifier
*/

#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<cstdlib>

#define KEYNUM 15
#define RELNUM 6
#define LOGNUM 3
#define SSNUM 9
#define MATHNUM 6
#define TOKENNUM 6

using namespace std;

//Keyword List
char keyword[KEYNUM][10]={"if",
                          "else",
                          "for",
                          "while",
                          "do",
                          "return",
                          "int",
                          "char",
                          "float",
                          "double",
                          "void",
                          "break",
                          "continue",
                          "const",
                          "goto"};

//RelOp List
char relop [RELNUM][3] = {"<=",
                          ">=",
                          "==",
                          "!=",
                          "<",
                          ">"};
//LogOp List
char logop [LOGNUM][3] = {"&&",
                          "||",
                          "!"};

//MathOP List
char mathop [MATHNUM][3] = {"++",
                          "--",
                          "+",
                          "-",
                          "*",
                          "/"};
//Special Symbol List
char ss[SSNUM][2] = {";",
                     "=",
                     ",",
                     "(",
                     ")",
                     "[",
                     "]",
                     "{",
                     "}"};

void trim(char *&s)
{
    while(s[0]==' '|| s[0]=='\t' || s[0]=='\n')
    s++;
}

void WriteFile(char *str, FILE *fp)
{
	fputs(str,fp);
	fputc('\n',fp);
}

void shiftString(char *&ptr, int len)
{
	ptr+=len;
	trim(ptr);
}

int  check(FILE *fp2, char *line)
{
	//static char c1[] = "\t\t\tKeyword\n";

	for(int i=0;i<KEYNUM;i++)
	{
		if(strncmp(line,keyword[i],strlen(keyword[i]))==0)
		{
			if(isalnum(line[strlen(keyword[i])]))			//To check if the found Keyword is not an ID instead
			continue;

		    printf("\nFound KEYWORD: %s\n",keyword[i]);
			WriteFile(keyword[i],fp2);
			return strlen(keyword[i]);
		}
	}

	//static char c2[] = "\t\t\tRELOP\n";

	for(int i=0;i<RELNUM;i++)
	{
		if(strncmp(line,relop[i],strlen(relop[i]))==0)
		{
			printf("\nFound: RELOP: %s\n",relop[i]);
			WriteFile(relop[i],fp2);
			return strlen(relop[i]);
		}
	}

	//static char c3[] = "\t\t\tLOGOP\n";

	for(int i=0;i<LOGNUM;i++)
	{
		if(strncmp(line,logop[i],strlen(logop[i]))==0)
		{
			printf("\nFound: LOGOP: %s\n",logop[i]);
			WriteFile(logop[i],fp2);
			return strlen(logop[i]);
		}
	}

	//static char c4[] = "\t\t\tMATHOP\n";

	for(int i=0;i<MATHNUM;i++)
	{
		if(strncmp(line,mathop[i],strlen(mathop[i]))==0)
		{
			printf("\nFound: MATHOP: %s\n",mathop[i]);
			WriteFile(mathop[i],fp2);
			return strlen(mathop[i]);
		}
	}

	//static char c5[] = "\t\t\tSpecial Symbol\n";

	for(int i=0;i<SSNUM;i++)
	{
		if(strncmp(line,ss[i],strlen(ss[i]))==0)
		{
			printf("\nFound: SS: %s\n",ss[i]);
			WriteFile(ss[i],fp2);
			return strlen(ss[i]);
		}
	}
	return 0;
}

int checkID(FILE *fp, char *&line)
{
	char temp[50]={'\0'};
	int i=0;

	if(line[0]=='\"')		//String Literal
	{
		line++;

		while(line[i]!='\"')
		temp[i]=line[i++];

		printf("\nFound: String Literal: \"%s\"\n",temp);
		WriteFile(temp,fp);
		return strlen(temp)+1;
	}

	if(isdigit(line[0]))		//Number Literal
	{
		int i=0;

		while(isdigit(line[i]))
		temp[i]=line[i++];

		printf("\nFound: Number Literal: %s\n",temp);
		fputs("NUM:",fp);
		WriteFile(temp,fp);
		return strlen(temp);
	}

	if(line[0]=='\'')		//Character Literal
	{
		char c = line[1];

		printf("\nFound: Character Literal: %c\n",c);
		putc(c,fp);
		putc('\n',fp);
		//fputs("\t\t\tCharacter Literal\n",fp);
		return 3;	//3 for 'c'
	}
	return 0;
}

int installID(FILE *fp, char *&ptr)
{
    char temp[32]={'\0'};

    if(isalpha(ptr[0]) || ptr[0]=='_')
    {
        int i=1;
        temp[0]=ptr[0];

        while(isalnum(ptr[i]) || ptr[i]=='[' || ptr[i]==']')		//Normal IDs and 1-D Arrays
            temp[i]=ptr[i++];

        printf("\nFound: ID: \"%s\"\n",temp);

        fputs("ID:",fp);

		WriteFile(temp,fp);
		return strlen(temp);
    }
    return 0;
}

int tokenize(FILE *fp, char *&ptr)
{
	trim(ptr);
	printf("\n~~~~Current:%s\n",ptr);
	int len;

	while(ptr[0]!='\0')
	{
		if((len=check(fp,ptr))!=0)
		{
			shiftString(ptr,len);
			continue;
		}

		else if((len=checkID(fp,ptr))!=0)
		{
			shiftString(ptr,len);
			continue;
		}

		else if((len=installID(fp,ptr))!=0)
		{
		    shiftString(ptr,len);
		    continue;
		}
		else
            ptr++;
	}
}

int main()
{
  	FILE* fp1,*fp2;
  	char *ptr,*str;

  	fp1 = fopen("sample1.c","r");
	fp2 = fopen("output.txt","w+");

    ptr = (char *) malloc (200*sizeof(char));
    memset(ptr,'\0',sizeof(ptr));

	while(fgets(ptr,200,fp1)!=NULL)
	{
		str=ptr;

		tokenize(fp2,ptr);

    	memset(str,'\0',sizeof(str));
	}

	fclose(fp1);
	fclose(fp2);

    return 0;
}
