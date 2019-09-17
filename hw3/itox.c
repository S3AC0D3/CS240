/*
 * functions that convert between int, quaternary, and vigesimal numbers
 * 
 * project: hw3
 * name   : Werner Ordonez 
 * date   : 03/01/2019
 * file   : itox.c
 * notes  : This has all the functions that convert decimals, quaternary and
 *          vigesimal numbers
 */

#include <stdio.h>
#include <string.h>
#include "itox.h"

/* function converts int n to a quaternary string in the
   hexstring array */
void itoq(char quaternaryStr[], int n)
{
  quaternaryStr[sizeof(int) * 4 + 1];

  int r; /* remainder */
  char s; /* quaternary equivalent char */
  int count = 15; 
 
  r = 0;
  
  /* Convert decimal intiger to a quaternary string*/
  if(n >= 0)
    {
      for(count; count >= 0; count--)
	{
	  r = n % 4;
	  if(r == 0)
	    {
	      s = '0';
	    }
	  else if(r == 1)
	    {
	      s = '1';
	    }
	  else if(r == 2)
	    {
	      s = '2';
	    }
	  else if(r == 3)
	    {
	      s = '3';
	    }
	  n = n / 4;
	  quaternaryStr[count] = s;
	}
    }
  quaternaryStr[sizeof(int) * 4 + 1] = '\0';   
}

/* function converts a quaternary string to its int value  */
int qtoi(char quaternaryStr[])
{
  int n = 0;
  int y = 0; /* quaternary int equivalent */ 
  int e = 0; /* exponent */
  int power = 0;  
  int count = 15;
 
  /* Convert quaternary string back to a decimal */
  for(count; count >= 0; count--)
    {
      y = 0;
      if(quaternaryStr[count] == '0')
	{
	  y = 0;
	}
      else if(quaternaryStr[count] == '1')
	{
	  y = 1;
	}
      else if(quaternaryStr[count] == '2')
	{
	  y = 2;
	}
      else if(quaternaryStr[count] == '3')
	{
	  y = 3;
	}
      if(e == 0)
	{
	  power = 1;
	}
      else
	{
	  while(e != 0)
	    {
	      power *= 4;
	      e--;
	    }
	}
      e++;
      y *= power;
      n += y;
    }
  return n;
}

/* function converts int n to a vigesimal string in the
   hexstring array */
void itov(char vigesimalStr[], int n)
{
  vigesimalStr[sizeof(int) * 2 + 1];

  int r; /* remainder */
  char s; /* vigesimal equivalent char */
  int count = 7; 
 
  r = 0;

  /* Convert int to vigesimal */
  for(count; count >= 0; count--)
    {
      r = n % 20;
      if(r == 0)
	{
	  s = '0';
	}
      else if(r == 1)
	{
	  s = '1';
	}
      else if(r == 2)
	{
	  s = '2';
	}
      else if(r == 3)
	{
	  s = '3';
	}
      else if(r == 4)
	{
	  s = '4';
	}
      else if(r == 5)
	{
	  s = '5';
	}
      else if(r == 6)
	{
	  s = '6';
	}
      else if(r == 7)
	{
	  s = '7';
	} 
      else if(r == 8)
	{
	  s = '8';
	}
      else if(r == 9)
	{
	  s = '9';
	}
      else if(r == 10)
	{
	  s = 'A';
	}
      else if(r == 11)
	{
	  s = 'B';
	} 
      else if(r == 12)
	{
	  s = 'C';
	}
      else if(r == 13)
	{
	  s = 'D';
	}
      else if(r == 14)
	{
	  s = 'E';
	}
      else if(r == 15)
	{
	  s = 'F';
	} 
      else if(r == 16)
	{
	  s = 'G';
	}
      else if(r == 17)
	{
	  s = 'H';
	}
      else if(r == 18)
	{
	  s = 'I';
	}
      else if(r == 19)
	{
	  s = 'J';
	} 
      n = n / 20;
      vigesimalStr[count] = s;
    }

  vigesimalStr[sizeof(int) * 2 + 1] = '\0';
}

/* function converts a vigesimal string to its int value  */
int vtoi(char vigesimalStr[])
{
  
  int n = 0;
  int y = 0; /* vigesimal int equivalent */ 
  int e = 0; /* exponent */
  int power = 0;  
  int count = 7;

  /* Convert vigesimal string to int */ 
  for(count; count >= 0; count--)
    {
      y = 0;
      if(vigesimalStr[count] == '0')
	{
	  y = 0;
	}
      else if(vigesimalStr[count] == '1')
	{
	  y = 1;
	}
      else if(vigesimalStr[count] == '2')
	{
	  y = 2;
	}
      else if(vigesimalStr[count] == '3')
	{
	  y = 3;
	}
      else if(vigesimalStr[count] == '4')
	{
	  y = 4;
	}
      else if(vigesimalStr[count] == '5')
	{
	  y = 5;
	}
      else if(vigesimalStr[count] == '6')
	{
	  y = 6;
	}
      else if(vigesimalStr[count] == '7')
	{
	  y = 7;
	}
      else if(vigesimalStr[count] == '8')
	{
	  y = 8;
	}
      else if(vigesimalStr[count] == '9')
	{
	  y = 9;
	}
      else if(vigesimalStr[count] == 'A')
	{
	  y = 10;
	}
      else if(vigesimalStr[count] == 'B')
	{
	  y = 11;
	}
      else if(vigesimalStr[count] == 'C')
	{
	  y = 12;
	}
      else if(vigesimalStr[count] == 'D')
	{
	  y = 13;
	}
      else if(vigesimalStr[count] == 'E')
	{
	  y = 14;
	}
      else if(vigesimalStr[count] == 'F')
	{
	  y = 15;
	}
      else if(vigesimalStr[count] == 'G')
	{
	  y = 16;
	}
      else if(vigesimalStr[count] == 'H')
	{
	  y = 17;
	}
      else if(vigesimalStr[count] == 'I')
	{
	  y = 18;
	}
      else if(vigesimalStr[count] == 'J')
	{
	  y = 19;
	}
      if(e == 0)
	{
	  power = 1;
	}
      else
	{
	  while(e != 0)
	    {
	      power *= 20;
	      e--;
	    }
	}
      e++;
      y *= power;
      n += y;
    }
  return n;
}
