#include "locationact.h"

locationact::locationact(){
    
}

locationact::locationact(Enactage la){
     locAct=la;    
}

Enactage locationact::getEngagement(){
    return locAct;
}

