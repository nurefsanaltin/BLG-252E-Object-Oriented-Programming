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
#include <fstream>

#include "../include/pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;           // Use this to keep track of the enemy names
int POK_COUNTER = 0;            // Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; // You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  // You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---//
//
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string *readEnemyNames(const char *);
string *readPokemonNames(const char *);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player *, string *, string *);
void catchPokemon(player *, string *);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---//
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char *argv[])
{
    system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string *enemyNames = readEnemyNames(argv[1]);
    string *pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n"
         << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);

    int menuChoice;

    while (true)
    {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readEnemyNames(const char *argv)
{
    fstream enemyFile;
    enemyFile.open(argv, ios::in);

    if (enemyFile.is_open())
    {
        int numberOfEnemies;
        string firstLine;
        enemyFile >> firstLine;
        numberOfEnemies = stoi(firstLine);

        string *enemyNames = new string[numberOfEnemies];
        int i = 0;
        while (!enemyFile.eof())
        {
            string line;
            enemyFile >> line;
            enemyNames[i] = line;
            i++;
        }

        return enemyNames;
    }
    else
    {
        cout << "Enemy file cannot be opened successfully\n";
        return nullptr;
    }
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readPokemonNames(const char *argv)
{
    fstream pokemonFile;
    pokemonFile.open(argv, ios::in);

    if (pokemonFile.is_open())
    {
        int numberOfPokemons;
        string firstLine;
        pokemonFile >> firstLine;
        numberOfPokemons = stoi(firstLine);

        string *pokemonNames = new string[numberOfPokemons];
        int i = 0;
        while (!pokemonFile.eof())
        {
            string line;
            pokemonFile >> line;
            pokemonNames[i] = line;
            i++;
        }

        return pokemonNames;
    }
    else
    {
        cout << "Pokemon file cannot be opened successfully\n";
        return nullptr;
    }
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice)
{
    string pokemonName;
    if (pokemonChoice == 1)
    {
        pokemonName = "Bulbasaur";
    }
    else if (pokemonChoice == 2)
    {
        pokemonName = "Charmender";
    }
    else if (pokemonChoice == 3)
    {
        pokemonName = "Squirtle";
    }
    else
    {
        cout << "Please enter correct number\n";
    }

    pokemon new_pokemon(pokemonName, 20);

    player my_player(playerName, new_pokemon);
    /* player *my_player = new player(playerName, new_pokemon);
    return *my_player; */
    return my_player;
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu()
{
    cout << "\n";
    cout << "-------- Menu --------\n";
    cout << "1. Fight for a badge\n";
    cout << "2. Catch a Pokemon\n";
    cout << "3. Number of Pokemons\n";
    cout << "4. Number of Pokeballs \n";
    cout << "5. Number of Badges\n";
    cout << "6. Pokedex\n";
    cout << "7. Exit\n";
    cout << "\n";
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player *newPlayer, string *enemyNames, string *pokemonNames)
{
    string enemyPokemonName = pokemonNames[POK_COUNTER];
    pokemon enemy_pokemon(enemyPokemonName, 10);
    string enemyName = enemyNames[NAME_COUNTER];
    enemy new_enemy(enemyName, enemy_pokemon);
    newPlayer->playerPokedex.updatePokedex(enemy_pokemon);

    cout << "You encounter with " << enemyName << " and his/hers pokemon " << enemyPokemonName << "\n";
    cout << enemyPokemonName << " Health: " << enemy_pokemon.getHpValue() << " Attack: " << enemy_pokemon.getAtkValue() << "\n";

    while (newPlayer->getPokemon().getHpValue() != 0 && new_enemy.getPokemon().getHpValue() != 0)
    {
        cout << "\n";
        cout << "1- Fight\n"
             << "2- Runaway\n"
             << "Choice: ";
        int fight_or_run;
        cin >> fight_or_run;

        if (fight_or_run == 1)
        {
            int newPlayer_s_hpValue = newPlayer->getPokemon().getHpValue() - new_enemy.getPokemon().getAtkValue();
            newPlayer->setPLayerHpValue(newPlayer_s_hpValue);

            int enemy_s_hpValue = new_enemy.getPokemon().getHpValue() - newPlayer->getPokemon().getAtkValue();
            new_enemy.setEnemyHpValue(enemy_s_hpValue);
        }
        else if (fight_or_run == 2)
        {
            // ı dont know what to do with this place I decide later
        }
        else
        {
            cout << "Please enter a valid number!!!\n";
        }

        cout << "Your Pokemons Health: " << newPlayer->getPokemon().getHpValue() << "\n";
        cout << enemyName << " Pokemons Health: " << new_enemy.getPokemon().getHpValue() << "\n";
    }

    if (newPlayer->getPokemon().getHpValue() == 0)
    {
        cout << enemyPokemonName << " won\n";
    }
    else if (new_enemy.getPokemon().getHpValue() == 0)
    {
        newPlayer->battleWon();
        cout << "You Won!\n";
    }

    new_enemy.setEnemyHpValue(100);
    newPlayer->setPLayerHpValue(100);

    POK_COUNTER++;
    NAME_COUNTER++;
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player *newPlayer, string *pokemonNames)
{
    string newPokemonName = pokemonNames[POK_COUNTER];
    pokemon newPokemon(newPokemonName, 10);
    newPlayer->playerPokedex.updatePokedex(newPokemon);

    cout << "You encounter with " << newPokemonName << " Health: " << newPokemon.getHpValue() << " Attack: " << newPokemon.getAtkValue() << "\n";

    cout << "\n";
    cout << "1- Catch\n"
         << "2- Runaway\n"
         << "Choice: ";
    int catch_or_run;
    cin >> catch_or_run;

    if (catch_or_run == 1)
    {
        newPlayer->catchPokemon();
        cout << "You catch " << newPokemonName << "\n";
    }
    else if (catch_or_run == 2)
    {
        // ı dont know what to do with this place I decide later
    }
    else
    {
        cout << "Please enter a valid number!!!" << endl;
    }

    POK_COUNTER++;
};
//--------------------------------------------//
