/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors: Ming Lei       100981171           */
/*                Zi Xuan Zhang  101027027           */
/*                Louis Nel                          */
/*  Date:  21-SEP-2017                               */
/*                                                   */
/*  (c) 2017                                         */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef OBSERVER_H
#define OBSERVER_H
#include <ostream>

//#include <string.h>

using namespace std;

class Subject;
class Observer {
public:
    virtual void update(Subject * subject) = 0;

    virtual void printOn(ostream & out) const = 0;

    int operator==(const Observer & obs) const{ return this == & obs;}

};

ostream & operator<<(ostream & out, const Observer & obs);






#endif
