#ifndef KICAD_PCB_SEGMENT_H
#define KICAD_PCB_SEGMENT_H

#include <string>
#include <vector>
#include "point.h"

class Segment
{
public:
    Segment(const int id = -1,
            const int netId = -1,
            const double width = 0,
            const std::string layer = "")
        : m_id(id), m_netId(netId), m_width(width), m_layer(layer) {}

    int getId() { return m_id; }
    int getNetId() { return m_netId; }
    double getWidth() { return m_width; }
    points_2d &getPos() { return m_pos; }
    std::string &getLayer() { return m_layer; }
    void setPosition(const points_2d &_pos) { m_pos = std::move(_pos); }
    double getLength()
    {
        if (m_pos.size() != 2)
            return 0;
        double length = m_pos[0].getDistance(m_pos[0], m_pos[1]);
        return length;
    }

private:
    int m_id;
    int m_netId;
    double m_width;
    points_2d m_pos;
    std::string m_layer;
};

using Segments = std::vector<Segment>;

#endif
