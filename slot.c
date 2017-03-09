#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_PLAYER -1

struct slots {
	int type;
	int player;
};

int main(void)
{	
	srand(time(NULL));
	//Declaring variables
	int numSlots =0, count =0, type =0, slot =0;
	int number_players =6, player =0;
	
	printf("Select a number of slots: ");
	scanf("%d", &numSlots);
	struct slots arrSlots[numSlots];
	if(numSlots>20){
		printf("Please enter a number less than 20");
	}
	else {
		//Assigning random integers for each type of Slot
		for(count=0;count<numSlots;count++) {
			type = rand()%3;
			arrSlots[count].type = type;
			arrSlots[count].player = NO_PLAYER;
		}
		
		for(int i = 0; i < numSlots; i++)  {
			printf("%d \n", arrSlots[i].type);
		}
		//Assigning each player to a Slot randomly
		for(count=0;count<number_players;count++) {
			slot = rand()% numSlots;
			printf("slot %d player %d\n", slot, count);
			
			while(arrSlots[slot].player != NO_PLAYER) {
				slot = rand()% numSlots;
			}
			arrSlots[slot].player = count;
		}
		for(int i = 0; i < numSlots; i++)  {
			printf("type%d player%d\n", arrSlots[i].type, arrSlots[i].player);
		}
	}
	return 0;
}
