file = open("code.txt", "r")
keyword = ["int", "if", "while", "void", "main", "for", "do", "else", "char","printf"]
spchar = [",","(",")","{","}","^","%","<",">",">=","<="]
operators = ["+","-","*","/","="]
delimiter = [";"]
linelist = []
lexeme = []
token = []
tokentype =""
linenumber = 0
count = 0
bracketopen=0
lines = file.readlines()
for line in lines:
    linenumber += 1
    line = line.strip()
    #print(str(linenumber) + ":" + line)
    lex = line.split(" ")
    for element in lex:
        linelist.append(linenumber)
        tokentype = "n"
        if element in keyword:
            tokentype = "Keyword"
            #print("Keyword", end =" ")
        elif element in spchar:
            #print("Special Character", end =" ")
            tokentype = "Special Character"
            if element == "{" or element == "(":
                bracketopen+=1;
            elif element == "}" or element == ")":
                bracketopen-=1;
        elif element in operators:
            tokentype = "Operator"
        try:
            isint = int(element)
            #print("type = ", typee)
            tokentype = "Constant"
        except:
            if tokentype == "n":
                if element in delimiter:
                    #print ("Delimiter", end =" ")
                    tokentype = "Delimiter"
                elif '"' in element:
                    tokentype = "String"
                else:
                    #print( "Identifier", end = " ")
                    tokentype = "Identifier"
        lexeme.append(element)
        token.append(tokentype)
        count += 1
if bracketopen>0:
    print('All brackets not closed.')
    exit()
elif bracketopen<0:
    print('Extra "}" or ")" used. ')
    exit()
for i in range(0, count-1):
    print (str(linelist[i]) + "\t:\t", end=" ")
    print (lexeme[i] + "\t:\t", end = " ")
    print (token[i])
