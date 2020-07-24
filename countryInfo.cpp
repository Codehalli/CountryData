#include "countryInfo.h" //including the header file

void findNeighbors( string dataFile, ostream& out, string commandArgument ) 
//findNeighbors function which is declared in the header file
{
	
	out << "Command: neighbors " << commandArgument << endl;
	ifstream in(dataFile);
	bool found = false;
	int counter = 0;
	string each_neighbor;
	//All variables used in the neighbors funciton 
	string iso;			//1
	string iso3;		//2
	string iso_numeric;		//3
	string fips;	//4
	string country;	//5
	string capital ;	//6
	double area;		//7
	string population;		//8
	string continent;		//9
	string top_level_domain;		//10
	string currency_code;		//11
	string currency_name;		//12
	string phone;		//13
	string postal_code_format;		//14
	string postal_code_regex;		//15
	string languages;		//16
	string geo_name_id;		//17
	string neighbors;		//18
	string equivalent_fips_code;		//19
	
	
	
	
	//reading the records
	readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
	top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	
	while( !in.fail() ) //while loop to determine the number of neighbors
	{
		
		if(neighbors.find(commandArgument) != string::npos)
		{
			counter ++;
			found = true;
			out << "Neighbor " << counter << endl;
			dataCountry( dataFile, out, iso );
			
		
		}
		
		readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, 
		continent, top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	}
	if (!found)
	{
	  out << "\tCountry " << commandArgument << " has no neighbors." << endl; //output for no neighbors 
	}	
	


}

void findCountry( string dataFile, ostream& out, string commandArgument )
//findCountry function which is declared in the header file
{
	ifstream in(dataFile);
	bool found = false;
	out << "Command: country " << commandArgument << endl;
	//All variables that our declared 
	string iso;			//1
	string iso3;		//2
	string iso_numeric;		//3
	string fips;	//4
	string country;	//5
	string capital ;	//6
	double area;		//7
	string population;		//8
	string continent;		//9
	string top_level_domain;		//10
	string currency_code;		//11
	string currency_name;		//12
	string phone;		//13
	string postal_code_format;		//14
	string postal_code_regex;		//15
	string languages;		//16
	string geo_name_id;		//17
	string neighbors;		//18
	string equivalent_fips_code;		//19
	
	readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
	top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	
	while( !in.fail() )
	{
		
		if ( iso == commandArgument )
		{
			found = true;
			displayRecord( out, iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
		top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex, languages, geo_name_id, neighbors, equivalent_fips_code );
			
		}
	
		readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, 
		continent, top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	}
	if ( !found ) //if ( found == false )
		out << "\tCountry " << commandArgument << " not found." << endl;
}
void findSize( string dataFile, ostream& out, string commandArgument )
//findSize function which is declared in the header file
{
	ifstream in(dataFile); //reading file
	int counter = 0;
	double sum = 0;
	double mean; 
	//declaring the variable in the size function
	string iso;			//1
	string iso3;		//2
	string iso_numeric;		//3
	string fips;	//4
	string country;	//5
	string capital ;	//6
	double area;		//7
	string population;		//8
	string continent;		//9
	string top_level_domain;		//10
	string currency_code;		//11
	string currency_name;		//12
	string phone;		//13
	string postal_code_format;		//14
	string postal_code_regex;		//15
	string languages;		//16
	string geo_name_id;		//17
	string neighbors;		//18
	string equivalent_fips_code;
			//19
	
	//reading the data
	readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
	top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	
	languages, geo_name_id, neighbors, equivalent_fips_code );
	
	string countryInterest = iso;
	double areaInterest = area;
	
	
	while( !in.fail() ) //sub groups in size function to determine which one to state
	{
		counter++;
		if ( commandArgument == "smallest" && area < areaInterest)
		{
			
			countryInterest = iso;
			areaInterest = area; 	
		}
		else if ( commandArgument == "largest" && area > areaInterest)
		{
			countryInterest = iso;
			areaInterest = area; 	
		}
		else if ( commandArgument == "average")
		{
			sum = sum + area;
			
		}
		readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, 
		continent, top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	}
	
	if ( commandArgument == "smallest") //if statement to state the output and declare the funcitons 
		{
			out << "Command: size " << commandArgument << endl;
			dataCountry( dataFile, out, countryInterest);	
		}
		else if ( commandArgument == "largest")
		{
			out << "Command: size " << commandArgument << endl;
			dataCountry( dataFile, out, countryInterest); 	
		}
		else if ( commandArgument == "average")
		{
			out << "Command: size " << commandArgument << endl;
			mean = sum/counter; 
			out << "\tSum: " << fixed << setprecision(2) << sum << endl;
			out << "\tCountry count: " << counter << endl;
			out << "\tAverage Size: " << fixed << setprecision(2)<< mean << endl;
		}
	 
		
}

void dataCountry( string dataFile, ostream& out, string commandArgument )
//dataCountry function which is declared in the header file
{
	ifstream in(dataFile);    //opening up the file and reading the data
	
	//All the variables that are in the file. 
	string iso;			//1
	string iso3;		//2
	string iso_numeric;		//3
	string fips;	//4
	string country;	//5
	string capital ;	//6
	double area;		//7
	string population;		//8
	string continent;		//9
	string top_level_domain;		//10
	string currency_code;		//11
	string currency_name;		//12
	string phone;		//13
	string postal_code_format;		//14
	string postal_code_regex;		//15
	string languages;		//16
	string geo_name_id;		//17
	string neighbors;		//18
	string equivalent_fips_code;		//19
	
	//reading the data
	readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
	top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	
	while( !in.fail() ) //while loop is to repeat the displaying and reading. 
	{
		
		if ( iso == commandArgument )
		{
			//displaying the data 
			displayRecord( out, iso, iso3, iso_numeric, fips, country, capital , area, population, continent, 
		top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex, languages, geo_name_id, neighbors, equivalent_fips_code );
			
		}

		//reading the data
		readRecord( in,	iso, iso3, iso_numeric, fips, country, capital , area, population, 
		continent, top_level_domain, currency_code, currency_name, phone, postal_code_format, postal_code_regex,	languages, geo_name_id, neighbors, equivalent_fips_code );
	}
	
}

void readRecord( istream &in, 	string &iso, string& iso3, string & iso_numeric, string& fips, 
	string& country, string& capital , double& area, string & population, string &continent, 
	string &top_level_domain, string & currency_code, string& currency_name, string& phone, 
	string &postal_code_format, string & postal_code_regex, 
	string &languages, string &geo_name_id, string &neighbors, string &equivalent_fips_code ) 
//readRecord function which is declared in the header file
{
	while( in.peek() == '#' && !in.fail() )
		in.ignore(15000, '\n');//ignore 15000 or until it see the newline
	
	getline(in, iso, '\t');//read from in, store in the iso and stop at the tab
	getline(in, iso3, '\t' );
	getline(in, iso_numeric, '\t' );
	getline(in, fips, '\t');
	getline(in, country, '\t');
	getline(in, capital, '\t');
	in >> area;
	in.ignore();
	getline(in, population, '\t');
	getline(in, continent, '\t');
	getline(in, top_level_domain, '\t');
	getline(in, currency_code, '\t');
	getline(in, currency_name , '\t');
	getline(in, phone , '\t');
	getline(in, postal_code_format , '\t');
	getline(in, postal_code_regex , '\t');
	getline(in, languages , '\t');
	getline(in, geo_name_id , '\t');
	getline(in, neighbors , '\t');
	getline(in, equivalent_fips_code);
}

void displayRecord( ostream &out, 	string iso, string iso3, string  iso_numeric, string fips, 
	string& country, string& capital , double& area, string  population, string continent, 
	string top_level_domain, string  currency_code, string currency_name, string phone, 
	string postal_code_format, string postal_code_regex, 
	string languages, string geo_name_id, string neighbors, string equivalent_fips_code )
//displayRecord function which is declared in the header file
{
	out << "\tISO:			" << iso << endl              //outputting values
		<< "\tISO3:			" << iso3 << endl             //from the file.  
		<< "\tISO Numeric:		" << iso_numeric << endl  
		<< "\tFIPS:			" << fips << endl             
		<< "\tCountry:		" << country << endl          
		<< "\tCapital:		" << capital << endl          
		<< "\tArea:			" << fixed << setprecision(2) << area << endl  
		<< "\tPopulation:		" << population << endl
		<< "\tContinent:		" << continent << endl
		<< "\tTopLevelDomain:			" << top_level_domain << endl
		<< "\tCurrency Code:		" << currency_code << endl
		<< "\tCurrency Name:		" << currency_name << endl
		<< "\tPhone:			" << phone << endl
		<< "\tPostal Code:		" << postal_code_format << endl 
		<< "\tPostal Code Regex:	" << postal_code_regex << endl
		<< "\tLanguages:		" << languages << endl
		<< "\tGeonameid:		" << geo_name_id << endl
		<< "\tNeighbors:		" << neighbors << endl
		<< "\tEquivalent FIPS Code: " << equivalent_fips_code << endl;
}
//readRecord function which is declared in the header file
void countryInfo( string input, string output )
{
	ifstream in(input);    //reading file
	ofstream out(output);  //outputting file
	
	string command, commandArgument;
	string dataFile;
	
	in.ignore( 500, ':' );
	in >> dataFile;        //input 
	
	in >> command >> commandArgument;    //input  
	
	out << "Data file: " << dataFile << endl;
	
	while( !in.fail() ) //while loop to declare which command
	{
		if ( command == "size" )
		{
			findSize( dataFile, out, commandArgument ); //calls findSize function 
		}
		else if ( command == "country" )
		{
			findCountry( dataFile, out, commandArgument );   //calls findCountry function
		}
		else if ( command == "neighbors" )
		{
			findNeighbors( dataFile, out, commandArgument ); //calls findNeighbor function
		}
		in >> command >> commandArgument;
	}
}