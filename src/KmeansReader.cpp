#include "KmeansReader.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

KMeans KmeansReader::read() {
  std::ifstream file(filename);
  int num_of_points, value_count, cluster_count, maxIterations;
  std::vector<double> point_data;
  double value;
  std::vector<Point> points;
  std::string temp;
  int i = 0;

  std::getline(file,temp,'\n');
  std::stringstream iss(temp);

  if(!(iss >> num_of_points >> value_count >> cluster_count >> maxIterations)) {
    throw std::runtime_error("Unable to parse first line of data file!");
  }

  while(std::getline(file,temp)) {
    ++i;
    iss.str(temp); // assign the current line read from file to stringstream
    iss.clear(); // clear stringstream's state flags
    if(!iss) throw std::runtime_error("Bad input from file!");
    for(int j = 0; j<value_count; j++) {
      iss >> value;
      point_data.push_back(value);
    }
    Point p(i,point_data);
    points.push_back(p);
    point_data.clear();
  }



  KMeans kmean(cluster_count,num_of_points,value_count,maxIterations);
  kmean.run(points);
  return kmean;
}

void KmeansReader::save(KMeans& kmeans) {
  std::fstream file;
  file.open(filename,std::ios::out | std::ios::trunc);
  if(file.is_open()) {
    file << kmeans.show();
  }
  else throw std::runtime_error("Unable to open file at position: " + filename);
}
