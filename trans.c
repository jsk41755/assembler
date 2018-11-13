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
			strcpy(mcode,"89");
	}//1.reg to reg
	
	else if(src[0] == '(' && src[strlen(src)-1] ==')'){
		if(dst[0] == '%')
			strcpy(mcode,"8b");
	}//2.mem to reg

	else if(src[0] == '-' && strchr(src,'(')!=NULL&& 
		src[strlen(src)-1] == ')'){
		if(dst[0] == '%')
			strcpy(mcode,"8b");
	}//3.mem to reg(addressing w/ disp.)

	else if(src[0] == '0'){
		if(dst[0] == '%')
			strcpy(mcode,"a1");
	}//4.mem to reg(eax)
	
	else if(src[0] == '%'){
		if(dst[0] == '0')
			strcpy(mcode,"a3");
	}//5.reg(eax) to mem

	else if(src[0] == '$'){
		if(strcmp(dst,"%eax") == 0)
			strcpy(mcode,"b8");
		
		else if(strcmp(dst,"%ecx") == 0)
			strcpy(mcode,"b9");
		
		else if(strcmp(dst, "%edx") == 0)
			strcpy(mcode,"ba");

		else if(strcmp(dst, "%ebx") == 0)
			strcpy(mcode,"bb");

		else if(strcmp(dst , "%esp") == 0)
			strcpy(mcode,"bc");
		
		else if(strcmp(dst ,"%ebp") == 0)
			strcpy(mcode,"bd");
	
		else if(strcmp(dst, "%esi") == 0)
			strcpy(mcode,"be");

		else if(strcmp(dst, "%edi") == 0)
			strcpy(mcode,"bf");
	}//6.immediate to reg	
	
	return 1;	
}
