#include <stdio.h>
#include <string.h>
#include "list.h"
#include "password_checker.h"
#include "passcrack.h"

void backtrack(int length, int digit_pos){
    int i = 0;
    //printf("\t");
    if(length == 0){
        
        printf("\n");
        return 0;
        
    }
    for(i = 0; i < digit_pos; i++){
        //printf("length = %d; i = %d\n",length,i);
        printf("%d",i);
        backtrack(length-1, digit_pos);
    }
}

int main(int argc, char **argv)
{
	hello_world();
    passwordStrengthCheck("123qwe123qwe");
    
    //password_crack("qwe");
    //char str[] = "abcdefghijklmnopqrstuvwxyz";
    //password_set(str);
    //int n = strlen(str);
    //password_crack_bt(str, 0, 4-1);
    
    char str[] = "abc";
    int n = strlen(str);
    backtrack(3,2);


	return 0;
}
