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

#include <iostream>
#include "subject.h"



void  Subject::attach(Observer & obs) {
    observers.insert(&obs);
    //cout << "\nAttach: " << " observers size: " << observers.size() << "\n";
    /*for (set<Observer*> ::iterator it = observers.begin(); it != observers.end(); ++it){
        cout << (*it)<<endl;   // print the memory address of observer
    }*/
    obs.update(this);

}
void Subject::dettach(Observer & obs) {
    observers.erase(&obs);
    //cout << "\nDettach: " << " observers size: " << observers.size() << "\n";
    /*for (set<Observer*> ::iterator it = observers.begin(); it != observers.end(); ++it){
        cout << (*it)<<endl;   // print the memory address of observer
    }*/
}

void Subject::notify() {

    //notify all observers that something about the subject they
    //are watching has changed. concrete subclasses should call
    //this method whenever a state change has ocurred that
    //observers might be interested in

    //Note: observer collection is copied and the copy
    //iterated over so that observers can dettach
    //when they are being notified (i.e. double buffering)

    //In the Gamma pattern this is not done and that code will
    //blow up in a situtation where observers choose to detach as
    //a result of being notified

    set<Observer*> observers_copy = observers; //make copy to iterate over
    for(set<Observer*>::iterator itr = observers_copy.begin(); itr != observers_copy.end(); itr++) {
        (*itr)->update((Subject*) this);
    }
}



