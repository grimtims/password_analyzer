#ifndef PASSWORD_CHECKER
#define PASSWORD_CHECKER

#define DEBUG

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

#define TRUE	1
#define FALSE	0

int passwordStrengthCheck(char * password);

#endif