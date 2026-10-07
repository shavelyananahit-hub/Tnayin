#include <iostream>
#include "gv.h"
#include "ab.h"
#include "ac.h"
#include "ad.h"

int mv = 11;

int main()
{
    oab(mv);
    oac(mv);
    oad(mv);

    mv = 12;

    oab(mv);
    oac(mv);
    oad(mv);

    return 0;
}
