#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]){
	int compare = getchar();
	while(compare != EOF){
		for (int x = 1; x < argc; x++){
			char temp[30] = {""};
			if(compare == argv[x][0]){
				temp[0] = (char)compare;
				compare = getchar();
				for(int n = 1; n < strlen(argv[x]);n++){
					if(compare != argv[x][n]){
						printf("%s",&temp[n-1]);
						putchar(compare);
						compare = getchar();
						n = strlen(argv[x]);
					}
					else{
						temp[n] = (char)compare;
						compare = getchar();
						if(n == strlen(argv[x])-1){
							printf("CENSORED");
						}
					}
				}
			}
			else if(x == argc-1){
				putchar(compare);
				compare = getchar();
			}
		}
		if(argc == 1){
			putchar(compare);
			compare = getchar();
		}
	}
}
