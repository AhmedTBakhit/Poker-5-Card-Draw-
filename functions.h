#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
	int face_valueIndex;
	int suitIndex;
	int card_num;
}Card;

typedef struct {
	int cards[5];
}Hand;

void menu(void);
void print_rules(void);

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[], int num_draw, int* card_num, int specific_deal);
int is_pair(Card hand[]);
int is_two_pair(Card hand[]);
int is_three_of_a_kind(Card hand[]);
int is_four_of_a_kind(Card hand[]);
int is_flush(Card hand[]);
int is_straight(Card hand[]);
void sort_hand(Card hand[]);
void print_hand(Card hand[], const char* wFace[], const char* wSuit[]);
void combos(int pair, int two_pair, int three_of_a_kind, int four_of_a_kind, int flush, int straight);
int check_hand(int pair, int two_pair, int three_of_a_kind, int four_of_a_kind, int flush, int straight);
void decide_winner(int p1, int p2);
#endif