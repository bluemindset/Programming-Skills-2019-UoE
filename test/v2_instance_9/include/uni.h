/**
 * @Author: B159973
 * @Date:	15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
#ifndef UNI_H
#define	UNI_H

/***************************************************************************//**
* Takes a single integer in the range
*		0 <= ijkl <= 900 000 000
* and produces the four smaller integers needed for rstart  
*******************************************************************************/
void rinit(int ijkl);

/***************************************************************************//**
* C version of Marsaglia's UNI random number generator
*******************************************************************************/
float random_uniform(void);

#endif