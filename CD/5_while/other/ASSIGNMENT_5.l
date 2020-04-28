%{
#include "y.tab.c"

void yyerror(char *);
%}


digit [0-9]
alpha [a-zA-Z]
other [ "\t"]
delimiter [;{}()]
arop [+\-*/%]
relop "<="|"=="|">="|"!="
rel [<>]
logop "&&"|"||"


%%

"while" 	return WHILE;

{digit}+	return INTEGER;


{alpha}({alpha}|{digit}|"_")*		return IDENT;

{relop} 	return RELOP;
{rel} 		return RELOP;
=			return *yytext;

{logop}		return LOGOP;
{arop}		return AROP;

{delimiter} return *yytext;

"\n"		return *yytext;
{other} {}

.		{yyerror("invalid expression");}

%%

int yywrap()
{
	return 1;
}

