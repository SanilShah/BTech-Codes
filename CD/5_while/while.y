%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
int yylex();
void yyerror(const char *s);
%}



%token ID NUM WHILE LE GE EQ NE OR AND
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'

%%
S        : ST1 {printf("Input accepted.\n");exit(0);};
ST1    :    WHILE'(' E2 ')' '{' ST '}'
ST      :     ST ST
          | E';'
          ;
E       : ID'='E
          | E'+'E
          | E'-'E
          | E'*'E
          | E'/'E
          | E'<'E
          | E'>'E
          | E LE E
          | E GE E
          | E EQ E
          | E NE E
          | E OR E
          | E AND E
          | ID
          | NUM
          ;
E2     : E'<'E
          | E'>'E
          | E LE E
          | E GE E
          | E EQ E
          | E NE E
          | E OR E
          | E AND E
          | ID
          | NUM
          ;

%%

#include "lex.yy.c"

void yyerror(char const *s)
{
    fprintf(stderr,"%s\n",s);
}

int yywrap()
{
    return(1);
}

int main()
{
   printf("Expression: \n");
   yyparse();
}

