#include "game.h"
#include <iostream>

using namespace std;

game::game(char *Name, char *Type, char *Date, char *Publisher, char *Rating):media(Name, Type, Date) {
  publisher = Publisher;
  rating = Rating;
}

//getpublisher function
char *game::getpublisher(){
  return publisher;
}

//getrating function
char *game::getrating(){
  return rating;
}

//twostring function
void game::twostring(){
  media::twostring();
  cout << "The publisher is " << publisher << endl;
  cout << "The rating is " << rating << endl;
}

//destructor
game::~game(){
  delete rating;
  delete publisher;
  delete media::name;
  delete media::type;
  delete media::year;
}
