#include "IsImplies.h"
#include "interestact.h"
#include "temporalrank.h"
#include "enactEL.h"
#include "Enact.h"
#include "Enactage.h"

IsImplies::IsImplies(){    
}

enactEL IsImplies::getEnact(){
    return EL;
}

interestact IsImplies::getInterestAct(){
    return IA;
}

locationact IsImplies::getLocationAct(){
    return LA;
}

temporalrank IsImplies::getTemporalRank(){
    return TR;
}

void IsImplies::setEnact(enactEL el){
    EL=el;
}

void IsImplies::setEnact1(Enactage e, Enact l){
    E.setAction(e.getAction());
    E.setLocation(e.getLocation());
    E.setTemporal(e.getTemporal());
    L.setInterests(l.getInterests()[0],l.getInterests()[1]);
    L.setRank(l.getRank());
}

void IsImplies::setInterestAct(interestact ia){
    IA=ia;
}

void IsImplies::setInterestAct1(Enactage i, action a){
    char* ir=i.getAction();
    char* lr1=i.getLocation();
    I.setAction(ir);
    I.setLocation(lr1);
    I.setAction(a);
    A=a;
}

void IsImplies::setLocationAct1(location loc, action A){
    Loc=loc;
    A=A;
}

void IsImplies::setTemporalRank1(temporal T, rank R){
    T=T;
    R=R;
}

void IsImplies::setTemporalRank(temporalrank tr){
    TR=tr;
}
