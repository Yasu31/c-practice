#include <stdio.h>
#include "first.h"

int hello_world_first(int N){
  for(int i=0; i<N; i++){
    printf("Hello World from first.c\n");
  }
  return 1;
}


// This part below is inappropriate for a library
// int main(int argc, char* argv[]){
//   int ret=hello_world_first(5);
//   return 1;
// }
