/**
 * @Author: B159973
 * @Date:   15/10/2019
 * @Course: Programming Skills - 2019
 * @University of Edinburgh
*/
#ifndef CLUSTER_H
#define	CLUSTER_H

/***************************************************************************//**
 * This data structure is used to store the sizes and ids of all the clusters
 * Basically a cluster has an ID and a size. The size of the clusters are the
 * number of the squares inside the maps that the cluster is located.
 * @size:   The size of the cluster in squares in the map.
 * @id:		The identification number of the cluster.
 ******************************************************************************/
typedef struct
{
    int size;
    int id;
} cluster;

/***************************************************************************//**
 * Initializes the structures of the clusters and the rank list. The clusters ranks
 * are initialized to the value of -1.The size of each cluster is 0 and the ID is
 * a assinged from 1 to L * L . The structure of the cluster can be found in cluster.h
 * file.
 *
 * @param con:      	A pointer that points to the configuration structure. The
 *                  	function use some values from it.
 * @param rank_list:    A pointer to an integer list that holds the ranking of the clusters.
 * @param cluster_list: A pointer to the cluster structure list.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void init_clusters_list_ranks(configure *con, int *rank_list, cluster *cluster_list, int **map);

/***************************************************************************//**
 * Updates the attribute size of the all the cluster structures.The function traverse
 * the map and for each square finds the corresponding ID of the cluster and updates
 * the size by increamenting by 1. Many clusters structures might not update at all.
 *
 * @param con:      	A pointer that points to the configuration structure. The
 *                  	function use some values from it.
 * @param cluster_list: A pointer to the cluster structure list.
 * @param map:    		The 2D array where the map is stored.
 *
 * @return:         	Nothing
 *******************************************************************************/
void update_clusters_size(configure *con, cluster *cluster_list, int **map);

/***************************************************************************//**
 * Updates the ranking list of the clusters by assinging values in it.
 * In the ranking list, the node which has the smallest integer (ex: 0) is the
 * biggest cluster in size. Furthermore every ascending value found in the
 * nodes of the rank list is a smaller cluster.
 *
 * @param cluster_list: A pointer to the cluster structure list.
 * @param rank_list: 	A pointer to an integer list that holds the ranking of the clusters.
 * @param all_clusters: All the possible clusters that are found in the cluster list.
 *
 * @return:         	Nothing
 *******************************************************************************/
void update_clusters_ranks(cluster *cluster_list, int *rank_list, int all_clusters);

/***************************************************************************//**
 * Prints the number of the largest clusters. The number is defined by user
 * preferences (see max_cluster: configuration.h)
 *
 * @param con:      	A pointer that points to the configuration structure. The
 *                  	function use some values from it.
 * @param all_clusters: All the possible clusters that are found in the cluster list.
 * @param cluster_list: A pointer that points to the cluster structure list.
 *
 * @return:         	Nothing
 *******************************************************************************/
void print_max_clusters(configure *con, int all_clusters, cluster *cluster_list);

/***************************************************************************//**
 * Traverse the structure list and count all the clusters that have size bigger than 0.
 *
 * @param con:        	A pointer that points to the configuration structure. The
 *                    	function use some values from it.
 * @param cluster_list: A pointer that points to the cluster structure list.
 *
 * @return:         	The number of all possible clusters.
 *******************************************************************************/
int find_all_clusters(configure *con, cluster *cluster_list);

/***************************************************************************//**
 * Compate the two clusters based on their size. If they have the same size
 * then compare them by there ID.
 *
 * @param p_cluster_1: The pointer of the first cluster structure.
 * @param p_cluster_1: The pointer of the first cluster structure.
 *
 * @return:			   The difference between cluster 2 size and cluster 1.
 *******************************************************************************/
static int cluster_compare(const void *p_cluster_1, const void *p_cluster_2);

/***************************************************************************//**
 * Sort the cluster structures according to the cluster_compare() which is found in
 * this file. The cluster with the bigger size attribute ranks first (0-position).
 *
 * @param cluster_list: A pointer that points to the cluster structure list.The
 *						function might alternate the positions of the list's nodes.
 *
 * @return:         	Nothing
 *******************************************************************************/
void clusters_sort(cluster *list, int n);

#endif