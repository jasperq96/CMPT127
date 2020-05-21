#include <stdio.h>
int main(){
  unsigned long int charcount=0;
  unsigned long int wordcount=0;
  unsigned long int linecount=0;
  int text;
  int inword = 0;
  while ((text = getchar()) != EOF){
    charcount++;
    if(text == '\n'){
      linecount++;
      if(inword == 1){
        wordcount++;
        inword = 0;
      }
    }
    else if ((text>64 && text<91)||(text>96 && text<123) || text == 39){
      if(inword == 0){
        inword = 1;
      }
    }
    else if(text == 32){
      if(inword == 1){
        wordcount++;
        inword = 0;
      }
    }
    else{
      if(inword == 1)
      {
        wordcount++;
        inword = 0;
      }
    }
  }
  printf( "%lu %lu %lu\n", charcount, wordcount, linecount);
}
