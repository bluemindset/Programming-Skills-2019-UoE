/**
 * @Author: B159973
 * @Date:   15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
/*========================== Library Files ===========================*/
#include <stdio.h>
#include <stdlib.h>
#include "configuration.h"
#include "arralloc.h"
#include "uni.h"
#include "map.h"

/*====================================================================*/

void map_init_zero(configure *con, int **map)
{
    int i, j;
    for (i = 0; i < con->L + 2; i++)
        for (j = 0; j < con->L + 2; j++)
            map[i][j] = 0;
}

void map_init_density(configure *con, int **map)
{
    int i, j;
    float r;
    con->allowed_squares = 0;
    for (i = 1; i <= con->L; i++)
    {
        for (j = 1; j <= con->L; j++)
        {
            r = random_uniform(); /*Test if the rho is bigger than the random value*/
            if(r > con->rho)
            {
                con->allowed_squares++; /*Allow a square have value one*/
                map[i][j] = 1;
            }
        }
    }
}

void map_init_nums(configure *con, int **map)
{
    int i, j;
    con->allowed_squares = 0;
    for (i = 1; i <= con->L; i++)
    {
        for (j = 1; j <= con->L; j++)
        {
            if (map[i][j] != 0) /*If a square is not 0 initialize a number to it*/
            {
                (con->allowed_squares) += 1;
                map[i][j] = con->allowed_squares;
            }
        }
    }
}

void map_update(configure *con, int **map)
{
    int i, j, old;
    int loop = 1, squares_changed = 1;

    while (squares_changed > 0)
    {
        squares_changed = 0;
        for (i = 1; i <= con->L; i++)
        {
            for (j = 1; j <= con->L; j++)
            {
                if (map[i][j] != 0)
                {
                    old = map[i][j]; /*Perform a check form the upper,left,bottom,right neighbor and re-write if has bigger value*/
                    if (map[i - 1][j] > map[i][j]) map[i][j] = map[i - 1][j];
                    if (map[i + 1][j] > map[i][j]) map[i][j] = map[i + 1][j];
                    if (map[i][j - 1] > map[i][j]) map[i][j] = map[i][j - 1];
                    if (map[i][j + 1] > map[i][j]) map[i][j] = map[i][j + 1];
                    if (map[i][j] != old)
                    {
                        squares_changed++;
                    }
                }
            }
        }
        //  printf("Number of changes on loop %d is %d\n", loop, squares_changed);
        loop++;
    }

}

int does_map_percolate(configure *con, int **map, int *cluster_num)
{
    int top_map_row_A = 0, top_map_row_B = 0;
    int does_percolate = 0;

    for (top_map_row_A = 1; top_map_row_A <= con->L; top_map_row_A++)
    {
        if (map[top_map_row_A][con->L] > 0)
        {
            for (top_map_row_B = 1; top_map_row_B <= con->L; top_map_row_B++)
            {
                /* Check the two most further columns */
                if (map[top_map_row_A][con->L] == map[top_map_row_B][1])
                {
                    does_percolate = 1;
                    *cluster_num = map[top_map_row_A][con->L];
                }
            }
        }
    }
    return does_percolate;
}

void print_percolation_message(int cluster_num, int does_percolate)
{
    if (does_percolate)
    {
        printf("Cluster DOES percolate. Cluster number: %d\n", cluster_num);
    }
    else
    {
        printf("Cluster DOES NOT percolate\n");
    }
}
