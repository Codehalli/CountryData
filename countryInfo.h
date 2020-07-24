/*
*  Purpose for program
*  This program will be reading in a tab delimited file. In the file there will be a list 
*  of countries around the earth. The program will read the file and facts about each country.
*  Based on the input command it will output the country and the facts the country. 
*
*  Programmer: Pranav Rao
*  Date: March 7, 2019
*/

#include <string>	//Including all the proper directives and headers
#include <iostream>	//for the opening/closing files, string, etc.
#include <fstream>     
#include <iomanip>

using std::string;   //Including all the proper using declarations 
using std::ifstream; //for this function, so it compiles properly
using std::ofstream;
using std::endl;
using std::cout;
using std::ostream;
using std::istream;
using std::setprecision;
using std::fixed;



void countryInfo(string input, string output );
/*
*  Function: countryInfo
*  Purpose: This function will be the primary function for reading in the records the commands.
*  input - this is the filename for the records to be read.
*  output - this is the filename to use for output.
*/

void readRecord( istream &in, 	string &iso, string& iso3, string & iso_numeric, string& fips, 
	string& country, string& capital , double& area, string & population, string &continent, 
	string &top_level_domain, string & currency_code, string& currency_name, string& phone, string 
	&postal_code_format, string & postal_code_regex, 
	string &languages, string &geo_name_id, string &neighbors, string &equivalent_fips_code ); 
/*
*  Function: readRecord
*  Purpose: This function will be the reading in all the different data facts
*  like iso, iso3, iso_numeric, fips,country, capital, area , population, continent, ect. 
*/
void displayRecord( ostream &in, 	string iso, string iso3, string  iso_numeric, string fips, 
	string& country, string& capital , double& area, string  population, string continent, 
	string top_level_domain, string  currency_code, string currency_name, string phone, 
	string postal_code_format, string postal_code_regex, 
	string languages, string geo_name_id, string neighbors, string equivalent_fips_code );
/*
*  Function: displayRecord
*  Purpose: This function will be the diplayed in all the different data facts
*  like iso, iso3, iso_numeric, fips,country, capital, area , population, continent, ect. 
*/
	
void findSize( string dataFile, ostream& out, string commandArgument );
/*
*  Function: findSize
*  Purpose: This function will determine the size of the countries 
*  dataFile - the filename will be stored here for the command process.
*  out - this is the filename to use for output.
*  command Argument- this is the command and based on which function it will do the proper process.
*/

void findCountry( string dataFile, ostream& out, string commandArgument );
/*
*  Function: findCountry
*  Purpose: This function will determine the country. 
*  dataFile - the filename will be stored here for the command process.
*  out - this is the filename to use for output.
*  command Argument- this is the command and based on which function it will do the proper process.
*/

void findNeighbors( string dataFile, ostream& out, string commandArgument );
/*
*  Function: findNeighbors
*  Purpose: This function will determine the neighbors of the country 
*  dataFile - the filename will be stored here for the command process.
*  out - this is the filename to use for output.
*  command Argument- this is the command and based on which function it will do the proper process.
*/

void dataCountry( string dataFile, ostream& out, string commandArgument );
/*
*  Function: dataCountry
*  Purpose: This function will help loop the displays for the 3 main functions
*  dataFile - the filename will be stored here for the command process.
*  out - this is the filename to use for output.
*  command Argument- this is the command and based on which function it will do the proper process.
*/