//
// Seng1120: Assignment 2
// File: LinkedList.hpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#ifndef ASSIGNMENT2_FIXED_LINKEDLIST_HPP
#define ASSIGNMENT2_FIXED_LINKEDLIST_HPP

#include "LinkedList.h"

template <typename var_type>
LinkedList<var_type>::LinkedList()
{
    head = NULL;                // Initialise Object variables
    tail = NULL;                //
    iterator = NULL;            //
}// F end
/**********************************************************************************************************************/
template <typename var_type>
LinkedList<var_type>::LinkedList(const var_type dataList[], int size)
{
    head = NULL;                // Initialise Object variables
    tail = NULL;                //
    iterator = NULL;            //
    setListTo(dataList, size);  // Add dataList elements to List Object
}// F end
/**********************************************************************************************************************/
template <typename var_type>
LinkedList<var_type>::~LinkedList()
{
    iterator = head;                 // Set to start of list
    Node<var_type>* buff = iterator; // Create buff Node pointer

    while(iterator != NULL)          // Must account for < 2 nodes
    {
        iterator = iterator->getN(); // The next node
        delete(buff);                // Delete node
        buff = iterator;             // Update buff
    }// While

    head = NULL;
    tail = NULL;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::setListTo(const var_type dataList[], int size)
{
    //Reset List (Same Logic as deconstruct)
    iterator = head;                // Set to start of list
    Node<var_type>* buff = iterator;

    while(iterator != NULL)         // Must account for < 2 nodes
    {
        iterator = iterator->getN();// The next node
        delete(buff);               // Delete node
        buff = iterator;            // Update buff
    }// While

    head = NULL;
    tail = NULL;

    for(int i = 0; i < size; i++)
    {
        addToBottom(dataList[i]);   // Add dataList elements to List Object
    }
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::empty()
{
    setListTo(NULL, 0);        // Remove List elements
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::addToTop(const var_type& temp)
{
    var_type* dataPt = new var_type(temp);              // Copy data onto heap
    if(head == NULL)                                    // It is, therefore, a list has not been created yet
    {                                                   //
        head = new Node<var_type>(NULL,NULL,dataPt);    // Create first element of list
        tail = head;                                    // Tail now becomes head
        iterator = head;                                // Iterator is referenced with recently modified/viewed Node
        return;
    } else if(tail == head)                             // It is, therefore a List with one element
    {                                                   //
        iterator = head;                                // Iterator set to one element
        head = new Node<var_type>(iterator,NULL,dataPt);// Head becomes new second Node
        iterator->setP(head);                           // Original node updated as tail
        return;                                         // Tail is by default, already set
    }else                                               // Head exists, needs replacement
    {
        iterator = new Node<var_type>(head,NULL,dataPt);// Create new node
        head->setP(iterator);                           // Set head prev pointer to new head
        head = iterator;                                // Update new head
        return;
    }// If
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::remFromTop()
{
    if(head == NULL)        // Nothing here
    {
        return;
    }else if(tail == head)  // One element in List
    {                       //
        iterator = head;    // Set iterator as head for removal
        head = NULL;        // Set tail & head to NULL as only one node present
        tail = NULL;        //
        delete(iterator);   // Delete Node
        iterator = NULL;    // Set iterator to NULL
        return;
    }else                   // List > 2 Nodes
    {                       //
        iterator = head;    // Set iterator as head for removal
        head = head->getN();// Set new head
        head->setP(NULL);   // Clean prev
        delete(iterator);   // Delete
        iterator = head;    // Reset iterator
        return;
    }// If
}// F End
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::addToBottom(const var_type& temp)
{
    var_type* dataPt = new var_type(temp);              // Copy data onto heap
    if (tail == NULL)                                   // New list
    {                                                   //
        tail = new Node<var_type>(NULL, NULL, dataPt);  // Assign tail
        head = tail;                                    // Head now becomes tail
        iterator = head;                                // Iterator is referenced with recently modified/viewed Node
        return;
    }else if(tail == head)                              // If one node in list
    {                                                   //
        iterator = tail;                                // Assign Iterator
        tail = new Node<var_type>(NULL,iterator,dataPt);// Add new tail node
        iterator->setN(tail);                           // Update iterator/head
        return;
    }else                                               // Node > 2 in List object
    {                                                   //
        iterator = new Node<var_type>(NULL,tail,dataPt);// Add new tail node
        tail->setN(iterator);                           // Update old tail data
        tail = iterator;                                // Update new tail
        return;
    }// If
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::remFromBottom()
{
    if(tail == NULL)        //Nothing here
    {
        return;
    }else if(tail == head)  // If one Node in List; Remove last node
    {                       //
        iterator = head;    // Assign Iterator
        head = NULL;        // Clear Head and tail nodes
        tail = NULL;        //
        delete(iterator);   // Delete Node
        iterator = NULL;    // Clear Iterator
        return;
    } else                  // > 2 Nodes
    {                       //
        iterator = tail;    // Assign Iterator
        tail = tail->getP();// Set new head
        tail->setN(NULL);   // Clean prev
        delete(iterator);   // Delete
        iterator = tail;    // Reset iterator
        return;
    }// If
}// F end
/**********************************************************************************************************************/
template <typename var_type>
void LinkedList<var_type>::addAt(const var_type& temp, int pos)
{
    iterator = head;                                                  // Assign Iterator
    for(int i = 0; iterator != NULL; i++)                             // Scan List for desired Node Position
    {
        if(i == pos)                                                  // Desired Node Position found
        {                                                             //
            Node<var_type>* iter = iterator;                          // Needed as iterator self NULLS in else
            //  statement. I dont know why
            if(pos == 0)                                              // First element, we need to change head
            {                                                         //  (but already accounted for)
                addToTop(temp);                                       // Dont need to copy temp onto heap as addToTop
                //  accounts for this
            }else if (pos == (size()-1))                              // Last element, tail remains same
            {                                                         //
                var_type* data = new var_type(temp);                  // Copy data onto heap
                iterator = new Node<var_type>(tail,tail->getP(),data);// Generate new Node
                tail->getP()->setN(iterator);                         // Update second last Node
                tail->setP(iterator);                                 // Update tail
            } else
            {
                var_type* data = new var_type(temp);                  // Copy data onto heap, iterator is on right node
                Node<var_type>* buff = new Node<var_type>(iter, iter->getP(), data);//new node set
                iter->getP()->setN(buff);                             //Right node set
                iter->setP(buff);                                     //Left Node set
            }// If
            return;
        }// If
        iterator = iterator->getN();
    }// For
    std::cout << "***Warning: addAt(data*,pos) position not found. Potential invalid position argument.***" << std::endl;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
var_type* LinkedList<var_type>::readNode(int pos)
{
    iterator = head;                                                                    // Assign Iterator

    if(head == NULL)                                                                    // No Nodes
    {                                                                                   //
        std::cout << "***Warning: readNode(pos) List has no elements.***" << std::endl; // Display Error message
        return NULL;
    }// If

    for(int count = 0; iterator != NULL; count ++)                                      // Scan List
    {                                                                                   //
        if(count == pos)                                                                // Node found
        {
            return iterator->getD();
        }// If

        iterator = iterator->getN();
    }// For
    std::cout << "***Warning: readNode(pos) position not found. Potential invalid position argument.***" << std::endl;
    return NULL;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
int LinkedList<var_type>::size()
{
    iterator = head;                // Assign iterator
    int count = 0;

    while(iterator != NULL)         // Increment through List
    {
        count++;
        iterator = iterator->getN();
    }// While

    return count;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
LinkedList<var_type>& LinkedList<var_type>::operator += (LinkedList<var_type>& L2)
{
    int count = L2.size();
    for(int i = 0; i < count; i++)
    {
        addToBottom(*(L2.readNode(i)));// For every element create a respective node
    }// For
    return *this;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
var_type& LinkedList<var_type>::operator [] (int pos)
{
    return *(readNode(pos));
}
/**********************************************************************************************************************/
template <typename var_type>
LinkedList<var_type>& LinkedList<var_type>::operator = (LinkedList<var_type>& L2)
{
    setListTo(NULL, 0);              //ResetList

    int count = L2.size();
    int index = 0;

    while(index < count)
    {
        addToBottom(*(L2.readNode(index)));
        index++;
    }// While

    return *this;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
std::ostream& operator << (std::ostream& out, LinkedList<var_type>& list)
{
    int count = 0;
    while(count < list.size())
    {
        out << *(list.readNode(count)) << " ";
        count++;
    }// While

    if(list.size()==0)
    {
        out << "-Empty-";
    }// If

    out << std::endl;

    return out;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
bool operator == (LinkedList<var_type>& L1, LinkedList<var_type>& L2)
{
    if(L1.size() != L2.size())
    {
        return false;
    }// If

    for(int count = 0; (count < L1.size()) && (count < L2.size()) ; count++)
    {
        if(*(L1.readNode(count)) != *(L2.readNode(count)))
        {
            return false;
        }// If
    }// For

    return true;
}// F end
/**********************************************************************************************************************/
template <typename var_type>
bool operator != (LinkedList<var_type>& L1, LinkedList<var_type>& L2)
{
    return !(L1==L2);
}// F end
/**********************************************************************************************************************/

#endif