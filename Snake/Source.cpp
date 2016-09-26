//# include < stdio.h >
//# include < iostream >
//# include < iomanip >
//# include < windows.h >
//# include < conio.h >
//# include "utility.h"
//using namespace std ;
//
//struct Snake
//{
//	int row ;
//	int column ;
//} ;
//
//void snakeMovement ( Snake snake [] , int size )
//{
//	setCursor ( snake [size].column , snake [size].row ) ;
//	cout << "@" ;
//	for (int i = 0 ; i < size ; i++ )
//	{
//		setCursor ( snake [i].column , snake [i].row ) ;
//		cout << "*" ;
//	}
//	setCursor ( snake [0].column , snake [0].row ) ;
//	cout << " " ;
//	for (int i = 1 ; i <= size ; i++)
//	{
//		snake[i-1] = snake[i] ;
//	}
//}
//void add_segment(Snake snake [] , int &direction , int size)
//{
//
//  switch(direction)
//  {
//
//    case(77):
//		{
//			snake[size].row=snake[size - 1].row;
//			snake[size].column=snake[size - 1].column + 1;
//			break;
//		}
//
//    case(75):
//		{
//			snake[size].row=snake[size - 1].row;
//			snake[size].column=snake[size - 1].column - 1;
//			break;
//		}
//
//    case(72):
//		{
//			snake[size].row=snake[size - 1].row - 1;
//			snake[size].column=snake[size - 1].column;
//			break;
//		}
//
//    case(80):
//		{
//			snake[size].row=snake[size - 1].row + 1;
//			snake[size].column=snake[size - 1].column;
//		}
//  }
//}
//
//void printDot ( int &x , int &y )										// Randomize the x and y coordinates of dot within console limit
//{
//	srand ( time(0) ) ;
//	x = rand() % 80 ;
//	y = rand() % 25 ;
//}
//
//void main ()
//{
//	Snake snake [30] ;
//	int dot_x , dot_y , direction = 77 , size = 5 ;
//
//	for ( int i = 0 ; i <= size ; i++ )
//	{
//		snake [i].row = 15 ;													//Initializing the snake array
//		snake [i].column = 25 + i ;
//	}
//
//	dot_x = snake [size].column ;
//	dot_y = snake [size].row ;
//
//	while ( ( snake [size].column < 80 && snake [size].column >= 0 ) && ( snake [size].row < 25 && snake [size].row >= 0 ) && size < 20 )		// Increase the size limit to increase no of dots.
//	{
//		if ( !_kbhit () )
//		{
//			if ( snake [size].column == dot_x && snake [size].row == dot_y )
//			{
//				printDot ( dot_x , dot_y ) ;									// Setting the dot position
//				setCursor ( dot_x , dot_y ) ;									// Printing the dot
//				cout << "*" ;													// If snake eats the dot then it increases and remaning dots decrease
//				size = size + 1 ;
//				add_segment(snake , direction , size) ;
//			}
//
//			snakeMovement (snake , size ) ;
//			add_segment(snake , direction , size) ;
//
//			Sleep (100) ;														// Remove it if you have superman reflexes
//			/*system ("cls") ;*/
//		}
//		else
//		{
//			direction = _getch() ;
//		}
//	}
//}