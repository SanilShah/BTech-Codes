%{
    #include<stdio.h>
    #include<string.h>
 
    char noun[20][20],verb[20][20]; 
    char pronoun[20][20],preposition[20][20];
    int NounFlag=0,VerbFlag=0,PronounFlag=0,PrepositionFlag=0;
    int i=0,j=0,k=0,a=0,b=0;
    int found=0;	
%}

%%
^NOUN {NounFlag = 1;}
^VERB {VerbFlag = 1;}
^PRONOUN {PronounFlag = 1;}
^PREPOSITION {PrepositionFlag = 1;}


"a"|"an"|"the"|"A"|"An"|"The"|"and"  {printf("%s is Article\n",yytext);}
"ball"|"bat"|"toy"|"field"          {printf("%s is Noun\n",yytext);}
"plays"|"keeps"|"throws"   	       {printf("%s is Verb\n",yytext);}
"he"|"she"|"they"     	       {printf("%s is Pronoun\n",yytext);}
"on"|"from"|"before"  	       {printf("%s is Preposition\n",yytext);}

[a-zA-z]*  { found = 0;

   //Search in the array
    if(NounFlag!=1 && VerbFlag!=1 && PronounFlag!=1 && PrepositionFlag!=1)
    {
        //search in noun
        for(k=0 ; k<i ; k++)
        {
            if(strcmp(noun[k],yytext) == 0)
            {
		found = 1;
                printf("%s is Noun\n",yytext);
                break;
            }    
        }
        
        //search in verb
        for(k=0 ; k<j ; k++)
        {
            if(strcmp(verb[k],yytext) == 0)
            {
		found = 1;
                printf("%s is Verb\n",yytext);
                break;
            }    
        }
	
	//Search in pronoun
        for(k=0 ; k<a ; k++)
        {
            if(strcmp(pronoun[k],yytext) == 0)
            {
		found = 1;
                printf("%s is Pronoun\n",yytext);
                break;
            }    
        }
	
	//search in preposition
        for(k=0 ; k<b ; k++)
        {
            if(strcmp(preposition[k],yytext) == 0)
            {
		found = 1;
                printf("%s is preposition\n",yytext);
                break;
            }    
        }
    }
    else if(NounFlag == 1 || VerbFlag == 1 || PronounFlag == 1 || PrepositionFlag == 1)
    {
	found = 1;
        //add in the array
        if(NounFlag == 1)
        {
            strcpy(noun[i++],yytext);
            printf("'%s' is successfully added in Noun\n",yytext);
            //NounFlag = 0;
        }
        else if(VerbFlag == 1)
        {
            strcpy(verb[j++],yytext);
            printf("'%s' is successfully added in Verb\n",yytext);
            //VerbFlag = 0;
        }
	else if(PronounFlag == 1)
	{
	    strcpy(pronoun[a++],yytext);
	    printf("'%s' is successfully added in Pronoun",yytext);		
	    //PronounFlag = 0;	
	}
	else if(PrepositionFlag == 1)
	{
	    strcpy(preposition[b++],yytext);
	    printf("'%s' is successfully added as Preposition",yytext);	
	    //PrepositionFlag = 0;
	}
    }
    if(found == 0)
    {
        printf("'%s' is invalid token\n",yytext);
    }
		
 }

"\n" {

if(NounFlag == 1)
	NounFlag = 0;
else if(VerbFlag == 1)
	VerbFlag = 0;
else if(PronounFlag = 1)
	PronounFlag = 0;
else if(PrepositionFlag = 1)
	PrepositionFlag = 0;
}
%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}

