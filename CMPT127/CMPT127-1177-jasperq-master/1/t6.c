#include <stdio.h>

int main(){
	float small = 0;
	float large = 0;
	float avr = 0;
	float user = 0;
	int end = scanf("%f",&user);
	small = user;
	large = user;
	avr += user;
	int count = 1;
	while(end == 1){	
		end = scanf("%f", &user); 
		if (user < small){
			small = user;
		}
		if (user > large){
			large = user;
		}
		if (end != EOF){
			count++;
			avr += user;
		}
	}
	printf("%0.2f %0.2f %0.2f\n", small, large, avr/count);
}
