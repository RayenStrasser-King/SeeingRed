#ifndef VLIST_H
#define VLIST_H
#include "video.h"
#include <iostream>
using namespace std;

class Vlist  {
        public:
                Vlist();
                ~Vlist();
                bool insert(Video* newvid);
                void print();
                void length();
                bool remove(string);
                bool lookup(string);
        private:
                int m_length;
                class Node
                {
                        public:
                                Node(Video *newvid, Node *next)
                                {m_video = newvid; m_next = next;}
                                Video *m_video;
                                Node *m_next;
                };
                Node *m_head;
};

#endif
