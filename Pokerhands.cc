#include <iostream>

using namespace std;

int main ()
{

//declare
	int	card1, card2, card3, card4, card5, //ranks
			rank1, rank2, rank3, rank4, rank5; //rankues of cards


// Ask for input
	cout	<< "Enter the cards in rank order (Between 0 and 51). "
		      "Seperate by a space. : ";
	cin >> card1 >> card2 >> card3 >> card4 >> card5;

// calculate rank
	rank1 = card1 % 13;
	rank2 = card2 % 13;
	rank3 = card3 % 13;
	rank4 = card4 % 13;
	rank5 = card5 % 13;

// Check that input is legal
	if (card1 < 0 || card5 > 51 || rank1 > rank2 || rank2 > rank3 ||
		rank3 > rank4 || rank4 > rank5)
		{
		cout <<"Error: Cards out of order or out of range." << endl;
		return 1;
		}


// determine hand
//royal flush: card1 % 13 = 8 and card1+1=card2 etc

	if (card1 % 13 == 8 && card1+1 == card2 && card2+1 == card3 &&
	card3+1 == card4 && card4+1 == card5)
		cout << "Royal flush" << endl;

//straight flush: card1+1 = card 2 etc, and rank1 <8

	else if (card1+1 == card2 && card2+1 == card3 &&
	card3+1 == card4 && card4+1 == card5 && rank1 < 8)
		cout << "Straight flush" << endl;

//four of a kind: r1==r4 or r2==r5

	else if (rank1 == rank4 || rank2 == rank5)
		cout << "Four of a kind" << endl;

//full house: (r1==r3 and r4==r5) OR (r1==2 and r3==r5)

	else if ((rank1 == rank3 && rank4 == rank5) || (rank1 == rank2 && rank3 == rank5))
		cout << "Full house" << endl;

//flush : all c/13 are equivalent

  	else if ((card1/13)==(card2/13) && (card2/13)==(card3/13) &&
  (card3/13)==(card4/13) && (card4/13)==(card5/13))
    cout << "Flush" << endl;

//straight: r1+1==r2 etc

  	else if ((rank1+1)==rank2 && (rank2+1)==rank3 && (rank3+1)==rank4 &&
  (rank4+1)==rank5)
    cout << "Straight" << endl;

//three of a kind: r1==r3 or r2==r4 or r3 == r5

  	else if ((rank1 == rank3) || (rank2 == rank4) || (rank3 == rank5))
    cout << "Three of a kind" <<endl;

//two pair: (r1==r2 AND r3==r4) OR (r1==r2 AND r4==r5) OR (r2==r3 AND r4==r5)

	else if ((rank1 == rank2 && rank3 == rank4)||
          (rank1 == rank2 && rank4 == rank5)||
          (rank2 == rank3 && rank4 == rank5))
      cout << "two pair" << endl;

//one pair:r1==r2 OR r2==r3 etc

  	else if (rank1 == rank2 || rank2 == rank3 || rank2 == rank4 || rank4 == rank5)
    cout << "one pair" << endl;

// highcard: else
    else
      cout << "Highcard" << endl;

return 0;
}
