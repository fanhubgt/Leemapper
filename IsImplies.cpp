//
// File:   IsImplies.h
// Author: appiah
//
// Created on 4 January 1980, 00:30
//
#include "LEEType.h"
#include "temporalrank.h"
#include "Enact.h"
#include "enactEL.h"
#include "locationact.h"
#include "Enactage.h"
#include "interestact.h"

//using namespace lee::ture;

#ifndef _ISIMPLIES_H
#define	 _ISIMPLIES_H


class IsImplies{
public:
    IsImplies();
    void setEnact1(Enactage E, Enact L);
    void setInterestAct1(Enactage I, action A);
    void setLocationAct1(location Loc, action Ac);
    void setTemporalRank1(temporal T, rank R);
    enactEL getEnact();
    locationact getLocationAct();
    temporalrank getTemporalRank();
    interestact getInterestAct();
    void setEnact(enactEL EL);
    void setInterestAct(interestact IA);
    void setLocationAct(locationact LA);
    void setTemporalRank(temporalrank TR);
private:
    temporalrank TR;
    locationact LA;
    enactEL EL;
    interestact IA;
    Enactage E;
    Enact L;
    rank R;
    action A;
    Enactage I;
    location Loc;
    temporal T;
};
#endif	/* _ISIMPLIES_H */
