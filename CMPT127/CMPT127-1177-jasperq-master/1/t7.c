#include <stdio.h>

int main(){
	int user[1000000];
	int success;
	int count = 0;
	do{
		success = scanf("%i", &user[count]);
		if (success == EOF){
			return(0);
		}
		else{
			for (int x = 0; x < user[count]; x++){
				printf("#");
			}
		printf("\n");
		}
	count++;
	}while(success != 0);
}
