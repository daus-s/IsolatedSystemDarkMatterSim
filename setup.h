#include "particle.h"

class setup
{
    public:
        particle p1;
        particle p2;

        void sim(int i, int x, std::string run);
        float getForce(particle p);
        int direction(particle p);
        setup();
};
