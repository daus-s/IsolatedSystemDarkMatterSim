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
    s.sim(1,-1,"plusminus");
    cout << "sim --" << endl;
    s.sim(-1,-1,"minusminus");
    cout << "sim ++" << endl;
    s.sim(1,1,"plusplus");
    cout << "sim -+" << endl;
    s.sim(-1,1,"minusplus");

    return 0;
}
