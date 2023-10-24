#include <iostream>
#include <vector>
#include <string> 
using namespace std;

// BASE CLASS
class Item {
	private:
		string title;
		int rating;
	public:
		// generic constructor for objects
		Item() { }
		// getters and setters
		string getTitle() {
			return title;
		}
		int getRating() {
			return rating;
		}
		void setTitle(string t) {
			title = t;
		}
		void setRating(int r) {
			rating = r+3;
		}
		void print() {
			cout << "Title: " << getTitle() << endl;
			cout << "Rating: " << getRating() << endl;
		}
};
// DERIVED CLASSES
class CD : public Item {
	private:
      string artist;
	public:
	// getters and setters, e.g.
	  string getArtist() {
		  return artist;
	  }
	  void setArtist(string a) {
		  artist = a;	  	
	  }
	// print out function
	  void print() {
	  	  Item::print();
		  cout << "Artist: " << getArtist() << endl;
	  }
};
class Video : public Item {
	private:
      string director;
	public:
	// getters and setters, e.g.
	  string getDirector() {
		  return director;
	  }
	  void setDirector(string d) {
		  director = d;	  	
	  }
	// print out function
	  void print() {
	  	  Item::print();
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
   
   CD cd2;
   cd2.setArtist("Depeche Mode");
   cd2.setRating(4);
   cd2.setTitle("Black Celebration");
   db.add(cd2);

   Video dvd1;
   dvd1.setDirector("Martin Scorsese");
   dvd1.setTitle("Casino");
   dvd1.setRating(3);
   db.add(dvd1);

   db.list();
   
   return 0;
}
