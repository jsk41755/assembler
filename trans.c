#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");
	
	char *src;
	char *dst;
	src = strtok(args, ",");
	dst = strtok(NULL, ",");
	
	if(src[0] == '%'){
		if(dst[0] == '%')
			printf("89\n");
	}//1.reg to reg
	
	else if(src[0] == '(' && src[ strlen(src)-1] ==')'){
		if(dst[0] == '%')
			printf("8b\n");
	}//2.mem to reg
	
	else if(src[0] == '0'){
		if(dst[0] == '%')
			printf("a1\n");
	}//4.mem to reg(eax)
	
	else if(src[0] == '%'){
		if(isxdigit(dst) == 1)
			printf("a3\n");
	}//5.reg(eax) to mem

	else if(src[0] == '$'){
		if(strcmp(dst == "%eax") == 0)
			printf("B8\n");
		
		else if(strcmp(dst == "%ecx") == 0)
			printf("B9\n");
		
		else if(strcmp(dst == "%edx") == 0)
			printf("BA\n");

		else if(strcmp(dst == "%ebx") == 0)
			printf("BB\n");

		else if(strcmp(dst == "%esp") == 0)
			printf("BC\n");	
		
		else if(strcmp(dst == "%ebp") == 0)
			printf("BD\n");
	
		else if(strcmp(dst == "%esi") == 0)
			printf("BE\n");

		else if(strcmp(dst == "%edi") == 0)
			printf("BF\n");
		}	
	
	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	return 1;	
}
