#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	char *src;
        char *dst;
        src = strtok(args, ",");
        dst = strtok(NULL, ",");

	if(src[0] == '(' && src[strlen(src)-1]	== ')'){
		if(dst[0] == '(' && dst[strlen(dst)-1] == ')')
			return 0;
	}//case : 1 () -1 () 

	if(src[0] == '(' && src[strlen(src)-1]  == ')'){
		if(dst[0] == '-' && strchr(dst,'(') != NULL)
			return 0;
	}//case : 1() -2 -()

	if(src[0] == '(' && src[strlen(src)-1]  == ')'){
		if(dst[0] == '0')
			return 0;
	}//case : 1() -2 0

	//==========================================================

	if(src[0] == '-' && strchr(src,'(') != NULL){
		if(dst[0] == '(' && dst[strlen(dst)-1] == ')')
                        return 0;
	}//case : 2 -() -1 ()
	
	 if(src[0] == '-' && strchr(src,'(') != NULL){
		 if(dst[0] == '-' && strchr(dst,'(') != NULL)
			return 0;
	}//case : 2 -() -2 -()
	
	 if(src[0] == '-' && strchr(src,'(') != NULL){
		if(dst[0] == '0')
			return 0;
	}//case : 2 -() -2 0
	
	//============================================================

	if(src[0] == '0'){
		if(dst[0] == '(' && dst[strlen(dst)-1] == ')')
                        return 0;
	}//case : 3 0 -1 ()
	
	if(src[0] == '0'){
		if(dst[0] == '-' && strchr(dst,'(') != NULL)
			return 0;
	}//case : 3 0 -2 -()
	
	if(src[0] == '0'){
		 if(dst[0] == '0')
			return 0;
	}//case : 3 0 -3 0
		
		
	
	return 1;
}
