#include <fstream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <conio.h>

using namespace std;

//					       display Function 
void welcome(string s[]);
void getscreen(char &x);
void gotoxy(int x,int y);
void getBox();

//					       Declaration of function
string get_cur_time();
string itos(long l);
char itoc(int i);
	
//						main menu function	
	
void aboutTDS();
void readPreviusRecoade();
void input(void);
void supportingInfo();
	
//						TDS Function
void setData(float data);
float getTDS(float x,float y);
string getQuality(float TDS);
fstream file;
						//   main function..
int main()
{		
	string s[] = {"welcome to ", " Water QualityChecker \n\t\t\t\t\t\t\t\t by A13, GT:G1, Pradeep "};
	char x = '1';
	welcome(s);	
	do
	{	
		getscreen(x);
	} while (true);
}
//						<--	  display FUNCTIONS   -->

void getscreen(char &x)
{
     up:
	getBox();
	cout << "Select any of above :  ";
	x = getch();
	gotoxy(0,2);
	switch (x)
	{
		case '1':
			input();
			break;
		case '2':
			readPreviusRecoade();
			break;
		case '3':
			supportingInfo();
			break;
		case '4':
			aboutTDS();
			break;
		case '5':
			exit(1);
		default:
		system("cls");	
		goto up;	
	}
	cout << '\n' << setw(20) << "" << "press any key to get menu bar \n";
	getch();
	system("color 9");
	system("cls");
	getscreen(x);
}

void getBox()
{
	char ul=201, ur=187, m=205, ll=200, lr=188, vm=186;
	cout << setfill(' ') << setw(20) << "" << ul << setfill(m) << setw(42) << "" << ur << "\n";
	cout << setfill(' ') << setw(20) << "" << vm << " WATER QUALITY CHECKER FROM TDS METHOD    " << vm << '\n';	
	cout << setfill(' ') << setw(20) << "" << ll << setfill(m) << setw(42) << "" << lr;
	cout << setfill(' ');
	char side=179, hr=196, u=218, l=192, uo=191, lo=217;	
	gotoxy(20,2);
	cout << u << setfill(hr) << setw(60) << "" << uo << '\n';
	gotoxy(20,0);
	cout << side << setfill(' ') << setw(60) << left << "  1. Check qulity of Water (TDS) from sample( Add info )." << side;
	gotoxy(20,1);
	cout << side << setfill(' ') << setw(60) << left << "  2. Show Previus Recoade (Date and time wise)." << side;
	gotoxy(20,1);
	cout << side << setfill(' ') << setw(60) << left << "  3. Get Suporting Information." << side;
	gotoxy(20,1);
	cout << side << setfill(' ') << setw(60) << left << "  4. Know about TDS." << side;
	gotoxy(20,1);
	cout << side << setfill(' ') << setw(60) << left << "  5. Exit." << side;
	gotoxy(20,1);

	cout << l << setfill(hr) << setw(60) << "" << lo;
	cout << setfill(' ') << '\n';
	gotoxy(20, 0);
}	

void supportingInfo()
{
	system("cls");
	cout << '\n' << setw(10) << "" << "TDS level as follows: excellent, less than 300 mg/liter. \n";
	cout << setw(10) << "" << "The minimum TDS based on some studies should be at least close to 30 ppm\n";
	cout << setw(10) << "" << "-keeps the mineral levels in check. The Bureau of Indian Standards (BIS)\n";
	cout << setw(10) << "" << "fixes the upper limit of TDS in drinking water at 500 ppm.\n";
	char side=179, hr=196, u=218, l=192, uo=191, lo=217;	
	gotoxy(20, 1);
	cout << u << setfill(hr) << setw(30) << "" << (char)194 << setw(29) << "" << uo << '\n';
	gotoxy(20, 0);
	cout << side << setfill(' ') << setw(30) << left << " TDS Level (Miligram/Litter)" << side << setw(29) << " Palatability of Water " << side;
	gotoxy(20, 1);
	cout << (char)195 << setfill(hr) << setw(30) << "" << (char)197 << setw(29) << "" << (char)180;
	gotoxy(20, 1);
	cout << side << setfill(' ') << setw(30) << left << " Less than 300 " << side << setw(29) << left << " Excellent" << side;
	gotoxy(20, 1);
	cout << side << setfill(' ') << setw(30) << left << " 300 - 600 " << side << setw(29) << left << " Good "<< side;
	gotoxy(20, 1);
	cout << side << setfill(' ') << setw(30) << left << " 600 - 900 " << side << setw(29) << left << " Fair " << side;
	gotoxy(20, 1);
	cout << side << setfill(' ') << setw(30) << left << " 900 - 1200 " << side << setw(29) << left << " Poor " << side;
	gotoxy(20, 1);
	cout << side << setfill(' ') << setw(30) << left << " Above 1200 " << side << setw(29) << left << " Unacceptable " << side;
	gotoxy(20, 1);
	cout << l << setfill(hr) << setw(30) << "" << (char)193 << setw(29) << "" << lo;
	cout << setfill(' ') << '\n';
	gotoxy(20, 0); 
 	return;
}			

void aboutTDS()
{
	cout << setw(20) << "" << "TDS of your solution: TDS=[(A-B) * 1000]/mL\n" <<
	setw(20) << "" << "A stands for the weight of the evaporating dish + filtrate\n" <<
	setw(20) << "" << "B stands for the weight of the evaporating dish on its own.\n\n";
}

void gotoxy(int x,int y)
{
	for (int i=0; i<y; i++)
		cout<<"\n";
	for (int i=0; i<x; i++)
		cout<<" ";
	return;
}
	
void welcome(string s[])
{
	system("color 9");
	gotoxy(40,10);
	cout<<"Loading   ";	
	for (int j=0; j<30; j++)	
	{
		cout<<(char)219;
		for(long i=0;i<35000000;i++);
	}
	gotoxy(40,1);			
	system("color b");
	cout<<"Loadding Completed 100 % ";
	for (int k=0; k<2; k++)
	{
		gotoxy(40,10);
		cout<<s[k];
		for(long v=0;v!=900000000;v++);
		
		system("cls");
		system("color 9");
	}
}

//						<--	  protject FUNCTIONS   -->

void input()
{
	float weight_Of_Evaporating_Dish_and_Filtrate;
	float weight_Of_Evaporating_Dish_on_its_own;
    _do:
	system("cls");
	gotoxy(20,5);
	cout<<"Enter Weight of the Evaporating Dish + Filtrate. ( mg/L ) : ";
	cin>>weight_Of_Evaporating_Dish_and_Filtrate;
	fflush(stdin);
	gotoxy(20,0);
	cout<<"Enter the Weight of the Evaporating Dish on its own. ( mg/L ) : ";
	cin>>weight_Of_Evaporating_Dish_on_its_own;
	float &x=weight_Of_Evaporating_Dish_and_Filtrate;
	float &y=weight_Of_Evaporating_Dish_on_its_own;
	
	if(x<y)
	{
		gotoxy(20,1);		
		cout<<""<<"Weight of the Evaporating Dish + Filtrate Must be greater\n"<<setw(20)<<""<<
	     		"than that the Weight of the Evaporating Dish on its own.\n";
		cout<<setw(20)<<""<<"press any key to Reenter values\n";
		getch();
		goto _do;
		system("color 3");
	}
	
	gotoxy(20,1);
	cout<<""<<"TDS value for given sample is "<<setw(10)<<
		getTDS(x,y) <<setw(20)<<getQuality(getTDS(x,y))<<"\n";
	setData(getTDS(x,y));
	return;
}

float getTDS(float A,float B)
{
	return (A-B)*1000;
}

void readPreviusRecoade()
{
	system("cls");
	file.open("info.txt",ios::in);
	//cout<<"\n"<<setw(25)<<"date_time"<<"|"<<setw(20)<<"data"<<"|";
	system("color d");
	string line;
	
	while ( getline(file,line) )
    	{
      		cout << line <<'\n';
    	}
 	file.close();
}

void setData(float TDS)
{

	file.open("info.txt",ios::app);
	string date_time;

	date_time=get_cur_time();

	//info.insert(pair<string,int>(date_time,data));
	//		file<<setw(30)<<"Date & Time Of Recoded "<<"|"<<setw(20)<<"Recoded TDS(mg/L)"
	//		<<"|"<<setw(25)<<"Quality"<<"|";
	file<<"\n"<<setw(30)<<date_time<<" "<<setw(20)<<TDS<<" "<<setw(25)<<getQuality(TDS)<<"|";
	
	file.close();
}

string getQuality(float TDS)
{
	if (TDS<=300)			//  miligram per liter
		return "Excellent";
	else if (TDS<=600)
		return "Good";
	else if (TDS<=900)
		return "Fair";
	else if (TDS<=1200)
		return "Poor";
	else if (TDS>1200)
		return "Unacceptable";

}

// 	   				for	time function...

char itoc(int i)
{
	return '0'+i;
/*
	{
		if(i==0)
			return '0';
		if(i==1)
			return '1';
		if(i==2)
			return '2';
		if(i==3)
			return '3';
		if(i==4)
			return '4';
		if(i==5)
			return '5';
		if(i==6)
			return '6';
		if(i==7)
			return '7';
		if(i==8)
			return '8';
		if(i==9)
			return '9';
	}
*/
}

string itos(long l)
{
	string s="";
	for (int i=0; l!=0; i++)
	{
		s=itoc(l%10)+s;
		l/=10;
	}
	return s;
}

time_t now=time(NULL);			// get time from  os;

string get_cur_time()
{
	struct tm nowlocal;
	nowlocal =*localtime(&now);
	string date_time;
	date_time = itos(nowlocal.tm_mday)+" : "
			  + itos(nowlocal.tm_mon) +" : "
			  + itos(nowlocal.tm_year+1900)+" : "
			  + itos(nowlocal.tm_hour) + " : "
			  + itos(nowlocal.tm_min) + " : "
			  + itos(nowlocal.tm_sec) ;
	return date_time;
}
//							277


