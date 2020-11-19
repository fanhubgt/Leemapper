// 
// File:   enactEL.h
// Author: appiah
//
// Created on 4 January 1980, 03:30
//
#include "LEEType.h"
#include "Enactage.h"
#include "Enact.h"

#ifndef _ENACTEL_H
#define	_ENACTEL_H


class enactEL{
public:
    enactEL();
    enactEL(Enactage E, Enact L);
    Enactage getEnactage();
    Enact getEnactmentL();
private :
    Enactage E;
    Enact L;
};

#endif	/* _ENACTEL_H */

