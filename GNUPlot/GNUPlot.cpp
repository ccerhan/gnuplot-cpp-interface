#include "GNUPlot.h"

GNUPlot::GNUPlot()
{
    _pipe = nullptr;
}

GNUPlot::~GNUPlot()
{
    close();
}

void GNUPlot::open()
{
    close();
    _pipe = popen("gnuplot", "w");
}

bool GNUPlot::isOpened() const
{
    return _pipe != nullptr;
}

void GNUPlot::flush()
{
    if (isOpened())
    {
        fflush(_pipe);
    }
}

void GNUPlot::close()
{
    if (isOpened())
    {
        pclose(_pipe);
        _pipe = nullptr;
    }
}

void GNUPlot::write(const char *line)
{
    if (isOpened() && line != nullptr && line[0] != '\0')
    {
        fprintf(_pipe, "%s\n", line);
    }
}

void GNUPlot::write(const std::string &line)
{
    if (!line.empty())
    {
        write(line.c_str());
    }
}

void GNUPlot::execute(const std::vector<std::string> &script)
{
    if (isOpened())
    {
        for (size_t i = 0; i < script.size(); i++)
        {
            write(script[i]);
            flush();
        }
    }
}

