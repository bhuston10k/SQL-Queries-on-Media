#include ".\queries.h"

Queries::Queries(void)
{
	SQLAllocEnv(&henv);
	SQLAllocConnect(henv, &hdbc);
	rc = SQLConnect(hdbc, (SQLCHAR *) "Awesomesauce", SQL_NTS, NULL, 0, NULL, 0);
	SQLAllocStmt(hdbc, &hstmt);
}

Queries::~Queries(void)
{
	SQLFreeStmt(hstmt, SQL_DROP);
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
}

void Queries::tester()
{
	
	ssSQL << "Select Title, Artist, year "
		<< "From kmoore07.CD "
		<< "Where (Type = 'Country') "
 		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

}

void Queries::tester2()
{
	ssSQL << "Select Title,year "
		<< "From kmoore07.DVD "
		<< " Order by Title";

	rc = SQLExecDirect(hstmt, (SQLCHAR *) ssSQL.str().c_str(), SQL_NTS);
	while (rc == SQL_SUCCESS) {
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout << szData <<" : ";
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

}
void Queries::SearchDvdName()
{
	string Title;
	cout<<"Enter DVD Title "<<endl;
	cin>>Title;

	ssSQL << "Select Title, Year, DVDID, Star "
		<< "From kmoore07.DVD "
		<< "Where Title Like '%"<<Title<<"%'"
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
			cout <<szData;
		cout << endl;
	}

	//Menu.DVDMenu();

}
void Queries::SearchDvdStar()
{
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

	//Menu.DVDMenu();
}
void Queries::SearchDvdDirector()
{
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

	//Menu.DVDMenu();
}
void Queries::SearchDvdGenre()
{
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
			cout <<szData;
		cout << endl;
	}

	//Menu.DVDMenu();
}

void Queries::SearchDvdYear()
{
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
			cout <<szData;
		cout << endl;
	}

	//Menu.DVDMenu();
}

void Queries::SearchDvdID()
{
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
			cout <<szData;
		cout << endl;
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//CD SEARCH
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queries::SearchCDArtist()
{
	string Artist;
	cout<<" Enter CD Artist "<<endl;
	cin>>Artist;

	ssSQL << "Select Artist, Title, Type, Type, CDId "
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
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

}
void Queries::SearchCDGenre()
{
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
		cout << szData <<" : ";
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
			cout <<szData;
		cout << endl;
	}

}
void Queries::SearchCDId()
{
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

}
void Queries::SearchCDYear()
{
	string year;
	cout<<" Enter CD Year "<<endl;
	cin>>year;

	ssSQL << "Select Artist, Title, Type, Imprint, CDId "
		<< "From kmoore07.CD "
		<< "Where Year ='%"<<year<<"'";

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
void Queries::SearchCDLabel()
{
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

}
void Queries::SearchCDSong()
{
	string song;
	cout<<" Enter CD Song "<<endl;
	cin>>song;

	ssSQL << "Select  Title, Artist, Type, Type, CDId "
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

}

void Queries::close()
{
	SQLFreeStmt(hstmt, SQL_DROP);
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
}

