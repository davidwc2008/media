#pragma once
#include <vector>

class media{
 public:
  char* getname();
  char* getyear();
  char* gettype();
  virtual void twostring();
  media(char *name, char *year, char *type);
 protected:
  char *name;
  char *year;
  char *type;
};


