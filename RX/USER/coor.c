#include "coor.h"
#include "stm32f4xx.h"
#include "math.h"
#include "oled.h"

int differ_min, differ_min2;
int x,y,m,n;

struct COOR
{
	int	 	x;
	int		y;
	int  _45Hz;
	int  _55Hz;
	int  _65Hz;
	
};

struct COOR A11,A12,A13,A14,A15,A16,A17;
struct COOR A21,A22,A23,A24,A25,A26,A27;
struct COOR A31,A32,A33,A34,A35,A36,A37;
struct COOR A41,A42,A43,A44,A45,A46,A47;
struct COOR A51,A52,A53,A54,A55,A56,A57;
struct COOR A61,A62,A63,A64,A65,A66,A67;
struct COOR A71,A72,A73,A74,A75,A76,A77;

void Struct_Init(void)
{
	A11.x=-30;A11.y=30;A11._45Hz=440; A11._55Hz=1830;A11._65Hz=440;
	A12.x=-20, A12.y=30, A12._45Hz=540, A12._55Hz=1820, A12._65Hz=540;
	A13.x=-10, A13.y=30, A13._45Hz=790, A13._55Hz=1520, A13._65Hz=790;
	A14.x=  0, A14.y=30, A14._45Hz=1180, A14._55Hz=1174, A14._65Hz=1174;
	A15.x= 10, A15.y=30, A15._45Hz=1520, A15._55Hz=1520, A15._65Hz=1520;
	A16.x= 20, A16.y=30, A16._45Hz=1870, A16._55Hz=1928, A16._65Hz=1928;
	A17.x= 30, A17.y=30, A17._45Hz=2200, A17._55Hz=433, A17._65Hz=170;

	A21.x=-30, A21.y=20, A21._45Hz=390, A21._55Hz=1580 , A21._65Hz=530 ;
	A22.x=-20, A22.y=20, A22._45Hz=600 , A22._55Hz=1770 , A22._65Hz=600 ;
	A23.x=-10, A23.y=20, A23._45Hz=850 , A23._55Hz=1600 , A23._65Hz=880 ;
	A24.x=  0, A24.y=20, A24._45Hz=1300 , A24._55Hz=1360 , A24._65Hz=1300 ;
	A25.x= 10, A25.y=20, A25._45Hz=1700 , A25._55Hz=1130 , A25._65Hz=1690 ;
	A26.x= 20, A26.y=20, A26._45Hz=1890 , A26._55Hz=743 , A26._65Hz=1890 ;
	A27.x= 30, A27.y=20, A27._45Hz=2240 , A27._55Hz=530 , A27._65Hz=227 ;

	A31.x= -30, A31.y=10, A31._45Hz=360 , A31._55Hz=1410 , A31._65Hz=640 ;
	A32.x= -20, A32.y=10, A32._45Hz=638 , A32._55Hz=1406 , A32._65Hz=730 ;
	A33.x= -10, A33.y=10, A33._45Hz=936 , A33._55Hz=1588 , A33._65Hz=937 ;
	A34.x=   0, A34.y=10, A34._45Hz=1330 , A34._55Hz=1375 , A34._65Hz=1327 ;
	A35.x=  10, A35.y=10, A35._45Hz=1730 , A35._55Hz=1735 , A35._65Hz=1735 ;
	A36.x=  20, A36.y=10, A36._45Hz=2137 , A36._55Hz=900 , A36._65Hz=2147 ;
	A37.x=  30, A37.y=10, A37._45Hz=2200 , A37._55Hz=653 , A37._65Hz=300 ;

	A41.x=-30, A41.y= 0, A41._45Hz=435 , A41._55Hz=1120 , A41._65Hz=650 ;
	A42.x=-20, A42.y= 0, A42._45Hz=681 , A42._55Hz=1503 , A42._65Hz=1084 ;
	A43.x=-10, A43.y= 0, A43._45Hz=965 , A43._55Hz=1296 , A43._65Hz=1072 ;
	A44.x=  0, A44.y= 0, A44._45Hz=1344 , A44._55Hz=1325 , A44._65Hz=1348 ;
	A45.x= 10, A45.y= 0, A45._45Hz=1756 , A45._55Hz=1300 , A45._65Hz=1760 ;
	A46.x= 20, A46.y= 0, A46._45Hz=1874 , A46._55Hz=1200 , A46._65Hz=1930 ;
	A47.x= 30, A47.y= 0, A47._45Hz=2140 , A47._55Hz=800 , A47._65Hz=700 ;
			
	A51.x= -30, A51.y= -10, A51._45Hz=290 , A51._55Hz=1000 , A51._65Hz=980 ;
	A52.x= -20, A52.y= -10, A52._45Hz=385 , A52._55Hz=810 , A52._65Hz=790 ;
	A53.x= -10, A53.y= -10, A53._45Hz=500 , A53._55Hz=930 , A53._65Hz=910 ;
	A54.x=   0, A54.y= -10, A54._45Hz=730 , A54._55Hz=850 , A54._65Hz=850 ;
	A55.x=  10, A55.y= -10, A55._45Hz=1140 , A55._55Hz=850 , A55._65Hz=1140 ;
	A56.x=  20, A56.y= -10, A56._45Hz=1600 , A56._55Hz=880 , A56._65Hz=1600 ;
	A57.x=  30, A57.y= -10, A57._45Hz=2000 , A57._55Hz=860 , A57._65Hz=1960 ;

	A61.x= -30, A61.y= -20, A61._45Hz=250 , A61._55Hz=600 , A61._65Hz=870 ;
	A62.x= -20, A62.y= -20, A62._45Hz=714 , A62._55Hz=1582 , A62._65Hz=2025 ;
	A63.x= -10, A63.y= -20, A63._45Hz=380 , A63._55Hz=1000 , A63._65Hz=1000 ;
	A64.x=   0, A64.y= -20, A64._45Hz=510 , A64._55Hz=770 , A64._65Hz=770 ;
	A65.x=  10, A65.y= -20, A65._45Hz=820 , A65._55Hz=624 , A65._65Hz=850 ;
	A66.x=  20, A66.y= -20, A66._45Hz=1150 , A66._55Hz=730 , A66._65Hz=1145 ;
	A67.x=  30, A67.y= -20, A67._45Hz=1750 , A67._55Hz=780 , A67._65Hz=1760 ;
													
	A71.x= -30, A71.y= -30, A71._45Hz=200 , A71._55Hz=550 , A71._65Hz=1030 ;
	A72.x= -20, A72.y= -30, A72._45Hz=240 , A72._55Hz=380 , A72._65Hz=780 ;
	A73.x= -10, A73.y= -30, A73._45Hz=280 , A73._55Hz=800 , A73._65Hz=880 ;
	A74.x=   0, A74.y= -30, A74._45Hz=345 , A74._55Hz=390 , A74._65Hz=800 ;
	A75.x=  10, A75.y= -30, A75._45Hz=430 , A75._55Hz=367 , A75._65Hz=750 ;
	A76.x=  20, A76.y= -30, A76._45Hz=660 , A76._55Hz=355 , A76._65Hz=660 ;
	A77.x=  30, A77.y= -30, A77._45Hz=1230 , A77._55Hz=720 , A77._65Hz=1200 ;
}
int differ[7][7];

extern int HeightA_avg, HeightB_avg, HeightC_avg; //A:45Hz, C:55Hz, B:65Hz

void Differ_Calc(void)
{
	differ[0][0]=abs(A11._45Hz-HeightA_avg)+abs(A11._55Hz-HeightC_avg)+abs(A11._65Hz-HeightB_avg);
	differ[0][1]=abs(A12._45Hz-HeightA_avg)+abs(A12._55Hz-HeightC_avg)+abs(A12._65Hz-HeightB_avg);
	differ[0][2]=abs(A13._45Hz-HeightA_avg)+abs(A13._55Hz-HeightC_avg)+abs(A13._65Hz-HeightB_avg);
	differ[0][3]=abs(A14._45Hz-HeightA_avg)+abs(A14._55Hz-HeightC_avg)+abs(A14._65Hz-HeightB_avg);
	differ[0][4]=abs(A15._45Hz-HeightA_avg)+abs(A15._55Hz-HeightC_avg)+abs(A15._65Hz-HeightB_avg);
	differ[0][5]=abs(A16._45Hz-HeightA_avg)+abs(A16._55Hz-HeightC_avg)+abs(A16._65Hz-HeightB_avg);
	differ[0][6]=abs(A17._45Hz-HeightA_avg)+abs(A17._55Hz-HeightC_avg)+abs(A17._65Hz-HeightB_avg);
	
	differ[1][0]=abs(A21._45Hz-HeightA_avg)+abs(A21._55Hz-HeightC_avg)+abs(A21._65Hz-HeightB_avg);
	differ[1][1]=abs(A22._45Hz-HeightA_avg)+abs(A22._55Hz-HeightC_avg)+abs(A22._65Hz-HeightB_avg);
	differ[1][2]=abs(A23._45Hz-HeightA_avg)+abs(A23._55Hz-HeightC_avg)+abs(A23._65Hz-HeightB_avg);
	differ[1][3]=abs(A24._45Hz-HeightA_avg)+abs(A24._55Hz-HeightC_avg)+abs(A24._65Hz-HeightB_avg);
	differ[1][4]=abs(A25._45Hz-HeightA_avg)+abs(A25._55Hz-HeightC_avg)+abs(A25._65Hz-HeightB_avg);
	differ[1][5]=abs(A26._45Hz-HeightA_avg)+abs(A26._55Hz-HeightC_avg)+abs(A26._65Hz-HeightB_avg);
	differ[1][6]=abs(A27._45Hz-HeightA_avg)+abs(A27._55Hz-HeightC_avg)+abs(A27._65Hz-HeightB_avg);
	
	differ[2][0]=abs(A31._45Hz-HeightA_avg)+abs(A31._55Hz-HeightC_avg)+abs(A31._65Hz-HeightB_avg);
	differ[2][1]=abs(A32._45Hz-HeightA_avg)+abs(A32._55Hz-HeightC_avg)+abs(A32._65Hz-HeightB_avg);
	differ[2][2]=abs(A33._45Hz-HeightA_avg)+abs(A33._55Hz-HeightC_avg)+abs(A33._65Hz-HeightB_avg);
	differ[2][3]=abs(A34._45Hz-HeightA_avg)+abs(A34._55Hz-HeightC_avg)+abs(A34._65Hz-HeightB_avg);
	differ[2][4]=abs(A35._45Hz-HeightA_avg)+abs(A35._55Hz-HeightC_avg)+abs(A35._65Hz-HeightB_avg);
	differ[2][5]=abs(A36._45Hz-HeightA_avg)+abs(A36._55Hz-HeightC_avg)+abs(A36._65Hz-HeightB_avg);
	differ[2][6]=abs(A37._45Hz-HeightA_avg)+abs(A37._55Hz-HeightC_avg)+abs(A37._65Hz-HeightB_avg);
	
	differ[3][0]=abs(A41._45Hz-HeightA_avg)+abs(A41._55Hz-HeightC_avg)+abs(A41._65Hz-HeightB_avg);
	differ[3][1]=abs(A42._45Hz-HeightA_avg)+abs(A42._55Hz-HeightC_avg)+abs(A42._65Hz-HeightB_avg);
	differ[3][2]=abs(A43._45Hz-HeightA_avg)+abs(A43._55Hz-HeightC_avg)+abs(A43._65Hz-HeightB_avg);
	differ[3][3]=abs(A44._45Hz-HeightA_avg)+abs(A44._55Hz-HeightC_avg)+abs(A44._65Hz-HeightB_avg);
	differ[3][4]=abs(A45._45Hz-HeightA_avg)+abs(A45._55Hz-HeightC_avg)+abs(A45._65Hz-HeightB_avg);
	differ[3][5]=abs(A46._45Hz-HeightA_avg)+abs(A46._55Hz-HeightC_avg)+abs(A46._65Hz-HeightB_avg);
	differ[3][6]=abs(A47._45Hz-HeightA_avg)+abs(A47._55Hz-HeightC_avg)+abs(A47._65Hz-HeightB_avg);
	
	differ[4][0]=abs(A51._45Hz-HeightA_avg)+abs(A51._55Hz-HeightC_avg)+abs(A51._65Hz-HeightB_avg);
	differ[4][1]=abs(A52._45Hz-HeightA_avg)+abs(A52._55Hz-HeightC_avg)+abs(A52._65Hz-HeightB_avg);
	differ[4][2]=abs(A53._45Hz-HeightA_avg)+abs(A53._55Hz-HeightC_avg)+abs(A53._65Hz-HeightB_avg);
	differ[4][3]=abs(A54._45Hz-HeightA_avg)+abs(A54._55Hz-HeightC_avg)+abs(A54._65Hz-HeightB_avg);
	differ[4][4]=abs(A55._45Hz-HeightA_avg)+abs(A55._55Hz-HeightC_avg)+abs(A55._65Hz-HeightB_avg);
	differ[4][5]=abs(A56._45Hz-HeightA_avg)+abs(A56._55Hz-HeightC_avg)+abs(A56._65Hz-HeightB_avg);
	differ[4][6]=abs(A57._45Hz-HeightA_avg)+abs(A57._55Hz-HeightC_avg)+abs(A57._65Hz-HeightB_avg);
	
	differ[5][0]=abs(A61._45Hz-HeightA_avg)+abs(A61._55Hz-HeightC_avg)+abs(A61._65Hz-HeightB_avg);
	differ[5][1]=abs(A62._45Hz-HeightA_avg)+abs(A62._55Hz-HeightC_avg)+abs(A62._65Hz-HeightB_avg);
	differ[5][2]=abs(A63._45Hz-HeightA_avg)+abs(A63._55Hz-HeightC_avg)+abs(A63._65Hz-HeightB_avg);
	differ[5][3]=abs(A64._45Hz-HeightA_avg)+abs(A64._55Hz-HeightC_avg)+abs(A64._65Hz-HeightB_avg);
	differ[5][4]=abs(A65._45Hz-HeightA_avg)+abs(A65._55Hz-HeightC_avg)+abs(A65._65Hz-HeightB_avg);
	differ[5][5]=abs(A66._45Hz-HeightA_avg)+abs(A66._55Hz-HeightC_avg)+abs(A66._65Hz-HeightB_avg);
	differ[5][6]=abs(A67._45Hz-HeightA_avg)+abs(A67._55Hz-HeightC_avg)+abs(A67._65Hz-HeightB_avg);
	
	differ[6][0]=abs(A71._45Hz-HeightA_avg)+abs(A71._55Hz-HeightC_avg)+abs(A71._65Hz-HeightB_avg);
	differ[6][1]=abs(A72._45Hz-HeightA_avg)+abs(A72._55Hz-HeightC_avg)+abs(A72._65Hz-HeightB_avg);
	differ[6][2]=abs(A73._45Hz-HeightA_avg)+abs(A73._55Hz-HeightC_avg)+abs(A73._65Hz-HeightB_avg);
	differ[6][3]=abs(A74._45Hz-HeightA_avg)+abs(A74._55Hz-HeightC_avg)+abs(A74._65Hz-HeightB_avg);
	differ[6][4]=abs(A75._45Hz-HeightA_avg)+abs(A75._55Hz-HeightC_avg)+abs(A75._65Hz-HeightB_avg);
	differ[6][5]=abs(A76._45Hz-HeightA_avg)+abs(A76._55Hz-HeightC_avg)+abs(A76._65Hz-HeightB_avg);
	differ[6][6]=abs(A77._45Hz-HeightA_avg)+abs(A77._55Hz-HeightC_avg)+abs(A77._65Hz-HeightB_avg);
}

void Diff_Min(void)
{
	int i,j;
	differ_min=differ[0][0];
	for (i=0;i<6;i++)
	{
		for (j=0;j<6;j++)
		{
			if (differ[i][j]<differ_min)
			{
				differ_min=differ[i][j];
				x=i,y=j;
			}
		}
	}
}

void Coor_Find(void)
{
	if (x==0 && y==0)						//A11
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,30");
	}
	if (x==0 && y==1)						//A12
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,30");
	}
	if (x==0 && y==2)						//A13
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,30");
	}
	if (x==0 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,30");
	}
	if (x==0 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,30");
	}
	if (x==0 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,30");
	}
	if (x==0 && y==6)					//A17
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,30");
	}

	if (x==1 && y==0)						//A21
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,20");
	}
	if (x==1 && y==1)						//A22
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,20");
	}
	if (x==1 && y==2)						//A23
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,20");
	}
	if (x==1 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,20");
	}
	if (x==1 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,20");
	}
	if (x==1 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,20");
	}
	if (x==1 && y==6)					//A17
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,20");
	}

	if (x==2 && y==0)						//A31
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,10");
	}
	if (x==2 && y==1)						//A32
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,10");
	}
	if (x==2 && y==2)						//A33
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,10");
	}
	if (x==2 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,10");
	}
	if (x==2 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,10");
	}
	if (x==2 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,10");
	}
	if (x==2 && y==6)					//A37
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,10");
	}
	
	if (x==3 && y==0)						//A41
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,0");
	}
	if (x==3 && y==1)						//A42
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,0");
	}
	if (x==3 && y==2)						//A43
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,0");
	}
	if (x==3 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,0");
	}
	if (x==3 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,0");
	}
	if (x==3 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,0");
	}
	if (x==3 && y==6)					//A47
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,0");
	}
	
	if (x==4 && y==0)						//A51
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,-10");
	}
	if (x==4 && y==1)						//A52
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,-10");
	}
	if (x==4 && y==2)						//A53
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,-10");
	}
	if (x==4 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,-10");
	}
	if (x==4 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,-10");
	}
	if (x==4 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,-10");
	}
	if (x==4 && y==6)					//A57
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,-10");
	}
	
	if (x==5 && y==0)						//A61
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,-20");
	}
	if (x==5 && y==1)						//A62
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,-20");
	}
	if (x==5 && y==2)						//A63
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,-20");
	}
	if (x==5 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,-20");
	}
	if (x==5 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,-20");
	}
	if (x==5 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,-20");
	}
	if (x==5 && y==6)					//A67
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,-20");
	}
	
	if (x==6 && y==0)						//A71
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-30,-30");
	}
	if (x==6 && y==1)						//A72
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-20,-30");
	}
	if (x==6 && y==2)						//A73
	{
		OLED_Clear();
		OLED_ShowString(0,0,"-10,-30");
	}
	if (x==6 && y==3)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"0,-30");
	}
	if (x==6 && y==4)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"10,-30");
	}
	if (x==6 && y==5)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"20,-30");
	}
	if (x==6 && y==6)					//A77
	{
		OLED_Clear();
		OLED_ShowString(0,0,"30,-30");
	}
	
}



							  