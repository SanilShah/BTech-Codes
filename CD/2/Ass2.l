%{ 
    /*Definition section */
   int flag=0;
   int counter=1;
%} 
  

%% 
"void"|"int"|"char" {fprintf(yyout,"%d\t%s\t%s\n",counter,yytext,"Keyword");}
"("|")"|"{"|"}"|","|";" {fprintf(yyout,"%d\t%s\t%s\n",counter,yytext,"Delimiter");}
"+"|"=" {fprintf(yyout,"%d\t%s\t%s\n",counter,yytext,"operator");}
[a-zA-Z]([0-9]|[a-zA-Z])* {fprintf(yyout,"%d\t%s\t%s\n",counter,yytext,"Identifier");}
"/*" {flag++;printf("\nFlag is up\n");}
"*/" {flag--;printf("\nFlag is down\n");}
"\n" {counter++;}
. {}
%% 
  
int yywrap()
{
//return 1;
} 
  
// driver code  
int main() 
{ 
  
    extern FILE *yyin,*yyout;
    yyin = fopen("input_ass2.txt", "r"); 
    yyout = fopen("Output.txt", "w"); 
    
    fprintf(yyout,"Line\tLexemes\tToken\n");
    yylex(); 
    yyout = fopen("Error.txt", "w");
    fprintf(yyout,"Comment error");
    return 0; 
} 
