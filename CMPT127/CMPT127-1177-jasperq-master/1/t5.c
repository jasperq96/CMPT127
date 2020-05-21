#include <stdio.h>
#include <math.h>

int main(){
	float user = 0;
	int end = scanf("%f",&user);
	while(end == 1){
		printf("%0.0f %0.0f %0.0f\n", floor(user), round(user),ceil(user));
		end = scanf("%f",&user);
	}	
	if (end == 0){
		printf("Scan Error: (%d)\n", end);
	}
	else if(end == EOF){
		printf("Done.\n");
	}
}
