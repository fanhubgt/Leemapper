//
// File:   Enact.h
// Author: appiah
//
// Created on 4 January 1980, 01:59
//
#include "LEEType.h"


#ifndef _ENACTAGE_H
#define	_ENACTAGE_H

//using namespace std;

class Enactage{
public:
    Enactage();
    Enactage(action a, location l, temporal t);
    void setAction(action a);
    void setLocation(location l);
    void setTemporal(temporal t);
    action getAction();
    location getLocation();
    temporal getTemporal();
private:
    action act;
    location loc;
    temporal temp;
};

#endif	/* _ENACTAGE_H */

