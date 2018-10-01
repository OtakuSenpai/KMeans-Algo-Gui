#include <iostream>
#include <sstream>
#include "KMeans.hpp"

using namespace std;

void KMeans::set(int numOfClusters,int totalPoints,int totalValuesPerPoint,int maxIterations) {
  this->num_of_clusters = numOfClusters;
  this->total_points = totalPoints;
  this->total_values = totalValuesPerPoint;
  this->max_iterations = maxIterations;
}

int KMeans::get_id_nearest_center(const Point& point) {
  double sum = 0.0, min_dist;
  int cluster_id_center = 0;
  int i,j;

  min_dist = 10000000000.0;
  for(i = 0; i < num_of_clusters; i++) {
    double dist;
    sum = 0.0;

    for(j = 0; j < total_values; j++) {
      sum = std::pow(clusters.at(i).get_central_value_at_index(j) -
          point.get_value_at_index(j),2);
    }

    dist = sqrt(sum);

    if(dist < min_dist) {
      min_dist = dist;
      cluster_id_center = i;
    }

  }

  return cluster_id_center;
}

KMeans::KMeans(int numOfClusters,int totalPoints,int totalValuesPerPoint,int maxIterations) {
  this->num_of_clusters = numOfClusters;
  this->total_points = totalPoints;
  this->total_values = totalValuesPerPoint;
  this->max_iterations = maxIterations;
}

void KMeans::run(vector<Point>& points) {
  std::srand(std::time(nullptr));
  vector<int> prohibited_indices;

  // If the total number of points is less than
  // the total number of clusters, dont execute
  if(num_of_clusters > total_points)
    return;

  // choose K distinct values for the centers of the clusters
  for(int i = 0; i < num_of_clusters; i++) {
    while(true) {
      // get a random point from total point size
      int index_point = std::rand() % total_points;

      // If index_point not found in prohibited list
      if(std::find(prohibited_indices.begin(),prohibited_indices.end(),
          index_point) == prohibited_indices.end()) {
            // add tht index point
            prohibited_indices.push_back(index_point);
            // set the cluster id of that random point
            points.at(index_point).set_cluster_id(i); // i is the current cluster
            Cluster cluster(i,points[index_point]);
            // add a new cluster to clusters var with i as the cluster id and
            // points[index_point] as the point
            clusters.push_back(cluster);
            break;
      }
    }
  }

  int iter = 1;

  while(true) {
    bool done = true;

    // associates each point to the nearest center
    for(int i = 0; i < total_points; i++) {
      // get old cluster id of current point
      int old_cluster_id = points.at(i).get_cluster_id();
      // get nearest to center id of a point(the current one)
      int nearest_center_id = get_id_nearest_center(points.at(i));


      // if old cluster id not equal to nearest center id
      if(old_cluster_id != nearest_center_id) {
        // if its a old id (the current point is newly read) then
        // remove said point from old cluster in clusters var
        // add this point to new cluster from clusters var
        if(old_cluster_id != -1)
          clusters.at(old_cluster_id).remove_point(points.at(i).get_point_id());

        // set the current point's cluster id to nearest cluster id
        // then add the point to cluster which is equal to nearest cluster id index
        points.at(i).set_cluster_id(nearest_center_id);
        clusters.at(nearest_center_id).add_point(points.at(i));
        done = false;
      }
    }

    // recalculating the center of each cluster
    for(int cluster = 0; cluster < num_of_clusters; cluster++) { // number of clusters
      for(int value = 0; value < total_values; value++) { // number of value per point

        // get the size of points in a cluster
        int total_points_cluster = clusters.at(cluster).get_points_size();
        double sum = 0.0;

        if(total_points_cluster > 0) {
          for(int point = 0; point < total_points_cluster; point++)
            sum += clusters.at(cluster).get_point_at_index(point).get_value_at_index(value);

          clusters.at(cluster).set_central_value_at_index(value,sum / total_points_cluster);
        }
      }
    }

    if(done == true || iter >= max_iterations) {
      break;
    }

    ++iter;
  }
}

std::string KMeans::show() {
  std::stringstream sss;
  for(int i = 0; i < num_of_clusters; i++) {
    sss << "Cluster: " << clusters[i].get_cluster_id() + 1 << "\n";

    for(size_t j = 0; j < clusters[i].get_points_size(); j++) {
      sss << "Point " << clusters[i].get_point_at_index(j).get_point_id() << ": ";
      for(int p = 0; p < total_values; p++)
        sss << clusters[i].get_point_at_index(j).get_value_at_index(p) << " ";
      sss << "\n";
    }

    sss << "Cluster central values: ";

    for(int j = 0; j < total_values; j++)
      sss << clusters[i].get_central_value_at_index(j) << " ";

    sss << "\n" << endl;
  }

  return sss.str();
}




