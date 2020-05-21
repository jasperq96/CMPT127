#include <math.h>
#include <stdio.h>

int main(){
  float value = 0;
  int success = 0;
  success = scanf("%f", &value);
  if (success != 0){
    printf("%0.0f %0.0f %0.0f\n", 
    floor(value), 
    round(value), 
    ceil(value));
  }
  else{
    printf("scanf error: (%d)\n",success);
  }
}
