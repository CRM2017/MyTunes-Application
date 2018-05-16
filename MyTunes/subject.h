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
#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
//#include "arraytList.h"
#include <set>
//using namespace std;




class Subject {


public:
    void attach(Observer & obs);
    void dettach(Observer & obs);

private:
    set<Observer*> observers;


protected:

    void notify();

};



#endif
