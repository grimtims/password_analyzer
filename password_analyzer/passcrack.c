#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

char password[100];
char set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
char cracked_password[100];
int64_t poss_comb = 0;
int64_t seq_counter = 0;
int64_t progress_scale = 0;
clock_t begin, end;
double time_spent;


void password_set(char * pass){
    
    if(strlen(pass) <= 100){
        strcpy(password,pass);
        printf("\tPASSWORD SET TO : %s\n\t",password);
        poss_comb = pow(strlen(set),strlen(password));
        progress_scale = 0.05*(poss_comb);
    }else
        printf("ERROR: Password too large ( <= 100 characters )\n");
}

void password_crack_progress(int64_t counter){
    
    if(counter >= progress_scale){
        seq_counter = 0;
        printf(".");
    }    
}

void password_crack_bt( char* set, char* prefix, int digit_pos, int length){
    
    int i = 0;
    if(length == 0){
        seq_counter++;
        password_crack_progress(seq_counter);
        if(!strcmp(prefix,password)){
            printf("\n\tPASSWORD = %s\n", prefix);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\tCracking Time : %f Sec", time_spent);
            while(1);
        }
        return;
        
    }
    
    for(i = 0; i < digit_pos; ++i){
        
        char seq[strlen(prefix)+2];
        strncpy(seq,prefix,strlen(prefix));
        seq[strlen(prefix)] = set[i];
        seq[strlen(prefix)+1] = '\0';
        password_crack_bt(set,seq, digit_pos, length-1);
        
    }
}

void password_crack(){
    if(strlen(password) != 0){
        begin = clock();
        password_crack_bt(set,"",strlen(set),strlen(password));
    }else
        printf("ERROR: Password is not set.");
}

