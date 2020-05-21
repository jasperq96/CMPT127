#include <math.h>
#include <stdio.h>

int main(){
  float value = 0;
  scanf("%f", &value);
  printf("%0.0f %0.0f %0.0f\n", 
  floor(value), 
  round(value), 
  ceil(value));
}
