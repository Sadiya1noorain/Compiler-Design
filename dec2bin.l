
%{
int dec = 0, bin = 0, r = 0, p = 1, num = 0;
%}
%%
[0-9]* {
    dec = atoi(yytext);
    num = dec;
    while(dec != 0){
        r = dec%2;
        bin = bin + r*p;
        p = p*10;
        dec = dec/2;
    }
}
\n {

printf("The binary form of %d is %d\n", num, bin);
return 0;
}

%%
int main(){
printf("Enter the number:");
yylex();
return 0;
}

int yywrap(){
    return 1;
}