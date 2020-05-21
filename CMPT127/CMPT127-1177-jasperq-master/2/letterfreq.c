#include <stdio.h>
#include <ctype.h>

int main(){
	int character = getchar();
	float occurences[26]={0};	
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char letter;
	int total = 0;

	while(character != EOF){
		if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
			total++;
			letter = tolower(character);
			for(int x = 0; x < 26; x++){
				if(letter == alphabet[x]){
					occurences[x]++;
				}
			}
		}
		character = getchar();
	}
	for(int n = 0; n < 26; n++){
		if(occurences[n] != 0){
			printf("%c %.4f\n", alphabet[n], occurences[n]/total);
		}
	}

}
