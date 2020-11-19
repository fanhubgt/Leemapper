//
// File:   locationact.h
// Author: appiah
//
// Created on 4 January 1980, 03:34
//
#include "Enactage.h"

#ifndef _LOCATIONACT_H
#define	_LOCATIONACT_H

class locationact{
public:
    locationact();
    locationact(Enactage locact);
    Enactage getEngagement();
private:
    Enactage locAct;
};

#endif	/* _LOCATIONACT_H */

