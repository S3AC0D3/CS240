/*
 * implement of myAdd() using fullAdderSum() and fullAdderCarry()
 *
 * project    : hw4
 * name       : Werner Ordonez 
 * user       : user48
 * date       : 03/11/2019
 * file       : myAdd.c
 * pseudo code: loop 32 times
 *                extract pbit and qbit
 *                add 3 bits sum
 *                find carry for 3 bits
 *                add bit to int
 * notes      : This has the function myAdd that uses fullAdderSum()
 *              and fullAdderCarry to add 2 numbers bit by bit
 */

#include <stdio.h>
#include <stdlib.h>
#include "adder.h"

/*
 * use fullAdderSum() and fullAdderCarry() to add two numbers bit by bit
 * p and q are nonnegative
 * assume their sum does not cause overflow of a 32-bit unsigned int
 */
unsigned int myAdd(unsigned int p, unsigned int q)
{
  unsigned int mySum;
  int i = 0;
  int pBit, qBit, S, Cout;
  int Cin = 0; 
  /*
   * loop 32 times
   * add a pair of bits from p and q, and the previous carry bit
   * record the sum bit in the corresponding bit in mySum
   * the first carry bit is zero
   * the last carry bit is discarded, assuming no overflow
   */

  for(i; i <= 31; i++)
    {
      pBit = (p >> i) & 1;
      qBit = (q >> i) & 1;
      S = fullAdderSum(pBit, qBit, Cin);
      Cout = fullAdderCarry(pBit, qBit, Cin);
      mySum ^= (-S ^ mySum) & (1UL << i);
      Cin = Cout;
    }
  return mySum;
}
