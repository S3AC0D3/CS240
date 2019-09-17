/*
 * implement fullAdderSum() fullAdderCarry()
 *
 * project    : hw4
 * name       : Werner Ordonez
 * user       : user48
 * date       : 03/11/2019
 * file       : adder.c
 * pseudo code: fullAdderSum
 *                add three bits
 *              fullAdderCarry
 *                find carry for three bi
 * notes      : This program adds two bits P and Q and returns the sum and
 *              and carry bit. It also adds three bits P, Q and Cin and also
 *              returns the sum and carry bit.
 */

#include "adder.h"

/*
 * add two bits P and Q
 * return the sum bit
 */
enum bits halfAdderSum(enum bits P, enum bits Q)
{
  return P ^ Q;
}

/*
 * add two bits P and Q
 * return the carry bit
 */
enum bits halfAdderCarry(enum bits P, enum bits Q)
{
  return P & Q;
}

/*
 * add three bits P, Q, and Cin
 * return the sum bit
 */
enum bits fullAdderSum(enum bits P, enum bits Q, enum bits Cin)
{
  return P ^ Q ^ Cin;
}

/*
 * add three bits P, Q, and Cin
 * return the carry bit
 */
enum bits fullAdderCarry(enum bits P, enum bits Q, enum bits Cin)
{
  return P & Q | P & Cin | Q & Cin;
}
