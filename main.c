#include "functions.h"


int main(void)
{
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	menu();
	int card_num = 0;
	shuffle(deck);
	
	Card p1_hand[5] = {{0,0,0}};
	Card p2_hand[5] = {{0,0,0}};
	deal(deck, face, suit, p1_hand,5,&card_num,-5);
	deal(deck, face, suit, p2_hand, 5, &card_num,-5);
	sort_hand(p1_hand);
	sort_hand(p2_hand);
	print_hand(p1_hand, face, suit);
	//print_hand(p2_hand, face, suit);
	combos(is_pair(p1_hand), is_two_pair(p1_hand), is_three_of_a_kind(p1_hand), is_four_of_a_kind(p1_hand), is_flush(p1_hand), is_straight(p1_hand));
	int replace = 0, cards_changes = 0;
	printf("do you want to replace any of the cards ? (press 1) \n");
	scanf("%d", &replace);
	if (replace == 1)
	{
		int option = 0, option2 = 0;
		do
		{
			cards_changes++;
			//do {
			printf("which card do you want to replace \n");
			print_hand(p1_hand, face, suit);
			scanf("%d", &option);
			//} while (option <= 1 || option >= 5);
			deal(deck, face, suit, p1_hand, 1, &card_num, option - 1);
			print_hand(p1_hand, face, suit);
			printf("do you want to proceed with you current cards (press 1) \n");
			scanf("%d", &option2);
			if (option2 == 1)
			
				break;
			
		} while (cards_changes < 4);
		

	}
	int computer_tries = 0;
	//computer is dumb and just replaces 3 cards 
	do {
		deal(deck, face, suit, p2_hand, 1, &card_num, rand()%5);
		computer_tries++;
	} while ( computer_tries < 4); //is_four_of_a_kind(p2_hand) == 0 || is_flush(p2_hand) == 0 || is_straight(p2_hand) == 0 ||

	printf("The computer's hand has been generated\n");

	int p1 = 0, p2 = 0;

	p1 = check_hand(is_pair(p1_hand), is_two_pair(p1_hand), is_three_of_a_kind(p1_hand), is_four_of_a_kind(p1_hand), is_flush(p1_hand), is_straight(p1_hand));
	p2 = check_hand(is_pair(p2_hand), is_two_pair(p2_hand), is_three_of_a_kind(p2_hand), is_four_of_a_kind(p2_hand), is_flush(p2_hand), is_straight(p2_hand));

	print_hand(p1_hand, face, suit);
    print_hand(p2_hand, face, suit);
	decide_winner(p1, p2);
	int again = 0;
	printf("Do you want to play again ?\n");
	scanf("%d", &again);
	if (again == 1)
	{
		return main();
	}
	return 0;
}
