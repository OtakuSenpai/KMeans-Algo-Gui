#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "Cluster.hpp"

using namespace std;

class KMeans {
  private:
    int num_of_clusters;
    int total_values, total_points, max_iterations;
    vector<Cluster> clusters;

    int get_id_nearest_center(const Point& point);

  public:

    KMeans() {}

    KMeans(int numOfClusters,int totalPoints,int totalValuesPerPoint,int maxIterations);

    //same as constructor
    void set(int numOfClusters,int totalPoints,int totalValuesPerPoint,int maxIterations);

    // Used to run the main program
    void run(vector<Point>& points);

    // Used to return the data in string format
    std::string show();

};


#endif
