#include <iostream>

using namespace std;

int main (void)
{

//declare
	int	card1, card2, card3, card4, card5, //ranks
			val1, val2, val3, val4, val5; //values of cards


// Ask for input
	cout	<< "Enter the cards rank in order (Between 0 and 51). "
		      "Seperate by a space. : ";
	cin >> card1 >> card2 >> card3 >> card4 >> card5;

// calculate value
	val1 = card1 % 13;
	val2 = card2 % 13;
	val3 = card3 % 13;
	val4 = card4 % 13;
	val5 = card5 % 13;

// Check that input is legal
	if (card1 < 0 || card5 > 51 || card1 >= card2 || card2 >= card3 ||
		card3 >= card4 || card4 >= card5)
		{
		cout <<"Error: Cards out of order or out of range." << endl;
		return 1;
		}


// determine hand
//royal flush = card1 % 13 = 8 and card1+1=card2 etc

	if (card1 % 13 == 8 && card1+1 == card2 && card2+1 == card3 &&
	card3+1 == card4 && card4+1 == card5)
		cout << "Royal flush" << endl;

//straight flush = card1+1 = card 2 etc, and val1 <8

	else if (card1+1 == card2 && card2+1 == card3 &&
	card3+1 == card4 && card4+1 == card5 && val1 < 8)
		cout << "Straight flush" << endl;

//four of a kind = c1=c2=c3=c4 OR c2=c3=c4=c5

	else if (val1 == val4 || val2 == val5)
		cout << "Four of a kind" << endl;

//full house = (v1=v3 AND v4=v5) OR (v1=v2 AND v3=v5)

	else if ((val1 == val3 && val4 == val5) || (val1 == val2 && val3 == val5))
		 cout << "Full house" << endl;

//flush = All c_n/13 are equal
	
	else if	((card1/13) == (card2/13) && (card2/13) == (card3/13) && (card3/13) == (card4/13) && (card4/13) == (card5/13))
		cout << "Flush" << endl;
		 
//straight = (val1+4 = val5)

	else if (val1+4 == val5)
		 cout << "Straight" << endl;
		 
//three of a kind = (val1 = val3 OR val2=val4 OR val3=val5)
	
	else if (val1 == val3 || val2 == val4 || val3 == val5)
		 cout << "Three of a kind" << endl;
		 
//two pair = (val1=val2 AND val3=val4) OR (val2=val3 AND val4=val5) OR (val1=val2 AND val4=val5)
		
	else if ((val1 == val2 && val3 == val4) || (val2 == val3 && val4 == val5) || (val1 == val2 && val4 == val5))
		cout << "Two pair" << endl;
		 
//one pair = v1 == v2 OR v2 == v3 OR v3 == v4 OR v4 == v5
	
	else if (val1 == val2 || val2 == val3 || val3 == val4 || val4 == val5)
		cout << "One pair" << endl;
	
	else
		 cout << "No significant combination" << endl;

return 0;
}
