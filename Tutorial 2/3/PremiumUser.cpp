#include "PremiumUser.h"
#include <iostream>
using namespace std;

PremiumUser ::PremiumUser(char *nama) : User(nama)
{
    num_of_music_downloaded = 0;
    active = true;
}
PremiumUser ::PremiumUser(const PremiumUser &user) : User(user)
{
    num_of_music_downloaded = user.num_of_music_downloaded;
    active = user.active;
}

PremiumUser ::~PremiumUser()
{
}

void PremiumUser ::downloadMusic(char *name)
{
    if (active)
    {
        cout << "Music Downloaded: " << name << endl;
        num_of_music_downloaded++;
    }
    else
    {
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser ::inactivatePremium()
{
    active = false;
}

void PremiumUser ::activatePremium()
{
    active = true;
}

int PremiumUser ::getNumOfMusicDownloaded() const
{
    return num_of_music_downloaded;
}

bool PremiumUser ::getPremiumStatus() const
{
    return active;
}
