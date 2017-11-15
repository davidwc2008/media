#include "movie.h"
#include <iostream>

using namespace std;

movie::movie(char *Name, char *Type, char *Date, char *Director, char *Duration, char *Rating):media(Name, Type, Date) {
  director = Director;
  duration = Duration;
  rating = Rating;
}

//getdirector function
void movie::getdirector(){
  cout << *director << endl;
}

//getduration function
void movie::getduration(){
  cout << *duration << endl;
}
//getrating function
void movie::getrating(){
  cout << *rating << endl;
}

//twostring function
void movie::twostring(){
  media::twostring();
  cout << "The director is " << director << endl;
  cout << "The duration is " << duration << endl;
  cout << "The rating is " << rating << endl;
}

//destructor
movie::~movie(){
  delete director;
  delete duration;
  delete rating;
  delete media::name;
  delete media::type;
  delete media::year;
}
