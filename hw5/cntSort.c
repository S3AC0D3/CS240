/*
 * implementation of counting sort
 *
 * project    : hw5
 * name       : Werner Ordonez
 * user       : user48
 * date       : 03/21/2019
 * file       : cntSort.c
 * pseudo code: initialize count to 0
 *              increment count for index[i]
 *              calculate starting index for each int
 *              set array of number for count[number] times
 * notes      : Implements of counting sort. Allocates memory and frees
 *              up memory.
 */

#include <stdlib.h>

void cntSort(unsigned m, unsigned n, unsigned data[])
{
  unsigned *count;
  unsigned output[n];
  int total = 0;
  int i;
  int oldCount;

  /* allocate memory */
  count = (unsigned *)malloc(sizeof(unsigned) * m);
  for(i = 0; i < m; i++){
      count[i] = 0;
    }
  /* corresponding count is incremented */
  for(i = 0; i < n; i++){
      ++count[data[i]];
    }
  /* calculate starting inder for each int */
  for(i = 0; i < m; i++){
      oldCount = count[i];
      count[i] = total;
      total += oldCount;
    }
  /* set data array as number for count[number] times */
  for(i = 0; i < n; i++){
      output[count[data[i]]] = data[i];
      ++count[data[i]];
    }
  for(i = 0; i < n; i++){
      data[i] = output[i];
    }
  /* free up memory */
  free(count);
}

