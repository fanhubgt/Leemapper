// 
// File:   interestact.h
// Author: appiah
//
// Created on 4 January 1980, 03:38
//

#include "LEEType.h"
#include "Enactage.h"
#include "Enact.h"

#ifndef _INTERESTACT_H
#define	_INTERESTACT_H

class interestact{
public:
    interestact();
    interestact(Enactage ia, Enact en);
protected:
    Enactage I;
    Enact A;
};



#endif	/* _INTERESTACT_H */

