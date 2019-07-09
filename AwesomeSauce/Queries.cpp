#include ".\queries.h"

Queries::Queries(void)
{
	SQLAllocEnv(&henv);
	SQLAllocConnect(henv, &hdbc);
	rc = SQLConnect(hdbc, (SQLCHAR *) "Awesomesauce", SQL_NTS, NULL, 0, NULL, 0);
	
}

Queries::~Queries(void)
{
	
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//DVD SEARCH
////////////////////////////////////////////////////////////////////////////////////////////////////

void Queries::SearchDvdName()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Title;
	cout<<"Enter DVD Title "<<endl;
	cin>>Title;

	ssSQL << "Select Title, Year,  Star, DVDID "
		<< "From kmoore07.DVD "
		<< "Where Title Like '%"<<Title<<"%'"
		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout<<szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout<<szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout<<szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchDvdStar()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Star;
	cout<<"Enter DVD Star "<<endl;
	cin>>Star;

	ssSQL << "Select Star, Title, Year, DVDID "
		<< "From kmoore07.DVD "
		<< "Where Star Like '"<<Star<<"%'"
		<< " Order by Star";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

	SQLFreeStmt(hstmt, SQL_DROP);
}
void Queries::SearchDvdDirector()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Dir;
	cout<<"Enter DVD Director "<<endl;
	cin>>Dir;

	ssSQL << "Select  Title, Year, Director, DVDID "
		<< "From kmoore07.DVD "
		<< "Where Director Like '"<<Dir<<"%'"
		<< " Order by Director";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

	SQLFreeStmt(hstmt, SQL_DROP);
}
void Queries::SearchDvdGenre()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Genre;
	cout<<"Enter DVD Genre "<<endl;
	cin>>Genre;

	ssSQL << "Select Title, Star, Year, Genre, DVDID "
		<< "From kmoore07.DVD "
		<< "Where Genre Like '%"<<Genre<<"%'"
		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

	SQLFreeStmt(hstmt, SQL_DROP);
}

void Queries::SearchDvdYear()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Year;
	cout<<"Enter DVD Year "<<endl;
	cin>>Year;

	ssSQL << "Select Title, Star, Year, Genre, DVDID "
		<< "From kmoore07.DVD "
		<< "Where Year Like '%"<<Year<<"%'"
		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

	SQLFreeStmt(hstmt, SQL_DROP);
}

void Queries::SearchDvdID()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string id;
	cout<<" Enter DVD ID "<<endl;
	cin>>id;

	ssSQL << "Select Title, Star, Year, Genre, DVDID "
		<< "From kmoore07.DVD "
		<< "Where DVDID ='"<<id<<"' "
		<< "Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//CD SEARCH
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queries::SearchCDArtist()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Artist;
	cout<<" Enter CD Artist "<<endl;
	cin>>Artist;

	ssSQL << "Select Artist, Title, Type, CDId "
		<< "From kmoore07.CD "
		<< "Where Artist Like '%"<<Artist<<"%' "
		<< "Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchCDGenre()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string Genre;
	cout<<" Enter CD Genre "<<endl;
	cin>>Genre;

	ssSQL << "Select Artist, Title, Type, CDId "
		<< "From kmoore07.CD "
		<< "Where Type Like '%"<<Genre<<"%' "
		<< "Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchCDId()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string id;
	cout<<" Enter CD ID "<<endl;
	cin>>id;

	ssSQL << "Select Artist, Title, Type, Imprint, CDId "
		<< "From kmoore07.CD "
		<< "Where CDId ='"<<id<<"' ";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchCDYear()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string year;
	cout<<" Enter CD Year "<<endl;
	cin>>year;

	ssSQL << "Select Artist, Title, Type, Year, CDId "
		<< "From kmoore07.CD "
		<< "Where Year Like '%"<<year<<"%'"
		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchCDLabel()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string label;
	cout<<" Enter CD Label"<<endl;
	cin>>label;

	ssSQL << "Select Imprint, Artist, Title, Type, CDId "
		<< "From kmoore07.CD "
		<< "Where Imprint Like '%"<<label<<"%' "
		<< "Order by Imprint";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
void Queries::SearchCDSong()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string song;
	cout<<" Enter CD Song "<<endl;
	cin>>song;

	ssSQL << "Select  Title, Artist, Type, Imprint, CDId "
		<< "From kmoore07.CD "
		<< "Where Title Like '%"<<song<<"%' "
		<< "Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//CD ADD
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queries::AddCD()
{

	stringstream ssSQL;
	string Title, Artist, Imprint, Year, Type, KEY;
	int Status;
	Status = 0;
	KEY = FindLastCDID();
	cout<<"Please do not use spaces!"<<endl;
	cout<<"Enter Song Title: ";
	cin>>Title;

	cout<<"Enter Song Artist: ";
	cin>>Artist;

	cout<<"Enter Record Label: ";
	cin>>Imprint;

	cout<<"Enter Year: ";
	cin>>Year;

	cout<<" Enter Genre"<<endl;
	cout<<"Select from: Rap-R&B, Country, Modern Rock, New Age, Latin, Dance, Adult Contemporary, Christian"<<endl;
	cout<<"or create a new type: ";
	cin>>Type;
	cout<<endl;
	
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "INSERT INTO kmoore07.CD (CDId, Title, Artist, Imprint, Year, Type, CheckOut) "
		<< " VALUES     ('"<<KEY<<"', '"<<Title<<"', '"<<Artist<<"', '"<<Imprint<<"', '"<<Year<<"', '"<<Type<<"','"<<Status<<"') ";
	
	
	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	SQLFreeStmt(hstmt, SQL_DROP);
	



}
///////////////////////////////////////////////////////////////////////////////////////////////////
//DVD ADD
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queries::AddDVD()
{

	stringstream ssSQL;
	string Title, Director, Star, Year, Genre, KEY;
	int Status;
	Status = 0;
	KEY = FindLastDVDID();
	cout<<"Please do not use spaces!"<<endl;
	cout<<"Enter DVD Title: ";
	cin>>Title;

	cout<<"Enter DVD Director: ";
	cin>>Director;
	

	cout<<"Enter DVD's starring actor: ";
	cin>>Star;

	
	cout<<"Enter DVD Year: ";
	cin>>Year;

	
	cout<<"Enter DVD Genre: ";
	cin>>Genre;

	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "INSERT INTO kmoore07.DVD (DVDID, Title, Director, Star, Year, Genre, CheckOut) "
	<< " VALUES ('"<<KEY<<"', '"<<Title<<"', '"<<Director<<"', '"<<Star<<"', "<<Year<<", '"<<Genre<<"','"<<Status<<"') ";


	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	SQLFreeStmt(hstmt, SQL_DROP);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//CD DELETE
////////////////////////////////////////////////////////////////////////////////////////////////////

void Queries::DeleteCD()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string KEY;
	cout<<"Enter the ID number of CD you want to delete: ";
	cin>>KEY;

	ssSQL << "DELETE FROM kmoore07.CD WHERE     (CDId = '"<<KEY<<"') ";
	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);




}
///////////////////////////////////////////////////////////////////////////////////////////////////
//DVD DELETE
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queries::DeleteDVD()
{
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string KEY;
	cout<<"Enter the ID number of DVD you want to delete: ";
	cin>>KEY;

	ssSQL << "DELETE FROM kmoore07.DVD WHERE     (DVDID = '"<<KEY<<"') ";
	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);




}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Primary Key Generators
////////////////////////////////////////////////////////////////////////////////////////////////////

string Queries::FindLastCDID()
{	
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string LastID, temp2;
	char cd[1000];
	int temp;

	ssSQL << "select CDId "
		<< "From kmoore07.CD "
 		<< " Order by CDId";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS){
			LastID = szData;
		}

	}	SQLFreeStmt(hstmt, SQL_DROP);
		cout<<LastID<<endl;

		temp2 = LastID.substr(2,4);
		temp = atoi(temp2.c_str());
		cout<<temp<<endl;
		temp++;
		LastID = "CD0";
		LastID = LastID + _itoa(temp,cd,10);
		return LastID;
			

}

string Queries::FindLastDVDID()
{	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string LastID, temp2;
	char cd[1000];
	int temp,Max;

	ssSQL << "select DVDID "
		<< "From kmoore07.DVD "
 		<< " Order by DVDID";

    Max = 0;
	
	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS){
			LastID = szData;
		}
	}
		temp2 = LastID.substr(3,LastID.length()-1);
		temp = atoi(temp2.c_str());
		if ( temp > Max)
			Max = temp;

		SQLFreeStmt(hstmt, SQL_DROP);
		cout<<LastID<<endl;

		Max++;
		LastID = "DVD";
		LastID = LastID + _itoa(Max,cd,10);
		return LastID;
		
			

}
////////////////////////////////////////////////////////////////////////////
//Member Stuff
////////////////////////////////////////////////////////////////////////////
void Queries::SignUp()
{
	
	stringstream ssSQL;
	string name;
	int KEY;
	KEY = FindLastMemberID();

	cout<<"Please do not use spaces!"<<endl;
	cout<<"Please enter your Name (Last,First): ";
	cin>>name;

	rc=SQLAllocStmt(hdbc, &hstmt);
	
	ssSQL << "INSERT INTO Members (IDNumber, Name, Admin ) "
		<< " VALUES    ('"<<KEY<<"', '"<<name<<"', '0') ";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	SQLFreeStmt(hstmt, SQL_DROP);
	cout<<"Your AwesomeSauce Member ID is: "<<KEY<<endl;
	cout<<"Please do not lose them! "<<endl;
}

int Queries::FindLastMemberID()
{	
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	string LastID;
	int temp;

	ssSQL << "select IdNumber "
		<< "From Members "
 		<< " Order by IdNumber";
	
	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS){
			LastID = szData;
		}

	}	
		temp = atoi(LastID.c_str());
		SQLFreeStmt(hstmt, SQL_DROP);
		temp++;
		return temp;

}

int Queries::Login()
{
	int count;
	string Name;
	count = 1;
	cout<<"Please Enter Your Member ID: "; cin>> MemberID;

	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "select Name "
		<< "From Members "
 		<< " WHERE Idnumber = '"<<MemberID<<"'";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Name = szData;
			count=0;
		}
			
	}
	SQLFreeStmt(hstmt, SQL_DROP);
	ClearScreen();
	if (count==0)
	{
		cout<<"Thank You, "<<Name<<endl;
		return 1;
		
	}
	else
	{

		cout<<"Member ID Not Found. Try Again."<<endl;
		return 0;
	}
	
}

int Queries::AdminLogin()
{
	int count, AdminID;
	string Name;
	count = 1;
	cout<<"Please Enter Your Admin ID: "; cin>> AdminID;

	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "select Name "
		<< "From Members "
 		<< " WHERE (Idnumber = '"<<AdminID<<"') AND (Admin = '1')";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Name = szData;
			count=0;
		}
			
	}
	SQLFreeStmt(hstmt, SQL_DROP);
	ClearScreen();
	if (count==0)
	{
		cout<<"Thank You, "<<Name<<endl;
		return 1;
		
	}
	else
	{

		cout<<"Member ID Not Found. Try Again."<<endl;
		return 0;
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//Output member information
//////////////////////////////////////////////////////////////////////////////////////////////

void Queries::Members()
{


	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "select IdNumber, Name "
		<< "From Members "
 		<< " Order by IdNumber";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);
}
void Queries::BorrowCD()
{ 
	string  mediaID, date, returnDate, Title;
	//string memberID;
	int count;
	count = 0;
	returnDate = ReturnDate();
	
	cout<<"Enter the ID number of CD: ";
	cin>>mediaID;

	//cout<<"Enter your AwesomeSauce membership number: ";
	//cin>>memberID;


	date = Date();


	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "select Title, CDID "
		<< "From kmoore07.CD "
 		<< " where (CheckOut = 0) AND (CDId = '"<<mediaID<<"')";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Title = szData;
			count=0;
		}
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			//cout << szData;
		}
			
	}
	SQLFreeStmt(hstmt, SQL_DROP);

	if (count==0)
	{
		stringstream ssSQL;
		rc=SQLAllocStmt(hdbc, &hstmt);
		ssSQL << "INSERT INTO kmoore07.Borrowed (UserNumber, CDId, DVDId, BorrowedDate, ReturnDate) "
		<< " VALUES ('"<<MemberID<<"', '"<<mediaID<<"', '00000', '"<<date<<"', '"<<returnDate<<"') ";
		

		rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
		SQLFreeStmt(hstmt, SQL_DROP);
	
		UpdateCD(mediaID,1); cout<<"Thank you, you have checked out "<<Title<<endl;
		
	}
	else
	{
		cout<<"This CD has been checked out by an AwesomeSauce Member."<<endl;
		cout<<"Please try a different CD"<<endl;
	}
	
}
void Queries::UpdateCD(string mediaId, int Status)
{
	
		stringstream ssSQL;
		rc=SQLAllocStmt(hdbc, &hstmt);

		if (Status ==1)
		{
			ssSQL << "UPDATE kmoore07.CD "
			<< " SET CheckOut = '1' "
			<< " WHERE CDId = '"<<mediaId<<"'";
		}
		else if (Status ==0)
		{
			ssSQL << "UPDATE kmoore07.CD "
			<< " SET CheckOut = '0' "
			<< " WHERE CDId = '"<<mediaId<<"'";
		}
		

		rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
		SQLFreeStmt(hstmt, SQL_DROP);
		
}

void Queries::BorrowDVD()
{
	string  mediaID, date, returnDate, Title;

	int count;
	count = 1;
	returnDate = ReturnDate();
	
	cout<<"Enter the ID number of DVD: ";
	cin>>mediaID;

	//cout<<"Enter your AwesomeSauce membership number: ";
	//cin>>memberID;

	date = Date();


	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);
	ssSQL << "select Title, DVDID "
		<< "From kmoore07.DVD "
 		<< " WHERE (CheckOut = 0) AND (DVDID = '"<<mediaID<<"')";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			//cout << szData <<" : ";
			Title = szData;
			count=0;
		}
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			//cout << szData;
		}
			
	}
	SQLFreeStmt(hstmt, SQL_DROP);

	if (count==0)
	{
		ClearScreen();
		stringstream ssSQL;
		rc=SQLAllocStmt(hdbc, &hstmt);
		ssSQL << "INSERT INTO kmoore07.Borrowed (UserNumber, CDId, DVDId, BorrowedDate, ReturnDate) "
		<< " VALUES ('"<<MemberID<<"', '00000', '"<<mediaID<<"', '"<<date<<"', '"<<returnDate<<"') ";
		

		rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
		SQLFreeStmt(hstmt, SQL_DROP);
	
		UpdateDVD(mediaID,1);
		cout<<"Thank you, you have checked out "<<Title<<endl;
		
	}
	else
	{
		cout<<"This DVD has been checked out by an AwesomeSauce Member."<<endl;
		cout<<"Please try a different DVD"<<endl;
	}
	
}
void Queries::UpdateDVD(string mediaId,  int Status)
{
		
		stringstream ssSQL;
		rc=SQLAllocStmt(hdbc, &hstmt);
		if (Status==1)
		{
			ssSQL << "UPDATE kmoore07.DVD "
			<< " SET CheckOut = '1' "
			<< " WHERE DVDID = '"<<mediaId<<"'";
		}
		else if(Status==0)
		{
			ssSQL << "UPDATE kmoore07.DVD "
			<< " SET CheckOut = '0' "
			<< " WHERE DVDID = '"<<mediaId<<"'";
		}
		

		rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
		SQLFreeStmt(hstmt, SQL_DROP);
		
}
void Queries::CheckInMedia()
{

	string memberID, mediaID;
	cout<<" Enter your memberID : ";
	cin>>memberID;
	Iborrowed(memberID);

	cout<<"Enter media ID of media your returning: ";
	cin>>mediaID;

		stringstream ssSQL;
		rc=SQLAllocStmt(hdbc, &hstmt);

		ssSQL << "DELETE FROM kmoore07.Borrowed "
		<< " WHERE CDId = '"<<mediaID<<"' OR DVDId = '"<<mediaID<<"'";
	
		rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
		SQLFreeStmt(hstmt, SQL_DROP);

		if(SQL_SUCCESS !=-1)
		{
			if (mediaID.substr(0,2)=="CD")
			{
					UpdateCD(mediaID, 0);
			}
			else
			{
				UpdateDVD(mediaID, 0);
			}
		}
		else
		{
			cout<<"Record Not Found"<<endl;
		}
		cout<<"Thank you, you have checked in: "<<mediaID<<endl;


}
void Queries::ShowBorrowed()
{
	
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);

	ssSQL << "Select * "
		<< "From kmoore07.Borrowed "
		<< "Order by UserNumber";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);


}
void Queries::Iborrowed(string userId)
{
	
	stringstream ssSQL;
	rc=SQLAllocStmt(hdbc, &hstmt);

	ssSQL << "Select * "
		<< "From kmoore07.Borrowed "
		<< "where UserNumber ='"<<userId<<"'";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}
	SQLFreeStmt(hstmt, SQL_DROP);
	cout<<"You currently have the above items checked out."<<endl;


}

void Queries::ClearScreen()
{
	system("cls");
}
/////////////////////////////////////////////////////////////////////////
//Utility Stuff DEBUG
///////////////////////////////////////////////////////////////////////////
void Queries::DebugUtil()
{
		
		SQLCHAR err[255];
		SQLSMALLINT x;
		SQLError(henv, hdbc, hstmt, NULL, NULL, err, 255, &x);
		cout << err << endl;
	
}
string Queries::Date()
{
          char dateStr [9];
          _strdate( dateStr);

		  return dateStr;
}
string Queries::ReturnDate()
{
        char dateStr [9], cd[1000];
		string s_day, s_month, s_year, s_date;
		int day, month, year;
        _strdate( dateStr);

		s_date = dateStr;
		s_day = s_date.substr(3, 2);
		s_month = s_date.substr(0,2);
		s_year = s_date.substr(7, 2);

		day = atoi(s_day.c_str());
		month = atoi(s_month.c_str());
		year = 2000 + atoi(s_year.c_str());

		if ( (day + 7) > 30)
		{
			if ((month+1) > 12)
			{
				month = 1;
				year++;
			}
			else
			{
				month++;
			}
			day = (day+7) - 30;
		}
		else
		{
			day+=7;
		}

		s_day= _itoa(day,cd, 10);
		s_month = _itoa(month,cd, 10);
		s_year = _itoa(year,cd, 10);
		s_date = s_month + "/" + s_day + "/" + s_year;
		
		return s_date;
}



