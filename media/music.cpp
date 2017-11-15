#include "music.h"
#include <iostream>

using namespace std;

music::music(char *Name, char *Type, char *Date, char *Artist, char *Duration, char *Publisher):media(Name, Type, Date) {
  artist = Artist;
  duration = Duration;
  publisher = Publisher;
}

//getartist function
void music::getartist(){
  cout << artist << endl;
}

//getduration function
void music::getduration(){
  cout << duration << endl;
}

//getpublisher function
void music::getpublisher(){
  cout << publisher << endl;
}

//twostring function
void music::twostring(){
  media::twostring();
  cout << "The artist is " << artist << endl;
  cout << "The duration is " << duration << endl;
  cout << "The publisher is " << publisher << endl;
}

//destructor
music::~music(){
  delete artist;
  delete duration;
  delete publisher;
  delete media::name;
  delete media::type;
  delete media::year;
}
