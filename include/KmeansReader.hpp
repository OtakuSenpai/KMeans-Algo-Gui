#include <string>

#include "KMeans.hpp"

class KmeansReader {
  private:

    std::string filename;

  public:

    KmeansReader() { }
    KmeansReader(const std::string& filename) {
      this->filename = filename;
    }

    KMeans read();
    void save(KMeans& kmeans);
};
