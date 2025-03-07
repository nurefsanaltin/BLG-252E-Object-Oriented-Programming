//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

//-------------------------POKEMON CLASS FUNCTIONS-------------------------------//

pokemon::pokemon(string name, int atkValue)
{
    this->name = name;
    this->hpValue = 100;
    this->atkValue = atkValue;
}
pokemon::pokemon(const pokemon &originalPokemon)
{
    this->name = originalPokemon.name;
    this->hpValue = originalPokemon.hpValue;
    this->atkValue = originalPokemon.atkValue;
}

string pokemon::getName() const
{
    return this->name;
}
int pokemon::getHpValue()
{
    return this->hpValue;
}
int pokemon::getAtkValue()
{
    return this->atkValue;
}
void pokemon::setHpValue(int new_hpValue)
{
    this->hpValue = new_hpValue;
}

//-------------------------POKEDEX CLASS FUNCTIONS-------------------------------------------------//

pokedex::pokedex()
{
    this->value = 0;
}
void pokedex::updatePokedex(const pokemon &newPokemon)
{
    // Only new pokemons are allowed to be added
    int is_new = 1;

    for (int i = 0; i <= value; i++)
    {
        if (pokedexArray[i].getName() == newPokemon.getName())
        {
            is_new = 0;
        }
    }

    if (is_new)
    {
        pokedexArray[this->value] = newPokemon;
        this->value++;
    }
}
void pokedex::printPokedex()
{
    // Method to print Pokemon names from pokedexArray
    for (int i = 0; i < this->value; i++)
    {
        cout << this->pokedexArray[i].getName() << "\n";
    }
}

//-------------------------PLAYER CLASS FUNCTIONS----------------------------------------------//

player::player(string name, pokemon &playerPokemon)
{
    this->name = name;
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    this->playerPokemon = playerPokemon;
}
int player::showPokemonNumber()
{
    return this->pokemonNumber;
}
int player::showPokeballNumber()
{
    return this->pokeballNumber;
}
int player::showBadgeNumber()
{
    return this->badgeNumber;
}
pokemon player::getPokemon()
{
    return this->playerPokemon;
}
void player::battleWon()
{
    this->badgeNumber++;
    this->pokeballNumber += 3;
}
void player::catchPokemon()
{
    this->pokemonNumber++;
    this->pokeballNumber--;
}
void player::setPLayerHpValue(int new_HpValue)
{
    this->playerPokemon.setHpValue(new_HpValue);
}

//-------------------------ENEMY CLASS FUNCTIONS--------------------------------------------------------//

enemy::enemy(string name, pokemon &enemyPokemon)
{
    this->name = name;
    this->enemyPokemon = enemyPokemon;
}
pokemon enemy::getPokemon()
{
    return this->enemyPokemon;
}
string enemy::getName()
{
    return this->name;
}
void enemy::setEnemyHpValue(int new_HpValue)
{
    this->enemyPokemon.setHpValue(new_HpValue);
}