#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <string>
#include <vector>

class GNUPlot
{
private:
    FILE* _pipe;

public:
    GNUPlot();
    virtual ~GNUPlot();

    bool isOpened() const;

    void open();
    void flush();
    void close();
    void write(const char *line);
    void write(const std::string &line);
    void execute(const std::vector<std::string> &script);
};

#endif //GNUPLOT_H
