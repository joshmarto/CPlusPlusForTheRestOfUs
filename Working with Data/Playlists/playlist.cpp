#include "playlist.h"
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

using namespace std;

playlist::playlist()
{
	this->playlistName = "";
	this->plFile = "";
}

void playlist::setPlaylistName(){
	cout << "Enter playlist name: " << endl;
	getline(cin, this->playlistName);
	this->plFile = this->playlistName + ".txt";
}

string playlist::trim(string anyString){
	string retVal = anyString;
	int lastPos = retVal.length() - 1;
	
	bool found = true;
	
	while(found == true && lastPos >= 0){
		if (retVal.substr(lastPos, 1) == " "){
			retVal = retVal.erase(lastPos, 1);
		} else if(retVal.substr(0, 1) == " "){
			retVal = retVal.erase(0, 1);
		} else{
			found = false;
		}
		lastPos = retVal.length() - 1;
	}
	return retVal;
}

string playlist::getFirst(string text, char separator){
	string value;

	int pos = text.find_first_of(separator);
	if (separator == '*'){
		size_t found = text.find(" by ");
	    if (found != string::npos)
	        pos = found;
	}
	
	if (pos != string::npos){
		value = text.substr(0, pos);
	}

	return value;
}

string playlist::getSecond(string text, char separator){
	string value;

	int pos = text.find_first_of(separator);
	if (separator == '*'){
		pos = text.find_first_of(" by ");
		string::iterator i;
		for(i = text.begin(); i != text.end(); i++){
			char c = *i;
			pos = text.find(" by ");
			pos += 3;
		}
	}
	
	if (pos != string::npos){
		value = text.substr(pos + 1);
	}

	return value;
}

void playlist::setSongs(){
	string songName;
	while(true){
		cout << "Enter track or 'Q' to quit." << endl;
		getline(cin, songName);
		if (songName == "q"){
			break;
		} else{
			if (songName.length() >= 5){
				string title;
				string artist;
				if (songName.find(":")){
					//Title:artist
					title = trim(getFirst(songName, ':'));
					artist = trim(getSecond(songName, ':'));
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						this->titles.push_back(title);
						this->artists.push_back(artist);
						this->songs.push_back(title + " by " + artist);
						continue;
					}
				}
				if (songName.find("-")){
					//Artist-title
					artist = trim(getFirst(songName, '-'));
					title = trim(getSecond(songName, '-'));
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						this->titles.push_back(title);
						this->artists.push_back(artist);
						this->songs.push_back(title + " by " + artist);
						continue;
					}
				}
				if (songName.find("by")){
					//Title by artist
					title = getFirst(songName, '*');
					artist = getSecond(songName, '*');
					if (title != "" && artist != ""){
						cout << "TITLE: " << title << "\nAUTHOR: " << artist << "\n" << endl;
						this->titles.push_back(title);
						this->artists.push_back(artist);
						this->songs.push_back(title + " by " + artist);
						continue;
					}
				}
			} else{
				cout << "please enter a track with more than five characters." << endl;
			}
		}
	}
}

void playlist::getSongs(){
	system("CLS");
	int x = 0;
	if (songs.size() > 0){
		cout << this->playlistName << ":" << endl;
		vector<string>::iterator itSong = songs.begin();
		while (itSong != songs.end()){
			cout << *itSong << endl;
			itSong++;
		}
	} else{
		cout << "No songs were entred" << endl;
	}
	cout << "Creating playlist..." << endl;
	cout.flush();
	sleep(2);
}

void playlist::createPlaylist(){
	ofstream myPlaylist;
	string fileName = this->playlistName + ".txt";
	myPlaylist.open(fileName.c_str());
	
	vector<string>::iterator itSong = this->songs.begin();
	
	while (itSong != this->songs.end()){
		myPlaylist << *itSong << endl;
		itSong++;
	}
	
	myPlaylist.close();
	
	ofstream lists;
	lists.open("Playlists.txt", ios_base::app);
	lists << this->playlistName << endl;
	lists.close();
}

void playlist::deletePlaylist(){
	string fileName = this->playlistName + ".txt";
	
	vector<string> playlists;
	vector<string> newPlaylists;
	ifstream lists("Playlists.txt");
	if(lists.is_open()){
		string line;
		while(getline(lists, line)){
			playlists.push_back(line);
		}
		vector<string>::iterator itList = playlists.begin();
		while (itList != playlists.end()){
			if (*itList != this->playlistName){
				newPlaylists.push_back(*itList);
			}
			itList++;
		}
		lists.close();
	} else{
		cout << "Unable to open the file" << endl;
	}
	lists.close();
	ofstream myPlaylist;
	myPlaylist.open("Playlists.txt");
	vector<string>::iterator itPlaylist = newPlaylists.begin();
	while(itPlaylist != newPlaylists.end()){
		myPlaylist << *itPlaylist << endl;
		itPlaylist++;
	}
	myPlaylist.close();
	
	int status = remove(fileName.c_str());
    if(status==0){
        cout<<"\nPlaylist Deleted Successfully!";
        cout.flush();
        sleep(2);
	} else{
        cout<<"\nErorr Occurred!";
        cout.flush();
        sleep(2);
	}
}

void playlist::savePlaylist(){
	ofstream myPlaylist;
	string fileName = this->playlistName + ".txt";
	myPlaylist.open(fileName.c_str());
	
	vector<string>::iterator itSong = this->songs.begin();
	
	while (itSong != this->songs.end()){
		myPlaylist << *itSong << endl;
		itSong++;
	}
	
	myPlaylist.close();
}

void playlist::deleteSong(int index){
	this->songs.erase(songs.begin() + index - 1);
	this->savePlaylist();
}

