//
// File:   LeeMain.cc
// Author: appiah
//
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <iterator>
#include <sys/unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sched.h>
#include <pthread.h>
#include <fstream>
#include <unistd.h>
#include "LEEType.h"
#include "IsImplies.h"

using namespace std;

namespace{
    
    action a="buy", a1="sell", a2="sold", a3="trade";
    
    interest ia="sell_pc", ia1="buy_pc";
    rank r="rank_9";
    location loc="tottenham", loc1="London";
    temporal temp="Sat 12/09/2019 12:00pm";
    
    std::string go;
    IsImplies is;
    
    std::string enterStarts(){
        std::string start;
        std::cout<< std::endl<< "Enter[ok] to start>>"<< std::endl;
        getline(std::cin, start);
        return start;
    }
    
    std::string enterContinues(){
        std::string con="go";
        std::cout<< std::endl<< "Enter number[go(1)/no(2)] to continue>>"<< std::endl;
        getline(std::cin, con);
        go=strtol(con.c_str(), 0, 10);
        std::cout << "Go Value:=#" << go << std::endl;
        return con;
    }
    
    inline std::ostream& italic(std::ostream& stream){
        stream << "\033[3m";
        return stream;
    }
    
    inline std::ostream& reset(std::ostream& stream){
        stream << "\033[00m";
        return stream;
    }
    
    inline std::ostream& bold(std::ostream& stream){
        stream << "\033[1m";
        return stream;
    }
    
    inline std::ostream& underline(std::ostream& stream){
        stream << "\033[4m";
        return stream;
    }
    
    inline std::ostream& blink(std::ostream& stream){
        stream << "\033[5m";
        return stream;
    }
    
    inline std::ostream& dark(std::ostream& stream){
        stream << "\033[2m";
        return stream;
    }
    
    template <int code> inline
    std::ostream& color(std::ostream& stream){
        char command[12];
        snprintf(command, sizeof(command), "\033[38;5;%dm", code);
        stream<< command;
        return stream;
    }
    
    template <int r, int g, int b> inline
    std::ostream& color(std::ostream& stream){
        char command[20];
        snprintf(command, sizeof(command), "\033[38;2;%d;%d;%dm", r, g, b);
        stream<< command;
        return stream;
    }
    
    void setLEEValues(){
        
        
        Enactage en1;
        en1.setAction(a);
        en1.setLocation(loc);
        en1.setTemporal(temp);
        
        Enact en2;
        en2.setInterests(ia, ia1);
        en2.setRank(r);
        
        is.setEnact1(en1, en2);
        
        enactEL EL(en1, en2);
        is.setEnact(EL);
        Enactage EA(a, loc, temp);
        is.setInterestAct1(EA, a);
        
        is.setEnact1(EA, en2);
        
        locationact LA(en1);
        
        is.setLocationAct1(loc, a);
        temporalrank TR(en2, EA);
        
        is.setTemporalRank1(temp, r);
        
    }
    
    void setContextLanguage(){
        cout<<endl<<"Structural Language Context(SLC)"<<reset<<endl;
        cout<<color<33, 33, 33><<"(1)  Enact_E ---> Enact_L ::="<<reset;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        cout<<color<34, 34, 34><<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" ---> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<33, 33, 33><<"(2)  a_i ---> a_j ::= ";
        cout<<color<34, 34, 34><<is.getEnact().getEnactage().getAction();
        cout<<"--->"<<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<endl<<color<33, 33, 33><<"(3)  a_j ---> l ::= "<<reset;
        cout<<color<34, 34, 34><<iss[0];
        cout<<" --->"<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<endl<<color<33, 33, 33><<"(4)  rank_i ---> t ::= "<<reset;
        cout<<color<34, 34, 34><<is.getEnact().getEnactmentL().getRank();
        cout<<" --->"<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        sleep(1);
        cout<<color<33, 21, 43><<bold<<"Contextual Language for LEE"<<reset<<endl;
        cout<<color<45, 34, 30><<"(i)The enact of business implies the enact of machinery, partonomy, interest, attention and more logic."<<endl;
        cout<<"(ii)The enact of business interest implies the enact of business action or event.";
        cout<<endl<<"(iii)The enact of business interest implies the enact of interest in a location.";
        cout<<endl<<"(iv)The enact rank of business interest implies the enact of the linear/temporal ordering of interest.";
        cout<<reset<<endl;
    }
    
    void setIsLanguage(){
        sleep(1);
        cout<<color<33, 33, 33><<"LEE is_Language"<<reset;
        sleep(1);
        cout<<color<33, 21, 43><<bold<<"Contextual Language for LEE_is"<<reset<<endl;
        cout<<color<45, 34, 30><<"(i) The enact of business is the enact of logic."<<endl;
        cout<<"(ii) The enact of business interest is the implication of business action. ";
        cout<<endl<<"(iii) The enact of business interest is in a location.";
        cout<<endl<<"(iv) The enact of business rank is based on temporal dimensions.";
        cout<<reset<<endl;
        
    }
    
    
    void setLEEImplies(){
        cout<<endl<<color<45, 46, 33><<"LEE Implies(LEE->)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" implies "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" implies "<<reset<<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(3)"<<iss[0];
        cout<<color<32><<" implies "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" implies "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        sleep(1);
        cout<<color<33, 21, 43><<bold<<"Contextual Language for LEE Implications"<<reset<<endl;
        cout<<color<45, 34, 30><<"(i)The enact of business is the enact of logic."<<endl;
        cout<<"(ii)The enact of business interest is the implication of business action.";
        cout<<endl<<"(iii)The enact of business interest is in a location.";
        cout<<endl<<"(iv)The enact of business rank is based on temporal dimensions.";
        cout<<reset<<endl;
    }
    
    void setLEEImpliesLang(){
        cout<<endl<<color<45, 46, 33><<"LEE Implies Language(LEE->)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" implies "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        cout<<color<34, 34, 34><<"(2) Interest "<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" implies Action "<<reset<<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(3) Interest "<<iss[0];
        cout<<color<32><<" implies Action in Location "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(4) Rank interest "<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" implies Ordering in temporal dimension "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        sleep(1);
        cout<<color<33, 21, 43><<bold<<"Contextual Language for LEE Implications"<<reset<<endl;
        cout<<color<45, 34, 30><<"(i)The enact of business is the enact of logic."<<endl;
        cout<<"(ii)The enact of business interest is the implication of business action.";
        cout<<endl<<"(iii)The enact of business interest is in a location.";
        cout<<endl<<"(iv)The enact of business rank is based on temporal dimensions.";
        cout<<reset<<endl;
    }
    
    void setLEEDoubleArrow(){
        cout<<endl<<color<45, 46, 33><<"LEE Double Arrow(LEE<==>)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" <==> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" <==> "<<reset<<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(3)"<<iss[0];
        cout<<color<32><<" <==> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" <==> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        
    }
    
    void setLEEStructLang(){
        cout<<endl<<color<45, 46, 33><<"LEE Structural Language(LEEStruct Language)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        sleep(1);
        cout<<color<45, 31, 36><<"Reading\n::A run(r) of an agent in an engaged environment is thus a sequence of inter-logic environment of states and actions."<<reset<<endl;
        enterContinues();
        cout<<color<34, 34, 34><<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" --> "<<reset<<iss[0]<<reset<<endl;
        cout<<color<45, 31, 36><<"Reading\n::A run of an agent by a sequence of inter-logic environment of states and actions in an engaged environment."<<reset<<endl;
        enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(3)"<<iss[0];
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        sleep(1);
        cout<<color<45, 31, 36><<"Reading\n::A run of an agent by sequence of inter-logic states and actions is localized in an engaged environment."<<reset<<endl;
        enterContinues();
        cout<<color<34, 34, 34><<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        cout<<color<45, 31, 36><<"Reading\n::A state is initially ranked in an engaged environment before choosing an action to execute (run in a specific time)."<<reset<<endl;
        
    }
    
    void setLEEAbbLanguage(){
        cout<<endl<<color<45, 46, 33><<"LEE Abbreviation Language(LEEAbb Language)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" <==> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        sleep(1);
        cout<<color<45, 31, 36><<"Reading\n::An Enact_E will exist to be true implies Enact_L is true and  Enact_L existence is true implies Enact_E is true."<<reset<<endl;
        enterContinues();
        cout<<color<34, 34, 34><<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" <==> "<<reset<<iss[0]<<reset<<endl;
        cout<<color<45, 31, 36><<"Reading\n::An interest a_i will exist to be true implies a_i is true and a hold to be true in existence implies a_i is existentially true."<<reset<<endl;
        enterContinues();
        cout<<color<34, 34, 34><<"(3)"<<iss[0];
        cout<<color<32><<" <==> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        sleep(1);
        cout<<color<45, 31, 36><<"Reading\n::An interest enaction, a_j is existentially true implies location exist to be true and location,l is very true in existence implies interest holding is truly in existence."<<reset<<endl;
        enterContinues();
        cout<<color<34, 34, 34><<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" <==> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        cout<<color<45, 31, 36><<"Reading\n::A rank for interest will exist true implies a chosen priority in time holds to be true."<<reset<<endl;
        
    }
    
    void setLEEDoubleArrowStruct(){
        cout<<endl<<color<45, 46, 33><<"LEE Double Arrow Structures(LEE<-->)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"(1) (Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<"))"<<reset;
        sleep(1);
        cout<<color<32><<" and "<<reset<<" (Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset;
        cout<<color<32><<" --> "<<reset<<color<34, 34, 34><<" Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<"))"<<endl;
        sleep(1);
//enterContinues();
        cout<<color<34, 34, 34><<"(2) ("<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" --> "<<reset<<iss[0]<<reset;
        cout<<color<35, 35, 35><<") and ("<<iss[0];
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getAction()<<")"<<reset<<endl;
        sleep(1);
        
        // enterContinues();
        cout<<color<34, 34, 34><<"(3) ("<<iss[0];
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset;
        cout<<color<35, 35, 35><<") and ("<<is.getEnact().getEnactage().getLocation();
        cout<<color<32><<" --> "<<reset<<iss[0]<<")"<<reset<<endl;
        
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(4) ("<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" ---> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset;
        cout<<color<35, 35, 35><<") and ("<<is.getEnact().getEnactage().getTemporal();
        cout<<color<32><<" ---> "<<reset<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl;
        sleep(1);
        enterContinues();
        
    }
    
    
    void setLEEAbb(){
        cout<<endl<<color<45, 46, 33><<"LEE Abbreviation(LEEAbb)::{";
        cout<<"LEE Implies are now abbreviated below:}"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        sleep(1);
        cout<<color<34><<"(1) not "<<reset<<color<31, 31, 31><<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")"<<reset<<endl;
        cout<<color<32><<" or "<<reset<<color<36, 36, 36><<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34><<"(2) not "<<reset<<color<31, 31, 31><<is.getEnact().getEnactage().getAction()<<reset;
        cout<<color<32><<" or "<<reset<<color<36, 36, 36><<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<color<34><<"(3) not "<<reset<<color<31, 31, 31><<iss[0]<<reset;
        cout<<color<32><<" or "<<reset<<color<36, 36, 36><<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34><<"(4) not "<<reset<<color<31, 31, 31><<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" or "<<reset<<color<36, 36, 36><<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        
        // cout<<reset<<endl;
    }
    
    
    void setLEELinearOrd(){
        cout<<endl<<color<45, 46, 33><<"LEE Mapping Structure(LEE-Linear Ordering)"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<color<32><<" --> "<<reset;
        //enterContinues();
        cout<<color<34, 34, 34><<is.getEnact().getEnactage().getAction()<<reset;
        cout<<color<32><<" --> "<<reset<<iss[0]<<reset;
        // enterContinues();
        sleep(1);
        cout<<color<32><<" --> "<<reset;
        cout<<color<34, 34, 34><<iss[0]<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset;
        //enterContinues();
        sleep(1);
        cout<<color<32><<" --> "<<reset;
        cout<<color<34, 34, 34><<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        
        cout<<reset<<endl;
    }
    
    void setLEEConsequentRun(){
        cout<<endl<<color<45, 46, 33><<"LEE Consequent Runs(LEE-runs)\n"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        cout<<color<34, 60, 43><<"D::Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<color<33><<" --> "<<reset;
        cout<<is.getEnact().getEnactage().getAction()<<endl;
        cout<<reset;
        sleep(1);
        cout<<color<32, 44, 55><<"Di::Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<color<32><<" --> "<<reset;
        cout<<is.getEnact().getEnactage().getAction();
        cout<<color<43><<" --> "<<reset<<iss[0]<<endl;
        cout<<reset;
        sleep(1);
        cout<<color<36, 41, 45><<"Dii::"<<iss[0];
        cout<<color<32><<" --> "<<reset;
        cout<<iss[1];
        cout<<color<33><<" --> "<<reset<<is.getEnact().getEnactage().getAction()<<endl;
        cout<<reset;
        sleep(1);
        cout<<color<44, 55, 12><<"Diii::"<<iss[0];
        cout<<color<32><<" --> "<<reset;
        cout<<iss[1]<<reset;
        cout<<color<35><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        sleep(1);
        cout<<color<30, 38, 47><<"Div::"<<iss[1];
        cout<<color<36><<" --> "<<reset;
        cout<<is.getEnact().getEnactage().getLocation()<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactmentL().getRank()<<reset<<endl;
        sleep(1);
        cout<<color<42, 67, 34><<"Dv::"<<is.getEnact().getEnactage().getLocation()<<reset;
        cout<<color<34><<" --> "<<reset;
        cout<<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        
    }
    
    void setLEEComposite(){
        cout<<endl<<color<45, 46, 33><<"LEE Propose Enactment (Enactment Formulas)\n"<<reset<<endl;
        
        cout<<color<33><<"Propositional Constants::"<<reset<<color<32><<"\nT and F\n"<<reset;
        
        cout<<endl<<color<45, 46, 33><<"Propositional Variables::"<<reset<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        sleep(1);
        cout<<color<34, 34, 34><<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" , "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<color<32><<" , "<<reset;
        //enterContinues();
        cout<<color<34, 34, 34><<is.getEnact().getEnactage().getAction()<<reset;
        cout<<color<32><<" , "<<reset<<iss[0]<<reset;
        // enterContinues();
        sleep(1);
        cout<<color<32><<" , "<<reset;
        cout<<color<34, 34, 34><<iss[0]<<reset;
        cout<<color<32><<" , "<<reset<<is.getEnact().getEnactage().getLocation()<<reset;
        //enterContinues();
        sleep(1);
        cout<<color<32><<" , "<<reset;
        cout<<color<34, 34, 34><<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" , "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        
        cout<<endl<<color<45, 46, 33><<"Propositional Composites::"<<reset<<endl;
        cout<<endl<<color<45, 46, 32><<"or-Composites"<<reset<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(i) not Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" or "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(ii) not "<<is.getEnact().getEnactage().getAction()<<reset;
        cout<<color<32><<" or "<<reset<<iss[0]<<reset<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(iii) not "<<iss[0]<<reset;
        cout<<color<32><<" or "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(iv) not "<<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" or "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        
        cout<<endl<<color<45, 46, 32><<"not-Composites"<<reset<<endl;
        sleep(1);
        sleep(1);
        cout<<color<34, 34, 34><<"(i) not "<<reset<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")"<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(ii) not "<<reset<<is.getEnact().getEnactage().getAction()<<reset<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(iii) not "<<reset<<iss[0]<<reset<<endl;
        cout<<color<34, 34, 34><<"(iv) not "<<reset<<is.getEnact().getEnactmentL().getRank()<<reset<<endl;
        
        cout<<endl<<color<45, 46, 32><<"and-Composites"<<reset<<endl;
        
        sleep(1);
        cout<<color<34, 34, 34><<"(i)  (Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<"))";
        cout<<color<32><<" and "<<reset<<"(Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<color<32><<" --> "<<reset<<color<34, 34, 34><<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<"))"<<endl;
        
        sleep(1);
        cout<<color<34, 34, 34><<"(ii) ("<<is.getEnact().getEnactage().getAction()<<reset;
        cout<<color<32><<" --> "<<reset<<iss[0]<<reset;
        cout<<color<32><<") and ("<<reset<<iss[0]<<reset;
        cout<<color<32><<" --> "<<reset;
        cout<<color<34, 34, 34><<" "<<is.getEnact().getEnactage().getAction()<<")"<<reset<<endl;
        
        sleep(1);
        cout<<color<34, 34, 34><<"(iii) ("<<iss[0]<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset;
        cout<<color<32><<" ) and ( "<<reset<<is.getEnact().getEnactage().getLocation()<<reset;
        cout<<color<34, 34, 34><<" --> "<<reset<<iss[0]<<")"<<reset<<endl;
        
        sleep(1);
        cout<<color<34, 34, 34><<"(iv) ("<<is.getEnact().getEnactmentL().getRank()<<reset;
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset;
        cout<<color<32><<") and ( "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset;
        cout<<color<34, 34, 34><<" --> "<<reset<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl;
        
        cout<<endl<<color<45, 46, 32><<"implies-Composites"<<reset<<endl;
        sleep(1);
        cout<<color<34, 34, 34><<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<color<32><<" --> "<<reset<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<reset<<endl<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<color<32><<" --> "<<reset<<iss[0]<<reset<<endl;
        // enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(3)"<<iss[0];
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getLocation()<<reset<<endl;
        //enterContinues();
        sleep(1);
        cout<<color<34, 34, 34><<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<color<32><<" --> "<<reset<<is.getEnact().getEnactage().getTemporal()<<reset<<endl;
        enterContinues();
        sleep(1);
        
        
    }
}

int main(int argc, char** argv) {
    
    cout<<color<36><<"LEE Run- (L)ogical (E)ngage (E)nactment Program"<<endl;
    cout<<reset<<endl;
    
    enterStarts();
    
    cout<<"LEE Language and Composites"<<endl;
    cout<<"Enactment Formalizations"<<endl;
    cout<<"Developed by: Frank Appiah"<<endl;
    
    enterContinues();
    cout<<"\n========================================\n        Enactment Logic Solution Menu\n======================================="<<endl;
    cout<<color<12, 45, 36><<"(1):: Context Language"<<endl;
    sleep(1);
    cout<<"(2):: LEE Implications"<<endl;
    sleep(1);
    cout<<"(3):: LEE Imply Language"<<endl;
    sleep(1);
    cout<<"(4):: LEE Linear Ordering"<<endl;
    sleep(1);
    cout<<"(5):: LEE Abbreviation(Abb)"<<endl;
    sleep(1);
    cout<<"(6):: LEE AbbStruct Language"<<endl;
    sleep(1);
    cout<<"(7):: LEE Abbreviation Language"<<endl;
    cout<<"(8):: LEE Double Arrow(DA)"<<endl;
    sleep(1);
    cout<<"(9):: LEE DA Structures"<<endl;
    cout<<"(10):: LEE is_Language"<<endl;
    sleep(1);
    cout<<"(11):: LEE Consequent Run"<<endl;
    cout<<"(12):: Enactment Formalizations"<<endl;
    cout<<reset<<endl;
    cout<<color<41, 66, 30><<"Building the Enactment Engagement Language....."<<endl;
    sleep(2);
    setLEEValues();
    enterContinues();
    setContextLanguage();
    enterContinues();
    setLEEImplies();
    enterContinues();
    setLEEImpliesLang();
    enterContinues();
    setLEELinearOrd();
    enterContinues();
    setLEEAbb();
    enterContinues();
    setLEEStructLang();
    enterContinues();
    setLEEAbbLanguage();
    enterContinues();
    setLEEDoubleArrow();
    enterContinues();
    setLEEDoubleArrowStruct();
    enterContinues();
    setIsLanguage();
    enterContinues();
    setLEEConsequentRun();
    enterContinues();
    setLEEComposite();
    enterContinues();
    
    return (EXIT_SUCCESS);
    
}

