//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    int hpValue;
    int atkValue;

public:
    friend class player;
    pokemon(){};
    pokemon(string, int);
    pokemon(const pokemon &);

    string getName() const;
    int getHpValue();
    int getAtkValue();

    void setHpValue(int);
};

class pokedex
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    pokemon pokedexArray[100];
    int value;

public:
    pokedex();
    void updatePokedex(const pokemon &);
    void printPokedex();
};

class player
{
private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    string name;
    int pokemonNumber;
    int pokeballNumber;
    int badgeNumber;
    pokemon playerPokemon;

public:
    pokedex playerPokedex;
    player(){};
    player(string, pokemon &);
    int showPokemonNumber();
    int showPokeballNumber();
    int showBadgeNumber();
    pokemon getPokemon();
    void battleWon();
    void catchPokemon();
    void setPLayerHpValue(int);
};

class enemy
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    pokemon enemyPokemon;

public:
    enemy(){};
    enemy(string, pokemon &);
    pokemon getPokemon();
    string getName();
    void setEnemyHpValue(int);
};

#endif