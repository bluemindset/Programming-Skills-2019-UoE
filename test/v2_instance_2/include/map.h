/**
 * @Author: B159973
 * @Date:	15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
#ifndef map_H
#define	map_H

/***************************************************************************//**
 * Initialize all the 2D map values(squares) to integer value 0 by a traversing
 * it with a simple nested loop.
 *
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void map_init_zero(configure *con, int **map);

/***************************************************************************//**
 * Initialize the density to the map by updating some squares to the integer
 * value 1. This squares are selected by comparing an output of a random uniform
 * with the density ρ (rho) given by the user. The random uniform function found
 * in uni.c file which uses a random seed.
 *
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void map_init_density(configure *con, int **map);

/***************************************************************************//**
 * For each square value that has integer value of one, update it by adding one
 * each time nad keep the sum for the next square.
 *
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void map_init_nums(configure *con, int **map);

/***************************************************************************//**
 * For each square value bigger than 1, replacing each square with the
 * maximum of its four neighbours.
 *
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void map_update(configure *con, int **map);

/***************************************************************************//**
 * Check if the map has a value that is the same on the first column and the last
 * column. If there is then the map percolates.
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param map:    		The 2D array where the map is stored.
 * @param cluster_num:	The cluster number that percolates the map.
 * @return:         	The value of integer 1 if the map does percolates, else
 *						the value of integer 0.
 *******************************************************************************/
int does_map_percolate(configure *con, int **map,int *cluster_num);

/***************************************************************************//**
 * Print a message according to the value of the does_percolate argument.
 * If it has integer value 1 then print a success percolate message else if it is 0
 * print a non successfull percolation message.
 *
 * @param cluster_num:	   The number of cluster that percolates the map.
 * @param does_percolates: The value which determines the printed message.
 *
 * @return:         	Nothing
 *******************************************************************************/
void print_percolation_message(int cluster_num, int does_percolate);

#endif
