#include <stdio.h>

int main() {
  char x;
  int integer;
  int number = 0;
  int sum = 0;
  int digit;
  int doublethis = 1;

  while((x = getchar()) != EOF){
    if(x >= '0' && x <= '9'){
      integer = x - '0';
      number = number * 10 + integer;
    }
    else {
      break;
    }
  }

  int check_digit = number % 10;
  number /= 10;


  while(number != 0){
    digit = number % 10;
    number /= 10;
    if(doublethis){
    digit *= 2;
      if(digit >= 10){
      digit -= 9;
      }
    }
    sum += digit;
    doublethis = !doublethis;
  }

  if((sum * 9) % 10 == check_digit){
  printf("Valid\n");
  }
  else {
  printf("Invalid\n");
  }

  return 0;
}
