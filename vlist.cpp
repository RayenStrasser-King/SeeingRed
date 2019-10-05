#include <iostream>
#include "vlist.h"
#include "video.h"
using namespace std;

Vlist::Vlist() //constructor
{
        m_head = NULL;
        m_length = 0;
}

Vlist::~Vlist() //deconstructor
{
        while (m_head)
        {
                Node *tmp = m_head;
                m_head = m_head->m_next;
                delete tmp;
        }
}

bool Vlist::insert(Video *newvid) //insert function
{
        if (m_head == NULL)//empty list
        {
                m_head = new Node(newvid, NULL);
                m_length++;
                return true;
        }

        else if (m_head->m_next == NULL)//one node in list
        {
                Node *reach = m_head;
                bool after = newvid->title(reach->m_video);
                if (after == true)//if video title goes after m_head
                {
                        m_head->m_next = new Node(newvid, NULL);
                        m_length++;
                        return true;
                }
                else//if video title goes before m_head
                {
                        bool same = newvid->vcompare(reach->m_video);//check if titles match
                        if (same == true)
                                return false;
                        m_head = new Node(newvid, m_head);//makes new m_head
                        m_length++;
                        return true;
                }
        }
        else //if there are more than one node in list
        {
                Node *ptr = m_head;
                Node *walk = ptr->m_next;
                while (walk)//while ptr->m_next exsists
                {
                        bool after = newvid->title(ptr->m_video);
                        bool afternext = newvid->title(walk->m_video);
                        if (after == true && afternext == false)//if it goes after current but not after next
                        {
                                Node *hold = walk;
                                ptr->m_next = new Node(newvid, hold);
                                m_length++;
                                return true;
                        }
                        else if (after == false)//if it goes before current
                        {
                                m_head = new Node(newvid, m_head);
                                m_length++;
                                return true;
                        }
                        else if (after == true && afternext == true)//if it goes after both of them, increment both
                        {
                                ptr = ptr->m_next;
                                walk = walk->m_next;
                        }
                }
                ptr->m_next = new Node(newvid, NULL);//if ptr->m_next doesn't exsist (end of list)
                m_length++;
                return true;
        }
}

void Vlist::print() //print function
{
        Node *reach = m_head;
        while (reach)
        {
                reach->m_video->print();
                reach = reach->m_next;
        }
        return;
}

void Vlist::length()//length function
{
        cout << m_length << endl;//print length
}

bool Vlist::remove(string search)//remove function
{
        if (m_head == NULL)//if there is no list
                return false;
        Node *ptr = m_head;
        Node *remove = ptr->m_next;
        if (ptr->m_video->compare(search))//if ptr's title and video's titles match search
        {
                Node *delete1;
                Video *delete2;
                delete1 = ptr;
                delete2 = ptr->m_video;
                if (remove)//while ptr->m_next exists
                {
                        m_head = remove;
                        ptr = m_head;
                        remove = ptr->m_next;
                }
                else if (remove == NULL)//special case
                {
                        m_head = NULL;
                }
                delete delete2;
                delete delete1;
                delete2 = NULL;
                delete1 = NULL;
                return true;
        }
        while (remove)//while ptr->m_next exists
        {
                if (remove->m_video->compare(search))//if ptr->m_next's title and video's titles match search
                {
                        Node *delete1;
                        Video *delete2;
                        delete2 = remove->m_video;
                        delete1 = remove;//set pointers to be deleted (deathrow)
                        ptr->m_next = ptr->m_next->m_next;
                        delete delete2;
                        delete delete1;
                        delete2 = NULL;
                        delete1 = NULL;
                        return true;
                }
                else if (ptr->m_video->compare(search))//if ptr's title and video's titles match search
                {
                        Node *delete1;
                        Video *delete2;
                        delete2 = ptr->m_video;
                        delete1 = ptr;
                        m_head = remove;
                        delete delete2;
                        delete delete1;
                        delete2 = NULL;
                        delete1 = NULL;
                        return true;
                }
                ptr = ptr->m_next;
                remove = ptr->m_next;
        }
        return false;
}

bool Vlist::lookup(string search)//lookup function
{
        if (m_head == NULL)//if list is empty
                return false;
        Node *lookup = m_head;
        while (lookup)//while there is a list
        {
                if (lookup->m_video->compare(search))
                {
                        lookup->m_video->print();
                        return true;
                }
                else
                {
                        lookup = lookup->m_next;
                }
        }
        return false;
}
