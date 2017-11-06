//
//  main.cpp
//  CPP-PRG-11-01-Movie-Data
//
//  Created by Keith Smith on 11/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that uses a structure named MovieData to store the following
//  information about a movie:
//
//      Title
//      Director
//      Year Released
//      Running Time (in minutes)
//
//  The program should create two MovieData variables, store values in their members,
//  and pass each one, in turn to a function that displays the infomation about the movie
//  in a clearly formatted manner.
//

#include <iostream>

using namespace std;

struct StructMovieData
{
    string strTitle;
    string strDirector;
    int intYearReleased;
    int intRunTime;
};

void createStructure(StructMovieData *);
void displayStructure(StructMovieData *);

int main()
{
    StructMovieData *smdMovie01 = nullptr;
    smdMovie01 = new StructMovieData;
    StructMovieData *smdMovie02 = nullptr;
    smdMovie02 = new StructMovieData;
    
    createStructure(smdMovie01);
    createStructure(smdMovie02);
    
    displayStructure(smdMovie01);
    displayStructure(smdMovie02);
    
    return 0;
}

void createStructure(StructMovieData *movieData)
{
    cout << "Please enter the following information:\n";
    
    cout << "\tMovie title:\t";
    getline(cin, (*movieData).strDirector);
    
    cout << "\tDirector:\t";
    getline(cin, (*movieData).strTitle);
    
    cout << "\tYear released:\t";
    cin >> (*movieData).intYearReleased;
    while(!cin || (*movieData).intYearReleased < 1900 || (*movieData).intYearReleased > 2017)
    {
        cout << "\tPlease enter a year\n";
        cout << "\tbetween 1900 and 2017:\t";
        cin.clear();
        cin.ignore();
        cin >> (*movieData).intYearReleased;
    }
    
    cout << "\tRuntime (in minutes):\t";
    cin >> (*movieData).intRunTime;
    while(!cin || (*movieData).intRunTime < 0 || (*movieData).intRunTime > 10000)
    {
        cout << "\tPlease enter a number\n";
        cout << "\tbetween 0 and 10,000:\t";
        cin.clear();
        cin.ignore();
        cin >> (*movieData).intRunTime;
    }
    cin.clear();
    cin.ignore();
}

void displayStructure(StructMovieData *movieData)
{
    cout << endl;
    cout << "Here is your movie's information:\n";
    cout << "\tMovie title:\t" << movieData->strTitle << endl;
    cout << "\tDirector:\t" << movieData->strDirector << endl;
    cout << "\tYear released:\t" << movieData->intYearReleased << endl;
    cout << "\tRuntime:\t" << movieData->intRunTime << endl;
    cout << endl;
}
