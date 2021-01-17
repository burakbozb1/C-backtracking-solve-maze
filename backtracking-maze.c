/*
Burak Boz 
18011706
*/
#include <stdio.h> 
#include <time.h>
#include <stdbool.h>
  
// Labirent boyutu 
#define N 10

  
bool solveMazeUtil( 
    int maze[N][N], int x, 
    int y, int sol[N][N]); 

//Bu fonksiyon matrisleri ekrana yazd�rmak i�in kullan�lm��t�r.
void printSolution(int sol[N][N]) 
{ 
	int i=0,j=0;
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) 
            printf(" %d ", sol[i][j]); 
        printf("\n"); 
    } 
} 
  
//Bu fonksiyon matristeki index de�erlerinin ge�erli olup olmad���n� kontrol eder..
bool isSafe(int maze[N][N], int x, int y) 
{ 
    //x ve y de�erleri matris s�n�rlar� d���ndaysa false d�nd�r�r.
    if ( 
        x >= 0 && x < N && y >= 0 
        && y < N && maze[x][y] == 1) 
        return true; 
  
    return false; 
} 

/*
Bu fonksiyon labirenti ��zmek i�in backtracking algoritmas�n� kullan�r.
�ncelikle solveMazeUtil() fonksiyonu kullan�l�r fakat false d�nd�r�l�rse ��z�m yok demektir.
E�er false d�nmez ise mevcut index 1 olarak sol matrisine yazd�r�l�r.
*/
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { 
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
  
    if (solveMazeUtil( 
            maze, 0, 0, sol) 
        == false) { 
        printf("Cikis yolu bulunamadi"); 
        return false; 
    } 
  
    printSolution(sol); 
    return true; 
} 

//Labirenti ��zmek i�in kullan�lan �zyinelemeli fonksiyon
bool solveMazeUtil( 
    int maze[N][N], int x, 
    int y, int sol[N][N]) 
{ 
    //E�er x ve y indeksleri ge�erli ise true d�nd�r�r.
    if ( 
        x == N - 1 && y == N - 1 
        && maze[x][y] == 1) { 
        sol[x][y] = 1; 
        return true; 
    } 
  
    //x ve y de�erlerinin ge�erli olup olmad���n� kontrol eder.
    if (isSafe(maze, x, y) == true) { 
        //E�er de�erler ge�erliyse matrise 1 de�erini yazar.
        sol[x][y] = 1; 
  
        //x y�n�nde ileri gider.
        if (solveMazeUtil( 
                maze, x + 1, y, sol) 
            == true) 
            return true; 
  
        //E�er x y�n�ne gidemiyorsa y y�n�nde ileri gider.
        if (solveMazeUtil( 
                maze, x, y + 1, sol) 
            == true) 
            return true; 
  
        //E�er yukar�daki iki yolda t�kal�ysa geri d�nmesi gerekti�ini anlar.
        sol[x][y] = 0; 
        return false; 
    } 
  
    return false; 
} 
  
// Ana fonksiyon
int main() 
{ 
	double t1,t2,t3,t4;

	clock_t start_t, end_t;
    start_t = clock();
    
	int maze[N][N] = { 
{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{ 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
{ 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
};
	
	printf("*******Burak Boz - Backtracking Algoritmasi ile Labirent Cozumu*******\n\n");
	printf("** Labirentin sol ust kosesi baslangici ve sag alt kosesi cikisi temsil etmektedir.\n** 1 ler yol, 0 lar ise duvarlari temsil etmektedir.\n\n");
	printf("Labirent 1:\n\n");
	printSolution(maze);
	printf("\n\nCikisa giden yol:\n\n");
    solveMaze(maze); 
    
    end_t = clock();
    t1=(double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n1.labirentin cozumlenmesi %f saniye surdu\n", t1);
    
    
    printf("\n-------------------------------\n\n");
    
    
    int maze2[N][N] = {
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
};
    
    start_t = clock();
    
    printf("Labirent 2:\n\n");
	printSolution(maze2);
	printf("\n\nCikisa giden yol:\n\n");
    solveMaze(maze2); 
    
    end_t = clock();
    t2=(double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n2.labirentin cozumlenmesi %f saniye surdu\n", t2);
    
    printf("\n-------------------------------\n\n");
    
    
    
    int maze3[N][N] ={
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
};
    
    start_t = clock();
    
    printf("Labirent 3:\n\n");
	printSolution(maze3);
	printf("\n\nCikisa giden yol:\n\n");
    solveMaze(maze3); 
    
    end_t = clock();
    t3=(double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n3.labirentin cozumlenmesi %f saniye surdu\n", t3);
    
    
    
    printf("\n-------------------------------\n\n");
    
    
    int maze4[N][N] ={
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
};
    
    start_t = clock();
    
    printf("Labirent 4:\n\n");
	printSolution(maze4);
	printf("\n\nCikisa giden yol:\n\n");
    solveMaze(maze4); 
    
    end_t = clock();
    t4=(double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n4.labirentin cozumlenmesi %f saniye surdu\n\n\n", t4);
    
    
    int time1,time2,time3,time4;
    
    time1=(int)(t1*1000);
    time2=(int)(t2*1000);
    time3=(int)(t3*1000);
    time4=(int)(t4*1000);
    
    
    int i=0;
    
    printf("Labirent 1:");
	for(i=0;i<50;i++)
	{
		if(i<time1)
		{
			printf("|");	
		}
		else{
			printf(".");
		}
	}
	printf("\t%f saniye \n",t1);
	
	printf("Labirent 2:");
	for(i=0;i<50;i++)
	{
		if(i<time2)
		{
			printf("|");	
		}
		else{
			printf(".");
		}
	}
	printf("\t%f saniye \n",t2);
	
	
	printf("Labirent 3:");
	for(i=0;i<50;i++)
	{
		if(i<time3)
		{
			printf("|");	
		}
		else{
			printf(".");
		}
	}
	printf("\t%f saniye \n",t3);
	
	printf("Labirent 4:");
	for(i=0;i<50;i++)
	{
		if(i<time4)
		{
			printf("|");	
		}
		else{
			printf(".");
		}
	}
	printf("\t%f saniye \n",t4);
	
    
    
} 
