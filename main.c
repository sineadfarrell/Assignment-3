#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_PLAYER -1

struct slots {
	int type1;
	int player;
};

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
	char name_player[20];
	char type_player[20];
	char slot_name[20];
	int  smartness;
	int  strength;
	int  magic_skills;
	int  luck;
	int  dexterity; 
	int  life_points;
	int  slot_location;
} ;
//created an aray of type struct to ensure that each player is placed in a different place in 
struct PLAYER_TYPE players[6];

//getting user to enter number of players
printf("Enter number of players (between 2 and 6)\n");
scanf("%d", &number_players);
// getting program to recognise the conditions regarding the number of players 
if(number_players == 0 || number_players == 1){
	printf("insufficient number of players entered");
}
if(number_players > 6){
	printf("Too many players entered");
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
	srand(time(NULL));
	//Declaring variables
	int numSlots =0, count =0, type1 =0, slot =0;
	 int player =0;
	
	printf("Select a number of slots: ");
	scanf("%d", &numSlots);
	struct slots arrSlots[numSlots];
	if(numSlots>20){
		printf("Please enter a number less than 20");
	}
	else {
		//Assigning random integers for each type of Slot
		for(count=0;count<numSlots;count++) {
			type1 = rand()%3;
			arrSlots[count].type1 = type1;
			arrSlots[count].player = NO_PLAYER;
		}
		
		
		for(int i = 0; i < numSlots; i++)  {
			//printf("%d \n", arrSlots[i].type1);
		}
		//Assigning each player to a Slot randomly
		for(count=1;count<number_players;count++) {
			for(i =1; i<=number_players; i++){
			players[i].slot_location = rand()% numSlots;
			printf("slot %d player %s\n", players[i].slot_location, players[i].name_player);
			
			while(arrSlots[players[i].slot_location].player != NO_PLAYER) {
				players[i].slot_location = rand()% numSlots;
			}
			arrSlots[players[i].slot_location].player = count;
		}
		for(int i = 1; i < numSlots; i++)  {
			//printf("type%d player%d\n", arrSlots[i].type1, arrSlots[i].player);
		}
	}
	}
	
	
	
	/*
	// at the end 
	for(i =1; i<=number_players; i++){
		printf("%s(%s  %d)\n", players[i].name_player, players[i].type_player, players[i].life_points);
	}*/
	return 0;
}
