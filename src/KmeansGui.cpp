#include "KmeansGui.hpp"

bool KmeansGui::exist(const std::string& filename) {
    std::fstream file(filename);
    bool found = false;
    if(file.is_open()) found = true;
    else found = false;
    return found;
}

void KmeansGui::open(const std::string& filename) {
    KmeansReader reader(filename);
    this->kmeans = reader.read();
}

void KmeansGui::save_data(const std::string& filename) {
    KmeansReader reader(filename);
    reader.save(kmeans);
}
