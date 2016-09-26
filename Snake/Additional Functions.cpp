# include <iostream>
# include <fstream>							//Scores will be handled through file handling
# include <iomanip>
# include <windows.h>
# include <conio.h>

# include "utility.h"

using namespace std ;

# include "Snake.cpp"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE) ;

ifstream fin ;
ofstream fout ;

void StartGame ( ) ;						//Only function included in main body... whih controls all other functions
void NewUserInfo ( char ) ;					//Take the name of new user
void PauseGame ( ) ;						//In case of pause game.
void Instructions ( ) ;						//Instructions for user assistance
bool Exitgame ( ) ;							//In case of exit from game
void ShowAllPlayersRecords ( ) ;			//Show top 5 scores... played till yet
void Gamelevel ( int & ) ;					//Includes Easy, Medium & Hard level for user
void Savegame ( int ) ;						//Save the score in file if it exist in top 5
void Gametype ( int & ) ;
void main ()
{
	StartGame ( ) ;
}

void NewUserInfo ( char name [] )			//Get user name using pointer variables
{
	cout << "\n\nPlease enter your name : " ;
	cin.ignore () ;							//Remove the prewritten value on buffer
	cin.getline ( name , 50 ) ;
}

void Savegame ( int score1 )				//Save the current play game score into file if it exist in top 5
{
	int score [ 5 ] ;
	fin.open ( "SaveGameData.txt" ) ;
	
	for ( int a = 0 ; a < 5 ; a ++ )
	{
		fin >> score [a] ;
	}
	fin.close ( ) ;

	if ( score1 >= score [ 0 ] )
	{
		score [ 4 ] = score [ 3 ] ;
		score [ 3 ] = score [ 2 ] ;
		score [ 2 ] = score [ 1 ] ;
		score [ 1 ] = score [ 0 ] ;
		score [ 0 ] = score1 ;
	}
	else if ( score1 >= score [ 1 ] )
	{
		score [ 4 ] = score [ 3 ] ;
		score [ 3 ] = score [ 2 ] ;
		score [ 2 ] = score [ 1 ] ;
		score [ 1 ] = score1 ;
	}
	else if ( score1 >= score [ 2 ] )
	{
		score [ 4 ] = score [ 3 ] ;
		score [ 3 ] = score [ 2 ] ;
		score [ 2 ] = score1 ;
	}
	else if ( score1 >= score [ 3 ] )
	{
		score [ 4 ] = score [ 3 ] ;
		score [ 3 ] = score1 ;
	}
	else if ( score1 >= score [ 4 ] )
	{
		score [ 4 ] = score1 ;
	}

	fout.open( "SaveGameData.txt" ) ;
	for ( int i = 0 ; i < 5 ; i++ )
	{
		fout << score [i] << endl ;
	}
	fout.close ( ) ;
}

void Gametype ( int &type )
{
	system ( "cls" ) ;
	cout << "\n\nGame type:\n----------\n\n" ;
	
	cout << "\n\t1 - Classic\n" ;
	cout << "\n\t2 - Modern\n\n" ;
	cout << "\n\nEnter your choice : " ;
	cin >> type ;
	while ( type < 1 || type > 2 )
	{
		cout << "Invalid choice !! Enter again : " ;
		cin >> type ;
	}
	fout.open ( "GameType.txt" ) ;
	if ( type == 1 )
	{
		type = 0 ;
		fout << type ;
	}
	else
	{
		cout << "\n\nModern type:\n----------\n\n" ;
		cout << "\n\t1 - Maze 1\n\n" ;
		cout << "\n\t2 - Maze 2\n\n" ;
		cout << "\n\t3 - Maze 3\n\n" ;
		cout << "\n\t4 - Maze 4\n\n" ;
		cout << "\n\nEnter your choice : " ;
		cin >> type ;
		fout << type ;
	}
	fout.close ( ) ;
	if ( type == 0 )
	{
		cout << endl << "Classical Game type is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else if ( type == 1 )
	{
		cout << endl << "Maze 1 is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else if ( type == 2 )
	{
		cout << endl << "Maze 2 is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else if ( type == 3 )
	{
		cout << endl << "Maze 3 is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else
	{
		cout << endl << "Maze 4 is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	
}

void Gamelevel ( int &level )			//Ask the user for difficulty level.. and according to this value of Sleep ( ) will be defin_scre.
{
	system ( "cls" ) ;
	cout << "\n\nDifficulty Level:\n-----------------\n\n" ;
	
	cout << "\t1 - Amuture\n\n" ;
	cout << "\t2 - Professional\n\n" ;
	cout << "\t3 - Gamer\n\n" ;
	cout << "\n\tEnter level :	" ;
	
	fout.open ( "GameLevel.txt" ) ;
	do
	{
		cin >> level ;
		if ( level > 3 || level < 1 )
		{
			cout << "Invalid number !! Enter correct level number again : " ;
		}
		
	} while ( level > 3 || level < 1 ) ;					//The value which will give to Sleep ( )
	if ( level == 1 )					
	{
		level = 200 ;
		cout << endl << "Easy level is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else if ( level == 2 )
	{
		level = 100 ;
		cout << endl << "Medium level is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	else if ( level == 3 )
	{
		level = 75 ;
		cout << endl << "Hard level is now set.Changes will be applied in the new game." << endl ;
		system("pause") ;
	}
	fout << level ;
	fout.close ( ) ;

}

void ShowAllPlayersRecords ( char name [] )				//Top 5 scores which are saved in file will be display
{
	int score [5] ;
	for ( int i = 0 ; i < 5 ; i ++ )
	{
		score [i] = 0 ;
	}
	fin.open ( "SaveGameData.txt" ) ;
	cout << "\tName : " << name ;
	cout << "\n\nTop Scores:\n-----------\n\n" ;
	for ( int i = 0 ; i < 5 ; i ++ )
	{
		fin >> score [i] ;
		
		cout << "\t" << i + 1 << " - " << score [i] << endl << endl ;
	}
	fin.close ( ) ;
}

void Instructions ( )				//If user wants to read the instructions
{
	cout << "\nInstructions:\n-------------\n\n" ;
	cout << "\n\n\tUse up, down, right, left keys \n\tto move the snake.\n" ;
	cout << "\tEat the food without colliding with any obstacles\n\tand eat bonous food quickly to score extra points.\n\n" ;
}
void StartGame ( )					//Includes all format of game and all functions call
{
	int choice , level , type , blink = 500 , score ;
	char name [ 20 ] = "                   " ;

	fin.open("GameType.txt") ;
	fin >> type ;
	fin.close() ;
	fin.open("GameLevel.txt") ;
	fin >> level ;
	fin.close() ;

	cout << "\n\n\n\n\n\n\t\t " ;
	for ( int i = 0 ; i < 47 ; i ++ )
	{
		SetConsoleTextAttribute(console, (i % 12) + 1);
		cout << "$" ;
		Sleep ( 50 ) ;
	}
	SetConsoleTextAttribute(console, 9);
		Sleep ( 1000 ) ;
		cout << "\n\t\t*\t\t\t\t\t\t*\n" ;
		Sleep ( 1000 ) ;
		cout << "\t\t$\t\t** Snake**\t\t\t$\n" ;
		Sleep ( 1000 ) ;
		cout << "\t\t*\t\t\t\t\t\t*\n\t\t " ;
		Sleep ( 1000 ) ;
	for ( int i = 0 ; i < 47 ; i ++ )
	{
		SetConsoleTextAttribute(console, (i % 12) + 1);
		cout << "$" ;
		Sleep (50 ) ;
	}
	for ( int n = 0 ; n < 3 ; n ++ )
	{
		SetConsoleTextAttribute(console, (n % 12) + 1);
		system ( "cls" ) ;
		Sleep ( blink -= 100 ) ;
		cout << "\n\n\n\n\n\n\t\t " ;
	for ( int i = 0 ; i < 47 ; i ++ )
	{
		SetConsoleTextAttribute(console, (i % 12) + 1);
		cout << "$" ;
		
	}
	SetConsoleTextAttribute(console, 9);
		cout << "\n\t\t*\t\t\t\t\t\t*\n" ;
		
		cout << "\t\t$\t\t** Snake**\t\t\t$\n" ;
		
		cout << "\t\t*\t\t\t\t\t\t*\n\t\t " ;
	
	for ( int i = 0 ; i < 47 ; i ++ )
	{
		SetConsoleTextAttribute(console, (i % 12) + 1);
		cout << "$" ;
		
	}
	Sleep ( 1000 ) ;
	}
	SetConsoleTextAttribute(console, 9);
	cout << "\n\n\n\n\n\nPress any key to continue . . . " ;
	_getch ( ) ;
c :	SetConsoleTextAttribute(console, 11);
	system ( "cls" ) ;
	cout << "\n\nMenu:\n----------" ;
	cout << "\n\n1 - Lets Play the Game\n" ;
	Sleep ( 100 ) ;
	cout << "\n2 - Wanna change the level ?\n" ;
	Sleep ( 100 ) ;
	
	cout << "\n3 - Lets change this game\n" ;
	Sleep ( 100 ) ;
	cout << "\n4 - Instructions\n" ;
	Sleep ( 100 ) ;
	cout << "\n5 - High Scores\n" ;
	Sleep ( 100 ) ;
	cout << "\n6 - Mommy's calling. Gotta go.\n" ;
	Sleep ( 100 ) ;
	cout << "\n\nEnter your choice : " ;
	do
	{
		cin >> choice ;
		if ( choice < 1 || choice > 6 )
		{
			cout << "Invalid Choice !! Enter Again " ;
		}
	} while ( choice < 1 || choice > 6 ) ;
	switch ( choice )
	{
	case 1 :
		{
			NewUserInfo ( name ) ;
			system("cls") ;
			SetConsoleTextAttribute(console, 12);
			score = start ( level , type ) ;
			Savegame ( score ) ;
			goto c ;
			break ;
		}
	case 2:
		{
			Gamelevel ( level ) ;
			goto c ;
			break ;
		}
	case 3 :
		{
			Gametype ( type ) ;
			goto c ;
			break ;
		}
	case 4 :
		{
			system ( "cls" ) ;
			Instructions ( ) ;
			cout << "\n\nPress any key to go back . . ." ;
			_getch ( ) ;
			
			system ( "cls" ) ;
			goto c ;
			break ;
		}
	case 5 :
		{
			system ( "cls" ) ;
			ShowAllPlayersRecords ( name ) ;
			cout << "\n\nPress any key to go back . . ." ;
			_getch ( ) ;
			system ( "cls" ) ;
			goto c ;
			break ;
		}
	case 6 :
		{

			int again ;
			again = Exitgame ( ) ;
			if ( again == 1 )
			{
				system ( "cls" ) ;
				goto c ;
			}
			else
			{
				exit ( 0 ) ;
			}
			break ;
		}
	default :
		{
			break ;
		}
	}
	cout << endl << endl ;
	
}
bool Exitgame ( )
{
	char again ;
	system ( "cls" ) ;
	cout << "\nDo you really wish to quit ( y / n ) : " ;

	cin >> again ;
	if ( again == 'n' || again == 'N' )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}