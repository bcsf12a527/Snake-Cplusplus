# include "Mazes.cpp"

void PauseGame ( )
{
	system ( "pause" ) ;
}

struct Snake
{
	int row ;
	int column ;
} ;

Snake snake [100] ;
int size ;

void snakeMovement ()
{
	for (int i = 0 ; i < size ; i++ )
	{
		setCursor ( snake [i].column , snake [i].row ) ;
		cout << "*" ;
	}

	setCursor ( snake [size].column , snake [size].row ) ;
	cout << "@" ;

	setCursor ( snake [0].column , snake [0].row ) ;
	cout << " " ;

	for (int i = 1 ; i <= size ; i++)
	{
		snake[i-1] = snake[i] ;
	}
}
void add_segment(const int &direction)
{

  switch(direction)
  {

    case(77):
		{
			snake[size].row=snake[size - 1].row;
			snake[size].column=snake[size - 1].column + 1;
			break;
		}

    case(75):
		{
			snake[size].row=snake[size - 1].row;
			snake[size].column=snake[size - 1].column - 1;
			break;
		}

    case(72):
		{
			snake[size].row=snake[size - 1].row - 1;
			snake[size].column=snake[size - 1].column;
			break;
		}

    case(80):
		{
			snake[size].row=snake[size - 1].row + 1;
			snake[size].column=snake[size - 1].column;
		}
  }
}

void randomDot ( int &x , int &y , const int type )										// Randomize the x and y coordinates considering maze limits
{
	x = rand() % 80 ;
	y = rand() % 25 ;
	while ( readFrom( x , y ) != ' ' )
	{
		x = rand() % 80 ;
		y = rand() % 25 ;
	}
}

bool maze_conditions ( const int type )
{
	if ( type == 0 )
	{
		return true ;
	}
	else if ( type == 1 )
	{
		if ( ( snake [size].column < 78 && snake [size].column >= 1 ) && ( snake [size].row < 24 && snake [size].row >= 1 ) )
		{
			return true ;
		}
		else
		{
			return false ;
		}
	}
	else if ( type == 2 )
	{
		if ( ( snake [size].column < 78 && snake [size].column >= 1 ) && ( snake [size].row < 24 && snake [size].row >= 1 ) )
		{
			if ( (snake [size].column > 10 && snake [size].column < 70 ) && ( snake[size].row == 6 || snake[size].row == 16 ) )
			{
				return false ;
			}
			else
			{
				return true ;
			}
		}
		else
		{
			return false ;
		}
	}
	else if ( type == 3 )
	{
		if (((snake [size].column >= 9 && snake [size].column <= 69)&&( snake [size].row==6 || snake [size].row == 16 ))  ||  ((( snake [size].column>=0 && snake [size].column<=8 ) || ( snake [size].column<=78 && snake [size].column>=70 )) && ( snake [size].row==0 || snake [size].row==24 )) || (( ( snake [size].row>=0 && snake [size].row<=6) || ( snake [size].row>=18 && snake [size].row<=24 ) ) && ( snake [size].column==0 || snake [size].column == 78 )))
		{
			return false ;
		}
		else
		{
			return true ;
		}
	}
	else if ( type == 4 )
	{
		if (( ( snake [size].row == 7 ) && ( snake [size].column >= 0 && snake [size].column <= 20 ) ) || ( snake [size].row == 19 ) && ( snake [size].column >= 0 && snake [size].column <= 20 ) || ( ( snake [size].row == 13 ) && ( snake [size].column >= 50 && snake [size].column < 80 ) ) || ( ( snake [size].column == 49 ) && ( snake [size].row >= 7 && snake [size].row <= 19 ) ) && ( snake [size].row !=0 ) )
		{
			return false ;
		}
		else
		{
			return true ;
		}
	}
}

bool snake_conditions()
{
	int i = 0 ;
	while ( i < size )
	{
		if ( snake [size].column == snake [i].column && snake [size].row == snake [i].row )
		{
			return false ;
			break ;
		}
		i = i + 1 ;
	}
	if ( i == size )
	{
		return true ;
	}
}

bool Conditions ( const int type )
{
	if ( maze_conditions ( type ) && snake_conditions () && size < 100 )					// Increase the size limit to increase no of dots.
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

void printSpecial ( int& count , int& score , const int direction , const int type )
{
	static int dotx , doty ;
	char ch = 15 ;
	if ( count == 0 )
	{
		randomDot ( dotx , doty, type ) ;
		setCursor ( dotx , doty ) ;
		cout << ch ;
		cout << "\a" ;
	}
	else if ( count < 50 && ( snake [size].column == dotx && snake [size].row == doty ) )
	{
		for ( int i = 0 ; i < 3 ; i++ )
		{
			size = size + 1 ;
			add_segment ( direction ) ;
			score = score + 10 ;
		}
		count = -5 ;
	}
	else if ( count == 50 )
	{
		setCursor ( dotx , doty ) ;
		cout << " " ;
		count = -5 ;
	}
	count = count + 1 ;
}

void AarPar ( )
{
	if ( snake [size].column > 79 )
	{
		snake [size].column = 0 ;
	}
	else if ( snake [size].column < 0 )
	{
		snake [size].column = 79 ;
	}
	if ( snake [size].row > 24 )
	{
		snake [size].row = 0 ;
	}
	else if ( snake [size].row < 0 )
	{
		snake [size].row = 24 ;
	}
}

int start ( int level , const int type)
{
	int dot_x , dot_y , direction = 77 , count = -4 , score = -10 , k = 77 ;
	srand ( time(0) ) ;
	size = 5 ;
	if ( type == 1)
	{
		maze1 () ;
	}
	else if ( type == 2 )
	{
		maze2 () ;
	}
	else if ( type == 3 )
	{
		maze3 () ;
	}
	else if ( type == 4 )
	{
		maze4 () ;
	}
	for ( int i = 0 ; i <= size ; i++ )
	{
		snake [i].row = 15 ;													//Initializing the snake array
		snake [i].column = 25 + i ;
	}

	dot_x = snake [size].column ;
	dot_y = snake [size].row ;

	while ( Conditions( type ) )		
	{
		if ( !_kbhit () )
		{
			AarPar () ;
			if ( snake [size].column == dot_x && snake [size].row == dot_y )
			{
				randomDot ( dot_x , dot_y , type ) ;									// Randomizing the dot position
				setCursor ( dot_x , dot_y ) ;									// Setting the dot position
				cout << "*" ;													// Printing the dot
				size = size + 1 ;												// If snake eats the dot then it increases and remaning dots decrease
				add_segment ( direction ) ;
				score = score + 10 ;
				count = count + 1 ;
			}

			snakeMovement () ;
			add_segment ( direction ) ;

			if ( count >= 0 && count <= 50 )
			{
				printSpecial ( count , score , direction , type ) ;
			}
			if ( score > 0 && score % 90 == 0 )
			{
				system("cls") ;
				setCursor ( 30 , 15 ) ;
				cout << "Level up" << endl << endl << endl ;
				level = level * 2/3 ;
				score = score + 10 ;
				PauseGame ( ) ;
				system("cls") ;
				if ( type == 1)
				{
					maze1 () ;
				}
				else if ( type == 2 )
				{
					maze2 () ;
				}
				else if ( type == 3 )
				{
					maze3 () ;
				}
				else if ( type == 4 )
				{
					maze4 () ;
				}
				setCursor ( dot_x , dot_y ) ;
				cout << "*" ;
			}

			Sleep (level) ;														// Remove it if you have superman reflexes
			/*system ("cls") ;*/
		}
		else
		{
			k = _getch() ;
			k = _getch() ;														// No Backward snake movement
			if ( ( direction == 77 && ( k == 80 || k == 72 ) ) || ( direction == 75 && ( k == 72 || k == 80 ) ) || ( direction == 80 && ( k == 77 || k == 75 ) ) || ( direction == 72 && ( k == 77 || k == 75 ) ) )
			{
				direction = k ;
			}
		}
	}
	system("cls") ;
	setCursor ( 30 , 15 ) ;
	cout << "You scored " << score << " in this round." << endl << endl << endl ;
	PauseGame ( ) ;
	size = 5 ;
	return score ;
}