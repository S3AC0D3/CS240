/*
 * Project: hw6
 * Name   : Werner Ordonez
 * Date   : 04/05/2019
 * File   : tail.c
 * Notes  : This program reads lines from standard input and keeps the last
 *        n of them in memory as it goes through standard input.
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
  int c, n, x, j, length = 0, i = 0;
  int y = 0;//i % n; 
  FILE *filePointer = NULL; // File type pointer set to NULL

  c = getopt(argc, argv, "n:"); // process command line option for n

  if(c == 'n'){
    // sscanf(const char *str, const char *format)
    sscanf(argv[2], "%d", &n); 
  }
  else{
    n= 10;
  }
  
  //filePointer = fopen("input.txt", "r"); // open file
  filePointer = fopen("/home/ming/240/hw6/testTail.txt", "r"); // open file

  // loop until all lines are read
  while(fgets(buffer, MAX_CHAR, filePointer) != NULL){
    length = strlen(buffer) + 1; // length of string
    string = malloc(length); // allocate space
    strcpy(string, buffer); // copy buffer to string
    // free up space
    if(array[y]){
      free(array[y]);
      array[y] = NULL;
    }
    array[y] = string;
    i++;
    // memset(void *str, int c, size n)
    memset(buffer, '\0', MAX_CHAR);
  }

  j = i - 1;
  // print n number of lines (tail)
  for(x = j; x < n + j; x++){
    printf("%s", array[x % n]);
  }
 
  return 0;
} 
