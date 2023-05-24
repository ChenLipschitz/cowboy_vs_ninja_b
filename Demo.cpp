/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>
#include <chrono>
#include "sources/Team2.hpp"

#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;




int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    cout<<""<<endl;
    cout << sushi->print() <<endl;


    tom->shoot(sushi);
    cout<<""<<endl;
    cout << sushi->print() <<endl;
    cout<<""<<endl;
    cout << tom->print() <<endl;

    cout<<""<<endl;

    sushi->move(tom);
    sushi->slash(tom);
   if (sushi->distance(tom) <= 1){
      cout<<"can slash"<<endl;
      cout<<sushi->getLocation().print()<<endl;
   }
   else{
      cout<<"cannot slash"<<endl;
      cout<<sushi->getLocation().print()<<endl;
   }
    cout<<"after slash"<<endl;
    cout << tom->print() <<endl;
    cout<<""<<endl;
   

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

   //  team_A.print();

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
      cout<<"new iteration\n"<<endl;
        team_A.attack(&team_B);
      //   cout<<"target in team B: "<<team_A.potantial_choice(&team_B)->print()<<endl;
      //   cout<<"in team A "<<team_A.stillAlive()<<" warriors"<<endl;
        team_B.attack(&team_A);
      //   cout<<"target in team A: "<<team_B.potantial_choice(&team_A)->print()<<endl;
      //   cout<<"\n"<<endl;
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}