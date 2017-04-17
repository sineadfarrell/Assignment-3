/* Assignmnet 3 Software Engineering project */
#include "crossfireOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct slots {
	int type;
};
//prototype
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);
int main(void)
{	srand(time(NULL));
//decaring variables
int number_players, i, j=0;
int elf_count=0,human_count=0,wizard_count=0, ogre_count=0; //initialising count
char type[20], player_name[20];
//decaring const chars to be compared with what the user inputs
const char type_elf[] = "elf";
const char type_human[] = "human";
const char type_ogre[] = "ogre";
const char type_wizard[] = "wizard";
const char type_level[] = "Level Ground";
const char type_hill[] = "Hill";
const char type_city[] = "City";

//structs for each player type 
//to contain the players name and set of capabilities
struct PLAYER_TYPE{
	char name_player[10];
	char type_player[10];
	char slot_name[10];
	int  smartness;
	int  strength;
	int  magic_skills;
	int  luck;
	int  dexterity; 
	int  life_points;
	int  board[7][7];
	int row;
	int column;
} ;
//created an aray of type struct to ensure that each player is placed in a different place in 
struct PLAYER_TYPE players[6];
struct slots location[7][7];
//getting user to enter number of players
printf("Enter number of players (between 2 and 6)\n");
scanf("%d", &number_players);
// getting program to recognise the conditions regarding the number of players 
if(number_players == 0 || number_players == 1){
	printf("insufficient number of players entered");
	exit(1);
}
if(number_players > 6){
	printf("Too many players entered");
	exit(1);
}
else { 
//when condition is correct the program asks user to input the player types
printf("enter player types\n");
for(i =0; i<=number_players; i++){	
	players[i];
	fgets(players[i].type_player, 20,stdin); //scans in the users input
	

	
	//when user inputs an elf 
 if(players[i].type_player[i] == type_elf[i]){
	elf_count++;
	printf("Enter the name of the elf\n");
	fgets(players[i].name_player, 20, stdin); //scaning in the name of the elves
	//printf("the elf's name is:\n");
	//printf("%s", elf.name_player);
	
	//taking into account the elves capabilities
	players[i].smartness = 70 + rand() %(100 - 70);
	players[i].strength = rand() %51;
	players[i].magic_skills = 50 + rand() %(80 - 50); 
	players[i].luck = 60 + rand() %(100 -60);
	players[i].dexterity = rand() %100 + 1; 
	players[i].life_points = 100;
	
	//printing the capabilities
	printf("elf smartness %d \n", players[i].smartness);
	printf("elf strength %d \n", players[i].strength);
	printf("elf magic_skills %d \n", players[i].magic_skills);
	printf("elf luck %d \n", players[i].luck);
	printf("elf dexterity %d \n", players[i].dexterity);
	printf("elf life points %d \n", players[i].life_points);
	 
 }	//when user inputs a human
else if(players[i].type_player[i] == type_human[i]){
	
	printf("Enter the name of the human\n");
	fgets(players[i].name_player, 20, stdin); //scans in  name of humans
	//printf("the human's name is:\n");
	//printf("%s", human.name_player);
	
	//human's capabilities
	players[i].smartness = rand() %100 +1;
	players[i].strength = rand() %100 +1;
	players[i].magic_skills = rand() %100 +1;
	players[i].luck = rand() %100 +1;
	players[i].dexterity = rand() %100 +1;
	players[i].smartness+players[i].strength+players[i].magic_skills+players[i].luck+players[i].dexterity<300;
	players[i].life_points = 100;
	
	//printing the capabilities of humans
	printf("human smartness %d \n", players[i].smartness);
	printf("human strength %d \n", players[i].strength);
	printf("human magic_skills %d \n", players[i].magic_skills);
	printf("human luck %d \n", players[i].luck);
	printf("human dexterity %d \n", players[i].dexterity);
	printf("human life poins %d \n", players[i].life_points);
}
else if(players[i].type_player[i] == type_ogre[i]){
	ogre_count++;
	printf("Enter the name of the ogre\n");
	fgets(players[i].name_player, 20, stdin);
	//printf("the ogre's name is:\n");
	//printf("%s", ogre.name_player);
	
	players[i].smartness = rand() %21;
	players[i].strength = 80 + rand() %(101-80) ;
	players[i].magic_skills = 0;
	players[i].luck = rand()%100;
	players[i].dexterity = 80 + rand() %(101 -80) ;
	players[i].luck + players[i].smartness <= 50;
	players[i].life_points = 100;
	
	
	printf("ogre smartness %d \n", players[i].smartness);
	printf("ogre strength %d \n", players[i].strength);
	printf("ogre magic_skills %d \n", players[i].magic_skills);
	printf("ogre luck %d \n", players[i].luck);
	printf("ogre dexterity %d \n", players[i].dexterity);
	printf("ogre life points %d \n", players[i].life_points);
} 
else if(players[i].type_player[i]== type_wizard[i]){
	wizard_count++;
	printf("Enter the name of the wizard\n");
	fgets(players[i].name_player, 20, stdin);
	//printf("the wizard's name is:\n");
	//printf("%s", wizard.name_player);
	
	players[i].smartness = 90 + rand() %(101 -90) ;
	players[i].strength = rand() %21 ;
	players[i].magic_skills = 80 + rand() %(100 -80);
	players[i].luck = 50 + rand() %(101 -50);
	players[i].dexterity = rand() %101;
	players[i].life_points = 100;
	
	
	printf("wizard smartness %d \n", players[i].smartness);
	printf("wizard strength %d \n", players[i].strength);
	printf("wizard magic_skills %d \n", players[i].magic_skills);
	printf("wizard luck %d \n", players[i].luck);
	printf("wizard dexterity %d \n", players[i].dexterity);
	printf("wizard life points %d \n", players[i].life_points);
}
}
}
/*
		*********  Creating 7 x 7 board of slots  **************
*/

int boardSize =7;
struct slot ** board = malloc(boardSize * sizeof(struct slot *));

//assigns a pointer to slot at position (0, 0)
struct slot *upLeft, *upRight, *downLeft, *downRight;
	
createBoard(boardSize, &upLeft, &upRight, &downLeft, &downRight);

 
/* when players have life points <=0 they must exit the game */

for(i =0; i<=number_players; i++){
	if(players[i].life_points <= 0){
		//remove player from the game
		players[i].name_player[10]=='\0';
		players[i].type_player[10]=='\0';
		players[i].smartness==0;
		players[i].strength==0;
		players[i].magic_skills==0;
		players[i].luck==0;
		players[i].dexterity==0; 
		//players[i].life_points==NULL;
		players[i].board[-1][-1];
	}
}
int r,c, slot_type;
/* Each slot should then be assigned  Level ground, hill or city */
 for(r=0; r<7; r++){
	 for(c=0; c<7; c++){
		 location[r][c].type = rand () %3;
		if(location[r][c].type==0){
			printf("Slot (%d, %d) is Level ground\n", r,c);
		}
		if(location[r][c].type==1){
			printf("Slot (%d, %d) is Hill\n", r,c);
		}
		if(location[r][c].type == 2){
			printf("Slot (%d, %d) is City\n", r,c);
		}
		
	 }
 }
/*Assigning each player to a slot */
//assigning random slot to player 
	for(i=0; i<number_players; i++){
	
		players[i].row = rand () %7;
		players[i].column = rand () %7;
		printf("Player %s in location(%d,%d) of type %d\n", players[i+1].name_player, players[i].row, players[i].column, location[players[i].row][players[i].column].type );
	}	
 int round;
 	//while the game continues rounds are played
	while(number_players >= 2){ 
	for(i=0; i < number_players; i++){
		
		printf("Do you(%s) want to move to ajacant slot(1), attack(2) or quit game(3)\n", players[i+1].name_player);
		scanf("%d", &round);
	
	if(round==1){
		//move ajacant slotint movement;
		int movement;
		printf("Do you want to move up(1), down(2), right(3) or left(4)\n");
		scanf("%d", &movement);
		
		//move up
		if(movement == 1){
		
			players[i].board[r-1][c];
			players[i].row -= 1;
		}
		//move down
		if(movement == 2){
			
			players[i].board[r+1][c];
			players[i].row += 1;
		}
		//move right
		if(movement == 3){
			
			players[i].board[r][c-1];
			players[i].column += 1;
		}
		//move left
		if(movement ==4){
			
			players[i].board[r][c+1];
			players[i].column -= 1;
		}
		players[i].board[players[i].row][players[i].column];
		printf("new location of %s is (%d , %d)\n", players[i+1].name_player, players[i].row,players[i].column);
		
	}
	
		
		//capabilty change if moved to hill
		
	if( location[r][c].type ==1){
			
		if(players[i].dexterity < 50)
			players[i].strength = players[i].strength -10;
		if(players[i].dexterity >= 60)
			players[i].strength = players[i].strength + 10;
		}
		
		if( location[r][c].type  ==2){
		//capabilty change if moved to City
		if(players[i].smartness > 60)
			players[i].magic_skills = players[i].magic_skills +10;
		if(players[i].smartness <= 50)
			players[i].dexterity = players[i].dexterity - 10;
		}
	
	
	
	if(round == 2){
		//attack
		int attack_number;
for(i=0;i<number_players; i++){
printf("Choose an attack to perform\n 1. Near attack\n 2. Distant Attack\n 3. Magic Attack\n");
scanf("%d", &attack_number);	

/*Near attack */
if(attack_number == 1){
	
	
	
	//find ajacant slot
	//check if theres a player in the slots
	//find player
	//change capabilties 
	
	

}

if(attack_number == 2){
	//Distant Attack
	int distant_at;
	//getting player to choose player to attack
	printf("Choose a player to preform the attack on \n");
	scanf("%d", &distant_at);
	
	
}

if(attack_number == 3){
	//Magic attack
	int magic_at;
	//getting player to choose what attack it wants to preform
	printf("Choose a player to preform the attack on \n");
	scanf("%d", &magic_at);
	
	if(players[magic_at].smartness + players[magic_at].magic_skills > 150){
		players[magic_at].life_points -= ((0.5 * players[i].magic_skills) + (0.2 * players[i].smartness)); 
	}
}	
}
		
	}
	if(round == 3){
		players[i].name_player[10]=='\0';
		players[i].type_player[10]=='\0';
		players[i].smartness==0;
		players[i].strength==0;
		players[i].magic_skills==0;
		players[i].luck==0;
		players[i].dexterity==0; 
		//players[i].life_points==NULL;
		players[i].board[-1][-1];
		number_players--; //decrementing number of players 
		}
	}
}
	if(number_players < 2){
		printf("GAME OVER");
		exit(0);
	}


 
return 0;
}

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight){
	
	
	
	//The board is represented as a pointer of pointer to slots
	//This allocates in memory the space for the pointers to each row of the board
	struct slot ** board = malloc(boardSize * sizeof(struct slot *));

	//assigns a pointer to slot at position (0, 0)
	*upLeft = &board[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	*upRight = &board[0][boardSize -1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	*downLeft = &board[boardSize -1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	*downRight = &board[boardSize -1][boardSize -1];



	for(int i =0; i< boardSize; i++){
		//This allocates in memory the space for the slots in each row of the board
		board[i] = malloc(boardSize * sizeof(struct slot));

		//For each slot it sets up the row and column number
		for(int j=0;j < boardSize; j++){
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	//It sets up the adjacent slots for the slots that are
	//not at the borders. These slots have 4 adjacent elements
	for(int i =1; i< boardSize-1; i++){
		for(int j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last row, except the slots at the edges.
	//
	for(int j = 1; j < boardSize -1; j++){
		//It sets up the adjacent slots for the slots that are in the first row.
		//These slots don't have an adjacent element on top of them
		// because they are on the first row of the board
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];

		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on down them
		// because they are on the last row of the board
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last column, except the slots at the edges.
	//
	for(int i = 1; i < boardSize -1; i++){
		//It sets up the adjacent slots for the slots that are in the first column.
		//These slots don't have an adjacent element on the left
		// because they are on the first column of the board
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];

		//It sets up the adjacent slots for the slots that are in the last column.
		//These slots don't have an adjacent element on the right
		// because they are on the last column of the board
		board[i][boardSize-1].left = &board[i][boardSize-2];
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
	}


	//It sets up the adjacent slots for the slot at position (0,0).
	//This only has only 2 adjacent slots: right and down
	board[0][0].right = &board[0][1];
	board[0][0].down = &board[1][0];

	//It sets up the adjacent slots for the slot at position (0,boardSize -1).
	//This only has only 2 adjacent slots: left and down
	board[0][boardSize-1].left = &board[0][boardSize-2];
	board[0][boardSize -1].down = &board[1][boardSize -1];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,0).
	//This only has only 2 adjacent slots: up and right
	board[boardSize -1][0].right = &board[boardSize -1][1];
	board[boardSize -1][0].up = &board[boardSize -2][0];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1).
	//This only has only 2 adjacent slots: up and left
	board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
	board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];





	//assigns a pointer to slot at position (0, 0)
	*upLeft = &board[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	*upRight = &board[0][boardSize -1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	*downLeft = &board[boardSize -1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	*downRight = &board[boardSize -1][boardSize -1];
	int i, j;
	printf("\n7 x 7 Board created\n");
	
			
		}
	
	
