#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>

using namespace std;

class playlist
{
	public:
		string playlistName;
		string plFile;
		vector<string> titles;
		vector<string> songs;
		vector<string> artists;
		playlist();
		void setPlaylistName();
		string trim(string anyString);
		string getFirst(string text, char sparator);
		string getSecond(string text, char separator);
		void setSongs();
		void getSongs();
		void createPlaylist();
		void deletePlaylist();
		void savePlaylist();
		void deleteSong(int index);
	protected:
};

#endif
