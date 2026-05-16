#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
public:
    int userId;
    std::string start;
    std::string destination;

    Route(int userId, const std::string& start, const std::string& destination);
};

#endif
