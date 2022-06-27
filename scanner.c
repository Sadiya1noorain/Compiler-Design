#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char ch;
    FILE *fptr;
    int len = 1;
    char word;
    char buff[10];
    int token = 0;

    char *KeyList[] = {"int", "main", "stdio.h", "include", "string", "float", "printf", "scanf", "while", "if", "for"};
    char *OpList[] = {"+", "-", "*", "!=", "=", "==", "<", ">", "."};
    char *SymbList[] = {"(", ")", ",", ";", "#", "{", "}", "%", "&"};

    fptr = fopen("scanner.txt", "r");
    if (fptr  == NULL) {
        printf("Error! File cannot be opened.");
        exit(1);
    }

   printf("TokenNo.\tLine\tLexeme\tToken\n");
    
    while((ch = fgetc(fptr)) != EOF){
        int f = 0;
        word = fscanf(fptr, "%s", buff);
        token++;
        for(int i = 0; i < 11; i++){
            if(strcmp(KeyList[i], buff) == 0){
                printf("%d\t\t%d\t%s\tKeyWord\n", token, len, buff);
                f = 1;
            }
            
            
        }

        for(int i = 0; i < 9; i++){
            if(strcmp(OpList[i], buff) == 0)
                printf("%d\t\t%d\t%s\tOperator\n", token, len, buff);   
            else if(strcmp(SymbList[i], buff) == 0)
                printf("%d\t\t%d\t%s\tSymbol\n", token, len, buff);
        }
        if(ch == '\n')
            len++;
        if(isnumber(buff[0]))
            printf("%d\t\t%d\t%s\tConstant\n", token, len, buff);
        if(isalpha(buff[0]) && f == 0)
            printf("%d\t\t%d\t%s\tVariable\n", token, len, buff);
        

    }
    
    
    printf("\n");
    fclose(fptr);
    

    return 0;
}


