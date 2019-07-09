#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <time.h>

#define Max_Data 100
using namespace std;

class Queries
{
private:

	RETCODE rc;
	HENV henv;
    HDBC hdbc;
	HSTMT hstmt;
	char szData[Max_Data];
	
	SDWORD cbData;
	int MemberID;
	
public:
	Queries(void);

	void SignUp();

	string FindLastCDID();
	string FindLastDVDID();
	int FindLastMemberID();
	int Login();
	int AdminLogin();

	void AddDVD();
	void AddCD();
	void DeleteDVD();
	void DeleteCD();

	void SearchDvdName();
	void SearchDvdStar();
	void SearchDvdYear();
	void SearchDvdDirector();
	void SearchDvdGenre();
	void SearchDvdID();

	void SearchCDArtist();
	void SearchCDLabel();
	void SearchCDSong();
	void SearchCDGenre();
	void SearchCDId();
	void SearchCDYear();
	
	void Members();
	void Iborrowed(string uerId);
	void BorrowCD();
	void UpdateCD(string mediaId, int Status);
	void BorrowDVD();
	void UpdateDVD(string mediaId, int Status);
	void CheckInMedia();
	//void ViewBorrowed();
	void ShowBorrowed();
	void DebugUtil();
	void ClearScreen();
	string Date();
	string ReturnDate();

	~Queries(void);
};


