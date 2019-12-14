#include "setup.h"
#include <fstream>
#include <iostream>

void setup::sim(int i, int z, std::string trial)
{
    p1 = particle(i);
    p2 = particle(z);
    p1.x = 1;
    p2.x = 0;

    std::ofstream clout;
    clout.open(trial+".txt");

    float prev_force;
    int repetition = 0;

    int j = 0;
    while (p1.x>=p2.x && (abs(getForce(p1))>.0001||abs(getForce(p1))>.0001) && repetition <= 100)
    {
        p1.F = getForce(p1) * direction(p1);
        p2.F = getForce(p2) * direction(p2);
        if (abs(getForce(p1))==abs(prev_force))
            repetition++;
        p1.move();
        p2.move();
        clout << j << "\np1: " << p1.print() << "\np2:" << p2.print() << "\n";
        clout << "K: " << (p1.E + p2.E) << " P: " << ((2*p1.mass*p2.mass)/(p1.x-p2.x)) << "\n";
        clout << "E: " << (p1.E + p2.E) + ((2*p1.mass*p2.mass)/(p1.x-p2.x)) << "\n";
        ++j;
    }
    clout.close();
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

int setup::direction(particle p)
{
    if (p.x == p1.x) //means it is p1
    {
        if (p.x > p2.x)
            return -1;
        if (p.x < p2.x)
            return 1;
    }

    if (p.x == p2.x) //means it is p2
    {
        if (p.x > p1.x)
            return -1;
        if (p.x < p1.x)
            return 1;
    }
}
