#include <stdio.h>
#include <stdbool.h>

int main(){
	int columns[80];
	int count = 0;
	int success;
	int check[80]={-2};
	int run = 0;
	int high = 0;
	int compare;

	success = scanf ("%i", &columns[count]);

	while(success != EOF){ 
		count ++;
		success = scanf("%i", &columns[count]);
	}

	while(run != count){
		run = 0;
		high = columns[0];
		for(int x = 0; x < count; x++){ 
			if (columns[x] == 0){
				check[x] = x;//holds index of 0 in columns[]
			}
			if (check[x] == x){
				run++;
			}
			compare = columns[x];
			if(high < compare){
				high = compare;
			} 
		}
		
		if(high == 0){
			run = count;
		}

		if(high != 0){
			for(int s = 0; s < count; s++){
				if (columns[s] >= high){
					if(columns[s]-1 >= 0){
						printf("#");
						columns[s]--;
					}
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
		
		//printf("Run is %i\n",run);//TP
		//printf("%i %i %i %i\n",columns[0],columns[1],columns[2],columns[3]);//TP
		//printf("high is %i\n",high);
	}
}
	
	

