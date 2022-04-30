#include "functions.h"


//shows the main menu
void menu(void)
{
	int option = 0;
	do {
		printf("1. Game Rules\n");
		printf("2. Play the game\n");
		printf("3. Exit Game\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1: print_rules();
			break;
		case 2: ;
			break;
		case 3: system("pause");
			break;
		
		}
	} while (option > 3 && option < 1);
}

void print_rules(void)
{
	printf("Poker is played from a standard pack of 52 cards\n");
	printf("The cards are ranked (from high to low) Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2, Ace\n");
	printf("(Ace can be high or low, but is usually high)\n");
	printf("There are four suits (spades, hearts, diamonds and clubs)\n");
	printf(" however, no suit is higher than another\n");
	printf("All poker hands contain five cards\n");
	printf("the highest hand wins\n");
	return menu();
}

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[],Card hand[],int num_draw, int *card_num,int specific_deal)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int count = 0; //count number

	if (specific_deal != -5)
	{
		count = specific_deal;

}

//	/* deal each of the 52 cards */
//	for (card = 1; card <= 52; card++)
//	{
//		/* loop through rows of wDeck */
//		for (row = 0; row <= 3; row++)
//		{
//			/* loop through columns of wDeck for current row */
//			for (column = 0; column <= 12; column++)
//			{
//				/* if slot contains current card, display card */
//				if (wDeck[row][column] == card)
//				{
//					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
//				}
//			}
//		}
//	}
//}
	for (card = *card_num; card <= num_draw + *card_num - 1; card++) {  //deals each of the 52 cards
		for (row = 0; row <= 3; row++) { // loop through rows of wDeck
			for (column = 0; column <= 12; column++) {
				if (wDeck[row][column] == card) {

					hand[count].suitIndex = row;
					hand[count].face_valueIndex = column;
					hand[count].card_num = card;
					++count;
					
				}
			}
		}
	}
	*card_num += num_draw;
}
//checks if there is a single pair
int is_pair(Card hand[]) { 

	int num = 0,pair = 0;
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand[i].face_valueIndex == hand[j].face_valueIndex)
				num++;
		}
	}
	if (num >= 1)
		pair = 1;
	return pair;
}

// checks if there are two pairs
int is_two_pair(Card hand[]) { 

	int num = 0, two_pair = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand[i].face_valueIndex == hand[j].face_valueIndex)
				num++;
		}
	}
	if (num >= 2)
		two_pair = 1;
	return two_pair;
}

//checks if there are 3 of a kind
int is_three_of_a_kind(Card hand[]) { 
	int three_kind = 0;
	if (hand[0].face_valueIndex == hand[1].face_valueIndex && hand[1].face_valueIndex == hand[2].face_valueIndex)
		three_kind = 1;
	if (hand[1].face_valueIndex == hand[2].face_valueIndex && hand[2].face_valueIndex == hand[3].face_valueIndex)
		three_kind = 1;
	if (hand[2].face_valueIndex == hand[3].face_valueIndex && hand[3].face_valueIndex == hand[4].face_valueIndex)
		three_kind = 1;
	return three_kind;
}

//checks if there are 4 of a kind
int is_four_of_a_kind(Card hand[]) { 
	int four_kind = 0;
	if (hand[0].face_valueIndex == hand[1].face_valueIndex && hand[1].face_valueIndex == hand[2].face_valueIndex &&
		hand[2].face_valueIndex == hand[3].face_valueIndex)
		four_kind = 1;
	if (hand[1].face_valueIndex == hand[2].face_valueIndex && hand[2].face_valueIndex == hand[3].face_valueIndex &&
		hand[3].face_valueIndex == hand[4].face_valueIndex)
		four_kind = 1;
	return four_kind;
}
//checks for a flush
int is_flush(Card hand[]) { 
	int i = 0, flush = 0;
	for (i = 0; i < 4; i++) {
		if (hand[i].suitIndex != hand[i + 1].suitIndex)
			flush = 1 ;
	}
	return flush;
}
//checks for a straight 
int is_straight(Card hand[]) { 
	int straight = 0;
	for (int i = 4; i > 0; i--) {
		if (hand[i - 1].face_valueIndex != hand[i].face_valueIndex - 1)
			straight = 1;
	}
	return straight;
}
//sorting the hand
void sort_hand(Card hand[]) { 
	int i, j;
	int temp;

	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (hand[i].face_valueIndex > hand[j].face_valueIndex) {
				temp = hand[i].face_valueIndex;
				hand[i].face_valueIndex = hand[j].face_valueIndex;
				hand[j].face_valueIndex = temp;
			}
		}
	}
}
//prints the hand
void print_hand(Card hand[], const char* wFace[], const char* wSuit[]) {
	int i;
	printf("This is your hand\n");
	for (i = 0; i < 5; i++) {
		printf("%d %s of %s\n", (i + 1), wFace[hand[i].face_valueIndex], wSuit[hand[i].suitIndex]);
	}
	printf("\n\n");
}
//shows your availble combos
void combos(int pair,int two_pair, int three_of_a_kind,int four_of_a_kind,int flush,int straight)
{
	printf("Here are your options: \n");

	if (pair == 1)
	{
		printf("1. You have a pair\n");
	}

	if (two_pair == 1)
	{
		printf("2. You have two pairs\n");
	}

	if (three_of_a_kind == 1)
	{
		printf("3. You have a three of a kind\n");
	}

	if (four_of_a_kind == 1)
	{
		printf("4. You have a four of a kind\n");
	}
	
	if (flush == 1)
	{
		printf("5. You have a flush\n");
	}

	if (straight == 1)
	{
		printf("6. You have a straight\n");
	}
		
}

int check_hand(int pair, int two_pair, int three_of_a_kind, int four_of_a_kind, int flush, int straight)
{
	if (straight&&flush == 1)
	{
		return 6;
	}
	else if (straight == 1)
	{
		return 5;
	}
	
	else if (four_of_a_kind == 1)
	{
		return 4;
	}
	

	else if (three_of_a_kind == 1)
	{
		return 3;
	}

	else if (two_pair == 1)
	{
		return 2;
	}
	else if (pair == 1)

	{
		return 1;
	}
	
}

void decide_winner(int p1, int p2)
{
	if (p1 > p2)
	{
		printf("Player 1 won\n");

	}
	else if (p2 > p1)
	{
		printf("The computer has won\n");
	}

	else if (p1 == p2)
	{
		printf("It's a tie \n");
	}
}