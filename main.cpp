/*
    KADSE201F-056
    KADSE201F-057
    KADSE201F-058
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void checkFiles();
void pharmacyObj();
void switchEmployeeLogin();
void pharmacyLogin();
void deleteRecordAlert();
void warningAlert();
void switchViewDataDoctor();
void deleteLocalAccount();
void switchDoctorLogin();
void switchDoctorAddMedicine();
void switchAddPatientRecord();
void switchClerkLogin();
void switchViewClerk();
void switchViewDoctor();
void switchCreateClerk();
void switchDeleteClerk();
void switchDeleteDoctor();
void switchCreateDoctor();
void switchLocalAdminLogin();
void localAdminView();
void mainMenu();
void invalidInput();

void createAccountLocalAdmin();

class Person
{
protected:
    string firstName;
    string lastName;
    int nic;
    string userName;
    string password;

public:
    Person();

    virtual void viewData(){};
    virtual void createAccount(Person & obj){};
    virtual void deleteAccount(){};
    virtual void login(string,string){};
    virtual void login(){};

    void setFirstName(string);
    void setLastName(string);
    void setNic(int);
    void setUserName(string);
    void setPassword(string);

    string getFirstName();
    string getLastName();
    int getNic();
    string getUserName();
    string getPassword();
};

class LocalAdmin : public Person
{
public:
    void createAccount(LocalAdmin & obj);
    void viewData();
    void deleteAccount(LocalAdmin & obj);
    void login();
};

class CompanyAdmin : public Person
{
private:
    void setUserNameAndPassword();
public:
    CompanyAdmin();
    void viewData();
    void setAccount(CompanyAdmin & obj);
    void login(string,string);
};

class Doctor : public Person
{
private:
    string medicine;
public:
    void login();
    void addPatientData();
    void viewData();
    void createAccount(Doctor & obj);
    void deleteAccount(Doctor & obj);
    void setMedicine(string);
};

class Clerk: public Person
{
public:
    void login();
    void createAccount(Clerk & obj);
    void deleteAccount(Clerk & obj);
    void insertData(Clerk & obj);
    void viewData();
};

class Patient: public Person
{
private:
    static int tokenNum;
public:

    Patient();
    void insertData();
    void viewDataDoctor();


};

class Employee : public Person
{
private:
    void setUserName()
    {
        userName = "username";
    }
    void setPassword()
    {
        password = "password";
    }

public:
    string getUserName()
    {
        return userName;
    }
    string getPassword()
    {
        return password;
    }

    void login()
    {
        string user_Username, user_password;

        cout << "Enter user name : "; cin >> user_Username;
        cout << "Enter password  : "; cin >> user_password;

        if(user_Username == "username" && user_password == "password")
        {
           pharmacyObj();
        }
        else
        {
            cout << "invalid username or password" << endl;
            mainMenu();
        }


    }

};


// pharmacy --- safras




class Pharmacy
{
	private:

	int patientId;
    string date;
    string med;
    string sta;
    float amo;
    float totAmo;
    int quantity;

   	int readId;
	string readDate;

	void makePayment();
	void viewPatRecord();


	public:

	char res;

	void welcome()
	{
		cout<<"\n\t*****************************************\t";
		cout<<"\n\t\t---ROYAL PHARMACY---";
		cout<<"\n\t*****************************************\t";
		//getch();
		system("cls");
	}
	void title()
	{
		int t;
		do
		{
			system("cls");

			cout<<"\n\n\n\n\t\t************\n";
			cout<<"\t\tSELECT TITLE\n";
			cout<<"\t\t************\n\n\n";

			cout<<"\t\tPress 1 |VIEW PATIENT MEDICINE & MAKE PAYMENT\n\t";
			cout<<"\tPress 2 |VIEW PATIENT BILL LIST\n\t";
			cout<<"\tPress 3 |EXITE\n\n\t\t";

			cin>>t;

			switch(t)
			{

				case 1:
					{

						makePayment();
						break;
					}
				case 2:
					{

						viewPatRecord();
						break;
					}
				case 3:
					{
		  				system("cls");
						//cout<<"\n\t\tTHANK YOU"<<endl;
						break;
					}
				default:
					{
						system("cls");
						cout<<"\n\n\t\tINVALID INPUT...";
						//getch();
					}
			}
		}while(t!=3);
	}
};

void Pharmacy::makePayment()
{

		char choice;


		cout<<endl;
		for(int c=0;c<45;c++){cout<<"-";}
		cout<<endl;
		cout<<"MEDICINE NAME\t\t"<<"MEDICINE PRICE(LKR)"<<endl;
		for(int c=0;c<45;c++){cout<<"-";}
		cout<<endl;
  		cout<<"Paracetamol       "<<"\t"<<"LKR  15.00"<<endl;
    	cout<<"Insulin           "<<"\t"<<"LKR 160.00"<<endl;
     	cout<<"Moxifloxacin      "<<"\t"<<"LKR 400.00"<<endl;
      	cout<<"Amoxicillin 250MG "<<"\t"<<"LKR 6.50"<<endl;
       	cout<<"Marino Tablet     "<<"\t"<<"LKR 10.00"<<endl;
        cout<<"Doxycycline Capsule1"<<"\t"<<"LKR 5.00"<<endl;
        cout<<"Amino Zinc Tablet "<<"\t"<<"LKR 8.75"<<endl;
        cout<<"Gefitinib Pack-1  "<<"\t"<<"LKR 397.68"<<endl;
        cout<<"Mebendazole 100MG "<<"\t"<<"LKR 30.00"<<endl;
        cout<<"Ofloxacian        "<<"\t"<<"LKR 174.25"<<endl;
		for(int c=0;c<45;c++){cout<<"-";}
		cout<<endl;
		cout<<endl;


		cout<<"\n\t\tEnter Patient Id : ";
    	cin>>readId;

    	cout<<"\n\t\tEnter Date :";
    	cin>>readDate;

    	ifstream read("Medicine.txt",::ios::in);

    	 while(!read.eof())
		 {

 			     read>>patientId;
				 read>>date;
			   	 read>>med;


		 	if((readId==patientId)&&(readDate==date))
 	        {

				 cout<<endl;
    			 for(int d=0;d<60;d++){cout<<"-";}
    			 cout<<endl;
    			 cout<<"PatientId\t"<<"Date\t\t"<<"Medicine"<<endl;
    			 for(int c=0;c<60;c++){cout<<"-";}
    			 cout<<endl;
				 cout<<readId<<"\t\t"<<date<<"\t"<<med<<endl;
				 for(int c=0;c<60;c++){cout<<"-";}
				 cout<<endl;

				 cout<<"\n\t\tEnter 1-Medicine Amount :";
				 cin>>amo;
				 cout<<"\n\t\tEnter Quantity :";
				 cin>>quantity;
			 	 cout<<"\n\t\tEnter Payment Y/N(Y-Paid||N-Not Paid) :";
    		   	 cin>>choice;



				 if(choice=='y')
				 {
		     		ofstream write("Record.txt",ios::app);
	 				totAmo=amo*quantity;

					write <<patientId;
					write <<"     ";
					write <<date;
					write <<"     ";
					write <<med;
					write <<"     ";
					write <<totAmo;
					write <<"     ";
					write <<sta<<" Paid "<<endl;
					write.close();

					cout<<"\n\t\tPAYMENT SUCCESS...(BILL HAS SAVED TO PATIENT RECORD)"<<endl;

				  }
				  else if(choice=='n')
				  {
	 				ofstream write("Record.txt",ios::app);
	 				totAmo=amo*quantity;

					write <<patientId;
					write <<"     ";
					write <<date;
					write <<"     ";
					write <<med;
					write <<"     ";
					write <<totAmo;
					write <<"     ";
					write <<sta<<" Not Paid "<<endl;
					write.close();

					cout<<"\n\t\tPAYMENT NOT COMPLETED...(BILL HAS DRAFTED TO PATIENT RECORD)"<<endl;
				  }
				  else
				  {
				 	break;
				  }
		    }
		    else
		    {
		    	continue;
			}
		 }
		 read.close();
		 system("PAUSE");

}

void Pharmacy::viewPatRecord()
{

	cout<<"\n\t\tEnter Patient Id : ";
    cin>>readId;

	ifstream read("Record.txt",ios::in);

	cout<<endl;
    for(int d=0;d<80;d++){cout<<"-";}
    cout<<endl;
    cout<<"PatientId\t"<<"Date\t\t"<<"Medicine"<<"\t"<<"TotalAmount\t"<<"\tStatus"<<endl;
    for(int c=0;c<80;c++){cout<<"-";}
    cout<<endl;


	read>>patientId;
	read>>date;
	read>>med;
	read>>totAmo;
	read.get();
	getline(read,sta);

	while(!read.eof())
	{


		if(readId==patientId)

		cout<<readId<<"\t\t"<<date<<"\t"<<med<<"\t\t"<<totAmo<<"\t\t   "<<sta<<endl;

			read>>patientId;
			read>>date;
			read>>med;
			read>>totAmo;
			read.get();
			getline(read,sta);

	}
 	for(int c=0;c<80;c++){cout<<"-";}
    cout<<endl;
	read.close();
	system("PAUSE");

}





// pharmacy --- safras

void Patient::viewDataDoctor()
{
    int patientId;
    string date;
    string medicine;

    int readPatientId;

    cout << "Enter Patient Id Here : ";
    cin >> readPatientId;

    ifstream readPatient ("Medicine.txt",::ios::in);

    cout << endl;
    for(int drawValue = 0; drawValue < 50; drawValue++){cout << "=";}
    cout << endl;
    cout << "Patient Id\t" << "Date\t\t" << "medicine" << endl;
    for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
    cout << endl;

    while(readPatient)
    {
        readPatient >> patientId;
        readPatient >> date;
        readPatient >> medicine;

        if(readPatientId  == patientId)
       {

            cout << readPatientId << "\t\t" << date << "\t" << medicine << endl;
            continue;
        }
        else
        {
            continue;
        }

        cout << "All Records That Related to " << patientId << " Has Printed" << endl;
    }

    for(int drawValue = 0; drawValue < 50; drawValue++){cout << "=";}
    cout << endl;
    cout << "Patient Id\t" << "Date\t\t" << "medicine" << endl;
    for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
    cout << endl;

    readPatient.close();
}

void Doctor::addPatientData()
{
    int getId;
    string getDate;
    string setMedicine;

    int readId;
    int readToken;
    string readDate;


    bool isCorrect = false;

    cout << "Enter Patient Id Here : ";
    cin >> getId;
    cout << "Enter date Here : ";
    cin >> getDate;


    ifstream read ("PatientRelation.txt",ios::in);


    while(read)
    {
        read >> readId;
        read >> readToken;
        read >> readDate;

        if(readId == getId && readDate == getDate)
        {
            isCorrect = true;
            break;
        }
        else
        {
            isCorrect = false;
            continue;
        }

    }
    read.close();


    if(isCorrect == true)
    {
        cout << "ENTER THE RECOMMENDED MEDICINE >";
        cout << "ENTER X FOR EXIT" << endl;
        while(1)
        {
            cout << "DOCTOR\ADD MEDICINE\SAVEFILE> ";
            cin >> setMedicine;

            if(setMedicine == "X" || setMedicine == "x")
            {
                for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
                cout << endl;
                cout << "\n\tRECORD HAS ADDED TO DATABASE SUCCESSFUL***" << endl << endl;
                for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
                cout << endl;
                break;
            }
            else
            {
                ofstream write ("Medicine.txt",ios::app);

                write << readId;
                write << ' ';
                write << readDate;
                write << ' ';
                write << setMedicine;
                write << endl;

                continue;

                write.close();
            }
        }
    }
    else if (isCorrect == false)
    {
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;
        cout << "\n\tFOLLOWING PATIENT RECORD DOES NOT EXIST!" << endl << endl;
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;
    }

}

void Doctor::setMedicine(string value)
{
    medicine = value;
}

Patient::Patient()
{
    tokenNum++;
}

int Patient::tokenNum;

void Patient::insertData()
{
    string getFirstName;
    string getLastName;
    int getNic;
    string tp;
    string date;

    string checkFirstName;
    string checkLastName;
    int checkNic;
    string checkTp;

    bool isCheck = false;

    cout << "First Name : ";
    cin >> getFirstName;
    cout << "Last Name  : ";
    cin >> getLastName;
    cout << "NIC        : ";
    cin >> getNic;
    cout << "TP Number Here : ";
    cin >> tp;
    cout << "Date Here  : ";
    cin >> date;

    cout << endl;

    ifstream readFile ("PatientData.txt",ios::in);

    while(readFile)
    {
        readFile >> checkFirstName;
        readFile >> checkLastName;
        readFile >> checkNic;
        readFile >> checkTp;

        if(getNic == checkNic)
        {
            isCheck = true;

            ofstream write ("PatientRelation.txt",ios::app);

                write << getNic;
                write << ' ';
                write << tokenNum;
                write << ' ';
                write << date;
                write << ' ';
                write << tp << endl;

            write.close();


            break;
        }
        else
        {
            isCheck = false;
        }
    }

    if(isCheck == false)
    {
        ofstream writeData ("PatientData.txt",ios::app);

        writeData << getFirstName;
        writeData << ' ';
        writeData << getLastName;
        writeData << ' ';
        writeData << getNic;
        writeData << ' ';
        writeData << tp;
        writeData << endl;

        cout << endl;
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;
        cout << "\n\tRECORD HAS ADDED TO DATABASE SUCCESSFUL***" << endl << endl;
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;


        writeData.close();

        ofstream write ("PatientRelation.txt",ios::app);

        write << getNic;
        write << ' ';
        write << tokenNum;
        write << ' ';
        write << date;
        write << endl;

        write.close();

    }
    else
    {
        cout << "\t----TRY AGAIN----" << endl;
        insertData();
    }

    readFile.close();


}

void Clerk::login()
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string loginFirstName;
    string loginLastName;
    int loginNic;
    string loginUserName;
    string loginPassword;

    string inputUserName;
    string inputPassword;

    bool isGateOne;
    bool isGateTwo;

    int selectMenu;
    bool isInvalid = false;

    cout << "ENTER NAME HERE     : ";
    cin >> inputUserName;

    cout << "ENTER PASSWORD HERE : ";
    cin >> inputPassword;

    ifstream read ("Clerk.txt",ios::in);

    while(read)
    {
        read >> loginFirstName;
        read >> loginLastName;
        read >> loginNic;
        read >> loginUserName;
        read >> loginPassword;

        if(inputUserName == loginUserName && inputPassword == loginPassword)
        {
            isGateOne = true;
            break;
        }
        else
        {
            isGateOne = false;
            isInvalid = true;
            continue;
        }

    }

    if(isGateOne == true)
    {
        ifstream readDelete ("DeleteClerk.txt",ios::in);

        while(readDelete)
        {
            readDelete >> tempFirstName;
            readDelete >> tempLastName;
            readDelete >> tempNic;
            readDelete >> tempUserName;
            readDelete >> tempPassword;

            if(inputUserName == tempUserName)
            {
                isGateTwo = false;
                cout << "RECORD HAS DELETED!" << endl;
                break;
            }
            else
            {
                isGateTwo = true;
                continue;
            }

        }


        if(isGateOne == true && isGateTwo == true)
        {
            cout << "\n\t-----LOGIN SUCCESSFUL-----" << endl;

            while(1)
                        {
                            cout << "\n\t[1]   - Add New Record" <<endl;
                            cout << "\t[0]   - Main Menu " << endl;
                            cout << "\t[99]  - Exit" << endl << endl;

                            cout << "Select Menu > ";
                            cin >> selectMenu;

                            if(selectMenu == 1  ||  selectMenu == 0 || selectMenu == 99)
                            {
                                    switch (selectMenu)
                                {
                                case 1:
                                    switchAddPatientRecord();
                                    break;
                                case 0:
                                    mainMenu();
                                    break;
                                case 99:
                                    exit(1);
                                    break;
                                }
                            }
                            else
                            {
                                cout << "Invalid Input " << endl;
                                continue;
                            }
                            }


        }


        else
        {

            deleteRecordAlert();

         cout << "DO YOU WANT TO LOG IN DIFFERENT ACCOUNT" << endl;
         cout << "\t[0] - YES\t[1] - NO" << endl << endl;

         cout << "SELECT Y/N > ";
         cin >> selectMenu;
         switch (selectMenu)
         {
         case 0:
            Clerk::login();
            break;
         case 1:
            mainMenu();
            break;
         }

        readDelete.close();

    }

    }

    if (isInvalid == true)
    {
        warningAlert();
    }

    read.close();

}

void Doctor::login()
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string loginFirstName;
    string loginLastName;
    int loginNic;
    string loginUserName;
    string loginPassword;

    string inputUserName;
    string inputPassword;

    bool isGateOne;
    bool isGateTwo;
    bool isInvalid = false;

    int selectMenu;

    cout << "Enter User Name  Here : ";
    cin >> inputUserName;

    cout << "Enter Password Here   : ";
    cin >> inputPassword;

    ifstream read ("Doctor.txt",ios::in);

    while(read)
    {
        read >> loginFirstName;
        read >> loginLastName;
        read >> loginNic;
        read >> loginUserName;
        read >> loginPassword;

        if(inputUserName == loginUserName && inputPassword == loginPassword)
        {
            isGateOne = true;
            break;
        }

        else
        {
            isGateOne = false;
            isInvalid = true;
            continue;
        }

    }

    if(isGateOne == true)
    {
        ifstream readDelete ("DeleteDoctor.txt",ios::in);

        while(readDelete)
        {
            readDelete >> tempFirstName;
            readDelete >> tempLastName;
            readDelete >> tempNic;
            readDelete >> tempUserName;
            readDelete >> tempPassword;

            if(inputUserName == tempUserName)
            {
                isGateTwo = false;
                cout << "RECORD HAS DELETED!" << endl;
                break;
            }
            else
            {
                isGateTwo = true;
                continue;
            }

        }


        if(isGateOne == true && isGateTwo == true)
        {
            cout << "\n\t-----LOGIN SUCCESSFUL-----" << endl << endl;

            while(1)
                        {
                            cout << "\n\t[1]  - ADD PATIENT MEDICINE" <<endl;
                            cout << "\t[2]  - VIEW PATIENT DATA"<< endl;
                            cout << "\t[0]  - MAIN MENU "<< endl;
                            cout << "\t[99] - EXIT" << endl << endl;

                            cout << "Select Menu > ";
                            cin >> selectMenu;

                            if(selectMenu == 1 || selectMenu == 2 ||  selectMenu == 0 || selectMenu == 99)
                            {
                                    switch (selectMenu)
                                {
                                case 1:
                                    switchDoctorAddMedicine();
                                    break;
                                case 2:
                                    switchViewDataDoctor();
                                    break;
                                case 0:
                                    mainMenu();
                                    break;
                                case 99:
                                    exit(1);
                                    break;
                                }
                            }
                            else
                            {
                                cout << "INVALID INPUT" << endl;
                                continue;
                            }
                            }


        }


        else
        {
            deleteRecordAlert();

         cout << "DO YOU WANT TO LOG IN DIFFERENT ACCOUNT" << endl << endl;
         cout << "\t[0] - YES\t[1] - NO" << endl << endl;

         cout << "SELECT Y/N > ";
         cin >> selectMenu;
         switch (selectMenu)
         {
         case 0:
            Doctor::login();
            break;
         case 1:
            mainMenu();
            break;
         }

        readDelete.close();

    }

    }
    if(isInvalid == true)
    {
        warningAlert();
    }

    read.close();


}

void Doctor::viewData()
{
    string readFirstName;
    string readLastName;
    int readNic;
    string readUserName;
    string readPassword;

    cout << endl;
    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;
    cout << "FIRST NAME\t\tLAST NAME\t\t\tNIC\t\t\t\t\tUSER NAME\t\tPASSWORD" << endl;
    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl << endl;

    ifstream readFile ("Doctor.txt",ios::in);

    if(readFile.is_open())
    {
        while(readFile)
        {
            readFile >> readFirstName;
            readFile >> readLastName;
            readFile >> readNic;
            readFile >> readUserName;
            readFile >> readPassword;


            cout << readFirstName << "\t\t\t" << readLastName << "\t\t\t\t" << readNic << "\t\t\t" << readUserName << "\t\t" << readPassword;
            cout << endl;

    }


    }
    else
    {
        cout << "FILE IS MISSING" << endl;
    }

    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;
    cout << "FIRST NAME\t\tLAST NAME\t\tNIC\t\tUSER NAME\t\tPASSWORD" << endl;
    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl << endl;

    readFile.close();
}

void Clerk::createAccount(Clerk &clerk1)
{
     string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string checkFirstName;
    string checkLastName;
    int checkNic;
    string checkUserName;
    string checkPassword;

    cout << "Enter First Name Here : ";
    cin >> tempFirstName;
    cout << "Enter Last Name Here  : ";
    cin >> tempLastName;
    cout << "Enter NIC Here        : ";
    cin >> tempNic;
    cout << "Enter User Name Here  : ";
    cin >> tempUserName;
    cout << "Enter Password Here   : ";
    cin >> tempPassword;

    ifstream checkSameUserName ("Clerk.txt",ios::in);

    while(checkSameUserName)
    {
        checkSameUserName >> checkFirstName;
        checkSameUserName >> checkLastName;
        checkSameUserName >> checkNic;
        checkSameUserName >> checkUserName;
        checkSameUserName >> checkPassword;

        if(tempUserName == checkUserName)
        {
            cout << "Cant Add " << tempUserName << endl;
            cout << "Already Taken" << endl;
            while(1)
            {
                cout << "Enter New User Name : ";
                cin >> tempUserName;
                if(tempUserName == checkUserName)
                {
                    continue;
                    cout << "Already Used Try Again" << endl;
                }
                else
                {
                    cout << "User Name : " << tempUserName << " Has Added" << endl;
                    break;
                }
            }
        }

    }

    checkSameUserName.close();

    Person *writeFilePerson1 = &clerk1;
    writeFilePerson1->setFirstName(tempFirstName);
    writeFilePerson1->setLastName(tempLastName);
    writeFilePerson1->setNic(tempNic);
    writeFilePerson1->setUserName(tempUserName);
    writeFilePerson1->setPassword(tempPassword);

    ofstream writeFile ("Clerk.txt",ios::app);
    if(writeFile.is_open())
    {
        writeFile << clerk1.firstName;
        writeFile << ' ';
        writeFile << clerk1.lastName;
        writeFile << ' ';
        writeFile << clerk1.nic;
        writeFile << ' ';
        writeFile << clerk1.userName;
        writeFile << ' ';
        writeFile << clerk1.password;
        writeFile << endl;
    }
    writeFile.close();
}

void Clerk::deleteAccount(Clerk &deleteClerk)
{
    string deleteFirstName;
    string deleteLastName;
    int deleteNic;
    string deleteUserName;
    string deletePassword;

    string getUserName;
    bool isDelete = false;

    Person *ptrDeleteNow = &deleteClerk;
    deleteClerk.viewData();

    cout << "Enter delete user name : ";
    cin >> getUserName;

    ifstream readData ("Clerk.txt",ios::in);

    while(readData)
    {
        readData >> deleteFirstName;
        readData >> deleteLastName;
        readData >> deleteNic;
        readData >> deleteUserName;
        readData >> deletePassword;

        if(getUserName == deleteUserName)
        {
            isDelete = true;

            ofstream deleteWrite ("DeleteClerk.txt",ios::app);

            deleteWrite << deleteFirstName;
            deleteWrite << ' ';
            deleteWrite << deleteLastName;
            deleteWrite << ' ';
            deleteWrite << deleteNic;
            deleteWrite << ' ';
            deleteWrite << deleteUserName;
            deleteWrite << ' ';
            deleteWrite << deletePassword;
            deleteWrite << endl;

            cout << "DELETED ADMIN RECORD HAS ADDED" << endl;
            break;
            deleteWrite.close();
        }
        else
        {
            continue;
        }
    }
    if (isDelete == true)
    {
        cout << "[0] - Main Menu" << endl;
        cout << "[99] - Exit" << endl;

        int menu;

        while(1)
        {
            cout << "> ";
            cin >> menu;
            if(menu == 0 || menu == 99)
            {
                switch (menu)
                {
                case 0:
                    break;
                case 99:
                    exit(1);
                }
            }
            else
            {
                cout << "Input is incorrect try again" << endl;
                continue;
            }
        }
    }
    else
    {
        cout << getUserName << " DOES NOT EXIST" << endl;

        cout << "[1] - Try Again" << endl;
        cout << "[2] - Main Menu" << endl;
        cout << "[3] - Exit" << endl;

        int quickMenu;

        while(1)
        {
            cout << "> ";
            cin >> quickMenu;
            if(quickMenu == 1 || quickMenu == 2 || quickMenu == 3)
            {
                switch (quickMenu)
                {
                case 1:
                    deleteAccount(deleteClerk);
                    break;
                case 2:
                    break;
                case 3:
                    exit(1);
                }
            }
            else
            {
                cout << "Input is incorrect try again" << endl;
                continue;
            }
        }


    }



    readData.close();
}

void Doctor::deleteAccount(Doctor &deleteDoctor)
{
    string deleteFirstName;
    string deleteLastName;
    int deleteNic;
    string deleteUserName;
    string deletePassword;

    string getUserName;
    bool isDelete = false;

    Person *ptrDeleteNow = &deleteDoctor;
    deleteDoctor.viewData();

    cout << "ENTER DELETE USER NAME : ";
    cin >> getUserName;

    ifstream readData ("Doctor.txt",ios::in);

    while(readData)
    {
        readData >> deleteFirstName;
        readData >> deleteLastName;
        readData >> deleteNic;
        readData >> deleteUserName;
        readData >> deletePassword;

        if(getUserName == deleteUserName)
        {
            isDelete = true;

            ofstream deleteWrite ("DeleteDoctor.txt",ios::app);

            deleteWrite << deleteFirstName;
            deleteWrite << ' ';
            deleteWrite << deleteLastName;
            deleteWrite << ' ';
            deleteWrite << deleteNic;
            deleteWrite << ' ';
            deleteWrite << deleteUserName;
            deleteWrite << ' ';
            deleteWrite << deletePassword;
            deleteWrite << endl;

            cout << "==============================" << endl;
            cout << "DELETED ADMIN RECORD HAS ADDED" << endl;
            cout << "==============================" << endl;
            break;
            deleteWrite.close();
        }
        else
        {
            continue;
        }
    }
    if (isDelete == true)
    {
        cout << "[0]  - MAIN MENU" << endl;
        cout << "[99] - EXIT" << endl;

        int menu;

        while(1)
        {
            cout << "> ";
            cin >> menu;
            if(menu == 0 || menu == 99)
            {
                switch (menu)
                {
                case 0:
                    break;
                case 99:
                    exit(1);
                }
            }
            else
            {
                cout << "INPUT IS INCORRECT TRY AGAIN" << endl;
                continue;
            }
        }
    }
    else
    {
        cout << getUserName << " DOES NOT EXIST" << endl;

        cout << "[1] - TRY AGAIN" << endl;
        cout << "[2] - MAIN MENU" << endl;
        cout << "[3] - EXIT" << endl;

        int quickMenu;

        while(1)
        {
            cout << "> ";
            cin >> quickMenu;
            if(quickMenu == 1 || quickMenu == 2 || quickMenu == 3)
            {
                switch (quickMenu)
                {
                case 1:
                    deleteAccount(deleteDoctor);
                    break;
                case 2:
                    break;
                case 3:
                    exit(1);
                }
            }
            else
            {
                cout << "INPUT IS INCORRECT TRY AGAIN" << endl;
                continue;
            }
        }


    }



    readData.close();
}

void Doctor::createAccount(Doctor & doctor1)
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string checkFirstName;
    string checkLastName;
    int checkNic;
    string checkUserName;
    string checkPassword;

    cout << "ENTER FIRST NAME HERE : ";
    cin >> tempFirstName;
    cout << "ENTER LAST NAME HERE  : ";
    cin >> tempLastName;
    cout << "ENTER NIC HERE        : ";
    cin >> tempNic;
    cout << "ENTER USER NAME HERE  : ";
    cin >> tempUserName;
    cout << "ENTER PASSWORD HERE   : ";
    cin >> tempPassword;

    ifstream checkSameUserName ("Doctor.txt",ios::in);

    while(checkSameUserName)
    {
        checkSameUserName >> checkFirstName;
        checkSameUserName >> checkLastName;
        checkSameUserName >> checkNic;
        checkSameUserName >> checkUserName;
        checkSameUserName >> checkPassword;

        if(tempUserName == checkUserName)
        {
            cout << "CANT USE " << tempUserName << endl;
            cout << "ALREADY TAKEN" << endl;
            while(1)
            {
                cout << "ENTER NEW USER NAME : ";
                cin >> tempUserName;
                if(tempUserName == checkUserName)
                {
                    continue;
                    cout << "ALREADY USE TRY AGAIN" << endl;
                }
                else
                {
                    cout << "\nUSE NAME " << tempUserName << " HAS ADDED" << endl << endl;
                    break;
                }
            }
        }

    }

    checkSameUserName.close();

    Person *writeFilePerson1 = &doctor1;
    writeFilePerson1->setFirstName(tempFirstName);
    writeFilePerson1->setLastName(tempLastName);
    writeFilePerson1->setNic(tempNic);
    writeFilePerson1->setUserName(tempUserName);
    writeFilePerson1->setPassword(tempPassword);

    ofstream writeFile ("Doctor.txt",ios::app);
    if(writeFile.is_open())
    {
        writeFile << doctor1.firstName;
        writeFile << ' ';
        writeFile << doctor1.lastName;
        writeFile << ' ';
        writeFile << doctor1.nic;
        writeFile << ' ';
        writeFile << doctor1.userName;
        writeFile << ' ';
        writeFile << doctor1.password;
        writeFile << endl;

        cout << endl;
        for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;
        cout << "FIRST NAME\t\tLAST NAME\t\tNIC\t\tUSER NAME\t\tPASSWORD" << endl;
        for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl << endl;
        cout << doctor1.firstName << "\t\t\t" << doctor1.lastName << "\t\t\t\t" << doctor1.nic << "\t\t" << doctor1.userName << "\t\t" << doctor1.password;
        cout << endl;
        for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;


        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << "\n\tRECORD HAS ADDED TO THE DATABASE!*****" << endl;
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl << endl << endl;

    }





    writeFile.close();
}

CompanyAdmin::CompanyAdmin()
{
    setUserNameAndPassword();
}

void CompanyAdmin::viewData()
{

}

void CompanyAdmin::setUserNameAndPassword()
{
    userName = "root";
    password = "toor";
}

void LocalAdmin::createAccount(LocalAdmin & admin1)
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string checkFirstName;
    string checkLastName;
    int checkNic;
    string checkUserName;
    string checkPassword;

    cout << "ENTER FIRST NAME HERE : ";
    cin >> tempFirstName;
    cout << "ENTER LAST NAME HERE  : ";
    cin >> tempLastName;
    cout << "ENTER NIC HERE        : ";
    cin >> tempNic;
    cout << "ENTER USER NAME HERE  : ";
    cin >> tempUserName;
    cout << "ENTER PASSWORD HERE   : ";
    cin >> tempPassword;

    ifstream checkSameUserName ("LocalAdmin.txt",ios::in);

    while(checkSameUserName)
    {
        checkSameUserName >> checkFirstName;
        checkSameUserName >> checkLastName;
        checkSameUserName >> checkNic;
        checkSameUserName >> checkUserName;
        checkSameUserName >> checkPassword;

        if(tempUserName == checkUserName)
        {
            warningAlert();
            cout << "CANT ADD " << tempUserName << endl;
            cout << "ALREADY TAKEN" << endl;
            while(1)
            {
                cout << "Enter New User Name : ";
                cin >> tempUserName;
                if(tempUserName == checkUserName)
                {
                    continue;
                    cout << "ALREADY USED TRY AGAIN" << endl;
                }
                else
                {
                    cout << "USER NAME " << tempUserName << " HAS ADDED" << endl;
                    break;
                }
            }
        }

    }

    checkSameUserName.close();

    Person *writeFilePerson1 = &admin1;
    writeFilePerson1->setFirstName(tempFirstName);
    writeFilePerson1->setLastName(tempLastName);
    writeFilePerson1->setNic(tempNic);
    writeFilePerson1->setUserName(tempUserName);
    writeFilePerson1->setPassword(tempPassword);

    ofstream writeFile ("LocalAdmin.txt",ios::app);
    if(writeFile.is_open())
    {
        writeFile << admin1.firstName;
        writeFile << ' ';
        writeFile << admin1.lastName;
        writeFile << ' ';
        writeFile << admin1.nic;
        writeFile << ' ';
        writeFile << admin1.userName;
        writeFile << ' ';
        writeFile << admin1.password;
        writeFile << endl;
    }
    writeFile.close();
}

void LocalAdmin::deleteAccount(LocalAdmin & deleteAdminNow)
{
    string deleteFirstName;
    string deleteLastName;
    int deleteNic;
    string deleteUserName;
    string deletePassword;

    string getUserName;

    bool isCheck = false;

    Person *ptrDeleteNow = &deleteAdminNow;
    deleteAdminNow.viewData();

    cout << "ENTER DELETE USER NAME : ";
    cin >> getUserName;

    ifstream readData ("LocalAdmin.txt",ios::in);

    while(readData)
    {
        readData >> deleteFirstName;
        readData >> deleteLastName;
        readData >> deleteNic;
        readData >> deleteUserName;
        readData >> deletePassword;

        if(getUserName == deleteUserName)
        {
            ofstream deleteWrite ("RejectAdmin.txt",ios::app);

            deleteWrite << deleteFirstName;
            deleteWrite << ' ';
            deleteWrite << deleteLastName;
            deleteWrite << ' ';
            deleteWrite << deleteNic;
            deleteWrite << ' ';
            deleteWrite << deleteUserName;
            deleteWrite << ' ';
            deleteWrite << deletePassword;
            deleteWrite << endl;

            cout << "DELETED ADMIN RECORD HAS ADDED" << endl;
            deleteWrite.close();
            isCheck = true;
            break;

        }
        else
        {
            continue;
            isCheck = false;
        }
    }

    if(isCheck == false)
    {
        cout << getUserName << " DOES NOT EXIST" << endl;
    }



    cout << "[1] - TRY AGAIN" << endl;
    cout << "[2] - MAIN MENU" << endl;
    cout << "[3] - EXIT" << endl;

    int quickMenu;

    while(1)
    {
        cout << "> ";
        cin >> quickMenu;
        if(quickMenu == 1 || quickMenu == 2 || quickMenu == 3)
        {
            switch (quickMenu)
            {
            case 1:
                deleteLocalAccount();
                break;
            case 2:
                mainMenu();
                break;
            case 3:
                exit(1);
            }
        }
        else
        {
            cout << "INPUT IS INCORRECT TRY AGAIN" << endl;
            continue;
        }
    }

    readData.close();
}

void LocalAdmin::login()
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    string loginFirstName;
    string loginLastName;
    int loginNic;
    string loginUserName;
    string loginPassword;

    string inputUserName;
    string inputPassword;

    bool isGateOne;
    bool isGateTwo;
    bool isInvalid = false;

    int selectMenu;

    cout << "ENTER USER NAME HERE : ";
    cin >> inputUserName;

    cout << "ENTER PASSWORD HERE  : ";
    cin >> inputPassword;

    ifstream read ("LocalAdmin.txt",ios::in);

    while(read)
    {
        read >> loginFirstName;
        read >> loginLastName;
        read >> loginNic;
        read >> loginUserName;
        read >> loginPassword;

        if(inputUserName == loginUserName && inputPassword == loginPassword)
        {
            isGateOne = true;
            break;
        }
        else
        {
            isGateOne = false;
            isInvalid = true;
            continue;
        }

    }

    if(isGateOne == true)
    {
        ifstream readDelete ("RejectAdmin.txt",ios::in);

        while(readDelete)
        {
            readDelete >> tempFirstName;
            readDelete >> tempLastName;
            readDelete >> tempNic;
            readDelete >> tempUserName;
            readDelete >> tempPassword;

            if(inputUserName == tempUserName)
            {
                isGateTwo = false;
                break;
            }
            else
            {
                isGateTwo = true;
                continue;
            }

        }


        if(isGateOne == true && isGateTwo == true)
        {
            cout << "\n\t-----LOGIN SUCCESSFUL-----" << endl;

            while(1)
                        {
                            cout << "\t[1]  - ADD DOCTOR" <<endl;
                            cout << "\t[2]  - DELETE DOCTOR"<< endl;
                            cout << "\t[3]  - ADD CLERK" << endl;
                            cout << "\t[4]  - DELETE CLERK" << endl;
                            cout << "\t[5]  - VIEW DOCTOR" << endl;
                            cout << "\t[6]  - VIEW CLERK" << endl;
                            cout << "\t[0]  - MAIN MENU" << endl;
                            cout << "\t[99] - EXIT" << endl << endl;

                            cout << "Select Menu > ";
                            cin >> selectMenu;

                            if(selectMenu == 1 || selectMenu == 2 || selectMenu == 3 || selectMenu == 4 || selectMenu == 5 || selectMenu == 6 || selectMenu == 0 || selectMenu == 99)
                            {
                                    switch (selectMenu)
                                {
                                case 1:
                                    switchCreateDoctor();
                                    break;
                                case 2:
                                    switchDeleteDoctor();
                                    break;
                                case 3:
                                    switchCreateClerk();
                                    break;
                                case 4:
                                    switchDeleteClerk();
                                    break;
                                case 5:
                                    switchViewDoctor();
                                    break;
                                case 6:
                                    switchViewClerk();
                                    break;
                                case 0:
                                    mainMenu();
                                    break;
                                case 99:
                                    exit(1);
                                    break;
                                }
                            }
                            else
                            {
                                cout << "INVALID INPUT" << endl;
                                continue;
                            }
                            }


        }


        else
        {

            deleteRecordAlert();

         cout << "\nDO YOU WANT TO LOG IN DIFFERENT ACCOUNT" << endl;
         cout << "\t[0] - YES\t[1] - NO" << endl;

         cout << "SELECT Y/N > ";
         cin >> selectMenu;
         switch (selectMenu)
         {
         case 0:
            LocalAdmin::login();
            break;
         case 1:
            mainMenu();
            break;
         }

        readDelete.close();

    }

    }


     if(isInvalid == true)
    {
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;
        cout << "\n\tFOLLOWING ADMIN RECORD DOES NOT EXIST!" << endl << endl;
        for(int countValue = 0; countValue < 50; countValue++){cout << "=";}
        cout << endl;
    }


    read.close();

}

void LocalAdmin::viewData()
{
    string readFirstName;
    string readLastName;
    int readNic;
    string readUserName;
    string readPassword;

    ifstream readFile ("LocalAdmin.txt",ios::in);

    if(readFile.is_open())
    {
        while(readFile)
        {
            readFile >> readFirstName;
            readFile >> readLastName;
            readFile >> readNic;
            readFile >> readUserName;
            readFile >> readPassword;

            cout << " First Name : " << readFirstName << endl;
            cout << " Last Name  : " << readLastName << endl;
            cout << " NIC        : " << readNic << endl;
            cout << " User Name  : " << readUserName << endl;
            cout << " Password   : " << readPassword << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "FILE IS MISSING" << endl;
    }

    readFile.close();
}

void CompanyAdmin::setAccount(CompanyAdmin & mainUser)
{
    Person *ptr = &mainUser;
    while(1)
    {
        string loginUserName;
        string loginPassword;
        int checkMenu;

        cout << endl;
        cout << "\tUSERNAME : ";
        cin >> loginUserName;
        cout << "\tPASSWORD : ";
        cin >> loginPassword;

        if(loginUserName == ptr->getUserName() && loginPassword == ptr->getPassword())
        {
            while(1)
            {
                cout << "\n\t---Login Has Completed---" << endl << endl;
                cout << "\t[1] - Delete Local Admin" << endl;
                cout << "\t[2] - Create A Local Admin" << endl;
                cout << "\t[0] - Exit\t[99]-Back" << endl << endl;

                cout << "ADMIN >";
                cout << "        ";
                cin >> checkMenu;
                if(checkMenu == 0 || checkMenu == 1 || checkMenu == 99)
                {
                    switch(checkMenu)
                    {
                    case 0:
                        exit(1);
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 99:
                        mainMenu();
                        break;
                    }
                }
                else
                {
                    continue;
                }
        }
    }
    else
    {
        int menu;
        cout << "INVALID INPUT" << endl << endl;
        cout << "Do You Want To Go Back ?" << endl;
        cout << "\t{0} - NO\t[1] - YES" << endl << endl;
        cout << "MAIN MENU \ ADMIN > " << endl;
        cout << "                      ";
        cin >> menu;

        if(menu == 0)
        {
            continue;
        }
        else if (menu == 1)
        {

        }

        continue;
    }
    }
}

void CompanyAdmin::login(string value1, string value2)
{
    while(1)
    {
        string loginUserName;
        string loginPassword;
        int checkMenu;

        cout << endl;
        cout << "\tUSERNAME : ";
        cin >> loginUserName;
        cout << "\tPASSWORD : ";
        cin >> loginPassword;

        if(loginUserName == value1 && loginPassword == value2)
        {
            while(1)
            {
                cout << "Login Has Completed" << endl << endl;
                cout << "[1] - Delete Local Admin" << endl;
                cout << "[2] - Create A Local Admin" << endl;
                cout << "[0] - Exit\t[99]-Back" << endl << endl;

                cout << "ADMIN >";
                cout << "        ";
                cin >> checkMenu;
                if(checkMenu == 0 || checkMenu == 1 || checkMenu == 2 || checkMenu == 99)
                {
                    switch(checkMenu)
                    {
                    case 0:
                        exit(1);
                        break;
                    case 1:
                        deleteLocalAccount();
                        break;
                    case 2:
                        createAccountLocalAdmin();
                        break;
                    case 99:
                        break;
                    }
                }
                else
                {
                    continue;
                }
        }
    }
    else
    {
        int menu;
        cout << "Invalid Input!" << endl << endl;
        cout << "Do You Want To Go Back ?" << endl;
        cout << "\t{0} - NO\t[1] - YES" << endl << endl;
        cout << "MAIN MENU \ ADMIN > " << endl;
        cout << "                      ";
        cin >> menu;

        if(menu == 0)
        {
            continue;
        }
        else if (menu == 1)
        {

        }

        continue;
    }
    }
}

void Clerk::insertData(Clerk & clerk1)
{
    string tempFirstName;
    string tempLastName;
    int tempNic;
    string tempUserName;
    string tempPassword;

    cout << "Enter First Name Here : ";
    cin >> tempFirstName;
    cout << "Enter Last Name Here  : ";
    cin >> tempLastName;
    cout << "Enter NIC Here        : ";
    cin >> tempNic;
    cout << "Enter User Name Here  : ";
    cin >> tempUserName;
    cout << "Enter Password Here   : ";
    cin >> tempPassword;

    Person *writeFilePerson2 = &clerk1;
    writeFilePerson2->setFirstName(tempFirstName);
    writeFilePerson2->setLastName(tempLastName);
    writeFilePerson2->setNic(tempNic);
    writeFilePerson2->setUserName(tempUserName);
    writeFilePerson2->setPassword(tempPassword);

    ofstream writeFile ("Clerk.txt",ios::app);
    if(writeFile.is_open())
    {
        writeFile << firstName;
        writeFile << lastName;
        writeFile << nic;
        writeFile << userName;
        writeFile << password;
    }
    writeFile.close();
}

void Clerk::viewData()
{
    string readFirstName;
    string readLastName;
    int readNic;
    string readUserName;
    string readPassword;

    ifstream readFile ("Clerk.txt",ios::in);

    if(readFile.is_open())
    {

        cout << endl;
        for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;
        cout << "FIRST NAME\t\tLAST NAME\t\t\tNIC\t\t\t\t\tUSER NAME\t\tPASSWORD" << endl;
        for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl << endl;

        while(readFile)
        {
            readFile >> readFirstName;
            readFile >> readLastName;
            readFile >> readNic;
            readFile >> readUserName;
            readFile >> readPassword;

            cout << readFirstName << "\t\t\t" << readLastName << "\t\t\t\t" << readNic << "\t\t\t" << readUserName << "\t\t" << readPassword;
            cout << endl;
        }
    }


    else
    {
        cout << "FILE IS MISSING" << endl;
    }

    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl;
    cout << "FIRST NAME\t\tLAST NAME\t\tNIC\t\tUSER NAME\t\tPASSWORD" << endl;
    for(int countValue = 0; countValue < 110; countValue++){cout << "=";}cout << endl << endl;

    readFile.close();
}

Person::Person()
{

}

void Person::setFirstName(string value)
{
    firstName = value;
}

void Person::setLastName(string value)
{
    lastName = value;
}

void Person::setNic(int value)
{
    nic = value;
}

void Person::setUserName(string value)
{
    userName = value;
}

void Person::setPassword(string value)
{
    password = value;
}

string Person::getFirstName()
{
    return firstName;
}

string Person::getLastName()
{
    return lastName;
}

int Person::getNic()
{
    return nic;
}

string Person::getUserName()
{
    return userName;
}

string Person::getPassword()
{
    return password;
}

int main()
{
    checkFiles();
    mainMenu();
    return 0;
}

void mainMenu()
{
    CompanyAdmin obj;
    Person *ptr = &obj;

    int selectMenu;
    while(1)
    {
        cout << "\nSelect Login Type : " << endl << endl;
        cout << "\t[0]-Login As Doctor" << endl;
        cout << "\t[1]-Login As Clerk" << endl;
        cout << "\t[2]-Login As Local Admin" << endl;
        cout << "\t[3]-Login As Software Owner" << endl;
        cout << "\t[4]-Login for Pharmacy" << endl << endl;

        cout << "\t[99] - Exit" << endl << endl;

        cout << "Select Menu > ";
        cin >> selectMenu;
        if(selectMenu == 1 || selectMenu == 2 || selectMenu == 3 || selectMenu == 4 || selectMenu == 0 || selectMenu == 99)
        {
            switch(selectMenu)
            {
            case 0:
                switchDoctorLogin();
                break;
            case 1:
                switchClerkLogin();
                break;
            case 2:
                switchLocalAdminLogin();
                break;
            case 3:
                ptr->login(ptr->getUserName(),ptr->getPassword());
                break;
            case 4:
                switchEmployeeLogin();
                break;
            case 99:
                exit(1);
                break;
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
            continue;
        }
    }
}

void invalidInput()
{
    cout << endl;
    //line break

    cout << "\t\t\t+";
    for(int countValue = 0; countValue < 31; countValue++)
    {
        cout << "-";
    }
    cout << "+";
    cout << "\t\t\t ";
    cout << endl;
    cout << "\t\t\t|\tInvalid Input\t\t|";
    cout << endl;

    cout << "\t\t\t|";
    for(int countValue = 0; countValue < 31; countValue++)
    {
        cout << "_";
    }
    cout << "|";
    cout << "\t\t\t|";
    cout << endl;
    //line break
}

void viewdataClerk()
{
    Clerk clerkViewObj;
    Person *ptrView2 = &clerkViewObj;
    ptrView2->viewData();
}

void localAdminView()
{
    int menuItem;

    cout << "\t[1] - Add Doctor" << endl;
    cout << "\t[2] - Add Clerk" << endl;
    cout << "\t[3] - View Records" << endl;
    cout << "\t[0] - MAIN MENU" << endl;

    while(1)
    {
        cout << "ADMIN PANEL \ MENU > ";
        cin >> menuItem;

        if(menuItem == 0 || menuItem == 1 || menuItem == 2 || menuItem == 3)
        {
            switch (menuItem)
            {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            }
        }
        else
        {
            cout << "INVALID INPUT!" << endl;
        }

    }

}

void deleteLocalAccount()
{
    LocalAdmin deleteLocalAdmin;
    Person *ptr = &deleteLocalAdmin;
    deleteLocalAdmin.deleteAccount(deleteLocalAdmin);
}

void createAccountLocalAdmin()
{
    LocalAdmin createAdmin;
    Person *ptr = &createAdmin;
    createAdmin.createAccount(createAdmin);
}

void switchLocalAdminLogin()
{
    LocalAdmin login1;
    Person *ptrLogin = &login1;
    ptrLogin->login();
}

void switchCreateDoctor()
{
    Doctor createDoctor;
    Person *ptr = &createDoctor;
    createDoctor.createAccount(createDoctor);
}

void switchDeleteDoctor()
{
    Doctor deleteDoctor;
    Person *ptr = &deleteDoctor;
    deleteDoctor.deleteAccount(deleteDoctor);
}

void switchCreateClerk()
{
    Clerk createClerk;
    Person *ptr = &createClerk;
    createClerk.createAccount(createClerk);
}

void switchDeleteClerk()
{
    Clerk deleteClerk;
    Person *ptr = &deleteClerk;
    deleteClerk.deleteAccount(deleteClerk);
}

void switchViewDoctor()
{
    Doctor doctorViewData;
    Person *ptr = &doctorViewData;
    doctorViewData.viewData();
}

void switchViewClerk()
{
    Clerk clerkViewData;
    Person *ptr = &clerkViewData;
    clerkViewData.viewData();
}

void switchClerkLogin()
{
    Clerk clerkLogin;
    Person *ptr = &clerkLogin;
    clerkLogin.login();
}

void switchAddPatientRecord()
{
    string date;

    Patient addPatient;
    Person *ptr = &addPatient;
    addPatient.insertData();

}

void switchDoctorAddMedicine()
{
    Doctor addMedicine;
    Person *ptr = &addMedicine;
    addMedicine.addPatientData();
}

void switchDoctorLogin()
{
    Doctor doctorLogin;
    Person *ptr = &doctorLogin;
    doctorLogin.login();
}

void switchViewDataDoctor()
{
    Patient viewForDoctor;
    viewForDoctor.viewDataDoctor();
}

void warningAlert()
{
    cout << endl;
        //break line

    int width = 57;

    cout << "\t";

    for(int countValue = 0; countValue < width; countValue++)
    {
        cout << "=";
    }

    cout << endl;

    cout << "\t|\t\t----WARNING ALERT!----\t\t\t|" << endl;
    cout << "\t|\tON SECURITY PERPOSE,\t\t\t\t|" << endl;
    cout << "\t|\tYOU CANT ACCCESS THE FOLLOWING CONDITION\t|" << endl;
    cout << "\t|\tTRY AGAIN\t\t\t\t\t|" << endl;

    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t";

    for(int countValue = 0; countValue < width; countValue++)
    {
        cout << "=";
    }

    cout << endl << endl;
        //break line
}


void deleteRecordAlert()
{
    cout << endl;
        //break line

    int width = 57;

    cout << "\t";

    for(int countValue = 0; countValue < width; countValue++)
    {
        cout << "=";
    }

    cout << endl;


    cout << "\t|\tUSER RECORD HAS DELETED\t\t\t\t|" << endl;
    cout << "\t|\tYOU CANT ACCCESS THE FOLLOWING CONDITION\t|" << endl;
    cout << "\t|\tTRY AGAIN\t\t\t\t\t|" << endl;

    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t";

    for(int countValue = 0; countValue < width; countValue++)
    {
        cout << "=";
    }

    cout << endl << endl;
        //break line
}

void pharmacyLogin()
{
    Pharmacy s;
    s.welcome();
    s.title();
}

void switchEmployeeLogin()
{
    Employee obj;
    obj.login();
}

void pharmacyObj()
{
    Pharmacy s;
            s.welcome();
            s.title();
}

void checkFiles()
{
    int loadFiles;
    int emptyFiles;

    ifstream readClerk ("Clerk.txt",ios::in);

    if(readClerk.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeClerk ("Clerk.txt",ios::app);
        writeClerk.close();
        emptyFiles++;
    }

    readClerk.close();
    //clerk

    ifstream readDeleteClerk ("DeleteClerk.txt",ios::in);

    if(readClerk.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeDeleteClerk ("DeleteClerk.txt",ios::app);
        writeDeleteClerk.close();
        emptyFiles++;
    }

    readDeleteClerk.close();
    //deleteClerk

    ifstream readDeleteDoctor ("DeleteDoctor.txt",ios::in);

    if(readDeleteDoctor.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeDeleteDoctor ("DeleteDoctor.txt",ios::app);
        writeDeleteDoctor.close();
        emptyFiles++;
    }

    readDeleteDoctor.close();
    //deleteDoctor

    ifstream readDoctor ("Doctor.txt",ios::in);

    if(readDoctor.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeDoctor ("Doctor.txt",ios::app);
        writeDoctor.close();
        emptyFiles++;
    }

    readDoctor.close();
    //doctor

    ifstream readLocalAdmin ("LocalAdmin.txt",ios::in);

    if(readLocalAdmin.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeLocalAdmin ("LocalAdmin.txt",ios::app);
        writeLocalAdmin.close();
        emptyFiles++;
    }

    readLocalAdmin.close();
    //localAdmin

    ifstream readMedicine ("Medicine.txt",ios::in);

    if(readMedicine.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeMedicine ("Medicine.txt",ios::app);
        writeMedicine.close();
        emptyFiles++;
    }

    readMedicine.close();
    //medicine

    ifstream readPatientData ("PatientData.txt",ios::in);

    if(readPatientData.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writePatientData ("PatientData.txt",ios::app);
        writePatientData.close();
        emptyFiles++;
    }

    readPatientData.close();
    //patientData

    ifstream readRelation ("PatientRelation.txt",ios::in);

    if(readRelation.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeRelation ("PatientRelation.txt",ios::app);
        writeRelation.close();
        emptyFiles++;
    }

    readRelation.close();
    //patientRelation

    ifstream readRejectAdmin ("RejectAdmin.txt",ios::in);

    if(readRejectAdmin.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writeRejectAdmin ("RejectAdmin.txt",ios::app);
        writeRejectAdmin.close();
        emptyFiles++;
    }

    readRejectAdmin.close();
    //rejectAdmin

    ifstream readPharmacy ("Record.txt",ios::in);

    if(readPharmacy.is_open())
    {
        loadFiles++;
    }
    else
    {
        ofstream writePharmacy ("Record.txt",ios::app);
        writePharmacy.close();
        emptyFiles++;
    }

    readPharmacy.close();
    //pharmacyRecords

    int processBar;
    int drawBarLength = 100;


    while(processBar <= 100)
    {
        cout << endl << endl << endl;
        int countLimit = 49;
        cout << "\t\t\t";
        for(int countValue = 0; countValue < countLimit; countValue++){cout << "=";} cout << endl;
        cout << "\t\t\t|      M E D I C A L  C E N T E R  \t\t|" << endl;
        cout << "\t\t\t|   C O N S O L E  A P P L I C A T I O N  \t|" << endl;
        cout << "\t\t\t|       X Y Z  S O F T W A R E S  \t\t|" << endl;
        cout << "\t\t\t";
        for(int countValue = 0; countValue < countLimit; countValue++){cout << "=";} cout << endl;
        cout << endl << endl << endl;
        int drawLine = 100;
        for(int draw = 0; draw < drawLine; draw++){cout << "=";} cout << endl;
        for(int drawBar = 0; drawBar < processBar; drawBar++){cout << "|";} cout << endl;
        for(int drawBar = 0; drawBar < processBar; drawBar++){cout << "|";} cout << endl;
        for(int draw = 0; draw < drawLine; draw++){cout << "=";} cout << endl << endl;
        cout << "IN PROCESS " << processBar << endl;
        system("cls");

        processBar+=4;

    }

}
