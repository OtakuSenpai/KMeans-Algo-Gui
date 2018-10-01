#ifndef POINT_HPP
#define POINTT_HPP

#include <vector>

using namespace std;

class Point {

private:
  int point_id, cluster_id;
  vector<double> values;
  size_t values_size;

public:

  Point(int pointId, vector<double>& values);

  Point(int pointId, int clusterId, vector<double>& values);

  int get_point_id() const;

  int get_cluster_id() const;

  void set_cluster_id(int cluster_id);

  int get_values_size() const;

  double get_value_at_index(int index) const;

  void add_value(double value);
};

#endif
