#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu(void)
{
}

MainMenu::~MainMenu(void)
{
}
void MainMenu::ClearScreen()
{
	system("cls");
}
void MainMenu::Greeting()
{
	char Choice;
	int Success;
	cout<<"******************************************************************"<<endl;
	cout<<"Welcome to Awesomesauce. If you are a new member, please sign up"<<endl;
	cout<<"******************************************************************"<<endl<<endl;
	cout<<"Enter 1 to sign up"<<endl;
	cout<<"Enter 2 if you are a member"<<endl;
	cout<<"Enter 3 if you are an Admin"<<endl;
	cout<<"Enter 4 to Exit"<<endl;
	cout<<"Enter Option: "; cin>>Choice;
	ClearScreen();
	
		if (Choice == '1')
		{		Q.SignUp();
				Greeting();
		}
		else if (Choice == '2') 
		{
			Success = Q.Login();
			if (Success == 1)
				MenuMain();
			else
				Greeting();
		}
		else if (Choice == '3') 
		{
			Success = Q.AdminLogin();
			if (Success == 1)
				AdminMenu();
			else
				Greeting();
		}
		else if (Choice == '4') 
		{
			exit(1);
			
		}
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
		Greeting();
}

void MainMenu::AdminMenu()
{
	char Choice;
	do{
		cout<<"******************************************************************"<<endl;
		cout<<"		  Administrator Menu							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"1. Add Media"<<endl;
		cout<<"2. Delete Media"<<endl;
		cout<<"3. View Members"<<endl;
		cout<<"4. View Checked out Items"<<endl;
		cout<<"5. Return to Login screen "<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		
			if (Choice == '1')
			{
				AddMedia();
				ClearScreen();
				AdminMenu();
			}
			else if (Choice == '2') 
			{
				DeleteMedia();
				ClearScreen();
				AdminMenu();
			}
			else if (Choice == '3')
			{
				Q.Members();
				AdminMenu();
				
			}
			else if (Choice == '4')
			{
				Q.ShowBorrowed();
				AdminMenu();
				
			}
			else if (Choice == '5')
			{
				ClearScreen();
				Greeting();
				
			}
		}while(Choice < '1' || Choice >'4');
		AdminMenu();
		ClearScreen();
	}



void MainMenu::MenuMain()
{
	char Choice;
	do{
		cout<<"******************************************************************"<<endl;
		cout<<"		 Member Menu							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"1: Search/Borrow Media"<<endl;
		cout<<"2: Return Media"<<endl;
		cout<<"3: Return to Login"<<endl;
		cout<<"4: Exit"<<endl;

		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1')
		{
			SearchMedia();
			MenuMain();

		}
		else if (Choice == '2') 
		{
			Q.CheckInMedia();
			MenuMain();
		}
		else if (Choice == '3')
		{		Greeting();
		}
		else if (Choice == '4')
		{		exit(1);
		}
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
	
	}while(Choice < '1' || Choice >'3');
	MenuMain();
	ClearScreen();

}

void MainMenu::SearchMedia()
{
	char Choice;
	do{
		cout<<"******************************************************************"<<endl;
		cout<<"	  Search Media							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"1: Search DVD's"<<endl;
		cout<<"2: Search CD's"<<endl;
		cout<<"3: Back"<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1')
			DVDMenu();
			
		else if (Choice == '2') 
			CDMenu();
			
		else if (Choice == '3')
			MenuMain();
		
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
	
	}while(Choice < '1' || Choice >'3');
	SearchMedia();
}

void MainMenu::DVDMenu()
{
	char Choice, Choice2;
	do{
		cout<<"******************************************************************"<<endl;
		cout<<"	  Search DVD							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"Search by..."<<endl;
		cout<<"1: Title"<<endl;
		cout<<"2: Actor"<<endl;
		cout<<"3: Director"<<endl;
		cout<<"4: Year"<<endl;
		cout<<"5: Genre"<<endl;
		cout<<"6: ID#"<<endl;
		cout<<"7: Back to Previous Menu"<<endl;
		cout<<"8: Back to Main"<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1') 
			Q.SearchDvdName();
		else if (Choice == '2') 
			Q.SearchDvdStar();
		else if (Choice == '3')
			Q.SearchDvdDirector();
		else if (Choice == '4')
			Q.SearchDvdYear();
		else if (Choice == '5')
			Q.SearchDvdGenre();
		else if (Choice == '6')
			Q.SearchDvdID();
		else if (Choice == '7')
			SearchMedia();
		else if (Choice == '8')
			MenuMain();
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}

	
	}while(Choice < '1' || Choice >'6');
	cout<<"1. Borrow DVD"<<endl;
	cout<<"2. Search Again"<<endl;
	cin>>Choice2;
	if (Choice2 =='1')
	{
		Q.BorrowDVD();
		DVDMenu();
		ClearScreen();
	}
	else if (Choice2 =='2')
	{	ClearScreen();
		DVDMenu();

	}
	else
	{
		cout<<"Enter a good choice"<<endl;
		cout<<endl;
	}
	DVDMenu();
}

void MainMenu::CDMenu()
{
	char Choice, Choice2;
	do{

		cout<<"******************************************************************"<<endl;
		cout<<"	  Search CD							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"Search by..."<<endl;
		cout<<"1: Song"<<endl;
		cout<<"2: Artist"<<endl;
		cout<<"3: Label"<<endl;
		cout<<"4: Year"<<endl;
		cout<<"5: Genre"<<endl;
		cout<<"6: ID#"<<endl;
		cout<<"7: Back to Previous Menu"<<endl;
		cout<<"8: Back to Main"<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1')
			Q.SearchCDSong();
		else if (Choice == '2') 
			Q.SearchCDArtist();
		else if (Choice == '3')
			Q.SearchCDLabel();
		else if (Choice == '4')
			Q.SearchCDYear();
		else if (Choice == '5')
			Q.SearchCDGenre();
		else if (Choice == '6')
			Q.SearchCDId();
		else if (Choice == '7')
			SearchMedia();
		else if (Choice == '8')
			MenuMain();
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
	}while(Choice < '1' || Choice >'6');
	cout<<"1. Borrow CD"<<endl;
	cout<<"2. Search Again"<<endl;
	cin>>Choice2;
	if (Choice2 =='1')
	{
		Q.BorrowCD();
		CDMenu();
		ClearScreen();
	}
	else if (Choice2 =='2')
	{	ClearScreen();
		CDMenu();
	}
	else
	{
		cout<<"Enter a good choice"<<endl;
		cout<<endl;
	}
	CDMenu();
}

void MainMenu::AddMedia()
{
	char Choice;

	do{
		cout<<"******************************************************************"<<endl;
		cout<<"	  Add Media							 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"1: Add DVD"<<endl;
		cout<<"2: Add CD"<<endl;
		cout<<"3: Back"<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1')
		{Q.AddDVD();
		}
		else if (Choice == '2') 
		{Q.AddCD();
		}
		else if (Choice == '3')
		{
			AdminMenu();
		}
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
	
	}while(Choice < '1' || Choice >'3');
	AddMedia();
}

void MainMenu::DeleteMedia()
{
char Choice;

	do{
		cout<<"******************************************************************"<<endl;
		cout<<"	Delete Media						 "<<endl;
		cout<<"******************************************************************"<<endl;
		cout<<"1: Delete DVD"<<endl;
		cout<<"2: Delete CD"<<endl;
		cout<<"3: Back"<<endl;
		cout<<"Enter Option: "; cin>>Choice;
		ClearScreen();

		if (Choice == '1')
		{	Q.DeleteDVD();
		}
		else if (Choice == '2') 
		{	Q.DeleteCD();
		}
		else if (Choice == '3')
		{
			AdminMenu();
		}
		else
		{
			cout<<"Enter a good choice"<<endl;
			cout<<endl;
		}
	
	}while(Choice < '1' || Choice >'3');
	DeleteMedia();
}
