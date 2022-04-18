//Alper Kandemir
//21703062
#ifndef MOVIEBOOKINGSYSTEM_H
#define MOVIEBOOKINGSYSTEM_H
#include "Movies.h"

class MovieBookingSystem{
public:
    const static int numRow = 30;
    const static int numCol = 26;
    MovieBookingSystem();
    ~MovieBookingSystem();
    void addMovie( const long movieID, const int audienceRadius );
    void cancelMovie( const long movieID);
    void showAllMovies();
    void showMovie( const long movieID);
    int makeReservation( const long movieID, const int row, const char col);
    void cancelReservations( const int numRes,const int* resCode);
    void showReservation( const int resCode);
    bool movieExists(long movieID);
    int getIndex(char a);
    
private:
    int reservationSize;
    int movieArrSize;
    int reservationNum;
    int getMovie(long movieId);
    void reservationDel(int reservationNumber);
    int reservationExist(int num);
    
    
};




#endif // MOVIEBOOKINGSYSTEM_H

