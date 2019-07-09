#include "Queries.h"
#include "prompt.h"
using namespace std;

class MainMenu
{
private:
	Queries Q;

public:
	MainMenu(void);
	~MainMenu(void);
	
	void Greeting();
	void MenuMain();
	void AdminMenu();
	void SearchMedia();
	void DVDMenu();
	void CDMenu();
	void AddMedia();
	void DeleteMedia();
	void BorrowMedia();
	void ClearScreen();

};

