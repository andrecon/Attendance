//****************************************************************
// File_name: attendance.cpp
// Author:    Andres Contreras
// Date:      Sunday, January 14, 2018
// Purpose:   This program is used in order to  take peoples attendance
//            and outputs them into a file that can be later used 
//            for a spreadsheet
//****************************************************************
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <ctime>
#include <cassert>

//Sleep
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//-------LOCAL VARIABLES------------------

std::map<std::string,std::string> types;
string answer = "NULL";
string names = "NULL";
ifstream name_file_out;
string command = "NULL";
string tabs = "				";
string clear = "\n\n\n\n\n\n\n\n\n\n\n";
bool loop = false;

//-----------------------------------------

void event_handler();


int main()
{
    //system("python3  python_program/bar.py");
    system("clear");
    event_handler();
}

void event_handler()
{


    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n";
    cout << "                           	        	████████╗ █████╗ ██╗   ██╗    ██╗  ██╗ █████╗ ██████╗ ██████╗  █████╗     ███████╗██████╗ ███████╗██╗██╗      ██████╗ ███╗   ██╗ " << endl;
    cout << "                           		        ╚══██╔══╝██╔══██╗██║   ██║    ██║ ██╔╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗    ██╔════╝██╔══██╗██╔════╝██║██║     ██╔═══██╗████╗  ██║ " << endl;
    cout << "                           		           ██║   ███████║██║   ██║    █████╔╝ ███████║██████╔╝██████╔╝███████║    █████╗  ██████╔╝███████╗██║██║     ██║   ██║██╔██╗ ██║ " << endl;
    cout << "                           		           ██║   ██╔══██║██║   ██║    ██╔═██╗ ██╔══██║██╔═══╝ ██╔═══╝ ██╔══██║    ██╔══╝  ██╔═══╝ ╚════██║██║██║     ██║   ██║██║╚██╗██║ " << endl;
    cout << "                           		           ██║   ██║  ██║╚██████╔╝    ██║  ██╗██║  ██║██║     ██║     ██║  ██║    ███████╗██║     ███████║██║███████╗╚██████╔╝██║ ╚████║ " << endl;
    cout << "                           		           ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝     ╚═╝  ╚═╝    ╚══════╝╚═╝     ╚══════╝╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ " << endl;
    cout << "\n\n\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    cout << "\n\n\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\n\n";

    cout << "-----------------" << "This program is takes peoples attendance and outputs them into a file that can be later used for a spreadsheet" << "-----------------" << endl;



    name_file_out.open("Data/names.txt");
    cout << "\n\n";

    if(loop == false)
    {
        cout << tabs << tabs << "WHAT WOULD YOU LIKE TO DO TODAY?\n";
    }

    else
    {
        cout << tabs << tabs << "ANYTHING ELSE?\n";
    }

    cout << "\n\n";
    cout << tabs << "   " << "*ATTENDANCE - TAKE ATTENDANCE OF MEMBERS \n" <<  tabs << "   " << "*EDIT - EDITS MEMBERS INFO (JUST IN CASE THEY GET HERE LATE)\n" << tabs << "   " << "*EXIT - EXITS PROGRAM \n" << endl;
    cout << tabs << "   " << "DON'T WORRY, THIS PROGRAM IS NOT CASE SENSITIVE... WE TOOK CARE OF THAT" << endl;


    while(1)
    {
        cout << "Respond: ";
        getline(cin,command);

        //Turns uppercase letters to all lower case
        transform(command.begin(), command.end(), command.begin() , [](unsigned char c)->unsigned char{ return std::tolower(c); });

        if(command == "attendance" || command == "a")
        {
            system("clear");
            while(getline(name_file_out, names))
            {
                // Turns lower case strings in upper case strings
                transform(names.begin(), names.end(), names.begin() , [](unsigned char c)->unsigned char{ return std::toupper(c); });
                cout << "---------------------------------------\n" << endl;
                if(names == "NICHOLAS JEFFREY")
                {
                    cout << "Is " << names << " (NICK) present?" << endl;
                }

                else if( names == "ANDREW GIANOLI")
                {
                    cout << "IS " << names << " (CAVEMAN) present?" << endl;
                }
                else if( names == "DIEGO ARRIAGA")
                {
                    cout << "IS " << names << " (CHAPO) present?" << endl;
                }
                else if( names == "ISAAC MENDOZA")
                {
                    cout << "IS " << names << " (GHOST) present?" << endl;
                }
                else if( names == "JACOB FULLER")
                {
                    cout << "IS " << names << " (WHIP) present?" << endl;
                }
                else if( names == "JOSH NEIL")
                {
                    cout << "IS " << names << " (5-0) present?" << endl;
                }

                else
                {
                    cout << "Is " << names << " present?" << endl;
                }
                cout << "\n---------------------------------------" << endl;

                while(1)
                {
                    cout << tabs << "Y = present; N = unexcused (Late); E = excused" << endl;
                    cout << "Respond: ";
                    getline(cin, answer);
                    cout << endl;

                    transform(answer.begin(), answer.end(), answer.begin() , [](unsigned char c)->unsigned char{ return std::tolower(c); });
                    if(answer == "p"|| answer == "y")
                    {
                        types[names] = "P";				
                        system("clear");
                        break;
                    }
                    else if(answer == "e")
                    {
                        types[names] = "E";				
                        system("clear");
                        break;
                    }
                    else if(answer == "u"|| answer == "n")
                    {
                        types[names] = "U";				
                        system("clear");
                        break;
                    }
                    else
                    {
                        cout << "\nUNKNOWN COMMAND... TRY AGAIN\n" << endl;
                        usleep(1000000);
                        system("clear");
                        cout << "---------------------------------------\n" << endl;
                        cout << "Is " << names << " present?" << endl;
                        cout << "\n---------------------------------------" << endl;
                    }

                }
            }

            name_file_out.close();

            ofstream myfile;

            time_t curr_time;
            tm * curr_tm;
            char date_string[100];
            char time_string[100];

            time(&curr_time);
            curr_tm = localtime(&curr_time);
            strftime(date_string, 50, "%B %d, %Y ", curr_tm);
            strftime(time_string, 50, "%r", curr_tm);

            string all = strcat(date_string,".txt");

            myfile.open(all);

            for(std::map<string,string>::iterator iter = types.begin(); iter != types.end(); iter++)
            {
                myfile << iter->first << ", " << iter->second << endl;
            }
            cout << endl;

            cout << "**EXCUSED LIST**" << endl;
            cout << "---------------------------------------\n" << endl;
            for(std::map<string,string>::iterator iter = types.begin(); iter != types.end(); iter++)
            {
                if(iter->second == "E")
                {
                    cout << "*" << iter->first << endl;
                }

            }
            cout << "---------------------------------------\n\n" << endl;

            cout << "**UNEXCUSED LIST**" << endl;
            cout << "---------------------------------------\n" << endl;
            for(std::map<string,string>::iterator iter = types.begin(); iter != types.end(); iter++)
            {
                if(iter->second == "U")
                {
                    cout << "*" << iter->first << endl;
                }

            }
            cout << "---------------------------------------\n" << endl;

            myfile.close();
            loop = true;

            cout << "\n\n";
            cout << tabs << "   " << "MODIFICATIONS COMPLETED" << endl;
            cout << "\n\n";

            cout << "Press Enter to Continue";
            cin.ignore();
            system("clear");
            return event_handler();
        }
        else if(command == "exit")
        {
            system("Python3 python_program/create.py");
            cout << "\n\n";
            cout << tabs  << "   " << "EXITING PROGRAM...GOODBYE!" << endl;
            //3 seconds
            usleep(3000000);
            system("clear");
            return;
        }
        else if(command == "edit" || command == "e")
        {
            system("clear");
            string target = "";
            string new_data = "";
            string old_value = "";

            while(1)
            {


                if(types.empty() == true)
                {
                    cout << "EMPTY MAP...GIVING UP" << endl;
                    usleep(2000000);
                    system("clear");
                    return event_handler();
                    break;
                }
                else
                {
                    cout << "**THESE ARE THE FOLLOWING NAMES OF ACTIVES**" << endl;
                    for(std::map<string,string>::iterator iter = types.begin(); iter != types.end(); iter++)
                    {
                        cout << iter->first << endl;
                    }
                }

                cout << "\n\n";
                cout << tabs  << "   " << "ENTER NAME THAT YOU WANT TO EDIT" << endl;
                cout << "\n\n";

                cout << "Name: ";
                getline(cin,target);
                cout << "\nCHAGE IT TO?" << endl;
                cout << tabs << "P = present; E = excused; U = unexcused" << endl;
                cout << "Input: ";
                getline(cin,new_data);

                transform(new_data.begin(), new_data.end(), new_data.begin() , [](unsigned char c)->unsigned char{ return std::tolower(c); });

                assert(new_data == "p" || new_data == "e" || new_data == "u" && "VALUE DID NOT MATCHED, GIVING UP");

                transform(new_data.begin(), new_data.end(), new_data.begin() , [](unsigned char c)->unsigned char{ return std::toupper(c); });

                std::map<string,string>::iterator iter = types.find(target);

                if(iter != types.end())
                {
                    old_value = iter->second;
                    iter->second = new_data;
                    cout << "\n\n";
                    cout << tabs << "   " << "UPDATE COMPLETED" << endl;
                    cout << "**VALUE WENT FROM \n" << old_value << "-> " << iter->second << "\nFOR ACTIVE NAME: " << iter->first << endl;

                    loop = true;
                    cout << "\n\n\n\n";
                    usleep(3000000);
                    system("clear");
                    return event_handler();
                    break;
                }
                else
                {
                    assert(iter == types.end());
                    cout << "\n**COULD NOT FIND NAME.. TRY AGAIN!" << endl;
                }

            }

        }
        else
        {
            assert(command != "exit" || command != "attendance" || command != "edit");
            cout << "\n\n";
            cout << "INVALID COMMAND, TRY AGAIN!" << endl;
            cout << "\n\n";
        }
    }
}

