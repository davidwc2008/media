#include "media.h"

class music:public media{
 public:
  music(char *, char *, char *, char *, char *, char *);
  void getartist();
  void getduration();
  void getpublisher();
  void twostring();
  ~music();
  
 protected:
  char *artist;
  char *duration;
  char *publisher;
};
