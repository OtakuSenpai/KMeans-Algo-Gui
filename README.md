# KMeans Algo in GUI

This is a implentation of the KMeans algo using FLTK gui library in c++.

## Build
 
Download the FLTK library version 1.3.4 and do the following:

```
git clone https://github.com/OtakuSenpai/KMeans-Algo-Gui.git
cd Kmeans-Algo-Gui
mkdir lib && cd lib
cp path/to/downloaded/fltk/lib/ .
tar -xf fltk-1.3.4.tar
cd fltk-xyz
mkdir build && cd build
cmake .. && make
cd ../../../
mkdir build && cd build
cmake .. && make
./kmeans
```

## License

The code is under public domain, feel free to do whatever you like with it.
