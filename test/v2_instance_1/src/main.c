/**
 * @Author: B159973
 * @Date:   15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
/*========================== Library Files ===============================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "configuration.h"
#include "cluster.h"
#include "file.h"
#include "uni.h"
#include "arralloc.h"
#include "main.h"
#include "map.h"
#include "userInput.h"
#include "allocs.h"
/*=========================================================================================================*/

int main ( int argc, char *argv[] )
{

    /*==========================DECLARATIONS===============================================================*/
    int i, j;
    int **map = NULL; /*The 2D map */
    int all_clusters;/* All the possible clusters*/
    int *rank_list = NULL; /*Rank list of the cluster*/
    int cluster_percolate = 0; /*The cluster number that percolates*/
	cluster *cluster_list = NULL;
    configure con;
    /*==========================INPUTS====================================================================*/

    get_input(&con, argc, argv);
    rinit(con.seed);
    printf("Parameters are rho=%f, L=%d, seed=%d\n", con.rho, con.L, con.seed);

    /*==========================ALLOCATIONS===============================================================*/

    /*Allocate the map,rank list and cluster list*/
    map = (int **) arralloc(sizeof(int), 2, con.L + 2, con.L + 2);
    cluster_list = (cluster *)arralloc(sizeof(cluster), 1, (con.L ) * (con.L));
    rank_list = (int *)arralloc(sizeof(int), 1, con.L * con.L);
    /*Check if allocation is ok, else abort*/
    check_map(map);
    check_cluster_list(cluster_list);
    check_int_list(rank_list);

    /*==========================MAP CALCULATIONS===========================================================*/
    /* Initialize the map to zero and then the density (insert 1's)*/
    map_init_zero(&con, map);
    map_init_density(&con, map);

    printf("rho = %f, actual density = %f\n", con.rho, 1.0 - ((double) con.allowed_squares) / ((double) con.L * con.L) );

    map_init_nums(&con, map);    /*And then each square to a number*/
    map_update(&con, map);        /*Perform the loop on the map*/

    /*Find if the cluster percolates and print the percolate message*/
    print_percolation_message(cluster_percolate, does_map_percolate(&con, map, &cluster_percolate));

    /*==========================DAT FILE WRITE==============================================================*/
    /*Write the context into the dat file*/
    write_dat_file(&con, map);

    /*==========================PGM FILE WRITE==============================================================*/
    init_clusters_list_ranks(&con, rank_list, cluster_list, map); /*Initiliaze the cluster list and the rank list*/
    update_clusters_size(&con, cluster_list, map); /*Update cluster sizes*/

    clusters_sort(cluster_list, con.L * con.L); /*Sort out clusters*/
    all_clusters = find_all_clusters(&con, cluster_list); /*Find the number of maximum/possible clusters*/
    update_clusters_ranks(cluster_list, rank_list,all_clusters);
    print_max_clusters(&con, all_clusters, cluster_list); /*Print the maximum/possible clusters*/
    write_pgm_file(&con, map, rank_list); /*Write them into pgm file*/

    dealloc(map, rank_list, cluster_list, (void *)0) ; /*Deallocate all the consuming resources*/
}



