#include "particle.h"

#include <fstream>

particle::particle(int i)
{
    mass = i;
    v = 0;
}
particle::particle()
{
    mass = 0;
}

void particle::move()
{
    E = .5*mass*(v + .5*F/mass);
    x += v + .5*F/mass;
    v+=F/mass;
}

std::string particle::print()
{
    return std::to_string(mass) + " v:" + std::to_string(v) + " x:" + std::to_string(x);
}
