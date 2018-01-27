
#ifndef UTIL_H
#define UTIL_H

union val{
	char character;
	unsigned char u_character;
	int integer;
	unsigned int u_integer;
	long long_int;
	unsigned long u_long_int;
	float float_val;
	double double_val;
	void* pointer; //Child Has To Free This
};


#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#endif /* UTIL_H */

