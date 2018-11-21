#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include<stdio.h>
using namespace std ;
int bc=0;
int fc=0;
int cc=0;
class HOUSES {
	public :
	int futsal;
	int cricket;
	int basketball;
	int total;
	//int i=0;
	//int c;
	string h;	
	public :
		HOUSES ()
		{
			
		}
		HOUSES(HOUSES &obj)
		{
			h=obj.h;
			total=obj.total;
			basketball=obj.basketball;
			cricket=obj.cricket;
			futsal=obj.futsal;
		}
		void setbbpoint(int a)
		{
			basketball=basketball+a;
		}
		void setfpoint(int a)
		{
			futsal=futsal+a;
			}
		void setcpoint(int a)
		{
			cricket=cricket+a;
			}
			int getbbpoints()
			{
				return basketball;
				}
			int getfpoints()
			{
				return futsal;
				}
			int getcpoints()
			{
				return cricket;
				}		
			int gettpoints()
			{
				total=cricket+futsal+basketball;
				return total;
			}
	
};
class SPORTS:public HOUSES {
	protected :
	
    int c ;
	string b ;
	
	public:
		SPORTS ()
		{
			b="CRICKET";
		}
		void selectsport()
		{
			cout<<"Basket Ball Matches "<<bc<<endl<<"Futsal Matches "<<fc<<endl<<"Cricket Matches "<<cc;
			cout<<endl<<"1.BASKETBALL"<<endl<<"2.CRICKET"<<endl<<"3.FUTSAL"<<endl;
			cout<<"ENTER CHOICES : " ;
			cin>>c;
			switch (c)
			{
				case 1 :
					if(bc!=15)
					{
					b="BASKETBALL";
					bc++;
				}
					else
				 	selectsport();
					break ;
				case 2 :
					if(cc!=15)
				   	{
					   b="CRICKET";
					   cc++;
				}
				   else
				 	selectsport();
				   
					break ;
				case 3:
					if(fc!=15)
				 {
				 b="FUTSAL";
				 fc++;}
				 	else
				 	selectsport();
				 
					break ;
		
		}
}};
class MATCHES:public SPORTS
{
	protected :
		int h ;
	public :
	MATCHES (){
		h=1;
	}
	void drawfixutes(HOUSES &obj1,HOUSES &obj2)
	{  
		cout<<" Match "<<b<<" "<<obj1.h<<" vs "<<obj2.h<<endl;
		cout <<"SELECT WINNER :"<<endl;
		cout<<"1."<<obj1.h<<endl;
		cout<<"2."<<obj2.h<<endl;
		cout<<"ENTER CHOICE : ";
		cin>>h ;
		if (h==1)
		{
			if(b=="BASKETBALL")
			setpoints(obj1);
			if(b=="FUTSAL")
			setpoints(obj1);
			if(b=="CRICKET")
			setpoints(obj1);
		}
		else
		{
			if(b=="BASKETBALL")
			setpoints(obj2);
			if(b=="FUTSAL")
			setpoints(obj2);
			if(b=="CRICKET")
			setpoints(obj2);
		}
		
		
	}
	void setpoints(HOUSES &obj)
	{
			if(b=="BASKETBALL")
			obj.setbbpoint(3);
			if(b=="FUTSAL")
			obj.setfpoint(3);
			if(b=="CRICKET")
			obj.setcpoint(3);
	}
	virtual void selectsport()
	{
		SPORTS::selectsport();
	}
	
	
	
};
class LOG {
	public :
	
	HOUSES h[6]; 
	MATCHES M[46];
	LOG()
 	{
 		int mn;
 		do
 		{
 		system("CLS");
 	cout<<("                   ___________      _________   ")<<endl;
	cout<<("        |         |           |    |             ")<<endl;
	cout<<("        |         |           |    |             ")<<endl;
	cout<<("        |         |           |    |             ")<<endl;
	cout<<("        |         |           |    |      _____       ")<<endl;
	cout<<("        |         |           |    |     |     |   ")<<endl;
	cout<<("        |________ |___________|    |_____|     |  ")<<endl<<endl;
		 char choice;
 		cout<<"\nEnter 1 for Team Names";
 		cout<<"\nEnter 2 for Selecting Sport";
 		cout<<"\nEnter 3 for Draw Fixtures and Matches Result";
 		cin>>choice;
 		switch(choice)
 		{
		 case '1':
 			setteams();
			break;
			case '2':
			mn=setmatch();
			static int nt=mn;
			break;
			case '3':
			string s;
			string s2;
			int t1;
			int t2;
			cout<<"Enter team 1\n";
			cin>>s;
			cout<<"Enter team 2\n";
			cin>>s2;
			for(int i=0;i<6;i++)
			{
				if(s==h[i].h)
				t1=i;
				if(s2==h[i].h)
				t2=i;
			}
			playmatch(nt-1,h[t1],h[t2]);
			nt++;
			break;
		}
		
		
		cout<<"Enter y to continue and n to exit"<<endl;
	}while(getche()=='y');
	updatetable();
 	}
 	void setteams()
 	{
 		
 		int i=0;
 		fstream myfile ;
 		myfile.open("Teams.txt",ios::in);
			while(!myfile.eof())
			{
				myfile>>h[i].h>>h[i].futsal>>h[i].basketball>>h[i].cricket>>h[i].total;
				i++;
			}
			myfile.close();
			cout<<"Teams Updated";
	 }
 	int setmatch()
 	{
 		static int i=0;
		M[i++].selectsport();
		return i;
	}
	void viewtable ()
	 {
	 	ofstream myfile ("LOG.txt");
	 	if(myfile.is_open())
	 	{
		myfile<<"TEAMS\t\tFUTSAL\t\tBASKETBALL\t\tCRICKET\t\tTotal"<<endl;
	 	myfile<<h[0].h<<"\t\t" <<h[0].futsal<<"\t\t" <<h[0].getbbpoints()<<"\t\t" <<h[0].getcpoints()<<"\t\t"<<h[0].gettpoints()<<endl;
	 	myfile<<h[1].h<<"\t\t" <<h[1].futsal<<"\t\t" <<h[1].getbbpoints()<<"\t\t" <<h[1].getcpoints()<<"\t\t"<<h[1].gettpoints()<<endl;
	 	myfile<<h[2].h<<"\t\t" <<h[2].futsal<<"\t\t" <<h[2].getbbpoints()<<"\t\t" <<h[2].getcpoints()<<"\t\t"<<h[2].gettpoints()<<endl;
	 	myfile<<h[3].h<<"\t\t" <<h[3].futsal<<"\t\t" <<h[3].getbbpoints()<<"\t\t" <<h[3].getcpoints()<<"\t\t"<<h[3].gettpoints()<<endl;
	 	myfile<<h[4].h<<"\t\t" <<h[4].futsal<<"\t\t" <<h[4].getbbpoints()<<"\t\t" <<h[4].getcpoints()<<"\t\t"<<h[4].gettpoints()<<endl;
	 	myfile<<h[5].h<<"\t\t" <<h[5].futsal<<"\t\t" <<h[5].getbbpoints()<<"\t\t" <<h[5].getcpoints()<<"\t\t"<<h[5].gettpoints()<<endl;
	 	
		}
		myfile.close();
	 }
	void playmatch(int mn,HOUSES &obj1,HOUSES &obj2)
	{
		M[mn].drawfixutes(obj1,obj2);
		viewtable();
	}
	void updatetable()
	{
		ofstream myfile ("Teams.txt");
	 	if(myfile.is_open())
	 	{
	 	myfile<<h[0].h<<" " <<h[0].futsal<<" " <<h[0].getbbpoints()<<" " <<h[0].getcpoints()<<" "<<h[0].gettpoints()<<endl;
	 	myfile<<h[1].h<<" " <<h[1].futsal<<" " <<h[1].getbbpoints()<<" " <<h[1].getcpoints()<<" "<<h[1].gettpoints()<<endl;
	 	myfile<<h[2].h<<" " <<h[2].futsal<<" " <<h[2].getbbpoints()<<" " <<h[2].getcpoints()<<" "<<h[2].gettpoints()<<endl;
	 	myfile<<h[3].h<<" " <<h[3].futsal<<" " <<h[3].getbbpoints()<<" " <<h[3].getcpoints()<<" "<<h[3].gettpoints()<<endl;
	 	myfile<<h[4].h<<" " <<h[4].futsal<<" " <<h[4].getbbpoints()<<" " <<h[4].getcpoints()<<" "<<h[4].gettpoints()<<endl;
	 	myfile<<h[5].h<<" " <<h[5].futsal<<" " <<h[5].getbbpoints()<<" " <<h[5].getcpoints()<<" "<<h[5].gettpoints()<<endl;
	 	
		}
		myfile.close();
	}
	/*Topper()
	{
		HOUSES temp[6]={{HOUSES(h[0])},{HOUSES(h[1])},{HOUSES(h[2])},{HOUSES(h[3])},{HOUSES(h[4])},{HOUSES(h[5])}};
		int k=0;
		HOUSES temp1;
		ofstream fg;
			fg.open("Topper.txt");
	fg<<"Team\t\tPosition\n";
	for (int i = 0; i < 5; i++)
{
    for (int j = i+1; j < 5 ; j++)
    {
        if (temp[j].gettpoints()>temp[i].gettpoints()  )
        {
            strcpy(temp1.h,temp[i].h);
            strcpy(temp[i].h,temp[j].h);
            strcpy(temp[j].h,temp1.h);
        }
    }
}
	fg<<temp[0]<<"\t\t\t1st\n";
	fg<<temp[1]<<"\t\t\t2nd\n";
	fg<<temp[2]<<"\t\t\t3rd\n";
	fg<<temp[3]<<"\t\t\t4th\n";
	fg<<temp[4]<<"\t\t\t5th\n";
	fg<<temp[5]<<"\t\t\t6th\n";
	getch();		
}*/
};
main ()
{
	char choice;
	
 	LOG L;
 	//table t1 ;
 	//t1.viewtable();
 
}

