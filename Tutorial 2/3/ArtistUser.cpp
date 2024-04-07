#include "ArtistUser.h"
#include <iostream>
using namespace std;
int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char *nama) : User(nama)
{
    num_of_music_uploaded = 0;
    uploaded_music_list = new char *[3000];
    ArtistUser::num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser &user) : User(user)
{
    num_of_music_uploaded = user.num_of_music_uploaded;
    uploaded_music_list = new char *[3000];
    for (int i = 0; i < num_of_music_uploaded; i++)
    {
        this->uploaded_music_list[i] = new char[strlen(user.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], user.uploaded_music_list[i]);
    }
    ArtistUser::num_of_artist++;
}

ArtistUser ::~ArtistUser()
{
    delete[] uploaded_music_list;
    cout << "Artist user " << getName() << " deleted" << endl;
}

void ArtistUser ::uploadMusic(char *music)
{
    uploaded_music_list[num_of_music_uploaded] = new char[strlen(music)];
    strcpy(uploaded_music_list[num_of_music_uploaded], music);
    num_of_music_uploaded++;
}

void ArtistUser ::deleteUploadedMusic(char *music)
{
    int idx = -1;
    int i = 0;
    while (idx == -1 && i < this->num_of_music_uploaded)
    {
        if (strcmp(music, this->uploaded_music_list[i]) == 0)
        {
            idx = i;
        }
        else
        {
            i++;
        }
    }

    if (idx == -1)
    {
        return;
    }

    for (int j = idx; j < this->num_of_music_uploaded - 1; j++)
    {
        this->uploaded_music_list[j] = new char[strlen(this->uploaded_music_list[j + 1])];
        strcpy(this->uploaded_music_list[j], this->uploaded_music_list[j + 1]);
    }

    num_of_music_uploaded--;
}

void ArtistUser ::viewUploadedMusicList() const
{
    if (num_of_music_uploaded == 0)
    {
        cout << "No music uploaded" << endl;
    }
    else
    {
        for (int i = 0; i < num_of_music_uploaded; i++)
        {
            cout << i + 1 << ". " << uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser ::getNumOfMusicUploaded() const
{
    return num_of_music_uploaded;
}

int ArtistUser ::getNumOfArtist()
{
    return ArtistUser::num_of_artist;
}
