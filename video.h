#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

class Video //Video class
{
        public:
                Video (string Ti, string YT, string com, float leg, int s);
                void print();
                bool longer(Video*);
                bool compare(string);
                bool vcompare(Video*);
                bool title(Video*);
                bool rating(Video*);

        private:
                string Title;
                string youtube;
                string comment;
                float length;
                int star;
};

#endif
