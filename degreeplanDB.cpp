// Steven Kundert
// Tech Ninjas Project
// Pseudo code for database
// This is a short program to read the database I created into an array of 
// structs. Each line of the database is similar to this form:
// ENGL 1103 BB COMM CORE. The first entry is the subject, which will be 
// either 3 or 4 letters. The next entry is a 4 digit number, which is stored
// as a string here. Next is a two letter entry for BA, BS, or both. Then the
// next entry represents the category of the course. There are many categories,
// all of which need to be searchable. Here, I used the following codes for
// each category: COMM for Communications, PSCI for History & Political Science,
// SSCI for Social & Behavioral Science, ARTS for Creative Arts, LANG for 
// Language, Philosophy, & Culture, GLOB for Cultural & Global Understanding,
// UINQ for Undergraduate Inquiry & Creativity, MATH for Mathematics, LSCI for
// (Lab) Science, and CMPS for Computer Science. The last entry is either CORE 
// or ELEC. Our program will need to use this database to match user-provided
// search criteria, which will then be matched to open courses in another
// database created from the class schedule.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// There are approximately 141 courses listed in both degree plans
const int NUMRECS = 200;

struct dbaseRecord {
	string SUBJ; // Subject
	string CRSE; // Course #
	string PLAN; // Degree plan - BA, BS, or both (BB)
	string CATG; // Category
	string EORC; // Elective or Core
};

int main() {

	ifstream infile;
	infile.open("degreeplans.txt");

	// Create an array of the struct to hold all courses in the degree plans
	dbaseRecord Catalog[NUMRECS];

	int i = 0;

	while (!infile.eof() && i < NUMRECS) {

		infile >> Catalog[i].SUBJ;
		infile >> Catalog[i].CRSE;
		infile >> Catalog[i].PLAN;
		infile >> Catalog[i].CATG;
		infile >> Catalog[i].EORC;
		i++;
	}

	// Test to see if loaded properly
	// Will display all BA language courses
	for (int j = 0; j < i; j++)
	{
		if ((Catalog[j].PLAN == "BA" || Catalog[j].PLAN == "BB") && Catalog[j].CATG == "LANG")
		{
			cout << Catalog[j].SUBJ << " " << Catalog[j].CRSE << endl;
		}
	}

	system("pause");
	return 0;
}