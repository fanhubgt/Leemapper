#include "Enact.h"

Enact::Enact(){
    
}

Enact::Enact(interest inr1, interest inr2):
IT1(inr1),
IT2(inr2){
    
}

Enact::Enact(interest inr3, interest inr4, rank r){
    IT1=inr3;
    IT2=inr4;
    R=r;
}

interest* Enact::getInterests(){
    IRS[0]=IT1;
    IRS[1]=IT2;
    
    return IRS;
}

rank Enact::getRank(){
    return R;
}

void Enact::setInterests(interest i1, interest i2){
    IT1=i1;
    IT2=i2;
}

void Enact::setRank(rank r)
{
    R=r;
}
