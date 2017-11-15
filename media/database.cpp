/*
David Chen
2017
Media Program in C++
*/

//include libraries
#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "music.h"
#include "game.h"
#include "movie.h"

using namespace std;

//function prototype
void add(vector<media*> *plist);
void search(vector<media*> *plist);
void remove(vector<media*> *plist);

//main function
int main()
{
  vector<media*> list;
  vector<media*> *plist = &list;
  char input[10];
  char invalid = 'y';

  cout << "Welcome to the Media Program." << endl;

  //user input and function calling
  while (invalid == 'y') {
    cout << "Type ADD to add data, SEARCH to search existing data, DELETE to remove existing data, and QUIT to quit." << endl;
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      add(plist);
    } else if (strcmp(input, "SEARCH") == 0) {
      search(plist);
    } else if (strcmp(input, "DELETE") == 0) {
      remove(plist);
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "The program is now quiting." << endl;
      invalid = 'n';
    } else {
      cout << "Unknown input.  Would you like to try again?  Press y for yes and n for no." << endl;
      cin >> invalid;
    }
  }

  return 0;
}

//add function
void add(vector<media*> *plist)
{
  //first start with the media parent information
  char *name = new char[20];
  char *year = new char[10];
  char *type = new char[10];

  cout << "Input name: " << endl;
  cin.get();
  cin.get(name, 20);
  cin.get();
  cout << "Input year: " << endl;
  cin >> year;
  cout << "Input type (MUSIC, MOVIE, GAME): " << endl;
  cin >> type;
  
  //secondly, enter the special input for different types
  if (strcmp(type, "MUSIC") == 0) {
    char *artist = new char[20];
    char *duration = new char[10];
    char *publisher = new char[20];

    cout << "Input artist: " << endl;
    cin.get();
    cin.get(artist, 20);
    cin.get();
    cout << "Input duration: " << endl;
    cin >> duration;
    cout << "Input publisher: " << endl;
    cin.get();
    cin.get(publisher, 20);
    cin.get();
    
    music* a = new music(name, "MUSIC", year, artist, duration, publisher);
    plist -> push_back(a);
    
  } else if (strcmp(type, "MOVIE") == 0) {
    char *director = new char[20];
    char *duration = new char[10];
    char *rating = new char[10];

    cout << "Input director: " << endl;
    cin.get();
    cin.get(director, 20);
    cin.get();
    cout << "Input duration: " << endl;
    cin >> duration;
    cout << "Input rating: " << endl;
    cin >> rating;

    movie* a = new movie(name, "MOVIE", year, director, duration, rating);
    plist -> push_back(a);
    
  } else if (strcmp(type, "GAME") == 0) {
    char *publisher = new char[20];
    char *rating = new char[10];

    cout << "Input publisher: " << endl;
    cin.get();
    cin.get(publisher, 20);
    cin.get();
    cout << "Input rating: " << endl;
    cin >> rating;

    game* a = new game(name, "GAME", year, publisher, rating);
    plist -> push_back(a);
    
  } else {
    cout << "Unknown type." << endl;
  }
  
}

//search function
void search(vector<media*> *plist)
{
  //what to search by?
  char searchby[10];
  cout << "Would you like to search by title or by year?  Type TITLE or YEAR." << endl;
  cin >> searchby;

  //search by title method
  if (strcmp(searchby, "TITLE") == 0) {
    char name[20];
    cout << "Input title: " << endl;
    cin.get();
    cin.get(name, 20);
    cin.get();

    for(vector<media*>::iterator it = plist -> begin(); it != plist -> end(); it++) {
      media* random = *it;
      if(!strcmp(random->getname(), name)) {
	random -> twostring(); //this calls the print function
      }
    }

    //search by year method
  } else if (strcmp(searchby, "YEAR") == 0) {
    char year[10];
    cout << "Input year: " << endl;
    cin >> year;

    for(vector<media*>::iterator it = plist -> begin(); it != plist -> end(); it++) {
      media* random = *it;
      if(!strcmp(random->getyear(), year)) {
	random -> twostring();
      }
    }
    
  } else {
    cout << "Invalid input." << endl;
  }
  
}

//remove function
void remove(vector<media*> *plist)
{
  //similar to search except we delete it when we find it
  
  //this variable is used for whether or not a particular data set should be deleted.  Also serves a generic use in the while loop.
  char choice = 'y';

  //prompt the user if he/she wants to search by title or year
  char searchby[10];
  cout << "Would you like to search by title or by year?  Type TITLE or YEAR." << endl;
  cin >> searchby;
  
  //method for if user wants to search by title
  if (strcmp(searchby, "TITLE") == 0) {
    char name[20];
    cout << "Input title: " << endl;
    cin.get();
    cin.get(name, 20);
    cin.get();

    while (choice == 'y') {
      choice = 'n';
      for(vector<media*>::iterator it = plist -> begin(); it != plist -> end(); it++) {
	media* random = *it;
	if(!strcmp(random->getname(), name)) {
	  random -> twostring();
	  cout << "Would you like to delete this data? Type y for yes and n for no." << endl;
	  cin >> choice;
	  if (choice == 'y') {
	    plist -> erase(plist -> begin());
	    break; //breaks the for loop so that the iterator can do it again fresh
	  } 
	}	    
      }
    }
    cout << "All deletes successful." << endl;

    //method for if the user wants to search by year
  } else if (strcmp(searchby, "YEAR") == 0) {
    char year[10];
    cout << "Input year: " << endl;
    cin >> year;

    choice = 'y';
    while (choice == 'y') {
      choice = 'n';
      for(vector<media*>::iterator it = plist -> begin(); it != plist -> end(); it++) {
        media* random = *it;
        if(!strcmp(random->getyear(), year)) {
          random -> twostring();
          cout << "Would you like to delete this data? Type y for yes and n for no." << endl;
          cin >> choice;
          if (choice == 'y') {
            plist -> erase(plist -> begin());
            break; //breaks the for loop so that the iterator can do it again fresh
          }
        }
      }
    }
    cout << "All deletes successful." << endl;
  } else {
    cout << "Invalid input." << endl;
  }
}

