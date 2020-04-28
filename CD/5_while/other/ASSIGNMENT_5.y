%{
#include<stdio.h>
void yyerror(char * );
int yylex(void);
%}


%token INTEGER WHILE RELOP LOGOP IDENT AROP
%left LOGOP
%left RELOP
%left AROP



%%

S:
	WHILE '(' cond ')' '\n' '{' '\n' stmt '}' '\n' { printf("perfect while loop\n"); }
	;
	
cond:
	cond LOGOP cond
	| expr RELOP expr
	| expr
	|
	;
	
stmt:
	IDENT '=' expr ';' '\n' stmt
	|
	;
	
expr:
	INTEGER
	| IDENT
	| expr AROP expr
	| '(' expr ')'
	;
	
%%

	
void yyerror(char * s)
{
	fprintf(stderr, "%s\n", s);
}

int main()
{
	yyparse();
	return 1;
}
