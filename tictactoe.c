#include<stdio.h>
#include<string.h>
int w=1,a=3;
char x[30],o[30],f[30];
char g[5];
int player()
{
        printf("enter the name of X player:\n");
        gets(x);
    
        printf("enter the name of O player:\n");
        gets(o);
     while(strcmp(x,f)!=0 || strcmp(o,f)!=0)
    {
        printf("who plays first, %s or %s?\n",x,o);
        gets(f);
        if(strcmp(x,f)==0 || strcmp(o,f)==0)
        { 
            return 0;
        }
          else{ 
                  printf("%s is not a registered player.\n",f); 
                continue;
          }
    }
}
void currentstate(char arr[3][3])
{
    for(int i=0;i<3;i++)
       {
            for(int j=0;j<3;j++)
                printf("%c",arr[i][j]);
                printf("\n");
       }
}
void rowCrossed(char arr[][3]) 
{ 
    for (int i=0; i<3; i++) 
    { 
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '.') 
        w=0; 
    } 
 
} 
  

void columnCrossed(char arr[][3]) 
{ 
    for (int i=0; i<3; i++) 
    { 
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] &&  arr[0][i] != '.') 
            w=0; 
    }  
} 
  
void diagonalCrossed(char arr[][3]) 
{ 
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.') 
        w=0; 
          
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '.') 
        w=0; 
    
} 
 void play(char arr[3][3])
{   
    int moves=0;
    while(w != 0 || moves != 9)
        {   
            int r,c;
             printf("Player of current turn: %s\n",f);
            printf("Choose a row number(0 to 2):\n");
                fflush(stdin);
                scanf("%d",&r);
        if(r>2 || r<0)
        {
            printf("%d is not valid row.\n",r);
            continue;
        }
        printf("Choose a column number(0 to 2):\n");
        fflush(stdin);
        scanf("%d",&c);
        if(c>2 || c<0)
        {
            printf("%d is not valid column.\n",c);
             continue;
        }
        if(arr[r][c]=='X'||arr[r][c]=='O')
        {
            printf("This grid is already used.\n");
            currentstate(arr);
             continue;
        }
    else {
        if(strcmp(f,x)==0)
            arr[r][c]='X';
            else
            {
                arr[r][c]='O';
            }
            
    }
    currentstate(arr);
    rowCrossed(arr);
    columnCrossed(arr);
    diagonalCrossed(arr); 
    if(w==0)
    {
        printf("Game over: \n %s wins!\n",f);
        break;
    }
            if(strcmp(x,f)==0)
            {
                strcpy(f,o);
            }else
            {
                strcpy(f,x);
            }
            moves++;
            
        }
    if(moves==9)
    printf("game over.\n it is a tie!\n");
}
void again()
{   
    printf("would you like to play again?(Y/N) \n");
    fflush(stdin);
    gets(g);
    if(strcmp(g,"Y")==0)
    {
        w=1;
        a=0;
    }
    else if(strcmp(g,"N")==0)
                {
                     printf("BYE!");
                    a=1;
                }
    else if(strcmp(g,"Y")==1 || strcmp(g,"N")==1)
            {
                printf("%s is not valid answer.\n",g);
                a=3;
            }
            
}
int main()
{   
        
       
       
        while(g != "N")
        {   
            char arr[3][3]={'.','.','.','.','.','.','.','.','.'};
            player();
             currentstate(arr);
            play(arr);
             
            while(a==3)
            {
                again();
            }
            if(a==0)
            {
                continue;
            } 
            if(a==1)
            {
                break;
            } 
        }  
       return 0;
}
