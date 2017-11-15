#include "media.h"

class movie:public media{
 public:
  movie(char *, char *, char *, char *, char *, char *);
  void getdirector();
  void getduration();
  void getrating();
  void twostring();
  ~movie();
  
 protected:
  char *director;
  char *duration;
  char *rating;
};
