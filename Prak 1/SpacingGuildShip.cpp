#include "SpacingGuildShip.hpp"

int SpacingGuildShip::producedShips = 0;
float SpacingGuildShip::totalGuildTravel = 0;


SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), passengerCount(0), guildNavigatorCount(3), operatingGuildNavigator(3), serialNum(producedShips + 1), spiceStock(50)
{
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), passengerCount(0), guildNavigatorCount(guildNavigatorCount), operatingGuildNavigator(guildNavigatorCount), serialNum(producedShips + 1), spiceStock(spiceStock)
{
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &other) : maxPassengerCap(other.maxPassengerCap), passengerCount(other.passengerCount), guildNavigatorCount(other.guildNavigatorCount), operatingGuildNavigator(other.operatingGuildNavigator), serialNum(producedShips + 1), spiceStock(other.spiceStock)
{
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip()
{
}

int SpacingGuildShip::getShipSerialNum() const
{
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
    return passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
    if (operatingGuildNavigator > 0)
    {
        totalGuildTravel += distance / (E * E * operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers)
{
    if (passengerCount + addedPassengers > maxPassengerCap)
    {
        passengerCount = maxPassengerCap;
    }
    else
    {
        passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
    if (passengerCount - droppedPassengers < 0)
    {
        passengerCount = 0;
    }
    else
    {
        passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n)
{
    if (spiceStock - n * GUILD_NAVIGATOR_SPICE_DOSE >= 0)
    {
        operatingGuildNavigator += n;
        spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
    spiceStock += addedSpice;
}