void maze1()
{
	
	for (int i=0;i<25;i++)
	{
		for (int j=0; j<79; j++)
		{
			if (i==0 || j == 0 || i == 24 || j == 78)
			{
				cout << char (178) ;
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;

	}
	
}

void maze2()
{
	
	for (int i=0;i<25;i++)
	{
		for (int j=0; j<79; j++)
		{
			
			if (i==0 || j == 0 || i == 24 || j == 78 || ((j > 10 && j < 70)&&(i==6 || i == 16)))
			{
				cout << char (178) ;
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	
}
void maze3()
{
	
	for (int i=0;i<25;i++)
	{
		for (int j=0; j<79; j++)
		{
			
			if (((j >= 9 && j <= 69)&&( i==6 || i == 16 ))  ||  ((( j>=0 && j<=8 ) || ( j<=78 && j>=70 )) && ( i==0 || i==24 )) || (( ( i>=0 && i<=6) || ( i>=18 && i<=24 ) ) && ( j==0 || j == 78 )))
			{
				cout << char (178);
			}
			else
			{
				cout << " ";
			}
		}
		    cout << endl;	
	}
}
void maze4()
{
	for (int i=0;i<25;i++)
	{
		for (int j=0; j<79; j++)
		{
			if (( ( i == 7 ) && ( j >= 0 && j <= 20 ) ) || ( i == 19 ) && ( j >= 0 && j <= 20 ) || ( ( i == 13 ) && ( j >= 50 && j < 80 ) ) || ( ( j == 49 ) && ( i >= 7 && i <= 19 ) ) && ( i !=0 ) )
			{
				cout << char (178);
			}
			else
			{
				cout << " ";
			}
		}
		    cout << endl;	
	}
}