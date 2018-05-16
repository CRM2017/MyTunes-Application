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

#include "observer.h"

 void  update(Subject * subject){}  // pure virtual function, will implement in subclass

 void printOn(ostream & out)  {}   // pure virtual function, will implement in subclass




ostream & operator<<(ostream & out, const Observer & obs) {
    obs.printOn(out);
    return out;
}







