/* 
* Name: <SMIT BAGUL>
* Roll number: <CS20B011>
*/
#include <stdio.h>

char board[3][3];
char player[2]={'X','O'};

void initialization(void);    //initialize to blank spaces
void showconfig(void);        //shows current status of board
int checklegal(int, int);     //checks if inputt place is blank
void putsymbol(int,int,char); //inputs player character to input place
int checkwindir(int,char);    //cases to check win conditions
int checkwin(void);           //checks win conditions

int main()
{
  initialization();         

  int i,j;
  int k=1;
  int p=0;
  while(checkwin()==0 && k!=10)        //if checkwin is 1 winner has been found and if k is 10 its a draw
  {
    showconfig();

    printf("Player %d's input:",p+1);
    scanf("%d %d",&i,&j);

    if(checklegal(i-1,j-1)==0)
    {
      printf("Player %d input valid move",p+1);
      continue;
    }

    putsymbol(i-1,j-1,player[p]);
    p=(p+1)%2;
    k++;
  }
  showconfig();
   if(checkwin()==0)
  {
    printf("Game ended in a draw\n");
  }
  else if(k%2==0)
  {
    printf("Winner is player 1\n");
  }
  else
  {
    printf("Winner is player 2\n");
  }
}

void initialization()
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      board[i][j]=' ';
    }
  }
}

void showconfig()
{
  printf("\n-------------\n");
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("| %c ",board[i][j]);
    }
    printf("|\n-------------\n");
  }
}

int checklegal(int i,int j)
{
  if(board[i][j]==' ')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void putsymbol(int i,int j,char c)
{
  board[i][j]=c;
}

int checkwindir(int dir,char symbol)
{
  int x,y,j=0;
  for(int i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      switch(dir)
      {
        case 1: x=i,y=j;            //check rowwise
                break;
        case 2: x=j,y=i;            //check columnwise
                break;
        case 3: x=j,y=j;            //checks diagonal
                break;
        case 4: x=j,y=3-j-1;        //checks reverse diagonal
                break;
      }
     if(board[x][y]!=symbol)
     {
       break;
     }
    }
   if(j==3)
   {
     return 1;
   }
  }
  return 0;
}

int checkwin()
{
  for(int i=1;i<5;i++)
  {
    for(int j=0;j<2;j++)
    {
      if(checkwindir(i,player[j])==1)
      {
        return 1;
      }
    }
  }
  return 0;
}
