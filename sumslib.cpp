//############################################################################
// BRIAN SUMNER                                                              #
// UCDENVER DEPARTMENT OF COMPUTER SCIENCE                                   #
// <SUMNER_STANDARD_LIBRARY>                                                 #
// FILE: sumslib.cpp                                                         #
//############################################################################



#include "sumslib.h"
#include <iostream>
#include <string>
#include <cstdlib>



namespace sumslib_rev02

{


	void msg(std::string arg_string_message, int arg_lines_above, int arg_lines_below)
	{
		std::cout << lf(arg_lines_above) << arg_string_message << lf(arg_lines_below);
	}



	void error(std::string arg_string_message, int arg_lines_above, int arg_lines_below)
	{
		msg(ctr("[ERROR: " + arg_string_message + "]"), arg_lines_above, arg_lines_below);
	}



	std::string ctr(int arg_left_align, std::string arg_string, int arg_lines_above, int arg_lines_below)
	{
		return ctr(arg_string, arg_lines_above, arg_lines_below, arg_left_align);
	}



	std::string ctr(std::string arg_string, int arg_lines_above, int arg_lines_below, int arg_left_align)
	{
		std::string margin = "";
		std::string output = "";

		output += lf(arg_lines_above);

		if (arg_string.length() <= 78)
			for (int index = 0;
				 index < (arg_left_align + (((80 - arg_string.length()) / 2) - 1 + arg_string.length() % 2));
				 index++)
				margin += " ";

		output += margin;
		output += arg_string;

		output += lf(arg_lines_below);

		return output;
	}



	std::string lf(int arg_lines)
	{
		std::string output = "";

		for (int index = 0; index < arg_lines ; index++)
			output += "\n";

		return output;
	}




	std::string promptString(std::string arg_string)
	{
		std::string buffer;

		std::cout << arg_string;
		std::getline(std::cin, buffer);

		return buffer;
	}




	bool promptYN(std::string arg_string, bool acceptLowerCase)
	{
		std::string buffer;
		bool output = false;
		bool valid = false;

		do
		{
			buffer = promptString(arg_string);

			if ((buffer == "Y") || (acceptLowerCase && (buffer == "y")))
			{
				valid = true;
				output = true;
			}
			else if ((buffer == "N") || (acceptLowerCase && (buffer == "n")))
			{
				valid = true;
				output = false;
			}

		} while (!valid);

		return output;
	}



	bool promptY(std::string arg_string, bool acceptLowerCase)
	{
		std::string buffer;
		bool output = false;

		buffer = promptString(arg_string);

		if ((buffer == "Y") || (acceptLowerCase && (buffer == "y")))
			output = true;

		return output;
	}





	int promptInt(std::string arg_string, int arg_lower, int arg_upper)
	{
		std::string buffer;
		int output = 0;
		bool useRange = (arg_lower < arg_upper);
		bool valid = false;

		do
		{
			buffer = promptString(arg_string);


			// YES THIS IS A HACK
			if (buffer == "0") return 0;


			// SET VALID IF OUTPUT AS INTEGER ASSIGNMENT SUCCESSFUL
			valid = (output = std::atoi(buffer.c_str()));

			// CHECK RANGE
			if (valid && useRange)
				valid = ((arg_lower <= output) && (output <= arg_upper));

		} while (!valid);

		return output;
	}




	double promptDouble(std::string arg_string, double arg_lower, double arg_upper)
	{
		std::string buffer;
		double output = 0.0;
		bool useRange = (arg_lower < arg_upper);
		bool valid = false;

		do
		{
			buffer = promptString(arg_string);

			// SET VALID IF OUTPUT AS FLOAT ASSIGNMENT SUCCESSFUL
			valid = (output = std::atof(buffer.c_str()));

			// CHECK RANGE
			if (valid && useRange)
				valid = (arg_lower <= output && output <= arg_upper);

		} while (!valid);

		return output;
	}





	int simpleMenu(std::string arg_string_menu, std::string arg_string_prompt, int arg_numberOfChoices)
	{
		int selection = 1;

		std::cout << arg_string_menu;

		promptInt(arg_string_prompt, 1, arg_numberOfChoices);

		return selection;
	}



	int simpleMenu(std::string arg_string_menuPrompt, int arg_numberOfChoices)
	{
		return simpleMenu("", arg_string_menuPrompt, arg_numberOfChoices);
	}






	std::string bencode(std::string arg_string, int arg_offset = 0)
	{
		std::string buffer = arg_string;

		for (int index = 0; index < arg_string.length(); ++index)
			buffer[index] = char(arg_string[index] + arg_offset);

		return buffer;
	}



	void pause(std::string arg_string, int arg_lines_above, int arg_lines_below)
	{
		promptString(lf(arg_lines_above) + arg_string + lf(arg_lines_below));
	}



	void pause(int arg_lines_above, int arg_lines_below)
	{
		pause(ctr("[PRESS ENTER TO CONTINUE]"), arg_lines_above, arg_lines_below);
	}













	/*



	// COPY INTO IMPLEMENTATION TO USE BENDEX


	std::string bendex(int arg_bendex)
	{

		const int DEFAULT_BENSET = -33;

		int benset = DEFAULT_BENSET;

		std::string benout;

		switch (arg_bendex)
		{
			case 110: benout = bencode("COPY ME", benset); break;
			case 120: benout = bencode("INTO IMPLEMENTATION", benset); break;

		}

		return benout;
	}



	 // COPY INTO IMPLEMENTATION TO USE BENLIST


	void benlist()
	{
		std::cout

		<< "110=" << bendex(110) << "\n"
		<< "120=" << bendex(120) << "\n\n"

		<< "" << bencode("BENCODE THIS STRING", 33);

	}

	*/











// END NAMESPACE
}