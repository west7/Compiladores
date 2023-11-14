#include <stdio.h>
#include <string.h>
#include <ctype.h>


int scanner(char str[]){


    return x; 
}

int main(){
    
    char str[100];
    scanf("%s", str);
    int x = 0, n = strlen(str);
    for(int i=0; i < n; i++){

        if(str[i] < '0' || str[i] > '4') 
            break;

        x = x * 5 + (str[i] - '0');
    } 

    return x; 
}

int main(){
    
    char str[100];
    scanf("%s", str);
    
    int n = scanner(str);
    printf("%d\n", n);
    
    return 0;
}