/*
 * Project: hw7
 * Name   : Werner Ordonez
 * Date   : 04/24/2019
 * File   : main.c
 * Notes  : reverse polish calculator
 */


/*
 * main.c
 *
 * reverse polish calculator
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h" /* header file */

#define MAXOP 128

int main(int argc, char *argv[])
{
  int type;
  int op2;
  char s[MAXOP];
  printf("hi");
  while ((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 != 0)
	push(pop() / op2);
      else {
	printf("error : zero divisor\n");
	exit(1);
      }
      break;
    case '&':
      op2 = pop();
      push(pop() & op2);
      break;
    case '|':
      op2 = pop();
      push(pop() | op2);
      break;
    case '^':
      op2 = pop();
      push(pop() ^ op2);
      break;
    case '~':
      op2 = pop();
      op2 = ~op2;
      push(op2);
      break;
    case '>':
      push(pop() < pop());
      break;
    case '=':
      push(pop() == pop());
      break;
    case '<':
      push(pop() > pop());
      break;
    case '!':
      push(pop() == 0);
      break;
    case '?':
      op2 = pop();
      int b = pop();
      int c = pop();
      if(op2 != 0)
	push(b);
      else
	push(c);
      break;
    case '\n':
      printf("The answer is %d\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      exit(1);
    }
  }
}
