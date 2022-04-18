//Alper Kandemir
//21703062

#include "MovieBookingSystem.h"
#include <iostream>
#include <string>

using namespace std;
Movies* movieArr;
int* reservationNums;
int* movieNum;
string* seatNum;
char chars[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

MovieBookingSystem::MovieBookingSystem( )
{
    reservationSize = 0;
    movieArrSize = 0;
    reservationNum = 1;
    movieArr = new Movies[movieArrSize];
    int* reservationNums = new int[reservationSize];
    int* movieNum = new int[reservationSize];
    string* seatNum = new string[reservationSize];
    
}

MovieBookingSystem::~MovieBookingSystem( )
{
    
}


void MovieBookingSystem::addMovie( const long movieID, const int audienceRadius )
{
    
    if(!movieExists(movieID))
    {   
        Movies* arrTemp = new Movies[movieArrSize+1];
        for(int i = 0; i < movieArrSize; i++){
            arrTemp[i] = movieArr[i];
        }
        movieArrSize++;
        
        delete[] movieArr;
        
        arrTemp[movieArrSize - 1] = Movies(movieID, audienceRadius);
        
        movieArr = arrTemp;
        
        //movieArr[movieArrSize - 1] = Movies(movieID, audienceRadius);
        cout << "Movie at " << arrTemp[movieArrSize-1 ].getDate() << "has been added.\n";
        
    }
    else{

        cout << "\n";
        cout << "The movie "  <<movieArr[getMovie(movieID)].getDate()<<"already exist.\n" << endl;
    }
}

void MovieBookingSystem::showAllMovies()
{
    cout << "Movies on show:\n " << endl;
    if(movieArrSize != 0){
        for(int i = 0; i < movieArrSize; i++)
        {
            cout <<"Movie at " << movieArr[i].getDate() << "(" << movieArr[i].getAvailableSeats()  << " available seats" << ") \n" << endl;
        }
    }
    else{
        cout << "No movie on show" << endl;
    }

}
void MovieBookingSystem::showMovie( const long movieID)
{
    if(movieExists(movieID)){
            //Movies movie = movieArr[getMovie(movieID)];
            int radius = movieArr[getMovie(movieID)].getRadius();

            cout <<"movie at " << movieArr[getMovie(movieID)].getDate() <<"has "<<movieArr[getMovie(movieID)].getAvailableSeats()<<" available seats\n";
            cout << "\n";
            cout << "\t" << " ";
            for(int i = 0 ; i < numCol; i += radius+1 ){
                cout << chars[i] << "  ";
            }
            //cout << "\n";
            cout << endl;

            for(int i = 1; i <= numRow; i += radius+1)
            { 
                cout << i << "\t";

                for(int k = 1; k <= numCol; k += radius+1)
                {
                    if(!movieArr[getMovie(movieID)].isReserved(i,k))
                    {
                        cout << " O ";
                    }
                    else
                    {
                        cout << " X ";
                    }
                }
                cout << endl;
            }
            cout << endl;
           
    }
    else{
        cout <<"The movie "<<movieArr[getMovie(movieID)].getDate()<<"is not exist \n";
        cout <<" \n";
        } 
}
void MovieBookingSystem::cancelMovie( const long movieID)
{
    if(movieExists(movieID))
    {
         cout << "Movie at " << movieArr[getMovie(movieID)].getDate() << "canceled \n";
         cout << "\n";
         //cout << "asdasdadsadwerq " << movieArr[getMovie(movieID)].getID() << "canceled \n";
         cout << "\n";
         Movies* arrTemp = new Movies[movieArrSize - 1]; 

         int c = 0;
         for(int i = 0; i < movieArrSize; i++)
         {
             if(movieArr[i].getID() != movieID)
             {
               arrTemp[c] = movieArr[i];
               c++;
             }
         }
         movieArrSize--;
         
         delete[] movieArr;
         movieArr = arrTemp;
         
         
    }
    else
        {
        cout << "movie at " <<movieArr[getMovie(movieID)].getDate()<<"is not exits";
        cout << "\n";
    }
}

int MovieBookingSystem::makeReservation( const long movieID, const int row, const char col)
{
    int movieIndex = getMovie(movieID);
    
    if(movieExists(movieID)){
        if(!movieArr[movieIndex].isReserved(row,getIndex(col))){
            movieArr[movieIndex].reservationAdd(row,getIndex(col));
            int* movieIDtemp = new int[reservationSize + 1];
            int* ResNumTemp = new int[reservationSize + 1];
            string* seatTemp = new string[reservationSize + 1];
            
            for(int i = 0; i < reservationSize; i++){
                ResNumTemp[i] = reservationNums[i];
            }
            
            for(int i = 0; i < reservationSize; i++){
                movieIDtemp[i] = movieNum[i];
            }
            
            for(int i = 0; i < reservationSize; i++){
                seatTemp[i] = seatNum[i];
            }

            ResNumTemp[reservationSize] = reservationNum;
            movieIDtemp[reservationSize] = movieID;
            seatTemp[reservationSize] = col+ to_string(row) ;

            cout << "Reservation done for  " <<seatTemp[reservationSize]  << " in Movie at " << movieArr[movieIndex].getDate() << endl;
            reservationNum++;
            delete[] reservationNums;
            delete[] movieNum;
            delete[] seatNum;
            seatNum = seatTemp;
            movieNum = movieIDtemp;
            reservationNums = ResNumTemp;
            reservationSize++;

        }
        else{
            cout << "Cannot book the selected seat " <<col+ to_string(row)<< endl;
        }
    }
    else{
        cout <<"The movie "<<movieArr[getMovie(movieID)].getDate()<< "is not exist\n\n" << endl;
    }
    return reservationNums[reservationSize-1];
}

void MovieBookingSystem::showReservation( const int resCode)
{
    int movieIndex = reservationExist(resCode);
    if(movieIndex != -1){
        cout << "Reservation No: " << reservationNums[movieIndex] << " Movie: " << movieArr[movieIndex].getDate() << "Seats " << seatNum[movieIndex] << endl;
        cout << "\n";
    }
    else{
        cout <<"The reservation is not exist" << endl;
        cout << "\n";
    }
//movieArr[getMovie(movieID)].getDate()
}

void MovieBookingSystem::cancelReservations( const int numRes,const int* resCode)
{
    bool exist = true;
    for(int i = 0; i<numRes; i++){
        if(reservationExist(resCode[i]) == -1)
            exist = false;
    }
    if(exist){
        for(int i = 0; i < numRes; i++)
            reservationDel(resCode[i]);

        cout << "The reservation cancelled\n" << endl;

    }
    else{
        cout << "Some reservation codes do not exist. Cancelation Failed!\n" << endl;
    }

}

void MovieBookingSystem::reservationDel(int reservationNumber){
    if(reservationExist(reservationNumber) != -1){
            int movieIndex = reservationExist(reservationNumber);
            int ctrl = 0;
            string seat(seatNum[movieIndex]);
            int row = (int)seat[0];
            int col = getIndex(seat[1]);
            int* movieIDtemp = new int[reservationSize - 1];
            int* ResNumTemp = new int[reservationSize - 1];
            string* seatTemp = new string[reservationSize - 1];
            movieArr[getMovie(movieNum[movieIndex])].reservationDel(row,col);
            for(int i = 0; i < reservationSize; i++){
                if(i != movieIndex){
                    ResNumTemp[ctrl] = reservationNums[i];
                    ctrl++;
                }
            }
            ctrl = 0;
            for(int i = 0; i < reservationSize; i++){
                if(i != movieIndex){
                    movieIDtemp[ctrl] = movieNum[i];
                    ctrl++;
                }
            }
            ctrl = 0;
            for(int i = 0; i < reservationSize; i++){
                if(i != movieIndex){
                    seatTemp[ctrl] = seatNum[i];
                    ctrl++;
                }
            }
            //cout<<"movie at:::"<<movieArr[getMovie(movieNum[movieIndex])].getDate()<< endl;
            
            delete[] reservationNums;
            delete[] movieNum;
            delete[] seatNum;
            seatNum = seatTemp;
            movieNum = movieIDtemp;
            reservationNums = ResNumTemp;
            reservationSize--;
    }
    else{
        //cout << "Reservation " << reservationNumber << " is not exist." << endl;
    }
}
bool MovieBookingSystem::movieExists(long movieID)
{
    for(int i = 0; i < movieArrSize; i++)
    {
        if(movieID == movieArr[i].getID())
        {
            return true;
        }

    }
        return false;
}

int MovieBookingSystem::getMovie(long movieId){
    for(int i = 0; i < movieArrSize; i++){
        if(movieId == movieArr[i].getID()){
            return i;
        }
    }
    return 0;
}

int MovieBookingSystem::getIndex(char a){
    for(int i = 0; i < 26; i++){
        if(chars[i] == a){
            return i+1;
        }
    }

    return 0;
}
int MovieBookingSystem::reservationExist(int num){
    int reservationIndex = -1;
    for (int i = 0; i < reservationSize; i++){
        if(reservationNums[i] == num)
            reservationIndex = i;
    }

    return reservationIndex;
}