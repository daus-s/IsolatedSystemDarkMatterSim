#include "particle.h"
#include "setup.h"

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    setup s;
    s = setup();

    cout << "sim +-" << endl;
    s.sim(1,-1);
    cout << "sim --" << endl;
    s.sim(-1,-1);
    cout << "sim ++" << endl;
    s.sim(1,1);
    cout << "sim -+" << endl;
    s.sim(-1,1);

    return 0;
}
