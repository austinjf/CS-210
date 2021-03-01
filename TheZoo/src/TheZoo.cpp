#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <jni.h>
using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

// --------------------- START CLASS Animal -----------------------------
class Animal {

private:
	int code;
	string name;

public:

	int getCode() {
		return this->code;
	}

	string getName() {
		return this->name;
	}

	void setCode(int code) {
		this->code = code;
	}

	void setName(string name) {
		this->name = name;
	}

	virtual string getType() = 0;

	virtual int getNurse() = 0;

	virtual int getNumberOfEggs() = 0;

	virtual string getSubType() = 0;
};
// --------------------- END CLASS Animal -------------------------------

// --------------------- START CLASS Oviparous -----------------------------
class Oviparous : public Animal {

private:
	string type;
	int numberOfEggs;

public:

	void setNumberOfEggs(int numberOfEggs) {
		this->numberOfEggs = numberOfEggs;
	}

	int getNumberOfEggs() {
		return this->numberOfEggs;
	}

	void setType(string type) {
		this->type = type;
	}

	string getType() {
		return this->type;
	}

	int getNurse() {
		return 0;
	}

};
// --------------------- END CLASS Oviparous -------------------------------

// --------------------- START CLASS Mammal -----------------------------
class Mammal : public Animal {

private:
	string type;
	int nurse;

public:

	void setNurse(int nurse) {
		this->nurse = nurse;
	}

	int getNurse() {
		return this->nurse;
	}

	void setType(string type) {
		this->type = type;
	}

	string getType() {
		return this->type;
	}

	int getNumberOfEggs() {
		return 0;
	}
};
// --------------------- END CLASS Mammal -------------------------------

// --------------------- START CLASS Crocodile -----------------------------
class Crocodile : public Oviparous {

private:
	string subType;

public:

	Crocodile(){
		// Default constructor
	}

	Crocodile(int code, string name, string type, string subType, int numEggs) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNumberOfEggs(numEggs);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS Crocodile -------------------------------

// --------------------- START CLASS Goose -----------------------------
class Goose : public Oviparous {

private:
	string subType;

public:

	Goose(){
		// Default constructor
	}

	Goose(int code, string name, string type, string subType, int numEggs) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNumberOfEggs(numEggs);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS Goose -------------------------------

// --------------------- START CLASS Pelican -----------------------------
class Pelican : public Oviparous {

private:
	string subType;

public:

	Pelican(){
		// Default constructor
	}

	Pelican(int code, string name, string type, string subType, int numEggs) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNumberOfEggs(numEggs);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS Pelican -------------------------------

// --------------------- START CLASS Bat -----------------------------
class Bat : public Mammal {

private:
	string subType;

public:

	Bat(){
		// Default constructor
	}

	Bat(int code, string name, string type, string subType, int numNurse) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNurse(numNurse);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS Bat -------------------------------

// --------------------- START CLASS Whale -----------------------------
class Whale : public Mammal {

private:
	string subType;

public:

	Whale(){
		// Default constructor
	}

	Whale(int code, string name, string type, string subType, int numNurse) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNurse(numNurse);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS Whale -------------------------------

// --------------------- START CLASS SeaLion -----------------------------
class SeaLion : public Mammal {

private:
	string subType;

public:

	SeaLion(){
		// Default constructor
	}

	SeaLion(int code, string name, string type, string subType, int numNurse) {
		this->setCode(code);
		this->setName(name);
		this->setType(type);
		this->setSubType(subType);
		this->setNurse(numNurse);
	}

	void setSubType(string subType) {
		this->subType = subType;
	}

	string getSubType() {
		return this-> subType;
	}
};
// --------------------- END CLASS SeaLion -------------------------------

void AddAnimal(vector<Animal*>& zoo)
{
	int trackNum;
	string name;
	string type;
	string subType;
	int numEggs;
	int nurse;
	char userKey;
	bool stop = false;

	while(!stop) {
		try {
			cout << endl << "----- Add Record -----" << endl;
			cout << "Enter tracking number: ";
			cin >> trackNum;

			// Error checking for size of tracking number
			if(trackNum < 1 || trackNum > 999999) {
				throw runtime_error("Invalid entry. Tracking number must be between 1 and 999999");
			}

			cout << "Enter name: ";
			cin >> name;

			// Error checking for size of name
			if(name.size() > 15) {
				throw runtime_error("Invalid entry. Name cannot exceed 15 characters.");
			}

			cout << "Enter type: ";
			cin >> type;

			// Error checking for size of type
			if(type.size() > 15) {
				throw runtime_error("Invalid entry. Type cannot exceed 15 characters.");
			}
			// Error checking for correct type entered
			else if(type != "Mammal" && type != "Oviparous") {
				throw runtime_error("Invalid entry. Only types Mammal and Oviparous are currently supported.");
			}

			cout << "Enter sub-type: ";
			cin >> subType;

			// Error checking for size of subType
			if(subType.size() > 15) {
				throw runtime_error("Invalid entry. Sub-type cannot exceed 15 characters.");
			}
			// Error checking for correct subType entered
			else if(subType != "Crocodile" && subType != "Goose" && subType != "Pelican" &&
					subType != "Bat" && subType != "Whale" && subType != "SeaLion"){
				string supportedSubTypes = "Crocodile, Goose, Pelican, Bat, Whale, and SeaLion.";
				string excpt;

				// Build the exception string to be thrown
				excpt += "Invalid entry. ";
				excpt += subType;
				excpt += " is not a supported sub-type.\n";
				excpt += "Currently, the supported sub-types are: ";
				excpt += supportedSubTypes;

				throw runtime_error(excpt);
			}

			cout << "Enter number of eggs: ";
			cin >> numEggs;

			// Error checking for non-negative number of eggs
			if(numEggs < 0) {
				throw runtime_error("Invalid entry. Number of eggs cannot be less than 0.");
			}

			cout << "Enter (1) if nursing, (0) if not nursing: ";
			cin >> nurse;

			// Error checking for acceptable value of nurse, either 0 or 1
			if(nurse != 0 && nurse != 1) {
				throw runtime_error("Invalid entry. Enter either (1) or (0).");
			}

			cout << endl << "Save new record? ( Y / N ): ";
			cin >> userKey;

			// Based on subType, add the new record to the zoo vector
			if(userKey == 'Y' || userKey == 'y') {
				if(subType == "Crocodile") {
					Crocodile *crocodile = new Crocodile(trackNum, name, type, subType, numEggs);
					zoo.push_back(crocodile);
				}
				else if(subType == "Goose") {
					Goose *goose = new Goose(trackNum, name, type, subType, numEggs);
					zoo.push_back(goose);
				}
				else if(subType == "Pelican") {
					Pelican *pelican = new Pelican(trackNum, name, type, subType, numEggs);
					zoo.push_back(pelican);
				}
				else if(subType == "Bat") {
					Bat *bat = new Bat(trackNum, name, type, subType, nurse);
					zoo.push_back(bat);
				}
				else if(subType == "Whale") {
					Whale *whale = new Whale(trackNum, name, type, subType, nurse);
					zoo.push_back(whale);
				}
				else if(subType == "SeaLion") {
					SeaLion *seaLion = new SeaLion(trackNum, name, type, subType, nurse);
					zoo.push_back(seaLion);
				}

				stop = true; // Record added, stop loop and exit AddAnimal() function
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Cannot add record. Please try again." << endl << endl;
		}
	}
	cout << endl << "Record added!" << endl << endl;
}


void RemoveAnimal(vector<Animal*>& zoo)
{
	int trackNum;
	char userKey;
	bool stop = false;

	while(!stop) {
		try {
			cout << endl << "----- Delete Record -----" << endl;
			cout << "Enter tracking number: ";
			cin >> trackNum;

			// Error checking for size of tracking number
			if(trackNum < 1 || trackNum > 999999) {
				throw runtime_error("Invalid entry. Tracking number must be between 1 and 999999");
			}

			cout << "Are you sure you want to delete the animal assigned to tracking number "
				 << setw(6) << setfill('0') << right << trackNum // Formatting for tracking number
				 << "? ( Y / N )" << endl;
			cin >> userKey;

			if(userKey == 'Y' || userKey == 'y') {
				bool recordDeleted = false;

				for(unsigned int i = 0; i < zoo.size(); ++i) {
					if(zoo.at(i)->getCode() == trackNum) {
						zoo.erase(zoo.begin() + i); // Delete record
						recordDeleted = true;
						cout << "Animal successfully deleted." << endl << endl;
						i = zoo.size() + 1; // Record deleted, exit for loop
					}
				}

				// If the record was not found, let the user know
				if(!recordDeleted) {
					cout << "Tracking number " << trackNum << " was not found." << endl;
					cout << "Animal was not deleted." << endl << endl;
				}
			}
			// If the user decides not to delete the record
			else {
				cout << "Animal assigned to tracking number " << trackNum << " was NOT deleted." << endl << endl;
			}

			stop = true; // Exit loop and return to main menu
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Cannot delete record. Please try again." << endl << endl;
		}
	}
}



void LoadDataFromFile(vector<Animal*>& zoo)
{
	cout << "Loading data from file. . . " << endl;
	ifstream file("zoodata.txt");
	string lineStr;

	// Get one line from file at a time and iterate through that line
	while(getline(file, lineStr)) {
		int code;
		string nameStr;
		string typeStr;
		string subTypeStr;
		int numEggs;
		int nurse;

		// Parse line to appropriate variables
		code = stoi(lineStr.substr(0, 6));
		nameStr = lineStr.substr(6, 15);
		typeStr = lineStr.substr(21, 15);
		subTypeStr = lineStr.substr(36, 15);
		numEggs = (int)lineStr[51] - '0';
		nurse = (int)lineStr[53] - '0';

		// Based on subType, create a class of that sub type and add it to the zoo vector
		if(subTypeStr == "Crocodile      ") {
			Crocodile *crocodile = new Crocodile(code, nameStr, typeStr, subTypeStr, numEggs);
			zoo.push_back(crocodile);
			//cout << "Added Crocodile" << endl;
		}
		else if(subTypeStr == "Goose          ") {
			Goose *goose = new Goose(code, nameStr, typeStr, subTypeStr, numEggs);
			zoo.push_back(goose);
			//cout << "Added Goose" << endl;
		}
		else if(subTypeStr == "Pelican        ") {
			Pelican *pelican = new Pelican(code, nameStr, typeStr, subTypeStr, numEggs);
			zoo.push_back(pelican);
			//cout << "Added Pelican" << endl;
		}
		else if(subTypeStr == "Bat            ") {
			Bat *bat = new Bat(code, nameStr, typeStr, subTypeStr, nurse);
			zoo.push_back(bat);
			//cout << "Added Bat" << endl;
		}
		else if(subTypeStr == "Whale          ") {
			Whale *whale = new Whale(code, nameStr, typeStr, subTypeStr, nurse);
			zoo.push_back(whale);
			//cout << "Added Whale" << endl;
		}
		else if(subTypeStr == "SeaLion        ") {
			SeaLion *seaLion = new SeaLion(code, nameStr, typeStr, subTypeStr, nurse);
			zoo.push_back(seaLion);
			//cout << "Added SeaLion" << endl;
		}
	}

	file.close();
	cout << "Load complete." << endl << endl;

}

void SaveDataToFile(vector<Animal*>& zoo)
{
     // Delete all data in the file
	 fstream file;
     file.open("zoodata.txt", ios::out | ios::trunc);
     file.close();

     // Write new data to the file
     ofstream zooData;
     zooData.open("zoodata.txt");

     // Iterate through zoo vector and write data in vector to zoodata.txt
     for(unsigned int i = 0; i < zoo.size(); ++i) {
         zooData << setw(6) << setfill('0') << right << zoo.at(i)->getCode()
        		 << setw(15) << setfill(' ') << left << zoo.at(i)->getName()
				 << setw(15) << setfill(' ') << left << zoo.at(i)->getType()
				 << setw(15) << setfill(' ') << left << zoo.at(i)->getSubType()
				 << zoo.at(i)->getNumberOfEggs() << " "
				 << zoo.at(i)->getNurse() << endl;
     }

     zooData.close();
     cout << "Save successfully completed." << endl << endl;

}

void DisplayMenu()
{
     cout << "--- Wildlife Zoo Interface Main Menu ---" << endl;
     cout << "(1). Load Animal Data" << endl;
     cout << "(2). Generate Data" << endl;
     cout << "(3). Display Animal Data" << endl;
     cout << "(4). Add Record" << endl;
     cout << "(5). Delete Record" << endl;
     cout << "(6). Save Animal Data" << endl;
     cout << "(7). Terminate Program" << endl << endl;
     cout << "Select a command . . ." << endl;

}

void DisplayAnimalData(vector<Animal*>& zoo) {
	cout << "+---------------------------------------------------------------------------+" << endl;
	cout << "| Track # | Name           | Type           | Sub-type       | Eggs | Nurse |" << endl;
	cout << "+---------------------------------------------------------------------------+" << endl;

	for(unsigned int i = 0; i < zoo.size(); ++i) {
		cout << "| " << setw(6) << setfill('0') << right << zoo.at(i)->getCode() << "  ";
		cout << "| " << setw(15) << setfill(' ') << left << zoo.at(i)->getName();
		cout << "| " << setw(15) << setfill(' ') << left << zoo.at(i)->getType();
		cout << "| " << setw(15) << setfill(' ') << left << zoo.at(i)->getSubType();
		cout << "|    " << zoo.at(i)->getNumberOfEggs();
		cout << " |     " << zoo.at(i)->getNurse() << " |" << endl;
	}

	cout << "+---------------------------------------------------------------------------+" << endl << endl;
}


int main()
{
	vector<Animal*> zoo;
	int userChoice = 0;

	while(userChoice > -1) {
		DisplayMenu();
		cin >> userChoice;

		if (userChoice == 1) {
			LoadDataFromFile(zoo);
		}
		else if (userChoice == 2) {
			GenerateData();
		}
		else if (userChoice == 3) {
			DisplayAnimalData(zoo);
		}
		else if (userChoice == 4) {
			AddAnimal(zoo);
		}
		else if (userChoice == 5) {
			RemoveAnimal(zoo);
		}
		else if (userChoice == 6) {
			SaveDataToFile(zoo);
		}
		else if (userChoice == 7) {
			char userKey;

			cout << "Are you sure you want to terminate the program? ( Y / N )" << endl;
			cout << "*** ANY UNSAVED DATA WILL BE LOST ***" << endl << endl;
			cin >> userKey;

			if(userKey == 'Y' || userKey == 'y') {
				cout << "Terminating program . . ." << endl;
				userChoice = -1;
			}
		}
		else {
			cout << "Invalid entry. Please try again." << endl << endl;
		}

	}
	return 1;
}
