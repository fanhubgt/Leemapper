//
// File:   ImplieStruct.h
// Author: appiah
//
// Created on 4 January 1980, 01:15
//

#include "Enact.h"
#include "Enactage.h"


#ifndef _TEMPORALRANK_H
#define	_TEMPORALRANK_H



class temporalrank{
public:
    temporalrank();
    temporalrank(Enact ee, Enactage eage);
    Enact getEnactment();
    Enactage getEngagement();
    char* toString();
protected:
    Enact T;
    Enactage R;
};
#endif	/* _TEMPORALRANK_H */

