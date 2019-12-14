#include "particle.h"

class setup
{
    public:
        particle p1;
        particle p2;

        void sim(int i, int x);
        float getForce(particle p);
        setup();
};
