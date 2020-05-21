#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	int end = strlen(argv[2]); 
	int string = strlen(argv[1]); 
	for(int x = 0; x < string; x++){
		if(argv[1][x] == argv[2][0]){
			for(int n = 0; n < end; n++){ 
				if(argv[1][x+n] != argv[2][n]){
					printf("false\n");
					return 0;
				}
			}
			printf("true\n");
			return 0;
		}
	}
	printf("false\n");
}
