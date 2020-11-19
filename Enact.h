//
// File:   Enactage.h
// Author: appiah
//
// Created on 4 January 1980, 02:11
//

#include "LEEType.h"
#ifndef _ENACT_H
#define	_ENACT_H

using namespace std;


class Enact{
public:
    Enact();
    Enact(interest inrs1, interest inrs2);
    Enact(interest inrs1, interest inrs2, rank r);
    void setInterests(interest inrs1, interest inrs2);
    void setRank(rank r);
    rank getRank();
    interest* getInterests();
private:
    rank R;
    interest IRS[2];
    interest IT1;
    interest IT2;
};

#endif	/* _ENACT_H */

