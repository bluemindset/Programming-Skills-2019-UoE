/**
 * @Author: B159973
 * @Date:	15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/

#ifndef FILE_H
#define FILE_H

/***************************************************************************//**
 * Write to the .pgm file the top three lines that define the pgm in ASCII content,
 * the second line the area size of the map (a x b) and the smallest cluster and
 * the third line the maximum color of value.
 *
 * @param con:      A pointer that points to the configuration structure that the
 *                  header file will use some values from.
 * @param file_p:   The file pointer that points to the file which the write will
 *                  execute.
 *
 * @return:         Nothing
 ******************************************************************************/
void header_pgm_file(configure *con, FILE *file_p);

/***************************************************************************//**
 * Write to the .pgm file the corresponding trasformation of the map into colours.
 * There will be size^2 values, each one is splitted with a tab. The smallest value
 * corresponse to the biggest cluster. If that value is on the top row and on the
 * bottom row then the cluster percolates and it can be seen when the pgm files opens
 * as darkest (black) line.
 *
 * @param con:      A pointer that points to the configuration structure
 *                  used to provide the maximum clusters that the user wants to output.
 *                  and the size of the map.
 * @param map:  	The pointer which shows to what file to write to.
 * @param rank_list:A pointer to an integer list that holds the ranking of the clusters.
 * @param file_p:   The file pointer that points to the file which the write will
 *                  execute.
 *
 * @return:         Nothing
 ******************************************************************************/
void body_pgm_file(configure *con, int **map, int *rank_list, FILE *file_p);

/***************************************************************************//**
 * This function handles the opening and the closing of the .pgm file as well as
 * the writing. The writing althought if handled throught different functions as
 * seen above this file.
 *
 * @param con:      A pointer that points to the configuration structure
 *                  used to provide the maximum clusters that the user wants to output.
 *                  and the size of the map.
 * @param map:  	The pointer which shows to what file to write to.
 * @param rank_list:A pointer to an integer list that holds the ranking of the clusters.
 *
 * @return:         Nothing
 ******************************************************************************/
void write_pgm_file(configure *con, int **map, int *rank_list);

/***************************************************************************//**
 * This function handles the opening and the closing of the .dat file as well as
 * the writing. The writing althought is handles throught different functions as
 * seen in this file.
 *
 * @param con:   A pointer that points to the configuration structure
 *               used to provide the maximum clusters that the user wants to output.
 *               and the size of the map.
 * @param map:  The pointer which shows to what file to write to.
 *
 * @return:      Nothing
 ******************************************************************************/
void write_dat_file(configure *con, int **map);

/***************************************************************************//**
 * This function gets the file pointer and writes the map. On each new row
 * a new line is inserted and for each square there is one tab space.
 *
 * @param con:   	A pointer that points to the configuration structure
 *               	used to provide the maximum clusters that the user wants to output.
 *               	and the size of the map.
 * @param map:  	The pointer which shows to what file to write to.
 * @param file_p:   The file pointer that points to the file which the write will
 *                  execute.
 *
 * @return: 	    Nothing
 ******************************************************************************/
void write_dat_body(configure *con, int **map, FILE *file_p);


/***************************************************************************//**
 * Closes the file that the file pointer is pointing and checks if the file
 * closed correctly. Also deallocates the file pointer.
 *
 * @param file_p: The pointer that points to the file that will close.
 *
 * @return:      Exits the program if the file haven't closed correcly.
 ******************************************************************************/
void close_file(FILE *file);

/***************************************************************************//**
 * Opens the file and check if the file opens correctly. It opens the file in a
 * write mode. ("w")
 *
 * @param file:  The pointer that points to the file that will close.
 * @filename  :  The file name that is going to open.
 *
 * @return:      Exits the program if the file haven't open correcly.
 ******************************************************************************/
void open_file(FILE **file, char *filename);

#endif