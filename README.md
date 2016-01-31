# gnuplot-cpp-interface
This is a simplest (highly low-level) C++ interface to gnuplot based on POSIX pipes. 

First, gnuplot must be installed. You can install gnuplot using macports or other package managers. 

Tested for only MAC OSX.

Just copy the header and source files to your project. 

Example scripts can be found in [here](http://gnuplot.sourceforge.net/demo/).

```c++
std::vector<std::string> script;
script.push_back("set terminal x11");
script.push_back("reset");
script.push_back("plot sin(x)");

GNUPlot plotter;
plotter.open();
plotter.execute(script);

getchar(); // prevent graph to close

plotter.write("exit");
plotter.flush();
plotter.close();
```


