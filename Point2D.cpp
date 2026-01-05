#include "Point2D.h"
#include <cmath>

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}

double distance(const Point2D &a, const Point2D &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool operator==(const Point2D &a, const Point2D &b){
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(const Point2D &a, const Point2D &b){
    return !(a == b);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p){
    return out << "(" << p.x << ", " << p.y << ")";
}

