#include <iostream>
#include <vector>

#include "KmeansGui.hpp"

using namespace std;

int main(int argc, char **argv) {
  Fl::scheme("gtk+");
  KmeansGui kmeans;
  kmeans.initialise();
  kmeans.show(argc,argv);
  return Fl::run();
}
