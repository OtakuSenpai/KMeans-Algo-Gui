#include "Point.hpp"

using namespace std;

Point :: Point(int pointId, vector<double>& values) {
    this->point_id = pointId;
    this->values = values;
    values_size = this->values.size();
    this->cluster_id = -1;
}

Point :: Point(int pointId, int clusterId, vector<double>& values) {
    this->point_id = pointId;
    this->values = values;
    this->cluster_id = clusterId;
    this->values_size = values.size();
    this->cluster_id = -1;
}

int Point :: get_point_id() const {
    return point_id;
}

int Point :: get_cluster_id() const {
    return cluster_id;
}

void Point::set_cluster_id(int cluster_id) {
    this->cluster_id = cluster_id;
}

int Point :: get_values_size() const {
    return values_size;
}

double Point :: get_value_at_index(int index) const{
  return this->values.at(index);
}

void Point :: add_value(double value) {
  values.push_back(value);
}


