//Strasser-King,Rayen
//rftrsaeer-king

#include <iostream>
#include "video.h"
using namespace std;

Video::Video (string Ti, string YT, string com, float leg, int s)
        : Title(Ti), youtube(YT), comment(com), length(leg), star(s){}

void Video::print()//p2 video print fucntion
{
        cout << Title <<", "<< youtube <<", "<< comment <<", "<< length <<", ";
        switch (star) //switch for outputing rating/stars
        {
                case 1:
                        cout << "*" << endl;
                        break;
                case 2:
                        cout << "**" << endl;
                        break;
                case 3:
                        cout << "***" << endl;
                        break;
                case 4:
                        cout << "****" << endl;
                        break;
                case 5:
                        cout << "*****" << endl;
                        break;
        }
}

bool Video::longer (Video* other)//check if video is longer than other
{
        return length > other->length;
}

bool Video::compare (string search)//check if titles are the same as "search"
{
        return Title == search;
}

bool Video::vcompare (Video *other)//check if titles are the same
{
        return Title == other->Title;
}

bool Video::title (Video *other)//check if title is higher than other
{
        return Title > other->Title;
}

bool Video::rating (Video* other)//check if rating is higher than other
{
        return star > other->star;
}
