/*
 * Project    : hw6
 * Name       : Werner Ordonez
 * Date       : 04/05/2019
 * File       : tail.c
 * Notes      : This program reads lines from standard input and keeps the last
 *               n of them in memory as it goes through standard input.
 * Pseudo Code: Define constans
 *              use getops
 *              loop until all lines are read
 *              find length
 *              allocate space using malloc
 *              strcpy the buffer
 *              free array
 *              print output
 */

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// defining constants
#define DEFAULT_LINES 10
#define MAX_LINES 2000
#define MAX_CHAR 1024

int main(int argc, char *argv[]){
 
  char *array[MAX_LINES] = {NULL}; // pointer array with 2000 lines
  char buffer[MAX_CHAR] = {'\0'}; // buffer array with 1024 characters
  char *string; // pointer to a string
  int c, n, j, z, length = 0, i = 0;
  FILE *filePointer = NULL; // File type pointer set to NULL

  c = getopt(argc, argv, "n:"); // process command line option for n

  if(c == 'n'){
    // sscanf(const char *str, const char *format)
    sscanf(argv[2], "%d", &n); 
  }
  else{
    n = 10;
  }
  
  // loop until all lines are read
  while(fgets(buffer, MAX_CHAR, stdin) != NULL){
    length = strlen(buffer) + 1; // length of string
    string =(char*)malloc(sizeof(char) * length); // allocate space
    strcpy(string, buffer); // copy buffer to string
    array[i] = string;
    i++;
    if(i >= MAX_LINES){
      if(array[0]){
	free(array[0]);
      }
      for(z = 0; z < MAX_LINES - 1; z++){
	array[z] = array[z+1];
      }
      i = MAX_LINES - 1;
    } 
    // memset(void *str, int c, size n)
    memset(buffer, '\0', MAX_CHAR);
  }

  
  j = i - 1;
  // print n number of lines (tail)
  if(n < 0){
    printf("n cannot be negative \n");
  }
  //  else if(n == 0){
  // printf("\n");
  // }
  else{
    for(z = i - n; z < i; z++){
      printf("%s", array[z]);
    }
  }

  return 0;
} 
