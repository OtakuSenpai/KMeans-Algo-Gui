#ifndef CLUSTERS_HPP
#define CLUSTERS_HPP

#include <vector>
#include "Point.hpp"

using namespace std;

class Cluster {

  private:
    int cluster_id;
    vector<double> central_values;
    vector<Point> points;

  public:

    Cluster(int clusterId, Point& point);

    void add_point(const Point& point);

    bool remove_point(int point_id);

    int get_central_value_at_index(int index) const;

    void set_central_value_at_index(int index,double value);

    Point get_point_at_index(int index) const;

    size_t get_points_size() const {
      return points.size();
    }

    int get_cluster_id() const;

};

#endif
