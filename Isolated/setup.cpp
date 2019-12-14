#include "setup.h"
#include <fstream>
#include <iostream>

void setup::sim(int i, int z)
{
    p1 = particle(i);
    p2 = particle(z);
    p1.x = 1;
    p2.x = 0;

    std::ofstream clout;
    clout.open("log.txt");

    int j = 0;
    while (p1.x>p2.x && (getForce(p1)<.0001||getForce(p1)<.0001))
    {
        p1.F = getForce(p1);
        p2.F = getForce(p2);
        p1.move();
        p2.move();
        clout << j << "\np1: " << p1.print() << "\np2:" << p2.print() << "\n";
        clout << "K: " << (p1.E + p2.E) << " P: " << ((2*p1.mass*p2.mass)/(p1.x-p2.x)) << "\n";
        clout << "E: " << (p1.E + p2.E) + ((2*p1.mass*p2.mass)/(p1.x-p2.x)) << "\n";
        ++j;
    }
}

float setup::getForce(particle p)
{
    if (p.x-p1.x!=0)
        return ((p1.mass * p.mass) / ((p.x-p1.x)*(p.x-p1.x)));
    return ((p2.mass * p.mass) / ((p.x-p2.x)*(p.x-p2.x)));
}

setup::setup()
{
    p1 = particle(0);
    p2 = particle(0);
}
