#include <stdio.h>
#include <math.h>

int main(){
	int width,length,height,left,right;
	scanf("%i %i %i", &width, &length, &height);
	for(int j = height-1; j >= 0; j--){
		left = floor( j * (width/(2.0*height)) );
		right = ceil( (width-1) + -j * (width/(2.0*height)) );
		for (int n = 0; n <= right; n++){ 
			if (j == 0 || j == (height-1)){
				if(n < left || n > right){
					printf(" ");
				}
				else{
					printf("#");
				}
			}
			else {
				if(n == left || n == right){
					printf("#");
				}
				if (n < left){
					printf(" ");
				}
				if (n > left && n < right){
					printf(".");
				}
			
			}
		}
		printf("\n");
	} 
	
}
