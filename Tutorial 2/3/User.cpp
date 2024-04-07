#include "User.h"
#include <iostream>
using namespace std;

int User::n_user = 0;

User ::User(char *name)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    num_of_favourite_music = 0;
    music_list = new char *[3000];
    User::n_user++;
}

User::User(const User &user)
{
    this->name = new char[strlen(user.name)];
    music_list = new char *[3000];
    strcpy(this->name, user.getName());
    num_of_favourite_music = user.num_of_favourite_music;
    for (int i = 0; i < num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(user.music_list[i])];
        strcpy(this->music_list[i], user.music_list[i]);
    }
    User::n_user++;
}

User ::~User()
{
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->music_list;
    delete[] name;
}

void User ::addFavouriteMusic(char *music)
{
    this->music_list[num_of_favourite_music] = new char[strlen(music)];
    strcpy(this->music_list[num_of_favourite_music], music);
    num_of_favourite_music++;
}

void User ::deleteFavouriteMusic(char *music)
{
    int idx = -1;
    int i = 0;
    while (idx == -1 && i < this->num_of_favourite_music)
    {
        if (strcmp(music, this->music_list[i]) == 0)
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

    for (int j = idx; j < this->num_of_favourite_music - 1; j++)
    {
        this->music_list[j] = new char[strlen(this->music_list[j + 1])];
        strcpy(this->music_list[j], this->music_list[j + 1]);
    }

    this->num_of_favourite_music--;
}

void User ::setName(char *name)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

char *User ::getName() const
{
    return name;
}
int User ::getNumOfFavouriteMusic() const
{
    return num_of_favourite_music;
}

void User ::viewMusicList() const
{
    if (num_of_favourite_music == 0)
    {
        cout << "No music in your favourite list" << endl;
    }
    else
    {
        for (int i = 0; i < num_of_favourite_music; i++)
        {
            cout << i + 1 << ". " << music_list[i] << endl;
        }
    }
}

int User ::getNumOfUser()
{
    return User::n_user;
}