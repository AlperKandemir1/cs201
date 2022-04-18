//Alper Kandemir
//21703062
#include "Movies.h"
#include <time.h>
int* resRow;
int* resCol;

Movies::Movies()
{
    //ctor
    movieDate;
    movieID = 0;
    audienceRadius = 0;

    newRow = numRow;
    newCol = numCol;
    emptySeat = newCol * newRow;
    int i = 0;
    for(int k = 1 ; k <= numCol; k++){
        emptyCol[i] = k;
        i++;
    }
    i = 0;
    for(int k = 1 ; k <= numRow; k ++){
        emptyRow[i] = k;
        i++;
    }
}

Movies::Movies(long ID, int radius)
{   
     int k = 0;
     time_t rawtime;
     time (&rawtime);
     movieDate= asctime(localtime ( &rawtime ));
     movieID = ID;
     audienceRadius = radius;
     if(radius != 0){
         newRow = numRow/(radius + 1);
         newCol = numCol/(radius + 1);
         

         if(numCol%(radius+1) != 0)
            newCol++;
        
        if(numRow%(radius+1) != 0)
            newRow++;

        emptySeat = newRow * newCol;
     }
     else{
         newRow = numRow;
         newCol = numCol;
         emptySeat = newCol * newRow;
     }

    for(int i = 1 ; i <= numCol; i += radius+1 ){
        emptyCol[k] = i;
        k++;
    }
    k = 0;
    for(int i = 1 ; i <= numRow; i += radius+1 ){
        emptyRow[k] = i;
        k++;
    }

    cout << endl;
}

Movies::~Movies(){
}

string Movies::getDate(){
    return movieDate;
}

long Movies::getID(){
   return movieID;
}

int Movies::getRadius(){
    return audienceRadius;
}
int Movies::getAvailableSeats(){
    return emptySeat;
}

bool Movies::isReserved(int row, int col){
    bool rowIsExist = false;
    bool colIsExist = false;
    for(int i = 0; i < reservationSize; i++){
       if(row == resRow[i] && col == resCol[i]){
            //cout << "Row " << row << " and col " << col << " exist." << endl; 
            return true;
       } 
    }
    for(int i = 0; i < newRow; i++){
        if(emptyRow[i] == row)
            rowIsExist = true;
    }

    for(int i = 0; i < newCol; i++){
        //cout << "Array Column " << emptyCol[i] << " input column " << col << endl;
        if(emptyCol[i] == col)
            colIsExist = true;
    }
    // if(!colIsExist)
    //     cout << "Col " << col << " does not exist" <<  endl; 
    // if(!rowIsExist)
    //    cout << "Row " << row << " does not exist" <<  endl;

    if(!colIsExist || !rowIsExist)
        return true;

    return false;
}

void Movies::reservationAdd(int row, int col){
    int* rowTemp = new int[reservationSize + 1];
    int* colTemp = new int[reservationSize + 1];
    
    for(int i = 0; i < reservationSize; i++){
        rowTemp[i] = resRow[i];
    }
    
    for(int i = 0; i < reservationSize; i++){
        colTemp[i] = resCol[i];
    }
    rowTemp[reservationSize] = row;
    colTemp[reservationSize] = col;
    delete[] resCol;
    delete[] resRow;
    resCol = colTemp;
    resRow = rowTemp;
    reservationSize++;
    emptySeat--;
}

void Movies::reservationDel(int row, int col){
    int k = 0;
    int* rowTemp = new int[reservationSize - 1];
    int* colTemp = new int[reservationSize - 1];

    for(int i = 0; i < reservationSize; i++){
        if(resRow[i] == row && resCol[i] == col){      }
        else{
            rowTemp[k] = resRow[i];
            colTemp[k] = resCol[i];
            k++;
        }
    }
    delete[] resCol;
    delete[] resRow;
    resCol = colTemp;
    resRow = rowTemp;
    reservationSize--;
    emptySeat++;
}

