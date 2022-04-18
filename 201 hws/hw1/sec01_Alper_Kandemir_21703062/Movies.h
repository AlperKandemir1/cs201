//Alper Kandemir
//21703062
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <string>
using namespace std;

class Movies
{
    public:
        Movies();
        Movies(long ID, int radius);
        ~Movies();
        string getDate();    
        long getID();      
        int getRadius();    
        int getAvailableSeats();
        bool isReserved(int row, int col);
        void reservationDel(int row, int col);
        void reservationAdd(int row, int col);

private:
      string movieDate;
      long movieID;
      int audienceRadius;
      int emptySeat;
      const static int numRow = 30;
      const static int numCol = 26;
      int reservationSize = 0;
      int newCol;
      int newRow;
      int emptyRow[30];
      int emptyCol[26];
    
};

#endif // MOVIES_H
