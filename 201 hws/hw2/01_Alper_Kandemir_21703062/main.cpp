#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <chrono>
using namespace std;

//1)Linear search (iterative implementation) which works in O(N) time, where N is the size of the collection.

int sequentialSearch( int* arr, int N, int key) 
{
    for ( int i = 0; i < N; i++)
    if ( arr[i] == key ){
        //cout<<i;
        return i;
    }
    //cout<<"no"<<N;
    return -1;
}


//2)Linear search (recursive implementation) which works in O(N) time, where N is the size of the collection.

int recursiveSearch(int* arr, int i, int key,int N)
{
    
    if (arr[i] == key){
    //cout<<i;
    return i;
    }
    else if(i==N){
    //cout<<"no"<<i;
    return -1;
    }
    return recursiveSearch(arr, i + 1, key,N);
}


//3)Binary search which works in O(logN) time, where N is the size of the collection.

int binarySearch( int* arr, int N, int key)
{ 
    int low = 0, high = N - 1;
    while ( low <= high ) 
        {
            int mid = (low + high) / 2;
    if ( arr[ mid ] < key )
        low = mid + 1;
    else if ( arr[ mid ] > key )
        high = mid - 1;
    else
        {
        //cout<< mid;
        return mid;
        }
    }
   //cout<< "no"<<N;
    return -1;
}


//4)Jump search

int jumpSearch(int* arr, int key, int N)
{

    int b = sqrt(N);
    int a = 0;
    while (arr[(min(b, N))-1] < key)
    {
        a = b;
        b =b+ sqrt(N);
        if (a >= N)
        {
            return -1;
        }
    }
    while (arr[a] < key)
    {
        a= a+1;
        if (a == min(b, N))
            return -1;
    }
    if (arr[a] == key)
        {
            //cout<<a;
            return a;
        }
    //cout<< "no"<<N;    
    return -1;
}



int main(){
    
    int N =10;
    int key= -1;
    //Creating random array
    int *arr = new int[N];
    for (int i = 0; i < N; i++) 
        {   
            int randomNumber = rand();
            arr[i] = randomNumber;  
        }
    //sorting
    sort(arr, arr + N);
    
    
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;



 //******************************************************************************************************  
    //ALGO 1 Sce A
//     key=arr[0];
//     startTime = std::chrono::system_clock::now();
//     sequentialSearch(arr, N, key);
//     elapsedTime = std::chrono::system_clock::now() - startTime;
//     cout << "Execution took for algo 1(scenario A) " << elapsedTime.count() << " milliseconds." << endl;
    
    //ALGO 1 Sce B
//     key=arr[N/2];
//     startTime = std::chrono::system_clock::now();
//     sequentialSearch(arr, N, key);
//     elapsedTime = std::chrono::system_clock::now() - startTime;
//     cout << "Execution took for algo 1(scenario B) " << elapsedTime.count() << " milliseconds." << endl;
    
    // //ALGO 1 Sce C
    // key=arr[N-1];
    // startTime = std::chrono::system_clock::now();
    // sequentialSearch(arr, N, key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 1(scenario C) " << elapsedTime.count() << " milliseconds." << endl;
    

    // ALGO 1 Sce D
    // startTime = std::chrono::system_clock::now();
    // sequentialSearch(arr, N, key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 1(scenario D) " << elapsedTime.count() << " milliseconds." << endl;
    
    
    
    
    //ALGO 2 SCE A
    // key=arr[0];
    // startTime = std::chrono::system_clock::now();
    // recursiveSearch(arr, 0, key,N );
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 2(scenario A) " << elapsedTime.count() << " milliseconds." << endl; 


//ALGO 2 SCE B
    // key=arr[N/2];
    // startTime = std::chrono::system_clock::now();
    // recursiveSearch(arr, 0, key,N ); 
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 2(scenario B) " << elapsedTime.count() << " milliseconds." << endl; 


    
//ALGO 2 SCE C
    // key=arr[N-1];
    // startTime = std::chrono::system_clock::now();
    // recursiveSearch(arr,0, key,N );  
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 2(scenario C) " << elapsedTime.count() << " milliseconds." << endl; 


//ALGO 2 SCE D

    // startTime = std::chrono::system_clock::now();
    // recursiveSearch(arr, 0, key,N ); 
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 2(scenario D) " << elapsedTime.count() << " milliseconds." << endl; 
    
//   
       
  //ALGO 3 SCE A
    // key=arr[0];
    // startTime = std::chrono::system_clock::now();
    // binarySearch(arr,N,key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 3(scenario A) " << elapsedTime.count() << " milliseconds." << endl; 
    
// // ALGO 3 SCE B
    // key=arr[(N/2)];
    // startTime = std::chrono::system_clock::now();
    // binarySearch(arr,N,key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 3(scenario B) " << elapsedTime.count() << " milliseconds." << endl; 
    
////ALGO 3 SCE C
    // key=arr[N-1];
    // startTime = std::chrono::system_clock::now();
    // binarySearch(arr,N,key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 3(scenario C) " << elapsedTime.count() << " milliseconds." << endl; 
    
////ALGO 3 SCE D
    
    // startTime = std::chrono::system_clock::now();
    // binarySearch(arr,N,key);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 3(scenario D) " << elapsedTime.count() << " milliseconds." << endl;  
    
    
    //ALGO 4 SCE A
    // key=arr[0];
    // startTime = std::chrono::system_clock::now();
    // jumpSearch(arr,key,N);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 4(scenario A) " << elapsedTime.count() << " milliseconds." << endl;
    
//ALGO 4 SCE B
    // key=arr[N/2];
    // startTime = std::chrono::system_clock::now();
    // jumpSearch(arr,key,N);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 4(scenario B) " << elapsedTime.count() << " milliseconds." << endl;

//ALGO 4 SCE C
    // key=arr[N-1];
    // startTime = std::chrono::system_clock::now();
    // jumpSearch(arr,key,N);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 4(scenario C) " << elapsedTime.count() << " milliseconds." << endl;

// ALGO 4 SCE D
    // startTime = std::chrono::system_clock::now();
    // jumpSearch(arr,key,N);
    // elapsedTime = std::chrono::system_clock::now() - startTime;
    // cout << "Execution took for algo 4(scenario D) " << elapsedTime.count() << " milliseconds." << endl;
    
//*****************************************************************************************************
//       for (int i = 0; i < N; i++) {
//     cout << "array: " << arr[i] <<  endl;
//     }
    return 0;
}
