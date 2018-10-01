#include "Cluster.hpp"

using namespace std;

Cluster::Cluster(int clusterId, Point& point) {
  this->cluster_id = clusterId;

  for(int i = 0; i < point.get_values_size(); i++)
    central_values.push_back(point.get_value_at_index(i));

  points.push_back(point);
}

void Cluster::add_point(const Point& p) {
  points.push_back(p);
}

bool Cluster::remove_point(int point_id) {
  bool found = false;
  for(size_t i = 0; i < points.size(); i++) {
    if(points.at(i).get_point_id() == point_id) {
      points.erase(points.begin() + i);
      found = true;
    }
  }
  return found;
}

int Cluster::get_central_value_at_index(int index) const {
  return central_values.at(index);
}

void Cluster::set_central_value_at_index(int index, double value) {
  central_values[index] = value;
}

Point Cluster::get_point_at_index(int index) const {
  return points.at(index);
}

int Cluster::get_cluster_id() const {
  return cluster_id;
}
