/*
 *  binary.c
 *	
 *	Description:
 *	This file will either send 1 or 0 depending on if u press 'a' or 'z'.
 *	'a' = increase by 1 and 'z' = decrease by 1. If the value goes under 0 it
 *	will exit.
 *
 *  Created by Niel Madlani on 2011-04-11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main(){
	
	char key1;
	int i = 0;
	
	
	printf("press 'a' to increase, or z to decrease: \n");
	while(1){
	
		scanf("%c", &key1);
	
		if (key1 == 'a') {
			i++;
			printf("increase: %d \n", i);
		}
			
		if (key1 == 'z'){
				i--;
				printf("decrease: %d \n", i);
		
		}
		
		if (i < 0) {
			printf("Can't go more lower! ");
		}
	}
}