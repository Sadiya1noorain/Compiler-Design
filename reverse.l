%{
int num = 0,r=0,s=0;
%}
%%
[0-9]* {
num = atoi(yytext);
while(num!=0){
r = num%10;
s = s*10 + r;
num = num/10;
}

}
\n {

printf("The reverse number %d\n",s);
}

%%
int main(){
printf("Enter a number\n");
yylex();
return 0;
}
int yywrap(){
    return 1;
}