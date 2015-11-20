#include <stdio.h>
#include <string.h>

char password[100];

void password_set(char * pass){
    if(strlen(pass) <= 100)
        strcpy(password,pass);
    else
        printf("ERROR: Password too large ( <= 100 characters )\n");
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void password_crack_bt(char *a, int l, int r)
{
   int i;
   if (l == r){
     printf("CRACKED! Password is %s\n", a);
     return 0;
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          password_crack_bt(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}

void password_crack(char * password){
    password_set(password);
    int n = strlen(password);
    password_crack_bt(password, 0, n-1);
}
