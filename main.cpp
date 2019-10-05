//RayenStrasser-King
//rfstrasser-king

#include <iostream>
#include "vlist.h"
#include "video.h"
using namespace std;

int main()
{
        string title;
        string url;
        string comment;
        string command;
        int rating;
        float time;

        Vlist vlist;//Vlist object (vlist)

        while (cin >> command)//while user inputs commands
        {
                cin.ignore();
                if (command == "insert")//if command entered  = insert
                {
                        getline(cin, title);
                        getline(cin, url);
                        getline(cin, comment);
                        cin >> time;
                        cin >> rating;
                        cin.ignore();
                        Video *newvid = new Video(title, url, comment, time, rating);//inserts all the information into a new video
                        bool inserted = vlist.insert(newvid);
                        if(inserted == false)
                                cerr << "Could not insert video <" << title << ">, already in list." << endl;
                }
                else if (command == "print")
                {
                        vlist.print();
                }
                else if (command == "length")
                {
                        vlist.length();
                }
                else if (command == "remove")
                {
                        string search;
                        getline(cin, search);//searches for what video that need to be removed
                        bool removed = vlist.remove(search);//removes
                        if (removed == false);
                        {
                                cerr << "Title <" << search << "> not in list, could not delete." << endl;
                        }
                }
                else if(command == "lookup")
                {
                        string search;
                        getline(cin, search);
                        bool lookedup = vlist.lookup(search);
                        if (lookedup == false)//if video is not in the list
                        {
                                cerr << "Title <" << search << "> not in list." << endl;
                        }
                }
                else //user inputs a command that is not listed
                {
                        cerr << "<" << command << "> is not a legal command, giving up." << endl;
                        return 1;
                }
        }
        return 0;
}
