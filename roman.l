%{
    int total = 0;
%}

WS [ \t]+
%%
int total = 0;
I total+=1; 
IV total+=4; 
V total+=5; 
IX total+=9; 
X total+=10; 
XL total+=40; 
\n return total; 
{WS} |

%%

int main(){ 
    int first,second; 
    first = yylex(); 
    second = yylex();

    printf("%d + %d = %d\n",first,second - first,second); 
    return 0;
}

int yywrap(void){ 
    return 1;
}
