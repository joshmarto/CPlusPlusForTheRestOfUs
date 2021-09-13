#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "playlist.h"

using namespace std;

void test(){
	cout << "Still working..." << endl;
}

void displayLists(){
	vector<string> playlists;
	
	ifstream lists("Playlists.txt");
	
	if(lists.is_open()){
		string line;
		while(getline(lists, line)){
			playlists.push_back(line);
		}
		lists.close();
	} else{
		cout << "Unable to open the file" << endl;
	}
	
	if(playlists.size() > 0){
		cout << "MAIN MENU" << "\nC. Create playlist\nS. Select playlist\nX. Exit the program" << endl;
		int c = 1;
		vector<string>::iterator playlist = playlists.begin();
		
		while(playlist != playlists.end()){
			cout << c << ". " << *playlist << endl;
			c++;
			playlist++;
		}
	} else{
		cout << "MAIN MENU" << "\nC. Create playlist\nS. Select playlist\nX. Exit the program" << endl;
	}
}

void displaySongs(string playlist){
	vector<string> songs;
	
	string file = playlist + ".txt";
	ifstream pl(file.c_str());
	
	if(pl.is_open()){
		string line;
		while(getline(pl, line)){
			songs.push_back(line);
		}
		pl.close();
	} else{
		cout << "Unable to open the file" << endl;
	}
	
	if(songs.size() > 0){
		cout << "A. Add track(s) to the playlist.\nD. Delete this playlist.\nS. Select track\nX. Exit to main menu." << endl;
		int c = 1;
		vector<string>::iterator song = songs.begin();
		
		while(song != songs.end()){
			cout << c << ". " << *song << endl;
			c++;
			song++;
		}
		cout <<"Your choice: ";
	} else{
		cout << "A. Add track(s) to the playlist.\nD. Delete this playlist.\nX. Exit to main menu.\nYour choice: ";
	}
}

vector<string> getLists(){
	vector<string> playlists;
	
	ifstream lists("Playlists.txt");
	
	if(lists.is_open()){
		string line;
		while(getline(lists, line)){
			playlists.push_back(line);
		}
		lists.close();
	} else{
		cout << "Unable to open the file" << endl;
	}
	return playlists;
}

vector<string> getSongs(string plName){
	vector<string> songs;
	
	string file = plName + ".txt";
	ifstream playlist(file.c_str());
	
	if(playlist.is_open()){
		string line;
		while(getline(playlist, line)){
			songs.push_back(line);
		}
		playlist.close();
	} else{
		cout << "Unable to open the file" << endl;
	}
	return songs;
}

void songOptions(string name){
	int option;
	playlist sing;
	sing.playlistName = name;
	sing.songs = getSongs(name);
	cout << "Enter the # of song: ";
	cin >> option;
	system("CLS");
	cout << "Playlist '" << sing.playlistName << "'" << endl;
	string currentSong = sing.songs[option - 1];
	string op;
	cout << "Track '" << currentSong << "' Menu:" << endl;
	cout << "d. Delete this track.\nx. Exit to Playlist menu.\nYour choice: ";
	cin.ignore();
	getline(cin, op);
	if (op == "d"){
		sing.deleteSong(option);
	} else if (op == "x"){
		cout << "Back to main menu..." << endl;
		cout.flush();
	  	sleep(2);
	}
}

void listOptions(string name){
	system("CLS");
	cout << "Playlist '" << name << "' Menu:" << endl;
	displaySongs(name);
	// -------------
	string option;
	playlist cool;
	cool.playlistName = name;
	cool.songs = getSongs(name);
	cin.ignore();
	getline(cin, option);
	if (option == "x"){
		cout << "Back to main menu..." << endl;
		cout.flush();
		sleep(2);
	}
	if (option == "a"){
		cool.setSongs();
		cool.savePlaylist();
	} else if(option == "d"){
		cool.deletePlaylist();
	} else if(option == "s"){
		songOptions(name);
	}
}

int main(int argc, char** argv) {
	string option;
	while(true){
		displayLists();
		cout << "Your choice: ";
		getline(cin, option);
		if(option == "x"){
			system("CLS");
			cout << "Farawell" << endl;
			break;
		} else if(option == "c"){
			system("CLS");
			playlist favorites;
			favorites.setPlaylistName();
			favorites.setSongs();
			favorites.createPlaylist();
			favorites.getSongs();
		} else if (option == "s"){
			int playNumber;
			cout << "Enter the playlist number: ";
			cin >> playNumber;
			vector<string> lists = getLists();
			if (playNumber <= lists.size()){
				playNumber--;
//				system("CLS");
//				cout << "Playlist '" << lists[playNumber] << "' Menu:" << endl;
//				displaySongs(lists[playNumber]);
				listOptions(lists[playNumber]);
			} else{
				cout << "Invalid playlist number. Please try again." << endl;
				cin >> playNumber;
				continue;
			}
		}
		system("CLS");
	}
	return 0;
}
