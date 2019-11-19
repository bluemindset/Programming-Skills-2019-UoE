/**
 * @Author: B159973
 * @Date:   15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
/*========================== Library Files ===========================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "configuration.h"
#include "cluster.h"
#include "file.h"
#include "allocs.h"
/*====================================================================*/

void write_dat_file(configure *con, int **map)
{
    int i, j;
    FILE *file_p = NULL;
    open_file(&file_p, con->dat_filename);

    printf("Writing the map inside the file %s file... Please wait\n", con->dat_filename);

    write_dat_body(con, map, file_p); /*Write grid in dat file*/

    printf("Write successful.\n");

    fclose(file_p);
    printf("File closed\n");
}

void write_dat_body(configure *con, int **map, FILE *file_p)
{
    int i, j;
    for (j = con->L; j >= 1; j--)
    {
        for (i = 1; i <= con->L; i++)
        {
            fprintf(file_p, " %4d", map[i][j]); /*Write the map inside the file*/
        }
        fprintf(file_p, "\n");
    }
}

void write_pgm_file(configure *con, int **map, int *rank_list)
{
    int colour, j, i;
    FILE *file_p = NULL;
    open_file(&file_p, con->pgm_filename);

    printf("Writing data inside the %s file...\n", con->pgm_filename);

    header_pgm_file(con, file_p); /*Write the header content of the pgm */
    body_pgm_file(con, map, rank_list, file_p); /*Write the body content, which is the colour conversion*/

    printf("File closed\n");
    close_file(file_p);
}

void header_pgm_file(configure *con, FILE *file_p)
{
    fprintf(file_p, "P2\n");
    if (con->max_clusters > 0)
    {
        fprintf(file_p, "%d %d\n%d\n", con->L, con->L, con->max_clusters); /*First line, maximum number of clusters*/
    }
    else
    {
        fprintf(file_p, "%d %d\n%d\n", con->L, con->L, 1); /*First line, maximum number of clusters*/
    }
}

void body_pgm_file(configure *con, int **map, int *rank_list, FILE *file_p)
{
    int colour = 0;
    int i, j;
    for (j = con->L; j >= 1; j--)
    {
        for (i = 1; i <= con->L; i++)
        {
            colour = map[i][j];
            if (map[i][j] > 0)
            {
                colour = rank_list[map[i][j] - 1];
                if (colour >= con->max_clusters)
                {
                    colour = con->max_clusters;
                }
            }
            else
            {
                colour = con->max_clusters;
            }
            fprintf(file_p, " %4d", colour);
        }
        fprintf(file_p, "\n");
    }
}

void open_file(FILE **file_p, char *filename)
{
    printf("Opening file <%s>\n", filename);
    *file_p = fopen(filename, "w");
    if (*file_p == NULL)
    {
        perror("Failed to open file: ");
        exit(EXIT_FAILURE);
    }
}

void close_file(FILE *file_p)
{
    printf("Operation finished. \n");

    // free(file_p);
}
