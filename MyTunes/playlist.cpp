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
#include <string>
using namespace std;

#include "playlist.h"
	
Playlist::Playlist(const string & aPlaylistName){
	cout << "Playlist(string&)" << endl;
	name = aPlaylistName;
}
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(const Playlist & aPlaylist)" << endl;
	cout << "ERROR: Playlist(const Playlist & aPlaylist) --should never run" << endl;
}

Playlist::~Playlist(){
	cout << "~Playlist(void)" << endl;
}
int Playlist::getID(){return -1;}
string Playlist::getName(){return name;}

vector<Track*> & Playlist::getTracks(){return tracks;}

Playlist Playlist:: getFollowing(){ return *following;}

void Playlist:: update(Subject* subject){
	//cout << this << " Playlist:: update (Subject*)" << endl;   // print the memory address of observer
	if(following != NULL) tracks = following->tracks;



}

void Playlist:: startFollowing (Playlist & followPlaylist){
	//cout << this << " Playlist:: startFollowing (Playlist& )" << endl;  // print the memory address of observer
	following = &followPlaylist;
	following->attach(*this);

}

void Playlist:: stopFollowing (){
	//cout << this << " Playlist:: stopFollowing" << endl;   // print the memory address of observer
	if (following != NULL) following->dettach(*this);
}

void Playlist::printOn(ostream &out) const {
    out << "following: " << this << "\n";
}



vector<Track*>::iterator Playlist::findPosition(Track & aTrack){
	for (vector<Track*>::iterator itr = tracks.begin() ; itr != tracks.end(); ++itr)
		if(*itr == &aTrack) return itr;
	return tracks.end();
}

void Playlist::addTrack(Track & aTrack){
	//add track if it does not already exist
	vector<Track*>::iterator itr = findPosition(aTrack);
	if(itr == tracks.end()) {
		tracks.push_back(&aTrack);
        notify();
	}	
}

void Playlist::removeTrack(Track & aTrack){
	vector<Track*>::iterator itr = findPosition(aTrack);
	if(itr != tracks.end()) {
		tracks.erase(itr);
        notify();
	}
}

string Playlist::toString()const {
	string indent = "     ";
	string s;
	s.append(name );
    if (following != NULL){ s.append(" following: " + name);}
	s.append("\n");
	s.append(indent + indent + "Playlist Tracks:\n");
	for (vector<Track*>::size_type i = 0 ; i < tracks.size(); i++){
		   s.append(indent + indent + to_string(i) + " " + (tracks[i])->toString() + "\n");
	}
	
	return s;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
