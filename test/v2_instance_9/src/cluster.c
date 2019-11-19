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
#include "allocs.h"
/*====================================================================*/

void init_clusters_list_ranks(configure *con, int *rank_list, cluster *cluster_list, int **map)
{
    int i, j;

    for (i = 0; i < (con->L * con->L); i++) /*Initializes the structures of the clusters and the rank list.*/
    {
        rank_list[i] = -1;
        cluster_list[i].size = 0;
        cluster_list[i].id = i + 1;
    }
}

void update_clusters_size(configure *con, cluster *cluster_list, int **map)
{
    int i, j;
    for (i = 1; i <= con->L; i++) /*Updates the cluster list*/
    {
        for (j = 1; j <= con->L; j++)
        {
            if (map[i][j] != 0)
            {
                cluster_list[map[i][j] - 1].size += 1 ; /*Update cluster size by 1 if map square number is not 0*/ 
            }
        }
    }
}

void update_clusters_ranks(cluster *cluster_list, int *rank_list, int all_clusters)
{
    int i;
    for (i = 0; i < all_clusters; i++)  /*Updates the rank list*/
    {
        rank_list[cluster_list[i].id - 1] = i;
    }
}

void print_max_clusters(configure *con, int all_clusters, cluster *cluster_list)
{
    if (con->max_clusters > all_clusters)
    {
        con->max_clusters = all_clusters;
    }

    printf("Map has %d clusters, maximum cluster size is %d\n", all_clusters, cluster_list[0].size);

    if (con->max_clusters == 1)
    {
        printf("Displaying the largest cluster\n");
    }
    else if (con->max_clusters == all_clusters)
    {
        printf("Displaying all clusters\n");
    }
    else
    {
        printf("Displaying the largest %d clusters\n", con->max_clusters);
    }
}

int find_all_clusters(configure *con, cluster *cluster_list)
{
    int i;
    int num_cluster = 0;
    for (i = 0; i < con->L * con->L; i++)
        if(cluster_list[num_cluster].size > 0) /* Count all the clusters that have size bigger than 0. */
            num_cluster++;
    return num_cluster;
}

static int cluster_compare(const void *p1, const void *p2)
{
    int size1, size2, id1, id2;

    size1 = ((cluster *) p1)->size;
    size2 = ((cluster *) p2)->size;
    id1   = ((cluster *) p1)->id;
    id2   = ((cluster *) p2)->id;

    if (size1 != size2)
    {
        return(size2 - size1); /*Return the difference of the size*/
    }
    else
    {
        return(id2 - id1); /*Return the difference on the id*/
    }
}

void clusters_sort(cluster *list, int n)
{
    qsort(list, (size_t) n, sizeof(cluster), cluster_compare);
}