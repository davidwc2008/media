#include "media.h"

class game:public media{
 public:
  game(char *, char *, char *, char *, char *);
  char *getpublisher();
  char *getrating();
  void twostring();
  ~game();
  
 protected:
  char *publisher;
  char *rating;
};
