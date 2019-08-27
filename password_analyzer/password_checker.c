#include <stdio.h>
#include <string.h>
#include "password_checker.h"

const char * password_strength[] = {
    "[ not good ] - No Password",
    "[||--------] 20 % - Very Weak", 
    "[||||------] 40 % - Weak",
    "[||||||----] 60 % - Fair", 
    "[||||||||--] 80 % - Strong",
    "[||||||||||] 100 % - Very Strong"
};
                                        
const char special_character[] = {
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '?',
    '_',
    '~',
    '-',
    '(',
    ')'
};


int passwordStrengthCheck(char * password){

	unsigned int i,j;
	int score = 0;

	int containsUpperCase = FALSE;
	int containsLowerCase = FALSE;
	int containsNumbers = FALSE;
	int containsSpecial = FALSE;
	int passLong = FALSE;
	int passMed = FALSE;
	
	
	
	D(printf("\n\n\t****** PASSWORD CHECKER ******\n\n\n"));
    
    D(printf("\tPassword: %s\n\n\n", password));



	for(i=0;i<strlen(password);i++){

		D(printf("\tpassword[%d] = %c", i, password[i]));

		if( password[i] >= 'A' && password[i] <= 'Z'){          // UPPER CASE
			D(printf("  ---  Upper Case\n"));
			containsUpperCase = TRUE;
		}

		if( password[i] >= 'a' && password[i] <= 'z'){          // LOWER CASE
            D(printf("  ---  Lower Case\n"));
            containsLowerCase = TRUE;
        }

		if( password[i] >= '0' && password[i] <= '9'){          // NUMBER
            D(printf("  ---  number\n"));
            containsNumbers = TRUE;
        }

		
        for( j = 0 ; j < strlen(special_character) ; j++ ){     // SPECIAL CHARACTER
            if(password[i] == special_character[j]){
                D(printf("  ---  is a special character\n"));
                containsSpecial = TRUE;
            }
        }	


	}	


	if(strlen(password) >= 8)
		passMed = TRUE;
	if(strlen(password) >= 12)
		passLong = TRUE;

	D(printf("\n\n\tLength        : %d\n", (int)strlen(password)));
	D(printf("\tUpper Case    : %d\n", containsUpperCase));
    D(printf("\tLower Case    : %d\n", containsLowerCase));
	D(printf("\tNumber        : %d\n", containsNumbers));
	D(printf("\tSpecial       : %d\n", containsSpecial));
	D(printf("\t> 8 chars     : %d\n", passMed));
	D(printf("\t> 12 chars    : %d\n", passLong));

	if(containsUpperCase && containsLowerCase){
		score++;
	}

	score += containsNumbers + containsSpecial + passMed + passLong;

	D(printf("\n\n\tScore = %d\n", score));

#ifdef DEBUG
	printf("\n\tPassword Strength : %s\n\n", password_strength[score]);
#else
	printf("%s", password_strength[score]);
#endif

	return score;

}
