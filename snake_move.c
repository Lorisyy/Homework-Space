#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define snakeMaxLen 20
#define minlen 5
#define snakeHead 'H'
#define snakeBody 'X'
#define food '$'
#define wall '*'
#define blank ' '
#define len 5
int snakeX[len] = {1,2,3,4,5};
int snakeY[len] = {1,1,1,1,1};
//If the length is changable, every time food is gotten ,len++;

char map[12][12]={
"************",
"*XXXXH     *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"************"
}
void move(int snakeX[],int snakeY[],int direction,int currentDrt,int invalid){
	int oppositeDrt ;
	switch (currentDrt){
	/*If the direction is opposite to the current direction,
	this is a invalid input*/ 
		case 'A':oppositeDrt = 'D';break;
		case 'D':oppositeDrt = 'A';break;
		case 'S':oppositeDrt = 'W';break;
		case 'W':oppositeDrt = 'S';break;
	}
	if (direction == oppositeDrt){
		printf("Invalid input!\tError!\n");
		invalid = 1;
	}
	else{
	
		currentDrt = direction;//change the direction
		for (int i = 0;i < len-1  ; i++){
		snakeX[i] = snakeX[i+1];
		snakeY[i] = snakeY[i+1];
		}//Change their coordinate position.
		switch (direction){
			case 'W':snakeY[4]++;break;
			case 'A':snakeX[4]--;break;
			case 'S':snakeY[4]--;break;
			case 'D':snakeX[4]++;break;
			 
		}
	}
}
void positionOFsnake(int snakeX[],int snakeY[],char map[][]){
	for(int  y = 0; y < 12 ; y++){
		for(int x = 0;x < 12; x++){
			for(int i = 0;i<len-1;i++){
			
			/*if (x==0||y==0||y==11)
				printf("*");
			if (x==11)
				printf("*\n");*/
			//Search for snake's body and print it.
			if (snakeX[i] == x && snakeY[i] == y)
				 map[x][y] = 'X';
			}
		}
	}
}

int main(){
	int GG = 1;
	int currentDrt = 'D';
	while (GG!=0){
		int invalid = 0;
		char command;
		printf("Input your command!Player!\n");
		scanf("%c",&command);
		int direction = command;
		move(snakeX,snakeY,direction,currentDrt,invalid);
		if(invalid)
		continue;
		positionOFsnake(snakeX,snakeY);
		puts(map);
			
	
	}
	
}

