
#include "enactEL.h"

enactEL::enactEL(){
    
}

Enactage enactEL::getEnactage(){
    return E;
}

Enact enactEL::getEnactmentL(){
    return L;
}

enactEL::enactEL(Enactage e, Enact l) {
    L.setInterests(l.getInterests()[0], l.getInterests()[1]);
    L.setRank(l.getRank());
    E.setAction(e.getAction());
    E.setLocation(e.getLocation());
    E.setTemporal(e.getTemporal());
}
