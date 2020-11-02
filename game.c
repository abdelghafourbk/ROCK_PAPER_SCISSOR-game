#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0



//compare the choices
int rock_paper_scissor(int player1 , int  player2){
	int result;
	if(player1 == ROCK && player2 == PAPER){
		result = PLAYER2_WIN;
	}
	else if(player1 == PAPER && player2 == ROCK){
		result = PLAYER1_WIN;
	}
	else if(player1 == ROCK && player2 == SCISSOR){
		result = PLAYER1_WIN;
	}
	else if(player1 == SCISSOR && player2 == ROCK){
		result = PLAYER2_WIN;
	}
	else if(player1 == PAPER && player2 == SCISSOR){
		result = PLAYER2_WIN; 
	}
	else if(player1 == SCISSOR && player2 == PAPER){
		result = PLAYER1_WIN;
	}
	else{
	 result = DRAW;
    }
    return result;
}


// scan the input of the user
int read_input_user(){
	int choice ;

	do{
		printf("u have three choices , can u pick one! \n");
		printf("1 ==> ROCK \n");
		printf("2 ==> PAPER \n");
		printf("3 ==> SCISSOR \n");
		printf("choose between (1,2,3) :\n");
		scanf("%d",&choice);
		if (choice <1 || choice>3){
		printf(" --ERROR-- , pick from the numbers above plz\n");
		printf("-------------\n\n");
		}
	}while(choice < 1 || choice >3); 
	return choice;
}

void print_choice(int v){
	if (v == ROCK){
		printf(" rock \n");
	}
	else if (v == PAPER){
		printf("paper \n");
	}
	else if (v == SCISSOR){
		printf("scissor \n");
	}
} 

int main() {
	
	int user_score=0 , computer_score=0 ,response,i;
	int result;
	srand(time(NULL));
	int quit = 0;
	int computer_choice;
	int user_input;
	
	//just a boring design
	printf("\t\t\t\t\t\t");
	for(i=0;i<65;i++){
			printf("*");
		}
			printf("*\n");
	printf("\t\t\t\t\t\t\tHELLO BRO,DO NOT VOTE FOR TEBBONE CONSTITUTION ty\n");
	printf("\t\t\t\t\t\t");
	for(i=0;i<65;i++){
			printf("*");
		}
		printf("*\n");
	//finish the boring design
	
	while(!quit){
		
		user_input=read_input_user();
		computer_choice= (rand() % 3) + 1; 
		printf("the computer choose :\t");
		print_choice(computer_choice);
		printf("user choose: \t");
		print_choice(user_input);
		
		result= rock_paper_scissor(user_input,computer_choice);
		if (result == DRAW){
			printf("It,s draw\n");
			
		}else if(result == PLAYER1_WIN){
			printf("You win this round and the computer lose it\n");
			user_score ++;
			
		}else if(result == PLAYER2_WIN){
			printf(" Computer win this round and you lose it\n");
			computer_score ++;
		}		
		
		printf("\n");
		printf("--------------------------------------\n");
		printf("user score : %d\n",user_score);
		printf("computer score : %d\n",computer_score);
		printf("--------------------------------------\n");
		printf("\n");
	
		printf("If u want to stop the game press 0 ,if not choose any number\n");
		scanf("%d",&response);
		if (response == 0){
		 quit=1;
		}
		
	}//the end 
	printf("THE FINAL SCORE :\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("user score : %d\n",user_score);
	printf("computer score : %d\n",computer_score);
	printf("--------------------------------------\n");
	printf("\n");
	if (computer_score > user_score){
		printf("\t\t\t\t\t\t :( GAME OVER !!\n");
	}else if( computer_score < user_score){
		printf("\t\t\t\t\t\t  :)  YOU WIN !!\n");
	}else if(computer_score == user_score){
		printf("\t\t\t\t\t\t	 DRAW !!\n ");
	}
	printf("\n");
	printf("THANK U FOR PLAYING!!");
	return 0;
}



