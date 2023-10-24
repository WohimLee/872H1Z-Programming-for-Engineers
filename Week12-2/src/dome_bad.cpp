#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class CD {
	private:
	  string title;
	  int rating;
      string artist;
	public:
	// constructor	  
      CD() {} 
	// getters and setters, e.g.
	  string getTitle() {
		  return title;
	  }
	  int getRating() {
		  return rating;
	  }
	  void setRating(int r){
		  rating = r;	  	
	  }
      void setTitle(string t)  {
		  title = t;      	
	  }
	  string getArtist() {
		  return artist;
	  }
	  void setArtist(string a) {
		  artist = a;	  	
	  }
	// print out function
	  void print() {
		  cout << "Title: " << getTitle() << endl;
	  	  cout << "Rating: " << getRating() << endl;
		  cout << "Artist: " << getArtist() << endl;
	  }
};
class Video {
	private:
	  string title;
	  int rating;
      string director;
	public:
	// constructor	  
      Video() {} 
	// getters and setters, e.g.
	  string getTitle() {
		  return title;
	  }
	  int getRating() {
		  return rating;
	  }
	  void setRating(int r){
		  rating = r;	  	
	  }
      void setTitle(string t)  {
		  title = t;      	
	  }
	  string getDirector() {
		  return director;
	  }
	  void setDirector(string d) {
		  director = d;	  	
	  }
	// print out function
	  void print() {
		  cout << "Title: " << getTitle() << endl;
	  	  cout << "Rating: " << getRating() << endl;
		  cout << "Director: " << getDirector() << endl;
	  }
};
// Database class

class Database {
	private:
      vector<CD> cds;
      vector<Video> videos;

	public:
	  void add(CD c) {
		cds.push_back(c);	  	
	  }
	  void add(Video d) {
	    videos.push_back(d);
	  }
	  
      void list() {
         for(int i=0; i< cds.size();i++) {
			cds[i].print();      
			cout << endl;
		 }
         for(int i=0; i< videos.size();i++) {
			videos[i].print();         	
			cout << endl;
		 }

	  }
};

int main() {
   Database db;
   
   CD cd1;
   cd1.setArtist("Queen");
   cd1.setRating(5);
   cd1.setTitle("Greatest Hits");
   db.add(cd1);

   Video dvd1;
   dvd1.setDirector("Martin Scorsese");
   dvd1.setTitle("Casino");
   dvd1.setRating(3);
   db.add(dvd1);

   db.list();
   
   return 0;
}
