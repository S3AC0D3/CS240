/*
 * declarations
 *
 * project: hw4
 * name   : Werner Ordonez
 * user   : user48
 * date   : 03/11/2019
 * file   : adder.h
 * notes  : This is the header file for the enum bits
 */

enum bits {ZERO, ONE};

enum bits halfAdderSum(enum bits P, enum bits Q);
enum bits halfAdderCarry(enum bits P, enum bits Q);

enum bits fullAdderSum(enum bits P, enum bits Q, enum bits Cin);
enum bits fullAdderCarry(enum bits P, enum bits Q, enum bits Cin);

unsigned int myAdd(unsigned int p, unsigned int q);
