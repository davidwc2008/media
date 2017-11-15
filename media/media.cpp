#include "media.h"
#include <iostream>

using namespace std;

media::media(char *Name, char *Type, char *Date) {
  name = Name;
  type = Type;
  year = Date;
}

char* media::getname(){
  return name;
}

char* media::getyear(){
  return year;
}

char* media::gettype(){
  return type;
  
}

void media::twostring(){
  cout << "The name is " << name << endl;
  cout << "The type is " << type << endl;
  cout << "The year is " << year << endl;
}
