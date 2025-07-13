#pragma once

struct interval
{
    double min{ 0.0 };
    double max{ 0.0 };

    interval() : min(+infinity), max(-infinity) {}

    interval(double min, double max) : min(min), max(max) {}

    double size() const
    {
        return max - min;
    }

    bool contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }

    static const interval empty;
    static const interval universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);