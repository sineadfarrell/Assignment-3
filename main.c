#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_PLAYER -1

struct slots {
	int type1;
	int player;
};

int main(void)
{
	srand(time(NULL));
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
		
		for(i =0; i<number_players; i++){	
			
    	    printf("enter player type %d\n", i);
			// fgets(players[i].type_player, 20,stdin); //scans in the users input
			scanf("%s", players[i].type_player); //scans in the users input
			printf("players[i].type_player %s\n", players[i].type_player);
			
			//when user inputs an elf 
			if(players[i].type_player[i] == type_elf[i]){
				elf_count++;
				printf("Enter the name of the elf\n");
				// fgets(players[i].name_player, 20, stdin); //scaning in the name of the elves
    			scanf("%s", players[i].name_player); //scans in the users input
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
    			scanf("%s", players[i].name_player); //scans in the users input
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
    			scanf("%s", players[i].name_player); //scans in the users input
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
    			scanf("%s", players[i].name_player); //scans in the users input
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
		
		for(i = 0; i < numSlots; i++)  {
			printf("%d \n", arrSlots[i].type1);
		}
    	printf("\n");
		
		//Assigning each player to a Slot randomly
		for(i = 0; i<number_players; i++){
			players[i].slot_location = rand()% numSlots;

			while(arrSlots[players[i].slot_location].player != NO_PLAYER) {
				players[i].slot_location = rand()% numSlots;
			}
			arrSlots[players[i].slot_location].player = i;
		}
		for(i = 0; i < numSlots; i++)  {
			printf("slot %d type %d player %d\n", i, arrSlots[i].type1, arrSlots[i].player);
		}
		for(i = 0; i < number_players;i++)	{
			printf("player %d name %s location %d\n", i, players[i].name_player, players[i].slot_location);
		}
		printf("\n");
	}
	int click, click2;
 
	for(i =0; i<number_players; i++){
	//getting user to pick movement or attack 
		printf("Player %d %s\n", i, players[i].name_player);
		printf("Enter 1 if you want to move %s\nEnter 2 if you want to attack another player\n", players[i].name_player);
		scanf("%d", &click);

		if(click == 1){
			//giving user the option to move forward or backwards
			printf("Click 1 if you want to move foward\nClick 2 if you want to move back\n");
			scanf("%d", &click2);
			if(click2 == 1){
				players[i].slot_location += 2; //adding 1 to the location didn't change the value 
			}
			if(click2 = 2){
				players[i].slot_location -=  1;
			}
			//1 = hill
			if(arrSlots[i].type1 == 1){
				//change of capabilities 
				if(players[i].dexterity < 50){
					players[i].strength = players[i].strength - 10;
					if(players[i].strength<0)	{
						players[i].strength = 0;
					}
				}
				if(players[i].dexterity >= 60){
					players[i].strength = players[i].strength + 10;
					if(players[i].strength>100)	{
						players[i].strength = 100;
					}
					
				}
			}	
			// 2 = city
			if(arrSlots[i].type1 == 2){
				//change of capabilities
				if(players[i].smartness > 60){
					players[i].magic_skills = players[i].magic_skills +10;
					if(players[i].magic_skills>100)	{
						players[i].magic_skills = 100;
					}
				}
				if(players[i].smartness <= 50){
					players[i].dexterity = players[i].dexterity - 10;
					if(players[i].dexterity<0)	{
						players[i].dexterity = 0;
					}
				}
			}
			printf("new location of %s %d\n",players[i].name_player, players[i].slot_location);
		}
		
		if(click == 2){
			
			printf("enter attack\n");
			// attack
			int attackedslot =0, attacked =0, choice =0, new =0;
			int attackerslot = players[i].slot_location;
			int j = attackerslot+1, k = attackerslot-1;

			printf("attacker %d slot %d \n", i, attackerslot);
			printf("attackedj %d slot %d \n", arrSlots[j].player, j);
			printf("attackedk %d slot %d \n", arrSlots[k].player, k);

			while(arrSlots[k].player == NO_PLAYER && arrSlots[j].player == NO_PLAYER)	{
				printf("attackedj %d slot %d \n", arrSlots[j].player, j);
				printf("attackedk %d slot %d \n", arrSlots[k].player, k);
				printf("players %d %d \n", arrSlots[k].player, arrSlots[j].player);
				k++; j++;
			}
			if(arrSlots[k].player = NO_PLAYER)	{
				// attack slot j
				attackedslot = j;
			}
			else if(arrSlots[j].player = NO_PLAYER)	{
				// attack slot k
				attackedslot = k;	
			}
			else {
				// give player choice of slot
				printf("Enter 1 for %s or 2 for %s", arrSlots[k].player, arrSlots[j].player);
				scanf("%d", &choice);
				if(choice == 1)	{
					attackedslot = k;
				}
				else	{
					attackedslot = j;
				}
			}
			printf("attack");
			attacked = arrSlots[attackedslot].player;
			
			if(players[attacked].strength<=70)	{
				new = players[attacked].life_points - 0.5*players[attacked].strength;
				players[attacked].life_points = new;
				printf("Your life points are now %d\n", players[attacked].life_points);
			}
			if(players[attacked].strength>70)	{
				new = players[i].life_points - 0.3*players[attacked].strength;
				players[i].life_points = new;
				printf("Your life points are now %d\n", players[i].life_points);
			}
		}
		printf("last line of for loop\n");
	}
	
	// at the end 
	for(i =0; i<number_players; i++){
		printf("%s(%s  %d)\n", players[i].name_player, players[i].type_player, players[i].life_points);
	}
	return 0;
}
