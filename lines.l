%{
    int lineCount = 0;
%}

%%
^(.*)\n printf("%d \t %s", ++lineCount, yytext);
%%

int main(){
    yyin = fopen("scanner.txt", "r");
    yylex();
    printf("\nTotal lines are %d\n", lineCount);
    fclose(yyin);
    return 0;
}
int yywrap(){
    return 1;
}