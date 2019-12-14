#include <iostream>
#include <string>

#ifndef particleD
#define particleD

class particle
{
    public:
        float mass;
        float v;
        float x;
        float E;
        float F;

        particle(int i);
        particle();
        void move();
        std::string print();
};

#endif
