///  @brief Program 4 - Date Class
///     Adapted from prior programs developed by Professor Reed.
///  @author [Muhamamad Wasiuddin Hakim]
///  @date July 20, 2021
///  CS 141 Summer 2021, Dr. Koehler

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date(){
       day = 1;
       month = 1;
       monthName = "January";
       year = 2000;
   };

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y){
       unsigned daysAllowed;
       bool inDate = false;
       if (m > 12){
           month = 12;
           monthName = name(12);
           daysAllowed = daysPerMonth(12,y);
           cout << "Invalid date values: Date corrected to ";
           inDate = true;
       }
       else if (m == 0){
           month = 1;
           monthName = name(1);
           daysAllowed = daysPerMonth(1,y);
           cout << "Invalid date values: Date corrected to ";
           inDate = true;           
       }
       else{
           month = m;
           monthName = name(m);
           daysAllowed = daysPerMonth(m,y);
       }
       if (d > daysAllowed){
           day = daysAllowed;
           if (inDate != true){
               cout << "Invalid date values: Date corrected to ";
               inDate = true;
           }
       }
       else if(d == 0){
           day = 1;
           if (inDate != true){
               cout << "Invalid date values: Date corrected to ";
               inDate = true;
           }
       }
       else{
           day = d;
       }
       year = y;
       if (inDate == true){
           cout << month << "/" << day << "/" << year << ".\n";
       }
   };


   /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y){
       unsigned daysAllowed;
       if ( mn == "January" ||  mn == "january" || mn == "February" ||  mn == "february" || mn == "March" ||  mn == "march" || mn == "April" ||  mn == "april" || mn == "May" ||  mn == "may" || mn == "June" ||  mn == "june" || mn == "July" ||  mn == "july" || mn == "August" ||  mn == "august" || mn == "September" ||  mn == "september" || mn == "October" ||  mn == "october" || mn == "November" ||  mn == "november" || mn == "December" ||  mn == "december" ){
           month = number(mn);
           monthName = name(month);
           daysAllowed = daysPerMonth(month,y);
           year = y;
           if (d > daysAllowed){
               day = daysAllowed;
               cout << "Invalid date values: Date corrected to ";
               printNumeric();
               cout << "." <<endl;
           }
           else if ( d == 0){
               day = 1;
               cout << "Invalid date values: Date corrected to ";
               printNumeric();
               cout << "." <<endl;               
           }
           else{
               day = d;
           }           
       }
       else{
           day = 1;
           month = 1;
           monthName = name(1);
           year = 2000;
           daysAllowed = 31;
           cout << "Invalid month name: the Date was set to ";
           printNumeric();
           cout << "."<<endl;
       }
   };


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const{
       cout << month << "/" << day << "/" << year;
   };


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const{
       cout << monthName << " " << day << ", " << year;
   };

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const{
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0)
                    return true;
                else
                    return false;
            }
            else
                return true;
        }
        else
            return false;      
   };


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const{
	if( m == 2)
	{
		if(isLeap(y) == true)	
			return 29;
		else	
			return 28;
	}
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)	
		return 31;
	else 		
		return 30;
       
   };

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const{
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return months[m-1];   
   };

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const{
       if ( mn == "January" || mn == "january")
            return 1;
       if ( mn == "February" || mn == "february")
            return 2;
       if ( mn == "March" || mn == "march")
            return 3;
       if ( mn == "April" || mn == "april")
            return 4;
       if ( mn == "May" || mn == "may")
            return 5;
       if ( mn == "June" || mn == "june")
            return 6;
       if ( mn == "July" || mn == "july")
            return 7;
       if ( mn == "August" || mn == "august")
            return 8;
       if ( mn == "September" || mn == "september")
            return 9;
       if ( mn == "October" || mn == "october")
            return 10;
       if ( mn == "November" || mn == "november")
            return 11;
       if ( mn == "December" || mn == "december")
            return 12;
    return 0;
   };
};
Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}