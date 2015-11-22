#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "password_checker.h"
#include "passcrack.h"

int main(int argc, char **argv)
{
	hello_world();
    
    char*phil = "cupYP6el";
    char*password = "))))))";
    
    passwordStrengthCheck(password);
    password_set(password);
    password_crack();

	return 0;
}
