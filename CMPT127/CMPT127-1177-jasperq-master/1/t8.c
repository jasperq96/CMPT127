#include <stdio.h>

int main(){
	int width,length,height;
	scanf("%i %i %i", &width, &length, &height);
	for(int y = 0; y < length; y++){
		for(int x = 0; x < width; x++){
			if (y == 0 || y == length-1){
				printf("#");
			}
			else if (x > 0 && x < width-1){
				printf(".");
			}
			else {
				printf("#");
			}
		}
		printf("\n");
	}
	
}
