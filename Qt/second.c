#include <stdio.h>
#include "second.h"

int hello_world_second(int N){
  for(int i=0; i<N; i++){
    printf("Hello World from second.c\n");
  }
  return 1;
}
